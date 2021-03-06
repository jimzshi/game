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

using namespace std;

extern const char* VERSION_NUMBER;
extern const char* PHASE_STRING;

class MyFrame : public ITCFrame {
	void UpdateInputGrid();

	void UpdateOutputTxtCtrl();
	void UpdateColOrder(bool moveup);
protected:
	virtual void UpdateInputPreview(wxFileDirPickerEvent& event);
	virtual void UpdateInputPreview(wxCommandEvent& event);
	virtual void UpdateOutputPreview(wxFileDirPickerEvent& event);
	virtual void UpdateOutputPreview(wxCommandEvent& event);
	virtual void OnRun(wxCommandEvent& event);
	virtual void OnClose(wxCommandEvent& event);
	virtual void OnClearLog(wxCommandEvent& event);
	virtual void OnColMoveUp(wxCommandEvent& event);
	virtual void OnColMoveDown(wxCommandEvent& event);

	//special command for 'loop and split'
	virtual void OnRun1(wxCommandEvent& event);
	virtual void OnColMoveUp1(wxCommandEvent& event);
	virtual void OnColMoveDown1(wxCommandEvent& event);

public:
	MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size, int threads = 4);

private:
	wxLog *m_log;
	std::vector<zks::u8string> preview_buf;
	std::vector<std::vector<zks::u8string>> preview_grid;
	zks::u8string ifname, ofname;
	zks::u8string delimiters, quotes;
	zks::u8string ideli, iquote, odeli, oquote;
	//std::vector<zks::u8string> col_names;  => preview_grid[0];
	std::vector<int> col_order;
	int col_sel;
	int thread_cnt;
};

#endif //ZKS_SUDOKUFRAME_H_
