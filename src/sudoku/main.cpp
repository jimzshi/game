#include "Solver.h"

#include "libzks.h"

#include <iostream>
#include <fstream>
#include <thread>
#include <future>

using namespace std;

zks::simlog g_logger;

int solver_thread(std::string line, int i) {
	zks::game::sudoku::BalanceSolver s{ line };
	ZKS_INFO(g_logger, "game", "\nGame(%d):\n%s\n", i, s.board_str().c_str());
	zks::StopWatch sw;
	zks::u8string buff;
	buff.format(128, "game(%d) start", i);
	sw.start(buff);
	bool ret = s.solve();
	buff.format(128, "game(%d) finished", i);
	sw.tick(buff);
	ZKS_INFO(g_logger, "game", "\nSolution(%d):\n%s\n", i, s.board_str().c_str());
	ZKS_INFO(g_logger, "stat", "%s", sw.u8str().data());
	return ret;
}

int main(int argc, char* argv[]) {
	if (argc < 3) {
		cerr << argv[0] << " log.ini game-file" << endl;
		return 0;
	}
	g_logger.configure(argv[1]);
	g_logger.reset();

	const int MAX_THREADS = 7;
	std::vector<std::future<int>> res_vec;
	//std::vector<zks::game::Sudoku> sudoku_vec;
	
	ifstream ifs(argv[2]);
	std::string line;
	int lno = 0;
	for (; lno < MAX_THREADS; ++lno) {
		if (std::getline(ifs, line)) {
			res_vec.push_back(std::async(launch::async, solver_thread, line, lno));
		}
	}
	g_logger.flush();
	try {
		for (;;) {
			bool finish_all{ true };
			for (auto& t : res_vec) {
				if (!t.valid()) {
					continue;
				}
				finish_all = false;
				auto status = t.wait_for(std::chrono::milliseconds(500));
				if (status == std::future_status::ready) {
					t.get();
					if (std::getline(ifs, line)) {
						t = std::async(launch::async, solver_thread, line, lno++);
					}
				}
			}
			if (finish_all) {
				break;
			}
		}
	}
	catch (std::exception& e) {
		ZKS_ERROR(g_logger, "main", "Exception: %s", e.what());
	}

	return 0;
}