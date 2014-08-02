#include "MyFrame.h"

#include <wx/dir.h>

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
                m_gn_hint->SetLabel("Choose Dir");
                m_hint = m_gn_hint_checker->GetValue();
            }
            void MyFrame::UpdateStatBMP() {
                wxDELETE(m_statbmp);
                m_statbmp = new wxStaticBitmap(m_gn_bmp_panel, wxID_ANY, wxBitmap(m_images[m_gn_index]));
                m_gn_bmp_panel->GetSizer()->Add(m_statbmp, wxSizerFlags().Expand().Proportion(1));
                GetSizer()->Layout();
            }
            void MyFrame::StartGuessName() {
                m_gn_btn_head->Enable();
                m_gn_btn_prev->Enable();
                m_gn_btn_next->Enable();
                m_gn_btn_tail->Enable();
                m_gn_index = 0;
                ProvidePuzzle();
            }
            void MyFrame::ProvidePuzzle() {
                UpdateStatBMP();
                m_gn_progress->SetValue(m_gn_index + 1);
                m_gn_input_text->Clear();
                m_gn_input_text->SetFocus();
                GNHint();
            }
            void MyFrame::GNHint() {
                if (m_hint) {
                    int diff = m_gn_names[m_gn_index].length() - m_gn_input_text->GetValue().length();
                    m_gn_hint->SetLabel(wxString::Format("%c, (%d)", char(m_gn_names[m_gn_index][0]), diff));
                }
                else {
                    m_gn_hint->SetLabel("Come On Honey!");
                }
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
                if (answer.MakeLower() == m_gn_names[m_gn_index]) {
                    wxLogMessage(wxT("Great, that's Correct!"));
                    ++m_gn_index;
                    ProvidePuzzle();
                }
                else {
                    wxLogMessage(wxT("ooh, try again."));
                    ProvidePuzzle();
                }
                event.Skip();
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
                m_images.resize(files.GetCount());
                m_gn_names.resize(files.GetCount());
                for (int i = 0; i < files.GetCount(); ++i) {
                    if (!m_images[i].LoadFile(files[i]))  {
                        wxLogMessage(wxString::Format("file: %s can't be parsed. ignore it...", files[i]));
                        continue;
                    }
                    m_gn_names[i] = GetNameFromFile(files[i]);
                    m_gn_progress->SetValue(i+1);
                    //wxLogMessage(wxString::Format("handling[%d/%lld]: name: %s", i + 1, files.GetCount(), m_gn_names[i]));
                }
                wxMessageBox(wxString::Format("Load in %lld images.", files.GetCount()), "Open Image Dir");
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
