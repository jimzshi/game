#include "TCMainFrame.h"

#include "mmap.h"

#include <algorithm>
#include <numeric>
#include <memory>
#include <fstream>
#include <cassert>
#include <unordered_map>

struct LoopSplitOFStream {
	zks::u8string key;
	zks::u8string ofname;
	int lno;
	std::ofstream ofs;
	LoopSplitOFStream(zks::u8string const& k, zks::u8string const& base, zks::u8string const& header, int line_number, char sep)
		: key(k), lno(line_number) {
		ofname.format(base.size() + k.size() + 16, "%s%c%s.%s", base.c_str(), sep, key.c_str(), "csv");

		ofs.open(ofname.c_str(), std::ios_base::trunc);
		if (!ofs) {
			throw 23;
		}

		ofs << header;
	}
};

using LoopSplitOFSMap = std::unordered_map<zks::u8string, LoopSplitOFStream>;

#define input_has_header (m_notebook->GetSelection() ? input_has_header1 : input_has_header0)
#define input_delimiter (m_notebook->GetSelection() ? input_delimiter1 : input_delimiter0)
#define input_quote (m_notebook->GetSelection() ? input_quote1 : input_quote0)
#define col_order_list (m_notebook->GetSelection() ? col_order_list1 : col_order_list0)
#define output_has_header (m_notebook->GetSelection() ? output_has_header1 : output_has_header0)
#define output_delimiter (m_notebook->GetSelection() ? output_delimiter1 : output_delimiter0)
#define output_quote (m_notebook->GetSelection() ? output_quote1 : output_quote0)
#define m_log_text (m_notebook->GetSelection() ? m_log_text1 : m_log_text0)

void MyFrame::UpdateInputGrid() {
	if (preview_buf.size() == 0) {
		return;
	}

	wxGrid* input_preview = nullptr;
	if (m_notebook->GetSelection() == 0) {
		input_preview = input_preview0;
	}
	else {
		input_preview = input_preview1;
	}
	input_preview->ClearGrid();
	preview_grid.clear();
	zks::u8string del{ 1, input_delimiter->GetSelection() >= delimiters.size() ? ',' : delimiters[input_delimiter->GetSelection()] };
	ideli = del;
	zks::u8string quote;
	if (input_quote->GetSelection() < quotes.size()) {
		quote.push_back(quotes[input_quote->GetSelection()]);
	}
	iquote = quote;


	auto first_row = preview_buf[0].split(false, del, quote);
	if (input_has_header->IsChecked()) {
		preview_grid.push_back(first_row);
		for (size_t c = 0; c < 5 && c < first_row.size(); ++c) {
			input_preview->SetColLabelValue(c, wxString::Format(wxT("%s"), first_row[c].str()));
		}
	}
	else {
		preview_grid.emplace_back(first_row.size());
		for (size_t i = 0; i < first_row.size(); ++i) {
			preview_grid[0][i].format(16, "Col%d", i + 1);
		}
		for (int c = 0; c < 5; ++c) {
			input_preview->SetColLabelValue(c, wxString::Format(wxT("Col%d"), c));
		}
	}
	assert(preview_buf.size() <= 5);
	for (int r = 0 + input_has_header->IsChecked(); r < 5 && r < preview_buf.size(); ++r) {
		auto fields = preview_buf[r].split(false, del, quote);
		preview_grid.push_back(fields);
		for (int c = 0; c < 5 && c < fields.size(); ++c) {
			input_preview->SetCellValue(r - input_has_header->IsChecked(), c, wxString::Format(wxT("%s"), fields[c].str()));
		}
	}
	col_order.resize(preview_grid[0].size());
	std::iota(col_order.begin(), col_order.end(), 0);
}

