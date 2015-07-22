///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "ITCFrame.h"

///////////////////////////////////////////////////////////////////////////

ITCFrame::ITCFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_notebook = new wxNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	single_panel = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );
	
	m_panel4 = new wxPanel( single_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( m_panel4, wxID_ANY, wxT("Input") ), wxVERTICAL );
	
	m_panel7 = new wxPanel( sbSizer1->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer1;
	fgSizer1 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer1->SetFlexibleDirection( wxBOTH );
	fgSizer1->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText1 = new wxStaticText( m_panel7, wxID_ANY, wxT("Input File Settings"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	fgSizer1->Add( m_staticText1, 0, wxALIGN_CENTER|wxALL, 5 );
	
	input_filepicker = new wxFilePickerCtrl( m_panel7, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*.*"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE|wxFLP_FILE_MUST_EXIST );
	fgSizer1->Add( input_filepicker, 0, wxALIGN_CENTER|wxALL|wxEXPAND, 5 );
	
	m_panel9 = new wxPanel( m_panel7, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( m_panel9, wxID_ANY, wxT("Format") ), wxVERTICAL );
	
	input_has_header = new wxCheckBox( sbSizer4->GetStaticBox(), wxID_ANY, wxT("Include Header"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer4->Add( input_has_header, 0, wxALL, 5 );
	
	wxString input_delimiterChoices[] = { wxT("comma (,)"), wxT("tab (\\t)"), wxT("semi-column (;)") };
	int input_delimiterNChoices = sizeof( input_delimiterChoices ) / sizeof( wxString );
	input_delimiter = new wxRadioBox( sbSizer4->GetStaticBox(), wxID_ANY, wxT("Input Delimiter"), wxDefaultPosition, wxDefaultSize, input_delimiterNChoices, input_delimiterChoices, 2, wxRA_SPECIFY_COLS );
	input_delimiter->SetSelection( 0 );
	sbSizer4->Add( input_delimiter, 0, wxALL, 5 );
	
	wxString input_escapeChoices[] = { wxT("Single Quote (')"), wxT("Double Quote(\")"), wxT("None") };
	int input_escapeNChoices = sizeof( input_escapeChoices ) / sizeof( wxString );
	input_escape = new wxRadioBox( sbSizer4->GetStaticBox(), wxID_ANY, wxT("Input Field Escape"), wxDefaultPosition, wxDefaultSize, input_escapeNChoices, input_escapeChoices, 2, wxRA_SPECIFY_COLS );
	input_escape->SetSelection( 2 );
	sbSizer4->Add( input_escape, 0, wxALL, 5 );
	
	
	m_panel9->SetSizer( sbSizer4 );
	m_panel9->Layout();
	sbSizer4->Fit( m_panel9 );
	fgSizer1->Add( m_panel9, 1, wxEXPAND | wxALL, 5 );
	
	m_panel11 = new wxPanel( m_panel7, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer6;
	sbSizer6 = new wxStaticBoxSizer( new wxStaticBox( m_panel11, wxID_ANY, wxT("Preview") ), wxVERTICAL );
	
	input_preview = new wxGrid( sbSizer6->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	input_preview->CreateGrid( 5, 5 );
	input_preview->EnableEditing( false );
	input_preview->EnableGridLines( true );
	input_preview->EnableDragGridSize( false );
	input_preview->SetMargins( 0, 0 );
	
	// Columns
	input_preview->EnableDragColMove( false );
	input_preview->EnableDragColSize( true );
	input_preview->SetColLabelSize( 30 );
	input_preview->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	input_preview->EnableDragRowSize( true );
	input_preview->SetRowLabelSize( 80 );
	input_preview->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	input_preview->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	sbSizer6->Add( input_preview, 1, wxALL, 5 );
	
	
	m_panel11->SetSizer( sbSizer6 );
	m_panel11->Layout();
	sbSizer6->Fit( m_panel11 );
	fgSizer1->Add( m_panel11, 1, wxEXPAND | wxALL, 5 );
	
	
	m_panel7->SetSizer( fgSizer1 );
	m_panel7->Layout();
	fgSizer1->Fit( m_panel7 );
	sbSizer1->Add( m_panel7, 1, wxEXPAND | wxALL, 5 );
	
	
	m_panel4->SetSizer( sbSizer1 );
	m_panel4->Layout();
	sbSizer1->Fit( m_panel4 );
	bSizer2->Add( m_panel4, 2, wxEXPAND | wxALL, 5 );
	
	m_panel5 = new wxPanel( single_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( m_panel5, wxID_ANY, wxT("Output") ), wxVERTICAL );
	
	m_panel14 = new wxPanel( sbSizer2->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxFlexGridSizer* fgSizer11;
	fgSizer11 = new wxFlexGridSizer( 0, 2, 0, 0 );
	fgSizer11->SetFlexibleDirection( wxBOTH );
	fgSizer11->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
	
	m_staticText11 = new wxStaticText( m_panel14, wxID_ANY, wxT("Output File Settings"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	fgSizer11->Add( m_staticText11, 0, wxALIGN_CENTER|wxALL, 5 );
	
	output_filepicker = new wxFilePickerCtrl( m_panel14, wxID_ANY, wxEmptyString, wxT("Select a file"), wxT("*.*"), wxDefaultPosition, wxSize( -1,-1 ), wxFLP_DEFAULT_STYLE|wxFLP_OVERWRITE_PROMPT|wxFLP_SAVE );
	fgSizer11->Add( output_filepicker, 1, wxALIGN_CENTER|wxALL|wxEXPAND, 5 );
	
	m_panel91 = new wxPanel( m_panel14, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer41;
	sbSizer41 = new wxStaticBoxSizer( new wxStaticBox( m_panel91, wxID_ANY, wxT("Format") ), wxVERTICAL );
	
	output_has_header = new wxCheckBox( sbSizer41->GetStaticBox(), wxID_ANY, wxT("Include Header"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer41->Add( output_has_header, 0, wxALL, 5 );
	
	wxString output_delimiterChoices[] = { wxT("comma (,)"), wxT("tab (\\t)"), wxT("semi-column (;)") };
	int output_delimiterNChoices = sizeof( output_delimiterChoices ) / sizeof( wxString );
	output_delimiter = new wxRadioBox( sbSizer41->GetStaticBox(), wxID_ANY, wxT("Output Delimiter"), wxDefaultPosition, wxDefaultSize, output_delimiterNChoices, output_delimiterChoices, 2, wxRA_SPECIFY_COLS );
	output_delimiter->SetSelection( 2 );
	sbSizer41->Add( output_delimiter, 0, wxALL, 5 );
	
	wxString output_escapeChoices[] = { wxT("Single Quote (')"), wxT("Double Quote(\")"), wxT("None") };
	int output_escapeNChoices = sizeof( output_escapeChoices ) / sizeof( wxString );
	output_escape = new wxRadioBox( sbSizer41->GetStaticBox(), wxID_ANY, wxT("Output Field Escape"), wxDefaultPosition, wxDefaultSize, output_escapeNChoices, output_escapeChoices, 2, wxRA_SPECIFY_COLS );
	output_escape->SetSelection( 2 );
	sbSizer41->Add( output_escape, 0, wxALL, 5 );
	
	
	m_panel91->SetSizer( sbSizer41 );
	m_panel91->Layout();
	sbSizer41->Fit( m_panel91 );
	fgSizer11->Add( m_panel91, 1, wxEXPAND | wxALL, 5 );
	
	m_panel111 = new wxPanel( m_panel14, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer61;
	sbSizer61 = new wxStaticBoxSizer( new wxStaticBox( m_panel111, wxID_ANY, wxT("Preview") ), wxVERTICAL );
	
	output_preview = new wxTextCtrl( sbSizer61->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 480,-1 ), wxHSCROLL|wxTE_MULTILINE|wxTE_READONLY );
	sbSizer61->Add( output_preview, 1, wxALL|wxEXPAND, 5 );
	
	
	m_panel111->SetSizer( sbSizer61 );
	m_panel111->Layout();
	sbSizer61->Fit( m_panel111 );
	fgSizer11->Add( m_panel111, 1, wxEXPAND | wxALL, 5 );
	
	
	m_panel14->SetSizer( fgSizer11 );
	m_panel14->Layout();
	fgSizer11->Fit( m_panel14 );
	sbSizer2->Add( m_panel14, 1, wxEXPAND | wxALL, 5 );
	
	
	m_panel5->SetSizer( sbSizer2 );
	m_panel5->Layout();
	sbSizer2->Fit( m_panel5 );
	bSizer2->Add( m_panel5, 2, wxEXPAND | wxALL, 5 );
	
	m_panel6 = new wxPanel( single_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( m_panel6, wxID_ANY, wxT("Control Area") ), wxVERTICAL );
	
	m_panel12 = new wxPanel( sbSizer3->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );
	
	btn_run = new wxButton( m_panel12, wxID_ANY, wxT("Run"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( btn_run, 0, wxALL, 5 );
	
	btn_close = new wxButton( m_panel12, wxID_ANY, wxT("Close"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( btn_close, 0, wxALL, 5 );
	
	btn_reset = new wxButton( m_panel12, wxID_ANY, wxT("Reset"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( btn_reset, 0, wxALL, 5 );
	
	btn_clear = new wxButton( m_panel12, wxID_ANY, wxT("Clear Log"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( btn_clear, 0, wxALL, 5 );
	
	
	m_panel12->SetSizer( bSizer3 );
	m_panel12->Layout();
	bSizer3->Fit( m_panel12 );
	sbSizer3->Add( m_panel12, 0, wxEXPAND | wxALL, 5 );
	
	m_log_text = new wxTextCtrl( sbSizer3->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY );
	sbSizer3->Add( m_log_text, 1, wxALL|wxEXPAND, 5 );
	
	
	m_panel6->SetSizer( sbSizer3 );
	m_panel6->Layout();
	sbSizer3->Fit( m_panel6 );
	bSizer2->Add( m_panel6, 1, wxEXPAND | wxALL, 5 );
	
	
	single_panel->SetSizer( bSizer2 );
	single_panel->Layout();
	bSizer2->Fit( single_panel );
	m_notebook->AddPage( single_panel, wxT("Single File"), false );
	batch_panel = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	m_notebook->AddPage( batch_panel, wxT("Batch Mode (TBC)"), false );
	
	bSizer1->Add( m_notebook, 1, wxEXPAND | wxALL, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	m_statusBar1 = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	m_menubar1 = new wxMenuBar( 0 );
	this->SetMenuBar( m_menubar1 );
	
	
	this->Centre( wxBOTH );
	
	// Connect Events
	input_filepicker->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( ITCFrame::UpdateInputPreview ), NULL, this );
	input_has_header->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ITCFrame::UpdateInputPreview ), NULL, this );
	input_delimiter->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( ITCFrame::UpdateInputPreview ), NULL, this );
	input_escape->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( ITCFrame::UpdateInputPreview ), NULL, this );
	output_filepicker->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( ITCFrame::UpdateOutputPreview ), NULL, this );
	output_has_header->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ITCFrame::UpdateOutputPreview ), NULL, this );
	output_delimiter->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( ITCFrame::UpdateOutputPreview ), NULL, this );
	output_escape->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( ITCFrame::UpdateOutputPreview ), NULL, this );
	btn_run->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ITCFrame::OnRun ), NULL, this );
	btn_close->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ITCFrame::OnClose ), NULL, this );
	btn_reset->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ITCFrame::OnReset ), NULL, this );
	btn_clear->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ITCFrame::OnClearLog ), NULL, this );
}

ITCFrame::~ITCFrame()
{
	// Disconnect Events
	input_filepicker->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( ITCFrame::UpdateInputPreview ), NULL, this );
	input_has_header->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ITCFrame::UpdateInputPreview ), NULL, this );
	input_delimiter->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( ITCFrame::UpdateInputPreview ), NULL, this );
	input_escape->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( ITCFrame::UpdateInputPreview ), NULL, this );
	output_filepicker->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( ITCFrame::UpdateOutputPreview ), NULL, this );
	output_has_header->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ITCFrame::UpdateOutputPreview ), NULL, this );
	output_delimiter->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( ITCFrame::UpdateOutputPreview ), NULL, this );
	output_escape->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( ITCFrame::UpdateOutputPreview ), NULL, this );
	btn_run->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ITCFrame::OnRun ), NULL, this );
	btn_close->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ITCFrame::OnClose ), NULL, this );
	btn_reset->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ITCFrame::OnReset ), NULL, this );
	btn_clear->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ITCFrame::OnClearLog ), NULL, this );
	
}
