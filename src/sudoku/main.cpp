#include "Solver.h"
#include "Generator.h"

#include "libzks.h"

#include <iostream>
#include <fstream>
#include <thread>
#include <future>

using namespace std;

zks::simlog g_logger;

int solver_thread(std::string line, int i) {
	zks::game::sudoku::BalanceSolver s{ line };
	ZKS_INFO(g_logger, "game", "\nGame(%d):%s", i, s.puzzle_str().c_str());
	zks::StopWatch sw;
	zks::u8string buff;
	buff.format(128, "game(%d) start", i);
	sw.start(buff);
	int ret = s.solve();
	buff.format(128, "game(%d) finished", i);
	sw.tick(buff);
	ZKS_INFO(g_logger, "game", "\nSolution(%d):%s\n", i, s.board_str().c_str());
	ZKS_INFO(g_logger, "stat", "%s", sw.u8str().data());
	return ret;
}

int count_thread(std::string line, int i) {
	zks::game::sudoku::CountSolver s{ line };
	ZKS_INFO(g_logger, "game", "Game(%d):%s", i, s.puzzle_str().c_str());
	zks::StopWatch sw;
	zks::u8string buff;
	buff.format(128, "game(%d) start", i);
	sw.start(buff);
	int ret = s.count_solve();
	buff.format(128, "game(%d) finished", i);
	sw.tick(buff);
	ZKS_INFO(g_logger, "game", "Solution number of game(%d): %d", i, ret);
	ZKS_INFO(g_logger, "stat", "%s", sw.u8str().data());
	return ret;
}


template<typename TASK_, int MAX_THREADS_=7>
int sudoku_solve(TASK_ task, char* file) {
	std::vector<std::future<int>> res_vec;

	ifstream ifs(file);
	std::string line;
	int lno = 0;
	for (; lno < MAX_THREADS_; ++lno) {
		if (std::getline(ifs, line)) {
			res_vec.push_back(std::async(launch::async, task, line, lno));
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
						t = std::async(launch::async, task, line, lno++);
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

int generate_thread(int i) {
	zks::game::sudoku::IGenerator gen;
	ZKS_INFO(g_logger, "proc", "generate(%d)", i);
	zks::StopWatch sw;
	sw.start("start");
	std::string puzzle = gen.puzzle();
	sw.tick("finished.");
	ZKS_INFO(g_logger, "return", "puzzle(%d): %s", i, puzzle.c_str());
	ZKS_INFO(g_logger, "stat", "%s", sw.u8str().data());
	return 0;
}

template<typename TASK_, int MAX_THREADS_ = 7>
int sudoku_generate(TASK_ task, int num) {
	std::vector<std::future<int>> res_vec;
	int lno = 0;
	for (; lno < MAX_THREADS_; ++lno) {
		if(lno<num) res_vec.push_back(std::async(launch::async, task, lno));
		//std::this_thread::sleep_for(std::chrono::milliseconds(500)); 
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
					if (lno<num) t = std::async(launch::async, task, lno++);
					//std::this_thread::sleep_for(std::chrono::milliseconds(500)); 
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
	if(cmd=="solve") {
		sudoku_solve(solver_thread, argv[3]);
	} else if(cmd == "generate") {
		sudoku_generate(generate_thread, 10);
	} else if(cmd == "count") {
		sudoku_solve(count_thread, argv[3]);
	}

	return 0;
}
