#ifndef ZKS_SUDOKUFRAME_H_
#define ZKS_SUDOKUFRAME_H_

#include "stopwatch.h"
#include "u8string.h"

#include "ITCFrame.h"

#include "wx/wxprec.h"
#ifndef WX_PRECOMP    
#include "wx/wx.h"
#endif

#include <vector>
#include <memory>
#include <fstream>
#include <cassert>

using namespace std;

class MyFrame : public ITCFrame {
	void UpdateInputGrid() {
		input_preview->ClearGrid();
		zks::u8string del {1, input_delimiter->GetSelection() >= delimiters.size() ? ',' : delimiters[input_delimiter->GetSelection()] };
		zks::u8string esc {1, input_escape->GetSelection() >= escapes.size() ? '\"' : escapes[input_escape->GetSelection()] };
		if (input_has_header->IsChecked()) {
			auto headers = preview_buf[0].split(true, del, esc);
			for (int c = 0; c < 5; ++c) {
				input_preview->SetColLabelValue(c, wxString::Format(wxT("%s"), headers[c].str()));
			}
		}
		else {
			for (int c = 0; c < 5; ++c) {
				input_preview->SetColLabelValue(c, wxString::Format(wxT("Col%d"), c));
			}
		}
		assert(input_buf.size() == 5);
		for (int r = 0 + input_has_header->IsChecked(); r < 5; ++r) {
			auto fields = preview_buf[r].split(true, del, esc);
			for (int c = 0; c < 5 && c<fields.size(); ++c) {
				input_preview->SetCellValue(r - input_has_header->IsChecked(), c, wxString::Format(wxT("%s"), fields[c].str()) );
			}
		}
	}

	void UpdateOutputTxtCtrl() {

	}
protected:
	virtual void UpdateInputPreview(wxFileDirPickerEvent& event) {
		ifname = event.GetPath().ToStdString();
		wxLogMessage("UpdateInputPreview: %s", ifname.c_str());
		std::ifstream ifs(ifname.c_str());
		if (!ifs) {
			return;
		}
		zks::u8string line;
		preview_buf.clear();
		for (int i = 1; i < 6 && zks::getline(ifs, line); ++i) {
			preview_buf.push_back(std::move(line));
		}
		UpdateInputGrid();
	}
	virtual void UpdateInputPreview(wxCommandEvent& event) { 
		wxLogMessage("UpdateInputPreview: %d, %d, %d", event.GetEventCategory(), event.GetEventType(), event.GetSelection()); 
		UpdateInputGrid();
	}
	virtual void UpdateOutputPreview(wxFileDirPickerEvent& event) { 
		ofname = event.GetPath().ToStdString();
		wxLogMessage("UpdateOutputPreview: %s", ofname.c_str());
		UpdateInputGrid();
	}
	virtual void UpdateOutputPreview(wxCommandEvent& event) { 
		wxLogMessage("UpdateOutputPreview: %d, %d, %d", event.GetEventCategory(), event.GetEventType(), event.GetSelection());
		UpdateInputGrid();
	}
	virtual void OnRun(wxCommandEvent& event) { wxLogMessage("OnRun"); }
	virtual void OnClose(wxCommandEvent& event) { wxLogMessage("OnClose"); }
	virtual void OnReset(wxCommandEvent& event) { wxLogMessage("OnReset"); }
	virtual void OnClearLog(wxCommandEvent& event) { wxLogMessage("OnClearLog"); }
public:
	MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size) : ITCFrame(NULL, wxID_ANY, title)
	{
		m_log = wxLog::SetActiveTarget(new wxLogTextCtrl(m_log_text));
		delimiters = ",\t;";
		escapes = "'\"";
	}
private:
	wxLog *m_log;
	std::vector<zks::u8string> preview_buf;
	zks::u8string ifname, ofname;
	zks::u8string delimiters, escapes;
};

#endif //ZKS_SUDOKUFRAME_H_
