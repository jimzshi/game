#include "worker.h"

namespace zks {
namespace game {
namespace sudoku{


    int solver_thread(std::string line, int i) {
        zks::game::sudoku::BalanceSolver s{ line };
        ZKS_NOTICE(g_logger, "game", "(%d):%s", i, s.puzzle_str().c_str());
        zks::StopWatch sw;
        zks::u8string buff;
        buff.format(128, "game(%d) start", i);
        sw.start(buff);
        int ret = s.solve();
        buff.format(128, "game(%d) finished", i);
        sw.tick(buff);
        ZKS_NOTICE(g_logger, "solution", "(%d):%s", i, s.board_str().c_str());
        ZKS_NOTICE(g_logger, "stat", "%s", sw.u8str().data());
        return ret;
    }

    int count_thread(std::string line, int i) {
        zks::game::sudoku::BalanceCounter s{ line };
        ZKS_NOTICE(g_logger, "game", "(%d):%s", i, s.puzzle_str().c_str());
        zks::StopWatch sw;
        zks::u8string buff;
        buff.format(128, "game(%d) start", i);
        sw.start(buff);
        int ret = s.count();
        buff.format(128, "game(%d) finished", i);
        sw.tick(buff);
        ZKS_NOTICE(g_logger, "count", "Solution number of game(%d): %d", i, ret);
        ZKS_NOTICE(g_logger, "stat", "%s", sw.u8str().data());
        return ret;
    }

    int generate_thread(int i) {
        zks::game::sudoku::IGenerator gen;
        ZKS_NOTICE(g_logger, "proc", "generate(%d)", i);
        zks::StopWatch sw;
        sw.start("start");
        std::string puzzle = gen.puzzle();
        sw.tick("finished.");
        ZKS_NOTICE(g_logger, "generate", "puzzle(%d): %s", i, puzzle.c_str());
        ZKS_NOTICE(g_logger, "stat", "%s", sw.u8str().data());
        return 0;
    }

}
}
}
