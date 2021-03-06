#include "Solver.h"
#include "Generator.h"
#include "worker.h"

#include "libzks.h"

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

#include "SudokuFrame.h"

#include "wx/wxprec.h"
#ifndef WX_PRECOMP    
#include "wx/wx.h"
#endif

class MyApp : public wxApp
{
public:
    virtual bool OnInit(){
    	g_logger.config.stream_type = 3;
    	g_logger.reset();
        MyFrame *frame = new MyFrame(wxT("ZKS Sudoku Beta"), wxDefaultPosition, wxDefaultSize);
        frame->Show(true);
        return true;
    }
};

wxDECLARE_APP(MyApp);

wxIMPLEMENT_WXWIN_MAIN_CONSOLE

wxIMPLEMENT_APP_NO_MAIN(MyApp);

#endif //USE_GUI
