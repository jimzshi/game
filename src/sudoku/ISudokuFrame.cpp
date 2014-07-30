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
	m_menuItem5 = new wxMenuItem( m_menu5, wxID_Exit, wxString( wxT("Exit") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu5->Append( m_menuItem5 );
	
	m_menubar3->Append( m_menu5, wxT("File") ); 
	
	m_menu6 = new wxMenu();
	wxMenuItem* m_menuItem6;
	m_menuItem6 = new wxMenuItem( m_menu6, wxID_ABOUT, wxString( wxT("About") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu6->Append( m_menuItem6 );
	
	m_menubar3->Append( m_menu6, wxT("Help") ); 
	
	this->SetMenuBar( m_menubar3 );
	
	m_frameStatusBar = this->CreateStatusBar( 3, wxST_SIZEGRIP, wxID_ANY );
	m_splitter2 = new wxSplitterWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter2->Connect( wxEVT_IDLE, wxIdleEventHandler( ISudokuFrame::m_splitter2OnIdle ), NULL, this );
	
	m_mgr.AddPane( m_splitter2, wxAuiPaneInfo() .Center() .MaximizeButton( true ).MinimizeButton( true ).PinButton( true ).Dock().Resizable().FloatingSize( wxDefaultSize ).DockFixed( false ).Floatable( false ) );
	
	m_workspace_panel = new wxPanel( m_splitter2, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer5;
	sbSizer5 = new wxStaticBoxSizer( new wxStaticBox( m_workspace_panel, wxID_ANY, wxT("Workspace") ), wxVERTICAL );
	
	m_book = new wxNotebook( m_workspace_panel, wxID_ANY, wxDefaultPosition, wxSize( 600,450 ), 0 );
	m_panel16 = new wxPanel( m_book, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	m_panel18 = new wxPanel( m_panel16, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer11;
	sbSizer11 = new wxStaticBoxSizer( new wxStaticBox( m_panel18, wxID_ANY, wxT("Actions") ), wxHORIZONTAL );
	
	m_btn_open = new wxButton( m_panel18, wxID_ANY, wxT("&Input Puzzle"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer11->Add( m_btn_open, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_button5 = new wxButton( m_panel18, wxID_ANY, wxT("Sol&ve"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer11->Add( m_button5, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_button6 = new wxButton( m_panel18, wxID_ANY, wxT("&Save"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer11->Add( m_button6, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	m_button4 = new wxButton( m_panel18, wxID_ANY, wxT("&Batch Mode"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer11->Add( m_button4, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	m_panel18->SetSizer( sbSizer11 );
	m_panel18->Layout();
	sbSizer11->Fit( m_panel18 );
	bSizer4->Add( m_panel18, 1, wxEXPAND | wxALL, 5 );
	
	m_panel19 = new wxPanel( m_panel16, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );
	
	m_panel21 = new wxPanel( m_panel19, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer9;
	sbSizer9 = new wxStaticBoxSizer( new wxStaticBox( m_panel21, wxID_ANY, wxT("Puzzle") ), wxVERTICAL );
	
	m_puzzle_grid = new wxGrid( m_panel21, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	m_puzzle_grid->CreateGrid( 9, 9 );
	m_puzzle_grid->EnableEditing( false );
	m_puzzle_grid->EnableGridLines( true );
	m_puzzle_grid->EnableDragGridSize( false );
	m_puzzle_grid->SetMargins( 1, 1 );
	
	// Columns
	m_puzzle_grid->SetColSize( 0, 26 );
	m_puzzle_grid->SetColSize( 1, 26 );
	m_puzzle_grid->SetColSize( 2, 26 );
	m_puzzle_grid->SetColSize( 3, 26 );
	m_puzzle_grid->SetColSize( 4, 26 );
	m_puzzle_grid->SetColSize( 5, 26 );
	m_puzzle_grid->SetColSize( 6, 26 );
	m_puzzle_grid->SetColSize( 7, 26 );
	m_puzzle_grid->SetColSize( 8, 26 );
	m_puzzle_grid->EnableDragColMove( false );
	m_puzzle_grid->EnableDragColSize( true );
	m_puzzle_grid->SetColLabelSize( 26 );
	m_puzzle_grid->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_puzzle_grid->SetRowSize( 0, 26 );
	m_puzzle_grid->SetRowSize( 1, 26 );
	m_puzzle_grid->SetRowSize( 2, 26 );
	m_puzzle_grid->SetRowSize( 3, 26 );
	m_puzzle_grid->SetRowSize( 4, 26 );
	m_puzzle_grid->SetRowSize( 5, 26 );
	m_puzzle_grid->SetRowSize( 6, 26 );
	m_puzzle_grid->SetRowSize( 7, 26 );
	m_puzzle_grid->SetRowSize( 8, 26 );
	m_puzzle_grid->EnableDragRowSize( true );
	m_puzzle_grid->SetRowLabelSize( 26 );
	m_puzzle_grid->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_puzzle_grid->SetDefaultCellFont( wxFont( 10, 70, 90, 90, false, wxEmptyString ) );
	m_puzzle_grid->SetDefaultCellAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	sbSizer9->Add( m_puzzle_grid, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	m_panel21->SetSizer( sbSizer9 );
	m_panel21->Layout();
	sbSizer9->Fit( m_panel21 );
	bSizer3->Add( m_panel21, 1, wxEXPAND | wxALL, 5 );
	
	m_panel22 = new wxPanel( m_panel19, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer10;
	sbSizer10 = new wxStaticBoxSizer( new wxStaticBox( m_panel22, wxID_ANY, wxT("Solution") ), wxVERTICAL );
	
	m_solution_grid = new wxGrid( m_panel22, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	m_solution_grid->CreateGrid( 9, 9 );
	m_solution_grid->EnableEditing( false );
	m_solution_grid->EnableGridLines( true );
	m_solution_grid->EnableDragGridSize( false );
	m_solution_grid->SetMargins( 1, 1 );
	
	// Columns
	m_solution_grid->SetColSize( 0, 26 );
	m_solution_grid->SetColSize( 1, 26 );
	m_solution_grid->SetColSize( 2, 26 );
	m_solution_grid->SetColSize( 3, 26 );
	m_solution_grid->SetColSize( 4, 26 );
	m_solution_grid->SetColSize( 5, 26 );
	m_solution_grid->SetColSize( 6, 26 );
	m_solution_grid->SetColSize( 7, 26 );
	m_solution_grid->SetColSize( 8, 26 );
	m_solution_grid->EnableDragColMove( false );
	m_solution_grid->EnableDragColSize( true );
	m_solution_grid->SetColLabelSize( 26 );
	m_solution_grid->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_solution_grid->SetRowSize( 0, 26 );
	m_solution_grid->SetRowSize( 1, 26 );
	m_solution_grid->SetRowSize( 2, 26 );
	m_solution_grid->SetRowSize( 3, 26 );
	m_solution_grid->SetRowSize( 4, 26 );
	m_solution_grid->SetRowSize( 5, 26 );
	m_solution_grid->SetRowSize( 6, 26 );
	m_solution_grid->SetRowSize( 7, 26 );
	m_solution_grid->SetRowSize( 8, 26 );
	m_solution_grid->EnableDragRowSize( true );
	m_solution_grid->SetRowLabelSize( 26 );
	m_solution_grid->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_solution_grid->SetDefaultCellFont( wxFont( 10, 70, 90, 90, false, wxEmptyString ) );
	m_solution_grid->SetDefaultCellAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	sbSizer10->Add( m_solution_grid, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	m_panel22->SetSizer( sbSizer10 );
	m_panel22->Layout();
	sbSizer10->Fit( m_panel22 );
	bSizer3->Add( m_panel22, 1, wxEXPAND | wxALL, 5 );
	
	
	m_panel19->SetSizer( bSizer3 );
	m_panel19->Layout();
	bSizer3->Fit( m_panel19 );
	bSizer4->Add( m_panel19, 4, wxEXPAND | wxALL, 5 );
	
	
	m_panel16->SetSizer( bSizer4 );
	m_panel16->Layout();
	bSizer4->Fit( m_panel16 );
	m_book->AddPage( m_panel16, wxT("Solver"), true );
	m_panel17 = new wxPanel( m_book, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_book->AddPage( m_panel17, wxT("Generator"), false );
	
	sbSizer5->Add( m_book, 1, wxEXPAND | wxALL, 5 );
	
	
	m_workspace_panel->SetSizer( sbSizer5 );
	m_workspace_panel->Layout();
	sbSizer5->Fit( m_workspace_panel );
	m_panel11 = new wxPanel( m_splitter2, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer6;
	sbSizer6 = new wxStaticBoxSizer( new wxStaticBox( m_panel11, wxID_ANY, wxT("Log Message") ), wxVERTICAL );
	
	m_log_text = new wxTextCtrl( m_panel11, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY|wxTE_WORDWRAP );
	sbSizer6->Add( m_log_text, 1, wxALL|wxEXPAND, 5 );
	
	
	m_panel11->SetSizer( sbSizer6 );
	m_panel11->Layout();
	sbSizer6->Fit( m_panel11 );
	m_splitter2->SplitHorizontally( m_workspace_panel, m_panel11, 500 );
	
	m_mgr.Update();
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_SIZE, wxSizeEventHandler( ISudokuFrame::OnSize ) );
	m_btn_open->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ISudokuFrame::OnInputPuzzle ), NULL, this );
	m_button5->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ISudokuFrame::OnSolve ), NULL, this );
	m_button6->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ISudokuFrame::OnSaveSolution ), NULL, this );
	m_button4->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ISudokuFrame::OnBatchMode ), NULL, this );
}

ISudokuFrame::~ISudokuFrame()
{
	// Disconnect Events
	this->Disconnect( wxEVT_SIZE, wxSizeEventHandler( ISudokuFrame::OnSize ) );
	m_btn_open->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ISudokuFrame::OnInputPuzzle ), NULL, this );
	m_button5->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ISudokuFrame::OnSolve ), NULL, this );
	m_button6->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ISudokuFrame::OnSaveSolution ), NULL, this );
	m_button4->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ISudokuFrame::OnBatchMode ), NULL, this );
	
	m_mgr.UnInit();
	
}

IBatchProgressFrame::IBatchProgressFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, wxT("This is a batch mode."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	bSizer3->Add( m_staticText4, 1, wxALL, 5 );
	
	wxStaticBoxSizer* sbSizer6;
	sbSizer6 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Step 1: Choose Input puzzles") ), wxHORIZONTAL );
	
	m_puzzle_file_textctrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 260,-1 ), 0 );
	sbSizer6->Add( m_puzzle_file_textctrl, 0, wxALL, 5 );
	
	m_button5 = new wxButton( this, wxID_ANY, wxT("Choose ..."), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer6->Add( m_button5, 0, wxALL, 5 );
	
	
	bSizer3->Add( sbSizer6, 2, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer61;
	sbSizer61 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Step 2: Choose Output solution file") ), wxHORIZONTAL );
	
	m_solution_file_textctrl = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 260,-1 ), 0 );
	sbSizer61->Add( m_solution_file_textctrl, 0, wxALL, 5 );
	
	m_button51 = new wxButton( this, wxID_ANY, wxT("Choose ..."), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer61->Add( m_button51, 0, wxALL, 5 );
	
	
	bSizer3->Add( sbSizer61, 2, wxEXPAND, 5 );
	
	wxStaticBoxSizer* sbSizer11;
	sbSizer11 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, wxT("Step 3: Let's Start!") ), wxVERTICAL );
	
	wxString m_solver_radioChoices[] = { wxT("Balanced Solver"), wxT("BruteForce Solver") };
	int m_solver_radioNChoices = sizeof( m_solver_radioChoices ) / sizeof( wxString );
	m_solver_radio = new wxRadioBox( this, wxID_ANY, wxT("Solver Selection"), wxDefaultPosition, wxDefaultSize, m_solver_radioNChoices, m_solver_radioChoices, 2, wxRA_SPECIFY_COLS );
	m_solver_radio->SetSelection( 0 );
	sbSizer11->Add( m_solver_radio, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );
	
	m_gauge = new wxGauge( this, wxID_ANY, 100, wxDefaultPosition, wxSize( 260,-1 ), wxGA_HORIZONTAL|wxGA_SMOOTH );
	m_gauge->SetValue( 0 ); 
	bSizer5->Add( m_gauge, 0, wxALIGN_CENTER|wxALL, 5 );
	
	m_button10 = new wxButton( this, wxID_ANY, wxT("Start"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_button10, 0, wxALL, 5 );
	
	
	sbSizer11->Add( bSizer5, 1, wxEXPAND, 5 );
	
	m_progress_text = new wxStaticText( this, wxID_ANY, wxT("Progress ..."), wxDefaultPosition, wxDefaultSize, 0 );
	m_progress_text->Wrap( -1 );
	sbSizer11->Add( m_progress_text, 0, wxALL, 5 );
	
	
	bSizer3->Add( sbSizer11, 4, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer3 );
	this->Layout();
	bSizer3->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_puzzle_file_textctrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( IBatchProgressFrame::OnUpdatePuzzleFile ), NULL, this );
	m_button5->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IBatchProgressFrame::ChoosePuzzle ), NULL, this );
	m_solution_file_textctrl->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( IBatchProgressFrame::OnUpdateSolutionFile ), NULL, this );
	m_button51->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IBatchProgressFrame::ChooseSolution ), NULL, this );
	m_solver_radio->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( IBatchProgressFrame::OnUpdateSolver ), NULL, this );
	m_button10->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IBatchProgressFrame::BatchStart ), NULL, this );
}

IBatchProgressFrame::~IBatchProgressFrame()
{
	// Disconnect Events
	m_puzzle_file_textctrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( IBatchProgressFrame::OnUpdatePuzzleFile ), NULL, this );
	m_button5->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IBatchProgressFrame::ChoosePuzzle ), NULL, this );
	m_solution_file_textctrl->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( IBatchProgressFrame::OnUpdateSolutionFile ), NULL, this );
	m_button51->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IBatchProgressFrame::ChooseSolution ), NULL, this );
	m_solver_radio->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( IBatchProgressFrame::OnUpdateSolver ), NULL, this );
	m_button10->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( IBatchProgressFrame::BatchStart ), NULL, this );
	
}
