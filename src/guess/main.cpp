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
        MyFrame *frame = new MyFrame(wxT("ZKS Sudoku Beta"), wxDefaultPosition, wxDefaultSize);
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);