#ifndef ZKS_GUESSFRAME_H_
#define ZKS_GUESSFRAME_H_

#include "IGuessFrame.h"

#include "wx/wxprec.h"
#ifndef WX_PRECOMP    
#include "wx/wx.h"
#endif

namespace zks
{
    namespace game
    {
        namespace guess
        {
            class MyFrame : public IGuessFrame {
            protected:
                void UpdateStatBMP() {
                    wxDELETE(m_statbmp);
                    wxString filepath("C:\\Users\\Public\\Pictures\\Sample Pictures\\Penguins.jpg");
                    wxImage image(filepath, wxBITMAP_TYPE_JPEG);
                    if (!image.IsOk())
                    {
                        wxLogMessage("Reading image from file '%s' failed.", filepath.c_str());
                        return;
                    }
                    m_statbmp = new wxStaticBitmap(m_gn_bmp_panel, wxID_ANY, wxBitmap(image));
                    m_gn_bmp_panel->GetSizer()->Add(m_statbmp, wxSizerFlags().Expand().Proportion(1));
                    GetSizer()->Layout();
                }
            public:
                MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size) : IGuessFrame(NULL, wxID_ANY, title)
                {
                    UpdateStatBMP();
                    m_log = wxLog::SetActiveTarget(new wxLogTextCtrl(m_log_text));
                    wxIconLocation ico_loc("Sudoku.ico");
                    this->SetIcons(wxIcon(ico_loc));
                    m_splitter->Disconnect(wxEVT_IDLE, wxIdleEventHandler(IGuessFrame::m_splitterOnIdle), NULL, this);
                    auto sh = this->GetRect();
                    m_splitter->SetSashPosition(sh.GetHeight() - 143);
                    m_splitter->SetSashGravity(0.91);
                }
            private:
                wxLog *m_log;
            };
        }
    }
}

#endif