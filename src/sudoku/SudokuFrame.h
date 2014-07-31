#ifndef ZKS_SUDOKUFRAME_H_
#define ZKS_SUDOKUFRAME_H_

#include "stopwatch.h"

#include "Solver.h"
#include "Generator.h"
#include "ISudokuFrame.h"

#include "wx/wxprec.h"
#ifndef WX_PRECOMP    
#include "wx/wx.h"
#endif

#include <vector>
#include <memory>

using namespace std;

class GridBottomLineRenderer : public wxGridCellStringRenderer
{
public:
    virtual void Draw(wxGrid& grid, wxGridCellAttr& attr, wxDC& dc, const wxRect& rect, int row, int col, bool isSelected) {
        wxGridCellStringRenderer::Draw(grid, attr, dc, rect, row, col, isSelected);

        dc.SetPen(wxPen(wxColor(0, 0, 0), 4, wxSOLID));
        dc.DrawLine(rect.x, rect.y + rect.height, rect.x + rect.width, rect.y + rect.height);
    }
};

class GridRightLineRenderer : public wxGridCellStringRenderer
{
public:
    virtual void Draw(wxGrid& grid, wxGridCellAttr& attr, wxDC& dc, const wxRect& rect, int row, int col, bool isSelected) {
        wxGridCellStringRenderer::Draw(grid, attr, dc, rect, row, col, isSelected);

        dc.SetPen(wxPen(wxColor(0, 0, 0), 4, wxSOLID));
        dc.DrawLine(rect.x + rect.width, rect.y, rect.x + rect.width, rect.y + rect.height);
    }
};

class GridRightBottomLineRenderer : public wxGridCellStringRenderer
{
public:
    virtual void Draw(wxGrid& grid, wxGridCellAttr& attr, wxDC& dc, const wxRect& rect, int row, int col, bool isSelected) {
        wxGridCellStringRenderer::Draw(grid, attr, dc, rect, row, col, isSelected);

        dc.SetPen(wxPen(wxColor(0, 0, 0), 4, wxSOLID));
        dc.DrawLine(rect.x + rect.width, rect.y, rect.x + rect.width, rect.y + rect.height);
        dc.DrawLine(rect.x, rect.y + rect.height, rect.x + rect.width, rect.y + rect.height);
    }
};

class BatchProgress : public IBatchProgressFrame {
    std::unique_ptr < zks::game::sudoku::ISolver > pSolver;
    std::string puzzle_file_;
    std::string solution_file_;
    
