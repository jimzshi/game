///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun  5 2014)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "IGuessFrame.h"

///////////////////////////////////////////////////////////////////////////
using namespace zks::game::guess;

IGuessFrame::IGuessFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	m_splitter = new wxSplitterWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D );
	m_splitter->SetSashGravity( 0 );
	m_splitter->Connect( wxEVT_IDLE, wxIdleEventHandler( IGuessFrame::m_splitterOnIdle ), NULL, this );
	
	m_panel2 = new wxPanel( m_splitter, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( m_panel2, wxID_ANY, wxT("Guess Area") ), wxVERTICAL );
	
	m_guess_book = new wxNotebook( m_panel2, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	m_guss_name_page = new wxPanel( m_guess_book, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* guess_name_sizer;
	guess_name_sizer = new wxBoxSizer( wxVERTICAL );
	
	m_gn_btn_panel = new wxPanel( m_guss_name_page, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* gn_btn_sizer;
	gn_btn_sizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_button1 = new wxButton( m_gn_btn_panel, wxID_ANY, wxT("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	gn_btn_sizer->Add( m_button1, 0, wxALL, 5 );
	
	m_button2 = new wxButton( m_gn_btn_panel, wxID_ANY, wxT("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	gn_btn_sizer->Add( m_button2, 0, wxALL, 5 );
	
	m_button3 = new wxButton( m_gn_btn_panel, wxID_ANY, wxT("MyButton"), wxDefaultPosition, wxDefaultSize, 0 );
	gn_btn_sizer->Add( m_button3, 0, wxALL, 5 );
	
	
	m_gn_btn_panel->SetSizer( gn_btn_sizer );
	m_gn_btn_panel->Layout();
	gn_btn_sizer->Fit( m_gn_btn_panel );
	guess_name_sizer->Add( m_gn_btn_panel, 0, wxEXPAND | wxALL, 5 );
	
	m_gn_bmp_panel = new wxScrolledWindow( m_guss_name_page, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_gn_bmp_panel->SetScrollRate( 5, 5 );
	wxBoxSizer* gn_bmp_sizer;
	gn_bmp_sizer = new wxBoxSizer( wxVERTICAL );
	
	m_statbmp = new wxStaticBitmap( m_gn_bmp_panel, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, 0 );
	gn_bmp_sizer->Add( m_statbmp, 1, wxALL|wxEXPAND, 5 );
	
	
	m_gn_bmp_panel->SetSizer( gn_bmp_sizer );
	m_gn_bmp_panel->Layout();
	gn_bmp_sizer->Fit( m_gn_bmp_panel );
	guess_name_sizer->Add( m_gn_bmp_panel, 1, wxEXPAND | wxALL, 5 );
	
	m_gn_input_panel = new wxPanel( m_guss_name_page, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( m_gn_input_panel, wxID_ANY, wxT("label") ), wxHORIZONTAL );
	
	m_gn_input_text = new wxTextCtrl( m_gn_input_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer3->Add( m_gn_input_text, 0, wxALL, 5 );
	
	
	m_gn_input_panel->SetSizer( sbSizer3 );
	m_gn_input_panel->Layout();
	sbSizer3->Fit( m_gn_input_panel );
	guess_name_sizer->Add( m_gn_input_panel, 0, wxEXPAND | wxALL, 5 );
	
	
	m_guss_name_page->SetSizer( guess_name_sizer );
	m_guss_name_page->Layout();
	guess_name_sizer->Fit( m_guss_name_page );
	m_guess_book->AddPage( m_guss_name_page, wxT("Guess Name"), true );
	m_guess_pic_page = new wxPanel( m_guess_book, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	m_textCtrl3 = new wxTextCtrl( m_guess_pic_page, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( m_textCtrl3, 0, wxALL, 5 );
	
	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 0, 2, 0, 0 );
	
	m_bpButton1 = new wxBitmapButton( m_guess_pic_page, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	gSizer1->Add( m_bpButton1, 0, wxEXPAND, 5 );
	
	m_bpButton2 = new wxBitmapButton( m_guess_pic_page, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	gSizer1->Add( m_bpButton2, 0, wxEXPAND, 5 );
	
	m_bpButton3 = new wxBitmapButton( m_guess_pic_page, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	gSizer1->Add( m_bpButton3, 0, wxEXPAND, 5 );
	
	m_bpButton4 = new wxBitmapButton( m_guess_pic_page, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	gSizer1->Add( m_bpButton4, 0, wxEXPAND, 5 );
	
	
	bSizer5->Add( gSizer1, 1, wxEXPAND, 5 );
	
	
	m_guess_pic_page->SetSizer( bSizer5 );
	m_guess_pic_page->Layout();
	bSizer5->Fit( m_guess_pic_page );
	m_guess_book->AddPage( m_guess_pic_page, wxT("Guess Pics"), false );
	
	sbSizer2->Add( m_guess_book, 1, wxEXPAND | wxALL, 5 );
	
	
	m_panel2->SetSizer( sbSizer2 );
	m_panel2->Layout();
	sbSizer2->Fit( m_panel2 );
	m_panel3 = new wxPanel( m_splitter, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), wxTAB_TRAVERSAL );
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( m_panel3, wxID_ANY, wxT("Log Window") ), wxVERTICAL );
	
	m_log_text = new wxTextCtrl( m_panel3, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY );
	sbSizer1->Add( m_log_text, 1, wxALL|wxEXPAND, 5 );
	
	
	m_panel3->SetSizer( sbSizer1 );
	m_panel3->Layout();
	sbSizer1->Fit( m_panel3 );
	m_splitter->SplitHorizontally( m_panel2, m_panel3, 0 );
	bSizer4->Add( m_splitter, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer4 );
	this->Layout();
	m_statusBar1 = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	m_menubar1 = new wxMenuBar( 0 );
	m_menu1 = new wxMenu();
	m_menubar1->Append( m_menu1, wxT("MyMenu") ); 
	
	m_menu2 = new wxMenu();
	m_menubar1->Append( m_menu2, wxT("MyMenu") ); 
	
	this->SetMenuBar( m_menubar1 );
	
	
	this->Centre( wxBOTH );
}

IGuessFrame::~IGuessFrame()
{
}
