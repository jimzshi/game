///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "ISudokuFrame.h"

///////////////////////////////////////////////////////////////////////////

ISudokuFrame::ISudokuFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	m_mgr.SetManagedWindow(this);
	m_mgr.SetFlags(wxAUI_MGR_DEFAULT);
	
	m_menubar3 = new wxMenuBar( 0 );
	m_menu5 = new wxMenu();
	wxMenuItem* m_menuItem5;
	m_menuItem5 = new wxMenuItem( m_menu5, wxID_ANY, wxString( wxT("MyMenuItem") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu5->Append( m_menuItem5 );
	
	m_menubar3->Append( m_menu5, wxT("MyMenu") ); 
	
	m_menu6 = new wxMenu();
	wxMenuItem* m_menuItem6;
	m_menuItem6 = new wxMenuItem( m_menu6, wxID_ANY, wxString( wxT("MyMenuItem") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu6->Append( m_menuItem6 );
	
	m_menubar3->Append( m_menu6, wxT("MyMenu") ); 
	
	this->SetMenuBar( m_menubar3 );
	
	m_frameStatusBar = this->CreateStatusBar( 3, wxST_SIZEGRIP, wxID_ANY );
	m_splitter2 = new wxSplitterWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter2->Connect( wxEVT_IDLE, wxIdleEventHandler( ISudokuFrame::m_splitter2OnIdle ), NULL, this );
	
	m_mgr.AddPane( m_splitter2, wxAuiPaneInfo() .Center() .MaximizeButton( true ).MinimizeButton( true ).PinButton( true ).Dock().Resizable().FloatingSize( wxDefaultSize ).DockFixed( false ).Floatable( false ) );
	
	m_workspace_panel = new wxPanel( m_splitter2, wxID_ANY, wxDefaultPosition, wxSize( -1,350 ), wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer5;
	sbSizer5 = new wxStaticBoxSizer( new wxStaticBox( m_workspace_panel, wxID_ANY, wxT("Workspace") ), wxVERTICAL );
	
	m_book = new wxNotebook( m_workspace_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_panel16 = new wxPanel( m_book, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	m_panel18 = new wxPanel( m_panel16, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer11;
	sbSizer11 = new wxStaticBoxSizer( new wxStaticBox( m_panel18, wxID_ANY, wxT("Actions") ), wxHORIZONTAL );
	
	m_btn_open = new wxButton( m_panel18, wxID_ANY, wxT("&Open"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer11->Add( m_btn_open, 0, wxALL, 5 );
	
	m_button5 = new wxButton( m_panel18, wxID_ANY, wxT("Sol&ve"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer11->Add( m_button5, 0, wxALL, 5 );
	
	m_button6 = new wxButton( m_panel18, wxID_ANY, wxT("&Save"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer11->Add( m_button6, 0, wxALL, 5 );
	
	
	m_panel18->SetSizer( sbSizer11 );
	m_panel18->Layout();
	sbSizer11->Fit( m_panel18 );
	bSizer4->Add( m_panel18, 1, wxEXPAND | wxALL, 5 );
	
	m_panel19 = new wxPanel( m_panel16, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );
	
	m_splitter4 = new wxSplitterWindow( m_panel19, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxSP_3D );
	m_splitter4->Connect( wxEVT_IDLE, wxIdleEventHandler( ISudokuFrame::m_splitter4OnIdle ), NULL, this );
	
	m_panel21 = new wxPanel( m_splitter4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer9;
	sbSizer9 = new wxStaticBoxSizer( new wxStaticBox( m_panel21, wxID_ANY, wxT("Puzzle") ), wxVERTICAL );
	
	m_puzzle_panel = new wxPanel( m_panel21, wxID_ANY, wxDefaultPosition, wxSize( 240,300 ), wxTAB_TRAVERSAL );
	sbSizer9->Add( m_puzzle_panel, 1, wxEXPAND | wxALL, 5 );
	
	
	m_panel21->SetSizer( sbSizer9 );
	m_panel21->Layout();
	sbSizer9->Fit( m_panel21 );
	m_panel22 = new wxPanel( m_splitter4, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer10;
	sbSizer10 = new wxStaticBoxSizer( new wxStaticBox( m_panel22, wxID_ANY, wxT("Solution") ), wxVERTICAL );
	
	m_solution_panel = new wxPanel( m_panel22, wxID_ANY, wxDefaultPosition, wxSize( 240,300 ), wxTAB_TRAVERSAL );
	sbSizer10->Add( m_solution_panel, 1, wxEXPAND | wxALL, 5 );
	
	
	m_panel22->SetSizer( sbSizer10 );
	m_panel22->Layout();
	sbSizer10->Fit( m_panel22 );
	m_splitter4->SplitVertically( m_panel21, m_panel22, 0 );
	bSizer6->Add( m_splitter4, 1, wxALL|wxEXPAND, 5 );
	
	
	m_panel19->SetSizer( bSizer6 );
	m_panel19->Layout();
	bSizer6->Fit( m_panel19 );
	bSizer4->Add( m_panel19, 1, wxEXPAND | wxALL, 5 );
	
	
	m_panel16->SetSizer( bSizer4 );
	m_panel16->Layout();
	bSizer4->Fit( m_panel16 );
	m_book->AddPage( m_panel16, wxT("Solver"), true );
	m_panel17 = new wxPanel( m_book, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_book->AddPage( m_panel17, wxT("Generator"), false );
	
	sbSizer5->Add( m_book, 1, wxEXPAND | wxALL, 5 );
	
	
	m_workspace_panel->SetSizer( sbSizer5 );
	m_workspace_panel->Layout();
	m_panel11 = new wxPanel( m_splitter2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer6;
	sbSizer6 = new wxStaticBoxSizer( new wxStaticBox( m_panel11, wxID_ANY, wxT("Log Message") ), wxVERTICAL );
	
	m_log_text = new wxTextCtrl( m_panel11, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY|wxTE_WORDWRAP );
	sbSizer6->Add( m_log_text, 1, wxALL|wxEXPAND, 5 );
	
	
	m_panel11->SetSizer( sbSizer6 );
	m_panel11->Layout();
	sbSizer6->Fit( m_panel11 );
	m_splitter2->SplitHorizontally( m_workspace_panel, m_panel11, 0 );
	
	m_mgr.Update();
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_SIZE, wxSizeEventHandler( ISudokuFrame::OnSize ) );
	m_btn_open->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ISudokuFrame::OpenPuzzle ), NULL, this );
	m_button5->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ISudokuFrame::OnSolve ), NULL, this );
	m_button6->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ISudokuFrame::OnSaveSolution ), NULL, this );
}

ISudokuFrame::~ISudokuFrame()
{
	// Disconnect Events
	this->Disconnect( wxEVT_SIZE, wxSizeEventHandler( ISudokuFrame::OnSize ) );
	m_btn_open->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ISudokuFrame::OpenPuzzle ), NULL, this );
	m_button5->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ISudokuFrame::OnSolve ), NULL, this );
	m_button6->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ISudokuFrame::OnSaveSolution ), NULL, this );
	
	m_mgr.UnInit();
	
}
