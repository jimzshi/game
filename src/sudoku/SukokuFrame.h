#ifndef ZKS_SUDOKUFRAME_H_
#define ZKS_SUDOKUFRAME_H_

#include "Solver.h"
#include "Generator.h"
#include "ISudokuFrame.h"

#include "wx/wxprec.h"
#ifndef WX_PRECOMP    
#include "wx/wx.h"
#endif

class BatchProgress : public IBatchProgressFrame {
    std::string puzzle_file_;
    std::string solution_file_;
public:
    BatchProgress(wxWindow* parent, const wxString& puzzle, const wxString& solution) : IBatchProgressFrame(parent), 
        puzzle_file_(puzzle.ToStdString()), solution_file_(solution.ToStdString()) 
    {
        Show();
        std::unique_ptr<zks::game::sudoku::ISolver> pSolver1;
        pSolver1.reset(new zks::game::sudoku::BalanceSolver);
        std::unique_ptr<zks::game::sudoku::ISolver> pSolver2;
        pSolver2.reset(new zks::game::sudoku::BrutalSolver);
        std::ifstream ifs(puzzle_file_);
        if (!ifs.good()) {
            wxLogMessage("can't open %s to read.", puzzle_file_);
            return;
        }
        std::ofstream ofs(solution_file_);
        if (!ofs.good()) {
            wxLogMessage("can't open %s to write.", solution_file_);
            return;
        }

        std::string line;
        std::vector<string> puzzles;
        for (; std::getline(ifs, line); ) {
            puzzles.push_back(line);
        }
        size_t psize = puzzles.size();
        wxLogMessage("read in %d puzzles.", psize);

        int ret;
        for (size_t i = 0; i < psize; ++i) {
            m_progress_text->SetLabel(wxString::Format("Solving puzzle %d ...", i));
            ofs << pSolver1->puzzle_str() << "\n";

            pSolver1->reset(puzzles[i]);
            ret = pSolver1->solve();
            ofs << ret << "\t" << pSolver1->str() << "\t" << pSolver1->complexity() << "\n";
            
            pSolver2->reset(puzzles[i]);
            ret = pSolver2->solve();
            ofs << ret << "\t" << pSolver2->str() << "\t" << pSolver2->complexity() << "\n";

            m_gauge->SetValue((int)(double(i) * m_gauge->GetRange() / psize));
        }
        wxMessageBox(wxString::Format("%d puzzles have been solved!", psize), "Finished!");
        Close();
    }
    ~BatchProgress() {}
};

class MyFrame : public ISudokuFrame {
    void UpdateGrid(wxGrid* grid, const zks::game::sudoku::ISolver* s) {
        int d;
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                d = s->grid(r, c);
                if (d == 0) {
                    grid->SetCellValue(r, c, wxString("."));
                }
                else {
                    grid->SetCellValue(r, c, wxString::Format(wxT("%d"), s->grid(r, c)));
                }
            }
        }
    }
    void UpdateGrid(wxGrid* grid, const std::string& s) {
        char ch;
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                ch = s[r * 9 + c];
                if (ch == '0') {
                    grid->SetCellValue(r, c, wxString("."));
                }
                else {
                    grid->SetCellValue(r, c, wxString::Format(wxT("%c"), ch));
                }
            }
        }
    }
