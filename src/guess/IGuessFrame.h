///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __IGUESSFRAME_H__
#define __IGUESSFRAME_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/button.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/statbmp.h>
#include <wx/scrolwin.h>
#include <wx/textctrl.h>
#include <wx/statbox.h>
#include <wx/bmpbuttn.h>
#include <wx/notebook.h>
#include <wx/splitter.h>
#include <wx/statusbr.h>
#include <wx/menu.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////

namespace zks
{
	namespace game
	{
		namespace guess
		{
			///////////////////////////////////////////////////////////////////////////////
			/// Class IGuessFrame
			///////////////////////////////////////////////////////////////////////////////
			class IGuessFrame : public wxFrame 
			{
				private:
				
				protected:
					wxSplitterWindow* m_splitter;
					wxPanel* m_panel2;
					wxNotebook* m_guess_book;
					wxPanel* m_guss_name_page;
					wxPanel* m_gn_btn_panel;
					wxButton* m_button1;
					wxButton* m_button2;
					wxButton* m_button3;
					wxScrolledWindow* m_gn_bmp_panel;
					wxStaticBitmap* m_statbmp;
					wxPanel* m_gn_input_panel;
					wxTextCtrl* m_gn_input_text;
					wxPanel* m_guess_pic_page;
					wxTextCtrl* m_textCtrl3;
					wxBitmapButton* m_bpButton1;
					wxBitmapButton* m_bpButton2;
					wxBitmapButton* m_bpButton3;
					wxBitmapButton* m_bpButton4;
					wxPanel* m_panel3;
					wxTextCtrl* m_log_text;
					wxStatusBar* m_statusBar1;
					wxMenuBar* m_menubar1;
					wxMenu* m_menu1;
					wxMenu* m_menu2;
				
				public:
					
					IGuessFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
					
					~IGuessFrame();
					
					void m_splitterOnIdle( wxIdleEvent& )
					{
						m_splitter->SetSashPosition( 0 );
						m_splitter->Disconnect( wxEVT_IDLE, wxIdleEventHandler( IGuessFrame::m_splitterOnIdle ), NULL, this );
					}
				
			};
			
		} // namespace guess
	} // namespace game
} // namespace zks

#endif //__IGUESSFRAME_H__