void MyFrame::UpdateOutputTxtCtrl() {
	if (preview_buf.size() == 0) {
		return;
	}

	assert(col_order.size() == preview_grid[0].size());
	col_order_list->Clear();
	for (size_t i = 0; i < col_order.size(); ++i) {
		col_order_list->AppendString(preview_grid[0][col_order[i]].str());
	}
	if (col_sel >= 0) {
		col_order_list->Select(col_sel);
	}

	zks::u8string del{ 1, output_delimiter->GetSelection() >= delimiters.size() ? ',' : delimiters[output_delimiter->GetSelection()] };
	odeli = del;
	zks::u8string quote;
	if (output_quote->GetSelection() < quotes.size()) {
		quote.push_back(quotes[output_quote->GetSelection()]);
	}
	oquote = quote;

	wxTextCtrl* output_preview = nullptr;
	if (m_notebook->GetSelection() == 0) {
		output_preview = output_preview0;
	}
	else {
		output_preview = output_preview1;
	}

	output_preview->Clear();
	for (size_t i = 1 - output_has_header->IsChecked(); i < preview_grid.size(); ++i) {
		if (preview_grid[i].size() != col_order.size()) {
			continue;
		}
		output_preview->AppendText(wxString::Format("%s\n",
			del.join(preview_grid[i], quote, "\\", col_order.begin(), col_order.end()).str()));
	}
}

void MyFrame::UpdateColOrder(bool moveup) {
	wxArrayInt selections;
	col_order_list->GetSelections(selections);
	if (selections.size() == 0) {
		wxLogMessage("select a column first.");
		return;
	}
	assert(selections.size() == 1);
	int pos = selections[0];
	int cnt = col_order_list->GetCount();
	wxLogMessage("move %d/%d %s", pos, cnt, moveup ? "up" : "down");
	if (moveup && pos) {
		std::swap(col_order[pos], col_order[pos - 1]);
		col_sel = pos - 1;
	}
	else if (!moveup && pos < cnt - 1) {
		std::swap(col_order[pos], col_order[pos + 1]);
		col_sel = pos + 1;
	}
	UpdateOutputTxtCtrl();
}

void MyFrame::UpdateInputPreview(wxFileDirPickerEvent & event) {
	ifname = event.GetPath().ToStdString();
	wxLogMessage("UpdateInputPreview: %s", ifname.c_str());
	std::ifstream ifs(ifname.c_str());
	if (!ifs) {
		return;
	}

	auto txt_fmt = zks::unicode::txt_consume_header(ifs);
	if (txt_fmt == zks::unicode::txt_format::error) {
		wxMessageBox("[Error]: Input file has an invalid UTF8 header!", "Error");
		return;
	}

	zks::u8string line;
	preview_buf.clear();
	for (int i = 1; i < 6 && zks::getline(ifs, line); ++i) {
		preview_buf.push_back(std::move(line));
	}
	UpdateInputGrid();
	UpdateOutputTxtCtrl();
}

void MyFrame::UpdateInputPreview(wxCommandEvent & event) {
	wxLogMessage("UpdateInputPreview: %d, %d, %d", event.GetEventCategory(), event.GetEventType(), event.GetSelection());
	UpdateInputGrid();
	UpdateOutputTxtCtrl();
}

void MyFrame::UpdateOutputPreview(wxFileDirPickerEvent & event) {
	ofname = event.GetPath().ToStdString();
	wxLogMessage("UpdateOutputPreview: %s", ofname.c_str());
	UpdateOutputTxtCtrl();
}

void MyFrame::UpdateOutputPreview(wxCommandEvent & event) {
	wxLogMessage("UpdateOutputPreview: %d, %d, %d", event.GetEventCategory(), event.GetEventType(), event.GetSelection());
	UpdateOutputTxtCtrl();
}

void MyFrame::OnRun(wxCommandEvent & event) {
	if (ofname.empty()) {
		wxMessageBox("[Error]: Output Filename is Empty!", "Error");
		return;
	}
	if (ifname.empty()) {
		wxMessageBox("[Error]: Input Filename is Empty!", "Error");
		return;
	}
	wxLogMessage("OnRun");
	std::ofstream ofs(ofname.c_str(), std::ios_base::trunc);
	if (!ofs) {
		wxMessageBox("[Error]: Can't access to output file!", "Error");
		return;
	}
	std::ifstream ifs(ifname.c_str());
	if (!ifs) {
		wxMessageBox("[Error]: Can't access to input file!", "Error");
		return;
	}

	if (!input_has_header->IsChecked() && output_has_header->IsChecked()) {
		ofs << odeli.join(preview_grid[0], oquote, "\\", col_order.begin(), col_order.end()).str() << "\n";
	}
	size_t ln = 0;
	size_t err = 0;
	size_t cnt = 0;
	size_t emptyno = 0;
	size_t skip = 0;
	for (zks::u8string line; zks::getline(ifs, line); ++ln) {
		line = line.trim_spaces();
		if (line.empty()) {
			++emptyno;
			continue;
		}
		++cnt;
		if (ln == 0 && input_has_header->IsChecked() && !output_has_header->IsChecked()) {
			++skip;
			continue;
		}
		auto row = line.split(false, ideli, iquote);
		if (row.size() != preview_grid[0].size()) {
			wxLogMessage("[Error]:Line(%d)'s fields size(%d) doesn't match header's size(%d), ignore it.", ln + 1, row.size(), preview_grid[0].size());
			++err;
			continue;
		}
		ofs << odeli.join(row, oquote, "\\", col_order.begin(), col_order.end()).str() << "\n";
	}
	wxMessageBox(wxString::Format("Conversion is done. Stats:\n  lines: %d\n  data lines: %d\n  skip lines: %d\n  error lines: %d", ln + 1, cnt, skip, err), "Error");
}

