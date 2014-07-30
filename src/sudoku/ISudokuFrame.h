///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __ISUDOKUFRAME_H__
#define __ISUDOKUFRAME_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/statusbr.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/panel.h>
#include <wx/grid.h>
#include <wx/notebook.h>
#include <wx/textctrl.h>
#include <wx/splitter.h>
#include <wx/frame.h>
#include <wx/aui/aui.h>
#include <wx/stattext.h>
#include <wx/radiobox.h>
#include <wx/gauge.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class ISudokuFrame
///////////////////////////////////////////////////////////////////////////////
class ISudokuFrame : public wxFrame 
{
	private:
	
	protected:
		enum
		{
			wxID_Exit = 1000
		};
		
		wxMenuBar* m_menubar3;
		wxMenu* m_menu5;
		wxMenu* m_menu6;
		wxStatusBar* m_frameStatusBar;
		wxSplitterWindow* m_splitter2;
		wxPanel* m_workspace_panel;
		wxNotebook* m_book;
		wxPanel* m_panel16;
		wxPanel* m_panel18;
		wxButton* m_btn_open;
		wxButton* m_button5;
		wxButton* m_button6;
		wxButton* m_button4;
		wxPanel* m_panel19;
		wxPanel* m_panel21;
		wxGrid* m_puzzle_grid;
		wxPanel* m_panel22;
		wxGrid* m_solution_grid;
		wxPanel* m_panel17;
		wxPanel* m_panel11;
		wxTextCtrl* m_log_text;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSize( wxSizeEvent& event ) { event.Skip(); }
		virtual void OnInputPuzzle( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSolve( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnSaveSolution( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBatchMode( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		ISudokuFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Sudoku"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,800 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		wxAuiManager m_mgr;
		
		~ISudokuFrame();
		
		void m_splitter2OnIdle( wxIdleEvent& )
		{
			m_splitter2->SetSashPosition( 500 );
			m_splitter2->Disconnect( wxEVT_IDLE, wxIdleEventHandler( ISudokuFrame::m_splitter2OnIdle ), NULL, this );
		}
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class IBatchProgressFrame
///////////////////////////////////////////////////////////////////////////////
class IBatchProgressFrame : public wxFrame 
{
	private:
	
	protected:
		wxStaticText* m_staticText4;
		wxTextCtrl* m_puzzle_file_textctrl;
		wxButton* m_button5;
		wxTextCtrl* m_solution_file_textctrl;
		wxButton* m_button51;
		wxRadioBox* m_solver_radio;
		wxGauge* m_gauge;
		wxButton* m_button10;
		wxStaticText* m_progress_text;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnUpdatePuzzleFile( wxCommandEvent& event ) { event.Skip(); }
		virtual void ChoosePuzzle( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUpdateSolutionFile( wxCommandEvent& event ) { event.Skip(); }
		virtual void ChooseSolution( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnUpdateSolver( wxCommandEvent& event ) { event.Skip(); }
		virtual void BatchStart( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		IBatchProgressFrame( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Solving Puzzles  ..."), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~IBatchProgressFrame();
	
};

#endif //__ISUDOKUFRAME_H__
