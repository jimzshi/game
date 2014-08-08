#include "MyFrame.h"

#include <wx/dir.h>

#include "random.h"

#include <functional>
#include <cstdlib>
#include <algorithm>

namespace zks {
    namespace game {
        namespace guess {

            MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
                : IGuessFrame(NULL, wxID_ANY, title)
            {
                //UpdateStatBMP();
                m_log = wxLog::SetActiveTarget(new wxLogTextCtrl(m_log_text));
                wxIconLocation ico_loc("guess.ico");
                this->SetIcons(wxIcon(ico_loc));
                m_splitter->Disconnect(wxEVT_IDLE, wxIdleEventHandler(IGuessFrame::m_splitterOnIdle), NULL, this);
                auto sh = this->GetRect();
                m_splitter->SetSashPosition(sh.GetHeight() - 169);
                m_splitter->SetSashGravity(0.91);
                m_gn_btn_head->Disable();
                m_gn_btn_prev->Disable();
                m_gn_btn_next->Disable();
                m_gn_btn_tail->Disable();
                m_gn_index = 0;
                m_gn_hint->SetLabel("Choose Dir");
                m_hint = m_gn_hint_checker->GetValue();
            }
            void MyFrame::UpdateStatBMP(wxSize new_size) {
                int idx = index();
                if (idx >= m_images.size()) {
                    return;
                }
                wxDELETE(m_statbmp);
                if (new_size == wxDefaultSize) {
                    new_size = m_gn_bmp_panel->GetSize();
                }
                wxImage img = FitFrame(m_images[idx], new_size);
                m_statbmp = new wxStaticBitmap(m_gn_bmp_panel, wxID_ANY, wxBitmap(img));
                m_gn_bmp_panel->GetSizer()->Add(m_statbmp, 1, wxALIGN_CENTER | wxALL, 5);
                m_gn_bmp_panel->GetSizer()->Layout();
                //GetSizer()->Layout();
            }
            void MyFrame::StartGuessName() {
                m_gn_progress->SetRange(m_images.size());
                m_gn_btn_head->Enable();
                m_gn_btn_prev->Enable();
                m_gn_btn_next->Enable();
                m_gn_btn_tail->Enable();
                m_gn_index = 0;
                wxCommandEvent nullevt;
                OnGNShuffle(nullevt);
                ProvidePuzzle();
            }
            void MyFrame::ProvidePuzzle() {
                if (m_guess_book->GetSelection() == 0) {
                    if (m_images.size() == 0) {
                        wxMessageBox("Oops! You need open a pics folder first :)", "Oops!");
                        return;
                    }
                    UpdateStatBMP();
                    m_gn_progress->SetValue(m_gn_index + 1);
                    m_gn_input_text->Clear();
                    m_gn_input_text->SetFocus();
                    GNHint();
                }
            }
            void MyFrame::GNHint() {
                if (m_hint) {
                    int diff = m_gn_names[index()].length() - m_gn_input_text->GetValue().length();
                    m_gn_hint->SetLabel(wxString::Format("%c, (%d)", char(m_gn_names[index()][0]), diff));
                }
                else {
                    m_gn_hint->SetLabel("Come On Honey!");
                }
            }
            void MyFrame::OnGNBMPSize(wxSizeEvent& event) {
                if (m_guess_book->GetSelection() == 0) {
                    UpdateStatBMP(event.GetSize());
                }
                event.Skip();
            }
            void MyFrame::OnGNShuffle(wxCommandEvent& event) {
                m_rands.resize(m_images.size());
                for (size_t i = 0; i < m_rands.size(); ++i) {
                    m_rands[i] = i;
                }
                std::shuffle(m_rands.begin(), m_rands.end(), global_rng());
                ProvidePuzzle();
            }
            void MyFrame::OnHead(wxCommandEvent& event)
            {
                m_gn_index = 0;
                ProvidePuzzle();
            }

            void MyFrame::OnPrev(wxCommandEvent& event)
            {
                --m_gn_index;
                m_gn_index = (m_gn_names.size() + m_gn_index) % m_gn_names.size();
                ProvidePuzzle();
            }

            void MyFrame::OnNext(wxCommandEvent& event)
            {
                m_gn_index = (++m_gn_index) % m_gn_names.size();
                ProvidePuzzle();
            }

