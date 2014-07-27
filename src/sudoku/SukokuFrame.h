#ifndef ZKS_SUDOKUFRAME_H_
#define ZKS_SUDOKUFRAME_H_

#include "Solver.h"
#include "Generator.h"
#include "ISudokuFrame.h"

#include "wx/wxprec.h"
#ifndef WX_PRECOMP    
#include "wx/wx.h"
#endif

class MyFrame : public ISudokuFrame {
protected:
    virtual void OnSize(wxSizeEvent& event)
    {
        UpdateStatusBar(GetPosition(), event.GetSize(), 0);
        UpdateStatusBar(GetPosition(), GetClientSize(), 1);
        UpdateStatusBar(m_book->GetPosition(), m_book->GetSize(), 2);
    }
    virtual void OpenPuzzle(wxCommandEvent& event) {
        wxLogMessage("Open it!");
        wxTextEntryDialog dialog(this,
            wxT("This is a small sample\n")
            wxT("A long, long string to test out the text entrybox"),
            wxT("Please enter a string"),
            wxT("Default value"),
            wxOK | wxCANCEL);

        if (dialog.ShowModal() == wxID_OK)
        {
            wxLogMessage(dialog.GetValue());
            pSolver->reset(dialog.GetValue().ToStdString());
        }
    }
    virtual void OnSolve(wxCommandEvent& event) {
        wxLogMessage("Solve it!");
        int ret = pSolver->solve();
        wxLogMessage("solve() returns: %d", ret);
    }
    virtual void OnSaveSolution(wxCommandEvent& event) { event.Skip(); }
    virtual void OnPaintPuzzle(wxPaintEvent& event) { event.Skip(); }
    virtual void OnPaintSolution(wxPaintEvent& event) { event.Skip(); }
    void UpdateStatusBar(const wxPoint& pos, const wxSize& size, int statusNo)
    {
        if (m_frameStatusBar)
        {
            wxString msg;
            msg.Printf(_("pos=(%d, %d), size=%dx%d"), pos.x, pos.y, size.x, size.y);
            SetStatusText(msg, statusNo);
        }
    }
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size) : ISudokuFrame(NULL, wxID_ANY, title)
    {
        m_log = wxLog::SetActiveTarget(new wxLogTextCtrl(m_log_text));
        pSolver.reset(new zks::game::sudoku::BalanceSolver("200000060000075030048090100000300000300010009000008000001020570080730000090000004"));
    }
private:
    wxLog *m_log;
    std::unique_ptr<zks::game::sudoku::BalanceSolver> pSolver;

};

#endif //ZKS_SUDOKUFRAME_H_