    void ChooseFile_(wxTextCtrl* txt) {
        static wxString s_filename1, s_ext1, s_path1, s_name1;
        if (!s_filename1.empty()) {
            wxFileName::SplitPath(s_filename1, &s_path1, &s_name1, &s_ext1);
        }
        s_filename1 = wxFileSelector(
            wxT("Select a file ..."),
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
        if (!s_filename1)
            return;
        txt->SetValue(s_filename1);
    }
    void ChooseFile2_(wxTextCtrl* txt) {
        static wxString s_filename2, s_ext2, s_path2, s_name2;
        if (!s_filename2.empty()) {
            wxFileName::SplitPath(s_filename2, &s_path2, &s_name2, &s_ext2);
        }
        wxFileDialog dialog(this,
            wxT("Select a file ..."),
            s_path2, s_name2,
            wxString::Format(
                wxT("Plain text (*.txt)|*.txt|All files (%s)|%s"),
                wxFileSelectorDefaultWildcardStr,
                wxFileSelectorDefaultWildcardStr
            ));

        dialog.CentreOnParent();

        if (dialog.ShowModal() == wxID_OK) {
            s_filename2 = dialog.GetPath();
            txt->SetValue(s_filename2);
        }
        
    }
protected:
    virtual void OnUpdatePuzzleFile(wxCommandEvent& event) { 
        puzzle_file_ = m_puzzle_file_textctrl->GetValue().ToStdString();
        event.Skip();
    }
    virtual void OnUpdateSolutionFile(wxCommandEvent& event) {
        solution_file_ = m_solution_file_textctrl->GetValue().ToStdString();
        event.Skip();
    }
    virtual void OnUpdateSolver(wxCommandEvent& event) { 
        int sel = m_solver_radio->GetSelection();
        if (sel == 0) {
            pSolver.reset(new zks::game::sudoku::BalanceSolver);
        }
        else if (sel == 1) {
            pSolver.reset(new zks::game::sudoku::BrutalSolver);
        }
        event.Skip(); 
    }
    virtual void ChoosePuzzle(wxCommandEvent& event) { 
        ChooseFile2_(m_puzzle_file_textctrl);
    }
    virtual void ChooseSolution(wxCommandEvent& event) { 
        ChooseFile2_(m_solution_file_textctrl);
    }
    virtual void BatchStart(wxCommandEvent& event) { 
        std::ifstream ifs(puzzle_file_);
        if (!ifs.good()) {
            wxMessageBox(wxString::Format("can't open '%s' to read.", puzzle_file_.c_str()));
            return;
        }
        std::ofstream ofs(solution_file_, std::ios_base::out | std::ios_base::trunc);
        if (!ofs.good()) {
            wxMessageBox(wxString::Format("can't open '%s' to write.", solution_file_.c_str()));
            return;
        }

        std::string line;
        std::vector<string> puzzles;
        for (; std::getline(ifs, line);) {
            puzzles.push_back(line);
        }
        size_t psize = puzzles.size();
        wxLogMessage("read in %lld puzzles.", psize);

        m_gauge->SetRange(psize);
        int ret;
        zks::StopWatch sw;
        sw.start();
        for (int i = 0; i < psize; ++i) {
            pSolver->reset(puzzles[i]);
            m_progress_text->SetLabel(wxString::Format("Solving puzzle %lld ...", i + 1));
            ofs << pSolver->puzzle_str() << "\n";
            ret = pSolver->solve();
            ofs << ret << "\t" << pSolver->str() << "\t" << pSolver->complexity() << "\n";
            m_gauge->SetValue(i + 1);

            wxYield();
        }
        sw.tick();
        wxMessageBox(wxString::Format("%lld puzzles have been solved!", psize), "Finished!");
        wxLogMessage("%lld puzzles solved in %lldms.", psize, sw.total().count());
    }
public:
    BatchProgress(wxWindow* parent) : IBatchProgressFrame(parent) {
        pSolver.reset(new zks::game::sudoku::BalanceSolver);
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
    void UpdateGridRenderer(wxGrid* grid) {
        for (int i = 0; i < 9; ++i) {
            grid->GetOrCreateCellAttr(2, i)->SetRenderer(new GridBottomLineRenderer);
            grid->GetOrCreateCellAttr(5, i)->SetRenderer(new GridBottomLineRenderer);
            grid->GetOrCreateCellAttr(i, 2)->SetRenderer(new GridRightLineRenderer);
            grid->GetOrCreateCellAttr(i, 5)->SetRenderer(new GridRightLineRenderer);
        }
        grid->GetOrCreateCellAttr(2, 2)->SetRenderer(new GridRightBottomLineRenderer);
        grid->GetOrCreateCellAttr(2, 5)->SetRenderer(new GridRightBottomLineRenderer);
        grid->GetOrCreateCellAttr(5, 2)->SetRenderer(new GridRightBottomLineRenderer);
        grid->GetOrCreateCellAttr(5, 5)->SetRenderer(new GridRightBottomLineRenderer);
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
        zks::StopWatch sw;
        sw.start();
        int ret = pSolver->solve();
        sw.tick();
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
        UpdateGrid(m_solution_grid, pSolver.get());
        wxLogMessage("solve() returns: %d, in %lldms, complexity is: %d",
                ret, sw.total().count(), pSolver->complexity());
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
        BatchProgress* pBP = new BatchProgress(this);
        pBP->Show();
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
    virtual void OnChangeSolver(wxCommandEvent& event) {
        std::string puzzle = pSolver->puzzle_str();
        int sel = m_solver_radio->GetSelection();
        if (sel == 0) {
            pSolver.reset(new zks::game::sudoku::BalanceSolver);
            wxLogMessage(wxT("change to balance solver"));
        }
        else if (sel == 1) {
            pSolver.reset(new zks::game::sudoku::BrutalSolver);
            wxLogMessage(wxT("change to brutal solver"));
        }
        pSolver->reset(puzzle);
        m_solution_grid->ClearGrid();
        event.Skip();
    }
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size) : ISudokuFrame(NULL, wxID_ANY, title)
    {
        m_log = wxLog::SetActiveTarget(new wxLogTextCtrl(m_log_text));
        pSolver.reset(new zks::game::sudoku::BalanceSolver("200000060000075030048090100000300000300010009000008000001020570080730000090000004"));
        UpdateGridRenderer(m_puzzle_grid);
        UpdateGridRenderer(m_solution_grid);
        UpdateGrid(m_puzzle_grid, pSolver.get());
        wxIconLocation ico_loc("Sudoku.ico");
        this->SetIcons(wxIcon(ico_loc));
    }
private:
    wxLog *m_log;
    std::unique_ptr<zks::game::sudoku::ISolver> pSolver;

};

#endif //ZKS_SUDOKUFRAME_H_
