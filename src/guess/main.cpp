#include "MyFrame.h"

#include "wx/wxprec.h"
#ifndef WX_PRECOMP    
#include "wx/wx.h"
#endif

#include "random.h"

using namespace zks::game::guess;
class MyApp : public wxApp
{
public:
    virtual bool OnInit(){
        wxInitAllImageHandlers();
        zks::randomize();
        MyFrame *frame = new MyFrame(wxT("ZKS Guess Beta"), wxDefaultPosition, wxDefaultSize);
        frame->Show(true);
        return true;
    }
};

wxDECLARE_APP(MyApp);

wxIMPLEMENT_WXWIN_MAIN_CONSOLE

wxIMPLEMENT_APP_NO_MAIN(MyApp);