void MyFrame::OnClose(wxCommandEvent & event) {
	wxLogMessage("OnClose");
	this->Close();
}

void MyFrame::OnClearLog(wxCommandEvent & event) {
	m_log_text->Clear();
	wxLogMessage("OnClearLog");
}

void MyFrame::OnColMoveUp(wxCommandEvent & event) {
	UpdateColOrder(true);
}

void MyFrame::OnColMoveDown(wxCommandEvent & event) {
	UpdateColOrder(false);
}


void MyFrame::OnColMoveUp1(wxCommandEvent & event) {
	//UpdateColOrder(true);
}

void MyFrame::OnColMoveDown1(wxCommandEvent & event) {
	//UpdateColOrder(false);
}

void MyFrame::OnRun1(wxCommandEvent & event) {
	if (ofname.empty()) {
		wxMessageBox("[Error]: Output Filename is Empty!", "Error");
		return;
	}
	if (ifname.empty()) {
		wxMessageBox("[Error]: Input Filename is Empty!", "Error");
		return;
	}
	wxLogMessage("OnRun1: %s", ifname.c_str());
	std::ifstream ifs(ifname.c_str());
	if (!ifs) {
		wxMessageBox("[Error]: Can't access to input file!", "Error");
		return;
	}

	zks::u8string base = ofname.split(true, ".")[0];

	zks::u8string header;
	if (output_has_header->IsChecked()) {
		header = odeli.join(preview_grid[0], oquote, "\\", col_order.begin(), col_order.end()) + "\n";
	}
	wxArrayInt selections;
	col_order_list->GetSelections(selections);
	if (selections.size() == 0) {
		wxLogMessage("select a column first.");
		return;
	}
	assert(selections.size() == 1);
	int sel = selections[0];
	int sel_cnt = col_order_list->GetCount();
	wxLogMessage("select %d of %d", sel, sel_cnt);

	size_t ln = 0;
	size_t err = 0;
	size_t cnt = 0;
	size_t emptyno = 0;
	size_t skip = 0;
	LoopSplitOFSMap lsmap;
	
	auto instr = zks::u8string( zks::mmap(ifs) );
	auto inlines = instr.split(true, "\n");

	for (zks::u8string line : inlines) {
		++ln;
		line = line.trim_spaces();
		if (line.empty()) {
			++emptyno;
			continue;
		}
		++cnt;
		if (ln == 1) {
			++skip;
			continue;
		}
		auto row = line.split(false, ideli, iquote);
		if (row.size() != preview_grid[0].size()) {
			wxLogMessage("[Error]:Line(%d)'s fields size(%d) doesn't match header's size(%d), ignore it.", ln, row.size(), preview_grid[0].size());
			++err;
			continue;
		}

		auto& ofs_entry = lsmap.try_emplace(row[sel], row[sel], base, header, ln, '_').first->second;

		ofs_entry.ofs << odeli.join(row, oquote, "\\", col_order.begin(), col_order.end()).str() << "\n";
	}
	wxMessageBox(wxString::Format("Conversion is done. Stats:\n  lines: %d\n  data lines: %d\n  skip lines: %d\n  error lines: %d", ln, cnt, skip, err), "Error");
}

MyFrame::MyFrame(const wxString & title, const wxPoint & pos, const wxSize & size) : ITCFrame(NULL, wxID_ANY, title)
{
	m_log = wxLog::SetActiveTarget(new wxLogTextCtrl(m_log_text));
	delimiters = ",\t;";
	quotes = "'\"";
	col_sel = -1;
	this->SetIcon(wxIcon("TCIcon"));
}
