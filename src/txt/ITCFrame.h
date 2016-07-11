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
#include <wx/intl.h>
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
		wxRadioBox* input_delimiter0;
		wxRadioBox* input_quote0;
		wxPanel* m_panel15;
		wxFilePickerCtrl* input_filepicker0;
		wxCheckBox* input_has_header0;
		wxPanel* m_panel11;
		wxGrid* input_preview0;
		wxPanel* m_panel5;
		wxPanel* m_panel91;
		wxRadioBox* output_delimiter0;
		wxRadioBox* output_quote0;
		wxPanel* m_panel16;
		wxFilePickerCtrl* output_filepicker;
		wxCheckBox* output_has_header0;
		wxPanel* m_panel111;
		wxPanel* m_panel13;
		wxListBox* col_order_list0;
		wxButton* btn_mv_up;
		wxButton* btn_mv_down;
		wxPanel* m_panel141;
		wxTextCtrl* output_preview0;
		wxPanel* m_panel6;
		wxPanel* m_panel12;
		wxButton* btn_run;
		wxButton* btn_close;
		wxButton* btn_clear;
		wxTextCtrl* m_log_text0;
		wxPanel* loop_panel;
		wxPanel* m_panel41;
		wxPanel* m_panel92;
		wxRadioBox* input_delimiter1;
		wxRadioBox* input_quote1;
		wxPanel* m_panel151;
		wxFilePickerCtrl* input_filepicker1;
		wxCheckBox* input_has_header1;
		wxPanel* m_panel112;
		wxGrid* input_preview1;
		wxPanel* m_panel51;
		wxPanel* m_panel911;
		wxRadioBox* output_delimiter1;
		wxRadioBox* output_quote1;
		wxPanel* m_panel161;
		wxFilePickerCtrl* output_filepicker1;
		wxCheckBox* output_has_header1;
		wxPanel* m_panel1111;
		wxPanel* m_panel131;
		wxListBox* col_order_list1;
		wxButton* btn_mv_up1;
		wxButton* btn_mv_down1;
		wxPanel* m_panel1411;
		wxTextCtrl* output_preview1;
		wxPanel* m_panel61;
		wxPanel* m_panel121;
		wxButton* btn_run1;
		wxButton* btn_close1;
		wxButton* btn_clear1;
		wxTextCtrl* m_log_text1;
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
		virtual void OnClearLog( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnColMoveUp1( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnColMoveDown1( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRun1( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		ITCFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Txt Converter 0.1 Beta"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,900 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~ITCFrame();
	
};

#endif //__ITCFRAME_H__
