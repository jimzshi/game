#include "Solver.h"
#include "Generator.h"
#include "worker.h"

#include "libzks/libzks.h"

#include <iostream>
#include <fstream>
#include <thread>
#include <future>
#include <memory>

using namespace std;

zks::simlog g_logger;

#ifndef USE_GUI
int main(int argc, char* argv[]) {
    if (argc < 4) {
        cerr << argv[0] << " [solve|generate|count] log.ini game-file" << endl;
        return 0;
    }
    g_logger.configure(argv[2]);
    g_logger.reset();

    zks::u8string cmd{argv[1]};
    cmd = cmd.tolower();
    ZKS_INFO(g_logger, "main", "read in command: %s %s %s %s", argv[0], argv[1], argv[2], argv[3]);
    int ret { -2 };
    if(cmd=="solve") {
        ret = zks::game::sudoku::solve(zks::game::sudoku::solver_thread, argv[3]);
    } else if(cmd == "generate") {
        ret = zks::game::sudoku::generate(zks::game::sudoku::generate_thread, 10);
    } else if(cmd == "count") {
        ret = zks::game::sudoku::solve(zks::game::sudoku::count_thread, argv[3]);
    } else {
        ZKS_ERROR(g_logger, "main", "can not interpret cmd:%s, (should be one of solve/generate/count).", cmd.c_str());
        ret = -3;
    }

    ZKS_INFO(g_logger, "main", "return value: %d", ret);

    return 0;
}
#else
//#include "wx/wxprec.h"
//#ifndef WX_PRECOMP    
//#include "wx/wx.h"
//#endif
//
//#if wxUSE_NOTEBOOK
//// dedicated to majority of desktops
//#include "wx/notebook.h"
//#define wxBookCtrl                             wxNotebook
//#define wxEVT_BOOKCTRL_PAGE_CHANGED            wxEVT_NOTEBOOK_PAGE_CHANGED
//#define wxEVT_BOOKCTRL_PAGE_CHANGING           wxEVT_NOTEBOOK_PAGE_CHANGING
//#define EVT_BOOKCTRL_PAGE_CHANGED(id, fn)      EVT_NOTEBOOK_PAGE_CHANGED(id, fn)
//#define EVT_BOOKCTRL_PAGE_CHANGING(id, fn)     EVT_NOTEBOOK_PAGE_CHANGING(id, fn)
//#else
//// dedicated to Smartphones
//#include "wx/choicebk.h"
//#define wxBookCtrl                             wxChoicebook
//#define wxEVT_BOOKCTRL_PAGE_CHANGED            wxEVT_CHOICEBOOK_PAGE_CHANGED
//#define wxEVT_BOOKCTRL_PAGE_CHANGING           wxEVT_CHOICEBOOK_PAGE_CHANGING
//#define EVT_BOOKCTRL_PAGE_CHANGED(id, fn)      EVT_CHOICEBOOK_PAGE_CHANGED(id, fn)
//#define EVT_BOOKCTRL_PAGE_CHANGING(id, fn)     EVT_CHOICEBOOK_PAGE_CHANGING(id, fn)
//#endif
//
//class MyApp : public wxApp
//{
//public:
//    virtual bool OnInit();
//};
//
//
//class MyFrame : public wxFrame
//{
//    wxTextCtrl      *m_text;
//    wxLog           *m_log;
//    wxBookCtrl      *m_book;
//    wxTextCtrl      *txt_puzzle;
//    wxTextCtrl      *txt_solution;
//
//    std::unique_ptr<zks::game::sudoku::BalanceSolver> pSolver;
//
//public:
//    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
//private:
//    void OnHello(wxCommandEvent& event);
//    void OnExit(wxCommandEvent& event);
//    void OnAbout(wxCommandEvent& event);
//    void OnOpenPuzzle(wxCommandEvent& event);
//    void OnSolvePuzzle(wxCommandEvent& event);
//    void OnMove(wxMoveEvent& event)
//    {
//        UpdateStatusBar(event.GetPosition(), GetSize());
//        event.Skip();
//    }
//    void OnSize(wxSizeEvent& event)
//    {
//        UpdateStatusBar(GetPosition(), event.GetSize());
//        event.Skip();
//    }
//    void UpdateStatusBar(const wxPoint& pos, const wxSize& size)
//    {
//        if (m_frameStatusBar)
//        {
//            wxString msg;
//            wxSize sizeAll = GetSize(), sizeCl = GetClientSize();
//            msg.Printf(_("pos=(%d, %d), size=%dx%d or %dx%d (client=%dx%d)"),
//                pos.x, pos.y, size.x, size.y, sizeAll.x, sizeAll.y, sizeCl.x, sizeCl.y);
//            SetStatusText(msg, 1);
//        }
//    }
//    wxDECLARE_EVENT_TABLE();
//};
//
//enum {
//    ID_Hello = 1,
//    ID_BOOK,
//    ID_BOOK_SOLVER,
//    ID_BOOK_GENERATOR,
//    ID_BOOK_SOLVER_OPEN,
//    ID_BOOK_SOLVER_SOLVE,
//    ID_BOOK_SOLVER_PUZZLE,
//    ID_BOOK_SOLVER_SOLUTION
//};
//
//wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
//EVT_MENU(ID_Hello, MyFrame::OnHello)
//EVT_MENU(wxID_EXIT, MyFrame::OnExit)
//EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
//EVT_BUTTON(ID_BOOK_SOLVER_OPEN, MyFrame::OnOpenPuzzle)
//EVT_BUTTON(ID_BOOK_SOLVER_SOLVE, MyFrame::OnSolvePuzzle)
//EVT_SIZE(MyFrame::OnSize)
//EVT_MOVE(MyFrame::OnMove)
//wxEND_EVENT_TABLE()
//
//wxIMPLEMENT_APP(MyApp);
//
//bool MyApp::OnInit()
//{
//    MyFrame *frame = new MyFrame(wxT("Hello World"), wxPoint(200, 200), wxSize(650, 500));
//    frame->Show(true);
//    return true;
//}
//
//MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
//: wxFrame(NULL, wxID_ANY, title, pos, size, wxDEFAULT_FRAME_STYLE, title)
//{
//    pSolver.reset(new zks::game::sudoku::BalanceSolver("200000060000075030048090100000300000300010009000008000001020570080730000090000004"));
//
//    wxMenu *menuFile = new wxMenu;
//    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H", "Help string shown in status bar for this menu item");
//    menuFile->AppendSeparator();
//    menuFile->Append(wxID_EXIT);
//    wxMenu *menuHelp = new wxMenu;
//    menuHelp->Append(wxID_ABOUT);
//    wxMenuBar *menuBar = new wxMenuBar;
//    menuBar->Append(menuFile, "&File");
//    menuBar->Append(menuHelp, "&Help");
//    SetMenuBar(menuBar);
//    //CreateStatusBar();    
//    //SetStatusText("Welcome to wxWidgets!");
//
//    m_text = new wxTextCtrl(this, wxID_ANY, wxT("======= Log Message ======= \n"),
//        wxPoint(0, 250), wxSize(100, 50), wxTE_MULTILINE | wxTE_READONLY);
//    m_log = wxLog::SetActiveTarget(new wxLogTextCtrl(m_text));
//
//    m_book = new wxBookCtrl(this, ID_BOOK);
//    wxPanel *panel = new wxPanel(m_book);
//
//    wxStaticBoxSizer *cvsizer = new wxStaticBoxSizer(new wxStaticBox(panel, wxID_ANY, wxT("Start Here")), wxVERTICAL);
//    wxButton *btn_open_puzzle = new wxButton(panel, ID_BOOK_SOLVER_OPEN, wxT("Open Puzzle"));
//    cvsizer->Add(btn_open_puzzle, 0, wxALL, 10);
//    wxButton *btn_solve_puzzle = new wxButton(panel, ID_BOOK_SOLVER_SOLVE, wxT("Solve it"));
//    cvsizer->Add(btn_solve_puzzle, 0, wxALL, 10);
//
//    wxBoxSizer *hsizer = new wxBoxSizer(wxHORIZONTAL);
//    hsizer->Add(cvsizer, 0, wxALL, 10);
//    hsizer->AddSpacer(5);
//    txt_puzzle = new wxTextCtrl(panel, ID_BOOK_SOLVER_PUZZLE, wxEmptyString,
//        wxPoint(20, 20), wxSize(240, 300), wxTE_MULTILINE | wxTE_READONLY | wxTE_NO_VSCROLL);
//    txt_solution = new wxTextCtrl(panel, ID_BOOK_SOLVER_SOLUTION, wxEmptyString,
//        wxPoint(20, 20), wxSize(240, 300), wxTE_MULTILINE | wxTE_READONLY | wxTE_NO_VSCROLL);
//    wxFont board_font{ wxFontInfo(10).FaceName("Consolas") };
//    txt_puzzle->SetFont(board_font);
//    txt_solution->SetFont(board_font);
//    hsizer->Add(txt_puzzle, 0, wxALL, 10);
//    hsizer->Add(txt_solution, 0, wxALL, 10);
//    panel->SetSizer(hsizer);
//    m_book->AddPage(panel, wxT("Solver"));
//
//    wxBoxSizer *vsizer = new wxBoxSizer(wxVERTICAL);
//    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
//    sizer->Add(m_book, wxSizerFlags().Border().Expand());
//    sizer->Add(m_text, wxSizerFlags(1).Border().Expand());
//    SetSizer(sizer);
//
//    CreateStatusBar(2);
//
//    (*txt_puzzle) << pSolver->board_str();
//
//}
//
//void MyFrame::OnExit(wxCommandEvent& event)
//{
//    Close(true);
//}
//
//void MyFrame::OnAbout(wxCommandEvent& event)
//{
//    wxMessageBox("This is a wxWidgets' Hello world sample", "About Hello World", wxOK | wxICON_INFORMATION);
//}
//
//void MyFrame::OnHello(wxCommandEvent& event)
//{
//    wxLogMessage("Hello world from wxWidgets!");
//}
//
//void MyFrame::OnOpenPuzzle(wxCommandEvent& event)
//{
//    wxLogMessage("Open it!");
//    wxTextEntryDialog dialog(this,
//        wxT("This is a small sample\n")
//        wxT("A long, long string to test out the text entrybox"),
//        wxT("Please enter a string"),
//        wxT("Default value"),
//        wxOK | wxCANCEL);
//
//    if (dialog.ShowModal() == wxID_OK)
//    {
//        wxLogMessage(dialog.GetValue());
//        pSolver->reset(dialog.GetValue().ToStdString());
//        txt_puzzle->Clear();
//        txt_puzzle->AppendText(pSolver->board_str());
//    }
//}
//
//void MyFrame::OnSolvePuzzle(wxCommandEvent& event)
//{
//    wxLogMessage("Solve it!");
//    int ret = pSolver->solve();
//    wxLogMessage("solve() returns: %d", ret);
//    txt_solution->Clear();
//    txt_solution->AppendText(pSolver->board_str());
//}


#include "SukokuFrame.h"

#include "wx/wxprec.h"
#ifndef WX_PRECOMP    
#include "wx/wx.h"
#endif

class MyApp : public wxApp
{
public:
    virtual bool OnInit(){
        MyFrame *frame = new MyFrame(wxT("ZKS Sudoku Beta"), wxDefaultPosition, wxDefaultSize);
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);

#endif //USE_GUI