protected:
    virtual void OnSize(wxSizeEvent& event)
    {
        UpdateStatusBar(GetPosition(), event.GetSize(), 0);
        UpdateStatusBar(GetPosition(), GetClientSize(), 1);
        UpdateStatusBar(m_book->GetPosition(), m_book->GetSize(), 2);
    }
    virtual void OnInputPuzzle(wxCommandEvent& event) {
        wxLogMessage("OnInputPuzzle");
        wxTextEntryDialog dialog(this,
            wxT("Please input your puzzle here.\n You can put it all in one line, use '0' for empty grid.\n"),
            wxT("Input your puzzle"),
            pSolver->puzzle_str(),
            wxOK | wxCANCEL);

        if (dialog.ShowModal() == wxID_OK)
        {
            wxLogMessage(dialog.GetValue());
            pSolver->reset(dialog.GetValue().ToStdString());
        }
        UpdateGrid(m_puzzle_grid, pSolver->puzzle_str());
    }
    virtual void OnSolve(wxCommandEvent& event) {
        int ret = pSolver->solve();
        if (ret == -3) {
            wxLogMessage("Puzzle is not valid!!");
            wxMessageBox("Puzzle is not valid!!");
            return;
        }
        if (ret == -1) {
            wxLogMessage("Puzzle has no solution!!");
            wxMessageBox("Puzzle has no solution!!");
            return;
        }
        wxLogMessage("Solve it!");
        UpdateGrid(m_solution_grid, pSolver.get());
        wxLogMessage("solve() returns: %d, complexity is: %d", ret, pSolver->complexity());
    }
    virtual void OnSaveSolution(wxCommandEvent& event) {
        static wxString s_filename, s_ext, s_path, s_name;
        wxLogMessage(wxT("start to select a file based on '%s'"), s_filename);
        if (!s_filename.empty()) {
            wxFileName::SplitPath(s_filename, &s_path, &s_name, &s_ext);
        }
        s_filename = wxFileSelector(
            wxT("Select a file to save the solution"),
            s_path, s_name, s_ext,
            wxString::Format
            (
            wxT("Plain text (*.txt)|*.txt|All files (%s)|%s"),
            wxFileSelectorDefaultWildcardStr,
            wxFileSelectorDefaultWildcardStr
            ),
            wxFD_OPEN | wxFD_CHANGE_DIR | wxFD_PREVIEW,
            this
            );
        wxLogMessage(wxT("selected '%s'"), s_filename);
        if (!s_filename)
            return;
        ofstream ofs(s_filename.ToStdString());
        ofs << pSolver->str() << "\n";
        wxLogMessage(wxT("solution '%s' has been writen"), pSolver->str());
        return;
    }
    virtual void OnBatchMode(wxCommandEvent& event) { 
        static wxString s_filename1, s_ext1, s_path1, s_name1;
        if (!s_filename1.empty()) {
            wxFileName::SplitPath(s_filename1, &s_path1, &s_name1, &s_ext1);
        }
        s_filename1 = wxFileSelector(
            wxT("Select a file contains puzzles.(one puzzle per line)"),
            s_path1, s_name1, s_ext1,
            wxString::Format
            (
            wxT("Plain text (*.txt)|*.txt|All files (%s)|%s"),
            wxFileSelectorDefaultWildcardStr,
            wxFileSelectorDefaultWildcardStr
            ),
            wxFD_OPEN | wxFD_CHANGE_DIR | wxFD_PREVIEW,
            this
            );
        wxLogMessage(wxT("puzzle input file is '%s'"), s_filename1);
        if (!s_filename1)
            return;

        static wxString s_filename2, s_ext2, s_path2, s_name2;
        if (!s_filename2.empty()) {
            wxFileName::SplitPath(s_filename2, &s_path2, &s_name2, &s_ext2);
        }
        s_filename2 = wxFileSelector(
            wxT("Select a file to save the solutions"),
            s_path2, s_name2, s_ext2,
            wxString::Format
            (
            wxT("Plain text (*.txt)|*.txt|All files (%s)|%s"),
            wxFileSelectorDefaultWildcardStr,
            wxFileSelectorDefaultWildcardStr
            ),
            wxFD_OPEN | wxFD_CHANGE_DIR | wxFD_PREVIEW,
            this
            );
        wxLogMessage(wxT("solutions will be saved to '%s'"), s_filename2);
        if (!s_filename2)
            return;

        BatchProgress bp(this, s_filename1, s_filename2);
    }
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
        UpdateGrid(m_puzzle_grid, pSolver.get());
        wxIconLocation ico_loc("Icon.ico");
        this->SetIcons(wxIcon(ico_loc));
    }
private:
    wxLog *m_log;
    std::unique_ptr<zks::game::sudoku::ISolver> pSolver;

};

#endif //ZKS_SUDOKUFRAME_H_