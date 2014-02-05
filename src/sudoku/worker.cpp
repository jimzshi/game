#include "worker.h"

extern zks::simlog g_logger;

namespace zks {
namespace game {
namespace sudoku{


	int solver_thread(std::string line, int i) {
		zks::game::sudoku::BalanceSolver s{ line };
		ZKS_INFO(g_logger, "game", "(%d):%s", i, s.puzzle_str().c_str());
		zks::StopWatch sw;
		zks::u8string buff;
		buff.format(128, "game(%d) start", i);
		sw.start(buff);
		int ret = s.solve();
		buff.format(128, "game(%d) finished", i);
		sw.tick(buff);
		ZKS_INFO(g_logger, "solution", "(%d):%s", i, s.board_str().c_str());
		ZKS_INFO(g_logger, "stat", "%s", sw.u8str().data());
		return ret;
	}

	int count_thread(std::string line, int i) {
		zks::game::sudoku::CountSolver s{ line };
		ZKS_INFO(g_logger, "game", "(%d):%s", i, s.puzzle_str().c_str());
		zks::StopWatch sw;
		zks::u8string buff;
		buff.format(128, "game(%d) start", i);
		sw.start(buff);
		int ret = s.count_solve();
		buff.format(128, "game(%d) finished", i);
		sw.tick(buff);
		ZKS_INFO(g_logger, "count", "Solution number of game(%d): %d", i, ret);
		ZKS_INFO(g_logger, "stat", "%s", sw.u8str().data());
		return ret;
	}

	int generate_thread(int i) {
		zks::game::sudoku::IGenerator gen;
		ZKS_INFO(g_logger, "proc", "generate(%d)", i);
		zks::StopWatch sw;
		sw.start("start");
		std::string puzzle = gen.puzzle();
		sw.tick("finished.");
		ZKS_INFO(g_logger, "generate", "puzzle(%d): %s", i, puzzle.c_str());
		ZKS_INFO(g_logger, "stat", "%s", sw.u8str().data());
		return 0;
	}

}
}
}