            void MyFrame::OnTail(wxCommandEvent& event)
            {
                m_gn_index = m_gn_names.size() - 1;
                ProvidePuzzle();
            }

            void MyFrame::OnGuessInput(wxCommandEvent& event)
            {
                GNHint();
                event.Skip();
            }
            void MyFrame::OnGuessEnter(wxCommandEvent& event)
            {
                wxString answer = m_gn_input_text->GetValue();
                if (answer.MakeLower() == m_gn_names[index()]) {
                    m_gn_tip->SetForegroundColour(*wxBLUE);
                    m_gn_tip->SetLabel("You're Great!");
                    wxLogMessage(wxT("Great, that's Correct!"));
                    wxCommandEvent nullevt;
                    OnNext(nullevt);
                }
                else {
                    m_gn_tip->SetForegroundColour(*wxRED);
                    m_gn_tip->SetLabel("ooh, you GUESS!");
                    wxLogMessage(wxT("ooh, try again."));
                    ProvidePuzzle();
                }
                event.Skip();
            }

            wxSize MyFrame::FitFrame(const wxSize& image_size, const wxSize& frame_size) {
                if (image_size.x == 0 || image_size.y == 0 || frame_size.x == 0 || frame_size.y == 0)
                    return wxDefaultSize;
                wxSize ret;
                float ratio = float(image_size.x) / image_size.y;
                ret.x = std::min(frame_size.x, int(frame_size.y * ratio));
                ret.x = std::min(ret.x, image_size.x);
                ret.y = ret.x / ratio;
                return ret;
            }
            wxImage MyFrame::FitFrame(const wxImage& image, const wxSize& frame_size) {
                wxSize image_size = image.GetSize();
                wxSize new_size = FitFrame(image_size, frame_size);
                if (new_size.x <= 0 || new_size.y <= 0) {
                    new_size = wxSize(1, 1);
                }
                wxImage ret(image);
                ret.Rescale(new_size.x, new_size.y);
                return ret;
            }
            void MyFrame::OnFileOpenFolder(wxCommandEvent& event)
            {
                wxGetHomeDir(&m_pic_dir);
                wxDirDialog dialog(this, wxT("Testing directory picker"), m_pic_dir, wxDD_DEFAULT_STYLE | wxDD_DIR_MUST_EXIST);
                if (dialog.ShowModal() != wxID_OK)
                {
                    wxLogMessage(wxT("aborted"));
                    return;
                }
                wxLogMessage(wxT("Selected path: %s"), dialog.GetPath().c_str());
                m_pic_dir = dialog.GetPath();
                wxDir dir(m_pic_dir);
                if (!dir.IsOpened()) {
                    wxLogMessage(wxT("can't open dir"));
                    return;
                }
                wxArrayString files;
                wxDir::GetAllFiles(m_pic_dir, &files);
                if (files.GetCount() == 0) {
                    wxLogMessage(wxT("found no files in this dir, please re-open dir."));
                    return;
                }
                m_gn_progress->SetRange(files.GetCount());
                m_images.clear();
                m_gn_names.clear();
                m_images.reserve(files.GetCount());
                m_gn_names.reserve(files.GetCount());
                for (int i = 0; i < files.GetCount(); ++i) {
                    wxImage img;
                    if (!img.LoadFile(files[i]) || !img.IsOk())  {
                        wxLogMessage(wxString::Format("file: %s can't be parsed. ignore it...", files[i]));
                        continue;
                    }
                    m_images.push_back(img);
                    m_gn_names.push_back(GetNameFromFile(files[i]));
                    m_gn_progress->SetValue(i+1);
                }
                wxMessageBox(wxString::Format("Load in %d images.", (int)files.GetCount()), "Open Image Dir");
                StartGuessName();
            }
            void MyFrame::OnHintChecker(wxCommandEvent& event) {
                m_hint = m_gn_hint_checker->GetValue();
                GNHint();
                event.Skip();
            }
            wxString MyFrame::GetNameFromFile(const wxString& fn) {
                wxString name;
                wxFileName::SplitPath(fn, nullptr, &name, nullptr);
                return name.BeforeFirst('_').MakeLower();
            }
            void MyFrame::OnFileExit(wxCommandEvent& event)
            {
                Close();
            }

        }
    }
}
