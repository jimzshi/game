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
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( m_panel4, wxID_ANY, _("Input") ), wxHORIZONTAL );
	
	m_panel9 = new wxPanel( sbSizer1->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer4;
	sbSizer4 = new wxStaticBoxSizer( new wxStaticBox( m_panel9, wxID_ANY, _("Format") ), wxVERTICAL );
	
	wxString input_delimiter0Choices[] = { _("comma (,)"), _("tab (\\t)"), _("semi-column (;)") };
	int input_delimiter0NChoices = sizeof( input_delimiter0Choices ) / sizeof( wxString );
	input_delimiter0 = new wxRadioBox( sbSizer4->GetStaticBox(), wxID_ANY, _("Input Delimiter"), wxDefaultPosition, wxDefaultSize, input_delimiter0NChoices, input_delimiter0Choices, 2, wxRA_SPECIFY_COLS );
	input_delimiter0->SetSelection( 0 );
	sbSizer4->Add( input_delimiter0, 0, wxALL, 0 );
	
	wxString input_quote0Choices[] = { _("Single Quote (')"), _("Double Quote(\")"), _("None") };
	int input_quote0NChoices = sizeof( input_quote0Choices ) / sizeof( wxString );
	input_quote0 = new wxRadioBox( sbSizer4->GetStaticBox(), wxID_ANY, _("Input Field Quote"), wxDefaultPosition, wxDefaultSize, input_quote0NChoices, input_quote0Choices, 2, wxRA_SPECIFY_COLS );
	input_quote0->SetSelection( 1 );
	sbSizer4->Add( input_quote0, 0, wxALL, 0 );
	
	
	m_panel9->SetSizer( sbSizer4 );
	m_panel9->Layout();
	sbSizer4->Fit( m_panel9 );
	sbSizer1->Add( m_panel9, 0, wxEXPAND | wxALL, 0 );
	
	m_panel15 = new wxPanel( sbSizer1->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );
	
	input_filepicker0 = new wxFilePickerCtrl( m_panel15, wxID_ANY, wxEmptyString, _("Select a file"), wxT("*.*"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE );
	bSizer8->Add( input_filepicker0, 2, wxALIGN_CENTER|wxALL|wxEXPAND, 0 );
	
	input_has_header0 = new wxCheckBox( m_panel15, wxID_ANY, _("Include Header"), wxDefaultPosition, wxDefaultSize, 0 );
	input_has_header0->SetValue(true); 
	bSizer8->Add( input_has_header0, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	bSizer7->Add( bSizer8, 0, wxEXPAND, 5 );
	
	m_panel11 = new wxPanel( m_panel15, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer6;
	sbSizer6 = new wxStaticBoxSizer( new wxStaticBox( m_panel11, wxID_ANY, _("Preview") ), wxVERTICAL );
	
	input_preview0 = new wxGrid( sbSizer6->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	input_preview0->CreateGrid( 5, 5 );
	input_preview0->EnableEditing( false );
	input_preview0->EnableGridLines( true );
	input_preview0->EnableDragGridSize( false );
	input_preview0->SetMargins( 0, 0 );
	
	// Columns
	input_preview0->EnableDragColMove( false );
	input_preview0->EnableDragColSize( true );
	input_preview0->SetColLabelSize( 30 );
	input_preview0->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	input_preview0->EnableDragRowSize( true );
	input_preview0->SetRowLabelSize( 80 );
	input_preview0->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	input_preview0->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	sbSizer6->Add( input_preview0, 1, wxALL, 0 );
	
	
	m_panel11->SetSizer( sbSizer6 );
	m_panel11->Layout();
	sbSizer6->Fit( m_panel11 );
	bSizer7->Add( m_panel11, 1, wxEXPAND | wxALL, 5 );
	
	
	m_panel15->SetSizer( bSizer7 );
	m_panel15->Layout();
	bSizer7->Fit( m_panel15 );
	sbSizer1->Add( m_panel15, 1, wxEXPAND | wxALL, 0 );
	
	
	m_panel4->SetSizer( sbSizer1 );
	m_panel4->Layout();
	sbSizer1->Fit( m_panel4 );
	bSizer2->Add( m_panel4, 0, wxEXPAND | wxALL, 5 );
	
	m_panel5 = new wxPanel( single_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( m_panel5, wxID_ANY, _("Output") ), wxHORIZONTAL );
	
	m_panel91 = new wxPanel( sbSizer2->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer41;
	sbSizer41 = new wxStaticBoxSizer( new wxStaticBox( m_panel91, wxID_ANY, _("Format") ), wxVERTICAL );
	
	wxString output_delimiter0Choices[] = { _("comma (,)"), _("tab (\\t)"), _("semi-column (;)") };
	int output_delimiter0NChoices = sizeof( output_delimiter0Choices ) / sizeof( wxString );
	output_delimiter0 = new wxRadioBox( sbSizer41->GetStaticBox(), wxID_ANY, _("Output Delimiter"), wxDefaultPosition, wxDefaultSize, output_delimiter0NChoices, output_delimiter0Choices, 2, wxRA_SPECIFY_COLS );
	output_delimiter0->SetSelection( 0 );
	sbSizer41->Add( output_delimiter0, 0, wxALL, 1 );
	
	wxString output_quote0Choices[] = { _("Single Quote (')"), _("Double Quote(\")"), _("None") };
	int output_quote0NChoices = sizeof( output_quote0Choices ) / sizeof( wxString );
	output_quote0 = new wxRadioBox( sbSizer41->GetStaticBox(), wxID_ANY, _("Output Field Quote"), wxDefaultPosition, wxDefaultSize, output_quote0NChoices, output_quote0Choices, 2, wxRA_SPECIFY_COLS );
	output_quote0->SetSelection( 1 );
	sbSizer41->Add( output_quote0, 0, wxALL, 1 );
	
	
	m_panel91->SetSizer( sbSizer41 );
	m_panel91->Layout();
	sbSizer41->Fit( m_panel91 );
	sbSizer2->Add( m_panel91, 0, wxEXPAND | wxALL, 0 );
	
	m_panel16 = new wxPanel( sbSizer2->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );
	
	output_filepicker = new wxFilePickerCtrl( m_panel16, wxID_ANY, wxEmptyString, _("Select a file"), wxT("*.*"), wxDefaultPosition, wxSize( -1,-1 ), wxFLP_OVERWRITE_PROMPT|wxFLP_SAVE|wxFLP_USE_TEXTCTRL );
	bSizer10->Add( output_filepicker, 2, wxALIGN_CENTER|wxALL|wxEXPAND, 1 );
	
	output_has_header0 = new wxCheckBox( m_panel16, wxID_ANY, _("Include Header"), wxDefaultPosition, wxDefaultSize, 0 );
	output_has_header0->SetValue(true); 
	bSizer10->Add( output_has_header0, 0, wxALL, 5 );
	
	
	bSizer9->Add( bSizer10, 0, wxEXPAND, 5 );
	
	m_panel111 = new wxPanel( m_panel16, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer61;
	sbSizer61 = new wxStaticBoxSizer( new wxStaticBox( m_panel111, wxID_ANY, _("Change Column Order") ), wxVERTICAL );
	
	m_panel13 = new wxPanel( sbSizer61->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );
	
	col_order_list0 = new wxListBox( m_panel13, wxID_ANY, wxDefaultPosition, wxSize( 200,-1 ), 0, NULL, wxLB_NEEDED_SB|wxLB_SINGLE ); 
	bSizer4->Add( col_order_list0, 0, wxALL|wxEXPAND, 1 );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	btn_mv_up = new wxButton( m_panel13, wxID_ANY, _("Move Up"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( btn_mv_up, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	btn_mv_down = new wxButton( m_panel13, wxID_ANY, _("Move Down"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( btn_mv_down, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	bSizer4->Add( bSizer5, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	m_panel13->SetSizer( bSizer4 );
	m_panel13->Layout();
	bSizer4->Fit( m_panel13 );
	sbSizer61->Add( m_panel13, 1, wxALIGN_CENTER_HORIZONTAL|wxALL, 0 );
	
	
	m_panel111->SetSizer( sbSizer61 );
	m_panel111->Layout();
	sbSizer61->Fit( m_panel111 );
	bSizer9->Add( m_panel111, 1, wxEXPAND | wxALL, 5 );
	
	
	m_panel16->SetSizer( bSizer9 );
	m_panel16->Layout();
	bSizer9->Fit( m_panel16 );
	sbSizer2->Add( m_panel16, 1, wxEXPAND | wxALL, 0 );
	
	
	m_panel5->SetSizer( sbSizer2 );
	m_panel5->Layout();
	sbSizer2->Fit( m_panel5 );
	bSizer2->Add( m_panel5, 0, wxEXPAND | wxALL, 5 );
	
	m_panel141 = new wxPanel( single_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer8;
	sbSizer8 = new wxStaticBoxSizer( new wxStaticBox( m_panel141, wxID_ANY, _("Output Preview") ), wxVERTICAL );
	
	output_preview0 = new wxTextCtrl( sbSizer8->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxTE_MULTILINE|wxTE_READONLY );
	sbSizer8->Add( output_preview0, 1, wxALL|wxEXPAND, 5 );
	
	
	m_panel141->SetSizer( sbSizer8 );
	m_panel141->Layout();
	sbSizer8->Fit( m_panel141 );
	bSizer2->Add( m_panel141, 1, wxEXPAND | wxALL, 5 );
	
	m_panel6 = new wxPanel( single_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( m_panel6, wxID_ANY, _("Control Area") ), wxVERTICAL );
	
	m_panel12 = new wxPanel( sbSizer3->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxHORIZONTAL );
	
	btn_run = new wxButton( m_panel12, wxID_ANY, _("Run"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( btn_run, 0, wxALL, 5 );
	
	btn_close = new wxButton( m_panel12, wxID_ANY, _("Close"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( btn_close, 0, wxALL, 5 );
	
	btn_clear = new wxButton( m_panel12, wxID_ANY, _("Clear Log"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( btn_clear, 0, wxALL, 5 );
	
	
	m_panel12->SetSizer( bSizer3 );
	m_panel12->Layout();
	bSizer3->Fit( m_panel12 );
	sbSizer3->Add( m_panel12, 0, wxEXPAND | wxALL, 5 );
	
	m_log_text0 = new wxTextCtrl( sbSizer3->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY );
	sbSizer3->Add( m_log_text0, 1, wxALL|wxEXPAND, 5 );
	
	
	m_panel6->SetSizer( sbSizer3 );
	m_panel6->Layout();
	sbSizer3->Fit( m_panel6 );
	bSizer2->Add( m_panel6, 1, wxEXPAND | wxALL, 5 );
	
	
	single_panel->SetSizer( bSizer2 );
	single_panel->Layout();
	bSizer2->Fit( single_panel );
	m_notebook->AddPage( single_panel, _("Single File"), false );
	loop_panel = new wxPanel( m_notebook, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxVERTICAL );
	
	m_panel41 = new wxPanel( loop_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer11;
	sbSizer11 = new wxStaticBoxSizer( new wxStaticBox( m_panel41, wxID_ANY, _("Input") ), wxHORIZONTAL );
	
	m_panel92 = new wxPanel( sbSizer11->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer42;
	sbSizer42 = new wxStaticBoxSizer( new wxStaticBox( m_panel92, wxID_ANY, _("Format") ), wxVERTICAL );
	
	wxString input_delimiter1Choices[] = { _("comma (,)"), _("tab (\\t)"), _("semi-column (;)") };
	int input_delimiter1NChoices = sizeof( input_delimiter1Choices ) / sizeof( wxString );
	input_delimiter1 = new wxRadioBox( sbSizer42->GetStaticBox(), wxID_ANY, _("Input Delimiter"), wxDefaultPosition, wxDefaultSize, input_delimiter1NChoices, input_delimiter1Choices, 2, wxRA_SPECIFY_COLS );
	input_delimiter1->SetSelection( 0 );
	sbSizer42->Add( input_delimiter1, 0, wxALL, 0 );
	
	wxString input_quote1Choices[] = { _("Single Quote (')"), _("Double Quote(\")"), _("None") };
	int input_quote1NChoices = sizeof( input_quote1Choices ) / sizeof( wxString );
	input_quote1 = new wxRadioBox( sbSizer42->GetStaticBox(), wxID_ANY, _("Input Field Quote"), wxDefaultPosition, wxDefaultSize, input_quote1NChoices, input_quote1Choices, 2, wxRA_SPECIFY_COLS );
	input_quote1->SetSelection( 1 );
	sbSizer42->Add( input_quote1, 0, wxALL, 0 );
	
	
	m_panel92->SetSizer( sbSizer42 );
	m_panel92->Layout();
	sbSizer42->Fit( m_panel92 );
	sbSizer11->Add( m_panel92, 0, wxEXPAND | wxALL, 0 );
	
	m_panel151 = new wxPanel( sbSizer11->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer71;
	bSizer71 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer81;
	bSizer81 = new wxBoxSizer( wxHORIZONTAL );
	
	input_filepicker1 = new wxFilePickerCtrl( m_panel151, wxID_ANY, wxEmptyString, _("Select a file"), wxT("*.*"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE );
	bSizer81->Add( input_filepicker1, 2, wxALIGN_CENTER|wxALL|wxEXPAND, 0 );
	
	input_has_header1 = new wxCheckBox( m_panel151, wxID_ANY, _("Include Header"), wxDefaultPosition, wxDefaultSize, 0 );
	input_has_header1->SetValue(true); 
	bSizer81->Add( input_has_header1, 0, wxALIGN_CENTER|wxALL, 5 );
	
	
	bSizer71->Add( bSizer81, 0, wxEXPAND, 5 );
	
	m_panel112 = new wxPanel( m_panel151, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer62;
	sbSizer62 = new wxStaticBoxSizer( new wxStaticBox( m_panel112, wxID_ANY, _("Preview") ), wxVERTICAL );
	
	input_preview1 = new wxGrid( sbSizer62->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	input_preview1->CreateGrid( 5, 5 );
	input_preview1->EnableEditing( false );
	input_preview1->EnableGridLines( true );
	input_preview1->EnableDragGridSize( false );
	input_preview1->SetMargins( 0, 0 );
	
	// Columns
	input_preview1->EnableDragColMove( false );
	input_preview1->EnableDragColSize( true );
	input_preview1->SetColLabelSize( 30 );
	input_preview1->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	input_preview1->EnableDragRowSize( true );
	input_preview1->SetRowLabelSize( 80 );
	input_preview1->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	input_preview1->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	sbSizer62->Add( input_preview1, 1, wxALL, 0 );
	
	
	m_panel112->SetSizer( sbSizer62 );
	m_panel112->Layout();
	sbSizer62->Fit( m_panel112 );
	bSizer71->Add( m_panel112, 1, wxEXPAND | wxALL, 5 );
	
	
	m_panel151->SetSizer( bSizer71 );
	m_panel151->Layout();
	bSizer71->Fit( m_panel151 );
	sbSizer11->Add( m_panel151, 1, wxEXPAND | wxALL, 0 );
	
	
	m_panel41->SetSizer( sbSizer11 );
	m_panel41->Layout();
	sbSizer11->Fit( m_panel41 );
	bSizer21->Add( m_panel41, 0, wxEXPAND | wxALL, 5 );
	
	m_panel51 = new wxPanel( loop_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer21;
	sbSizer21 = new wxStaticBoxSizer( new wxStaticBox( m_panel51, wxID_ANY, _("Output") ), wxHORIZONTAL );
	
	m_panel911 = new wxPanel( sbSizer21->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer411;
	sbSizer411 = new wxStaticBoxSizer( new wxStaticBox( m_panel911, wxID_ANY, _("Format") ), wxVERTICAL );
	
	wxString output_delimiter1Choices[] = { _("comma (,)"), _("tab (\\t)"), _("semi-column (;)") };
	int output_delimiter1NChoices = sizeof( output_delimiter1Choices ) / sizeof( wxString );
	output_delimiter1 = new wxRadioBox( sbSizer411->GetStaticBox(), wxID_ANY, _("Output Delimiter"), wxDefaultPosition, wxDefaultSize, output_delimiter1NChoices, output_delimiter1Choices, 2, wxRA_SPECIFY_COLS );
	output_delimiter1->SetSelection( 0 );
	sbSizer411->Add( output_delimiter1, 0, wxALL, 1 );
	
	wxString output_quote1Choices[] = { _("Single Quote (')"), _("Double Quote(\")"), _("None") };
	int output_quote1NChoices = sizeof( output_quote1Choices ) / sizeof( wxString );
	output_quote1 = new wxRadioBox( sbSizer411->GetStaticBox(), wxID_ANY, _("Output Field Quote"), wxDefaultPosition, wxDefaultSize, output_quote1NChoices, output_quote1Choices, 2, wxRA_SPECIFY_COLS );
	output_quote1->SetSelection( 1 );
	sbSizer411->Add( output_quote1, 0, wxALL, 1 );
	
	
	m_panel911->SetSizer( sbSizer411 );
	m_panel911->Layout();
	sbSizer411->Fit( m_panel911 );
	sbSizer21->Add( m_panel911, 0, wxEXPAND | wxALL, 0 );
	
	m_panel161 = new wxPanel( sbSizer21->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer91;
	bSizer91 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer101;
	bSizer101 = new wxBoxSizer( wxHORIZONTAL );
	
	output_filepicker1 = new wxFilePickerCtrl( m_panel161, wxID_ANY, wxEmptyString, _("Select a file"), wxT("*.*"), wxDefaultPosition, wxSize( -1,-1 ), wxFLP_OVERWRITE_PROMPT|wxFLP_SAVE|wxFLP_USE_TEXTCTRL );
	bSizer101->Add( output_filepicker1, 2, wxALIGN_CENTER|wxALL|wxEXPAND, 1 );
	
	output_has_header1 = new wxCheckBox( m_panel161, wxID_ANY, _("Include Header"), wxDefaultPosition, wxDefaultSize, 0 );
	output_has_header1->SetValue(true); 
	bSizer101->Add( output_has_header1, 0, wxALL, 5 );
	
	
	bSizer91->Add( bSizer101, 0, wxEXPAND, 5 );
	
	m_panel1111 = new wxPanel( m_panel161, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer611;
	sbSizer611 = new wxStaticBoxSizer( new wxStaticBox( m_panel1111, wxID_ANY, _("Choose Loop Column") ), wxVERTICAL );
	
	m_panel131 = new wxPanel( sbSizer611->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer41;
	bSizer41 = new wxBoxSizer( wxHORIZONTAL );
	
	col_order_list1 = new wxListBox( m_panel131, wxID_ANY, wxDefaultPosition, wxSize( 200,-1 ), 0, NULL, wxLB_NEEDED_SB|wxLB_SINGLE ); 
	bSizer41->Add( col_order_list1, 0, wxALL|wxEXPAND, 1 );
	
	wxBoxSizer* bSizer51;
	bSizer51 = new wxBoxSizer( wxVERTICAL );
	
	btn_mv_up1 = new wxButton( m_panel131, wxID_ANY, _("(Not Used)"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer51->Add( btn_mv_up1, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	btn_mv_down1 = new wxButton( m_panel131, wxID_ANY, _("(Not Used)"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer51->Add( btn_mv_down1, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	bSizer41->Add( bSizer51, 0, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	m_panel131->SetSizer( bSizer41 );
	m_panel131->Layout();
	bSizer41->Fit( m_panel131 );
	sbSizer611->Add( m_panel131, 1, wxALIGN_CENTER_HORIZONTAL|wxALL, 0 );
	
	
	m_panel1111->SetSizer( sbSizer611 );
	m_panel1111->Layout();
	sbSizer611->Fit( m_panel1111 );
	bSizer91->Add( m_panel1111, 1, wxEXPAND | wxALL, 5 );
	
	
	m_panel161->SetSizer( bSizer91 );
	m_panel161->Layout();
	bSizer91->Fit( m_panel161 );
	sbSizer21->Add( m_panel161, 1, wxEXPAND | wxALL, 0 );
	
	
	m_panel51->SetSizer( sbSizer21 );
	m_panel51->Layout();
	sbSizer21->Fit( m_panel51 );
	bSizer21->Add( m_panel51, 0, wxEXPAND | wxALL, 5 );
	
	m_panel1411 = new wxPanel( loop_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer81;
	sbSizer81 = new wxStaticBoxSizer( new wxStaticBox( m_panel1411, wxID_ANY, _("Output Preview") ), wxVERTICAL );
	
	output_preview1 = new wxTextCtrl( sbSizer81->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxTE_MULTILINE|wxTE_READONLY );
	sbSizer81->Add( output_preview1, 1, wxALL|wxEXPAND, 5 );
	
	
	m_panel1411->SetSizer( sbSizer81 );
	m_panel1411->Layout();
	sbSizer81->Fit( m_panel1411 );
	bSizer21->Add( m_panel1411, 1, wxEXPAND | wxALL, 5 );
	
	m_panel61 = new wxPanel( loop_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer31;
	sbSizer31 = new wxStaticBoxSizer( new wxStaticBox( m_panel61, wxID_ANY, _("Control Area") ), wxVERTICAL );
	
	m_panel121 = new wxPanel( sbSizer31->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxHORIZONTAL );
	
	btn_run1 = new wxButton( m_panel121, wxID_ANY, _("Run"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer31->Add( btn_run1, 0, wxALL, 5 );
	
	btn_close1 = new wxButton( m_panel121, wxID_ANY, _("Close"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer31->Add( btn_close1, 0, wxALL, 5 );
	
	btn_clear1 = new wxButton( m_panel121, wxID_ANY, _("Clear Log"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer31->Add( btn_clear1, 0, wxALL, 5 );
	
	
	m_panel121->SetSizer( bSizer31 );
	m_panel121->Layout();
	bSizer31->Fit( m_panel121 );
	sbSizer31->Add( m_panel121, 0, wxEXPAND | wxALL, 5 );
	
	m_log_text1 = new wxTextCtrl( sbSizer31->GetStaticBox(), wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY );
	sbSizer31->Add( m_log_text1, 1, wxALL|wxEXPAND, 5 );
	
	
	m_panel61->SetSizer( sbSizer31 );
	m_panel61->Layout();
	sbSizer31->Fit( m_panel61 );
	bSizer21->Add( m_panel61, 1, wxEXPAND | wxALL, 5 );
	
	
	loop_panel->SetSizer( bSizer21 );
	loop_panel->Layout();
	bSizer21->Fit( loop_panel );
	m_notebook->AddPage( loop_panel, _("Loop And Split"), true );
	
	bSizer1->Add( m_notebook, 1, wxEXPAND | wxALL, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	m_statusBar1 = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	m_menubar1 = new wxMenuBar( 0 );
	this->SetMenuBar( m_menubar1 );
	
	
	this->Centre( wxBOTH );
	
	// Connect Events
	input_delimiter0->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( ITCFrame::UpdateInputPreview ), NULL, this );
	input_quote0->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( ITCFrame::UpdateInputPreview ), NULL, this );
	input_filepicker0->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( ITCFrame::UpdateInputPreview ), NULL, this );
	input_has_header0->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ITCFrame::UpdateInputPreview ), NULL, this );
	output_delimiter0->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( ITCFrame::UpdateOutputPreview ), NULL, this );
	output_quote0->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( ITCFrame::UpdateOutputPreview ), NULL, this );
	output_filepicker->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( ITCFrame::UpdateOutputPreview ), NULL, this );
	output_has_header0->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ITCFrame::UpdateOutputPreview ), NULL, this );
	btn_mv_up->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ITCFrame::OnColMoveUp ), NULL, this );
	btn_mv_down->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ITCFrame::OnColMoveDown ), NULL, this );
	btn_run->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ITCFrame::OnRun ), NULL, this );
	btn_close->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ITCFrame::OnClose ), NULL, this );
	btn_clear->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ITCFrame::OnClearLog ), NULL, this );
	input_delimiter1->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( ITCFrame::UpdateInputPreview ), NULL, this );
	input_quote1->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( ITCFrame::UpdateInputPreview ), NULL, this );
	input_filepicker1->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( ITCFrame::UpdateInputPreview ), NULL, this );
	input_has_header1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ITCFrame::UpdateInputPreview ), NULL, this );
	output_delimiter1->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( ITCFrame::UpdateOutputPreview ), NULL, this );
	output_quote1->Connect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( ITCFrame::UpdateOutputPreview ), NULL, this );
	output_filepicker1->Connect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( ITCFrame::UpdateOutputPreview ), NULL, this );
	output_has_header1->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ITCFrame::UpdateOutputPreview ), NULL, this );
	btn_mv_up1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ITCFrame::OnColMoveUp1 ), NULL, this );
	btn_mv_down1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ITCFrame::OnColMoveDown1 ), NULL, this );
	btn_run1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ITCFrame::OnRun1 ), NULL, this );
	btn_close1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ITCFrame::OnClose ), NULL, this );
	btn_clear1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ITCFrame::OnClearLog ), NULL, this );
}

ITCFrame::~ITCFrame()
{
	// Disconnect Events
	input_delimiter0->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( ITCFrame::UpdateInputPreview ), NULL, this );
	input_quote0->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( ITCFrame::UpdateInputPreview ), NULL, this );
	input_filepicker0->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( ITCFrame::UpdateInputPreview ), NULL, this );
	input_has_header0->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ITCFrame::UpdateInputPreview ), NULL, this );
	output_delimiter0->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( ITCFrame::UpdateOutputPreview ), NULL, this );
	output_quote0->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( ITCFrame::UpdateOutputPreview ), NULL, this );
	output_filepicker->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( ITCFrame::UpdateOutputPreview ), NULL, this );
	output_has_header0->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ITCFrame::UpdateOutputPreview ), NULL, this );
	btn_mv_up->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ITCFrame::OnColMoveUp ), NULL, this );
	btn_mv_down->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ITCFrame::OnColMoveDown ), NULL, this );
	btn_run->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ITCFrame::OnRun ), NULL, this );
	btn_close->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ITCFrame::OnClose ), NULL, this );
	btn_clear->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ITCFrame::OnClearLog ), NULL, this );
	input_delimiter1->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( ITCFrame::UpdateInputPreview ), NULL, this );
	input_quote1->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( ITCFrame::UpdateInputPreview ), NULL, this );
	input_filepicker1->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( ITCFrame::UpdateInputPreview ), NULL, this );
	input_has_header1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ITCFrame::UpdateInputPreview ), NULL, this );
	output_delimiter1->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( ITCFrame::UpdateOutputPreview ), NULL, this );
	output_quote1->Disconnect( wxEVT_COMMAND_RADIOBOX_SELECTED, wxCommandEventHandler( ITCFrame::UpdateOutputPreview ), NULL, this );
	output_filepicker1->Disconnect( wxEVT_COMMAND_FILEPICKER_CHANGED, wxFileDirPickerEventHandler( ITCFrame::UpdateOutputPreview ), NULL, this );
	output_has_header1->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ITCFrame::UpdateOutputPreview ), NULL, this );
	btn_mv_up1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ITCFrame::OnColMoveUp1 ), NULL, this );
	btn_mv_down1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ITCFrame::OnColMoveDown1 ), NULL, this );
	btn_run1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ITCFrame::OnRun1 ), NULL, this );
	btn_close1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ITCFrame::OnClose ), NULL, this );
	btn_clear1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ITCFrame::OnClearLog ), NULL, this );
	
}
