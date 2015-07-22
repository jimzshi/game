///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __ITCFRAME_H__
#define __ITCFRAME_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/radiobox.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/panel.h>
#include <wx/filepicker.h>
#include <wx/checkbox.h>
#include <wx/grid.h>
#include <wx/listbox.h>
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/notebook.h>
#include <wx/statusbr.h>
#include <wx/menu.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class ITCFrame
///////////////////////////////////////////////////////////////////////////////
class ITCFrame : public wxFrame 
{
	private:
	
	protected:
		wxNotebook* m_notebook;
		wxPanel* single_panel;
		wxPanel* m_panel4;
		wxPanel* m_panel9;
		wxRadioBox* input_delimiter;
		wxRadioBox* input_quote;
		wxPanel* m_panel15;
		wxFilePickerCtrl* input_filepicker;
		wxCheckBox* input_has_header;
		wxPanel* m_panel11;
		wxGrid* input_preview;
		wxPanel* m_panel5;
		wxPanel* m_panel91;
		wxRadioBox* output_delimiter;
		wxRadioBox* output_quote;
		wxPanel* m_panel16;
		wxFilePickerCtrl* output_filepicker;
		wxCheckBox* output_has_header;
		wxPanel* m_panel111;
		wxPanel* m_panel13;
		wxListBox* col_order_list;
		wxButton* btn_mv_up;
		wxButton* btn_mv_down;
		wxPanel* m_panel141;
		wxTextCtrl* output_preview;
		wxPanel* m_panel6;
		wxPanel* m_panel12;
		wxButton* btn_run;
		wxButton* btn_close;
		wxButton* btn_reset;
		wxButton* btn_clear;
		wxTextCtrl* m_log_text;
		wxPanel* batch_panel;
		wxStatusBar* m_statusBar1;
		wxMenuBar* m_menubar1;
		
		// Virtual event handlers, overide them in your derived class
		virtual void UpdateInputPreview( wxCommandEvent& event ) { event.Skip(); }
		virtual void UpdateInputPreview( wxFileDirPickerEvent& event ) { event.Skip(); }
		virtual void UpdateOutputPreview( wxCommandEvent& event ) { event.Skip(); }
		virtual void UpdateOutputPreview( wxFileDirPickerEvent& event ) { event.Skip(); }
		virtual void OnColMoveUp( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnColMoveDown( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRun( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClose( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnReset( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnClearLog( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		ITCFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Txt Converter 0.1 Beta"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,900 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~ITCFrame();
	
};

#endif //__ITCFRAME_H__
