#ifndef _ZKS_SUDOKU_WORKER_H
#define _ZKS_SUDOKU_WORKER_H

#include "Solver.h"
#include "Generator.h"

#include "libzks.h"

#include <iostream>
#include <fstream>
#include <thread>
#include <future>


namespace zks {
namespace game {
namespace sudoku {

	int solver_thread(std::string line, int i);
	int count_thread(std::string line, int i);
	int generate_thread(int i);

	template<typename TASK_, int MAX_THREADS_ = 7>
	int solve(TASK_ task, char* file) {
		std::vector<std::future<int>> res_vec;

		std::ifstream ifs(file);
		if (!ifs.good()) {
			ZKS_ERROR(g_logger, "controller", "can not open file: %s", file);
		}
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

	template<typename TASK_, int MAX_THREADS_ = 7>
	int generate(TASK_ task, int num) {
		std::vector<std::future<int>> res_vec;
		int lno = 0;
		for (; lno < MAX_THREADS_; ++lno) {
			if (lno<num) res_vec.push_back(std::async(launch::async, task, lno));
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

}
}
}


#endif //_ZKS_SUDOKU_WORKER_H
