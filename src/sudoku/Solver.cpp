#include "libzks.h"

#include "Solver.h"

#include <iterator>
#include <algorithm>

extern zks::simlog g_logger;

namespace zks {
namespace game {
namespace sudoku {

	int ISolver::rank(digit_t d, index_t i) {
		auto conn = traverse_index(i);
		return (int)std::count_if(conn.cbegin(), conn.cend(),
			[&](index_t idx) { return opportunities_[idx].find(d) != opportunities_[idx].end(); });
	}
	ISolver::digit_t ISolver::pop_top(choice_t& g, index_t i) {
		digit_t ret;
		if (g.size() == 1) {
			ret = *g.begin();
			g.clear();
			return ret;
		}
		
		ret = *std::max_element(g.begin(), g.end(),
					[&](digit_t lh, digit_t rh){ return rank(lh, i) < rank(rh, i); });

		g.erase(ret);
		return ret;
	}

	int BrutalSolver::find_oppor_impl(int from, int to) {
		size_t mins{ 10 };
		int mini{ -1 };
		bool finish_all{ true };
		for (int i = from; i < to; ++i) {
			opportunities_[i].clear();
			if (board_[i] == '0') {
				opportunities_[i] = choices(i);
				finish_all = false;
			}
			if (opportunities_[i].size() > 0) {
				if (opportunities_[i].size() < mins) {
					mins = opportunities_[i].size();
					mini = i;
				}
			}
		}
		return finish_all ? -2 : mini;
	}


	bool BrutalSolver::solve_impl(int start) {
		start;
		LocalBackup<oppor_t> Here(opportunities_);
		int next = find_opportunites(0, 81);
		ZKS_DEBUG(g_logger, "solver", "\nBoard:%s", board_str().c_str());
		ZKS_DEBUG(g_logger, "solver", "opportunites:%s", oppor_str().c_str());
		ZKS_DEBUG(g_logger, "solver", "next=%d, next_x=%d, next_y=%d", next, i2x(next), i2y(next));
		if (next == -1) {
			return false;
		}
		else if (next == -2) {
			return true;
		}
		for (auto t : opportunities_[next]) {
			ZKS_DEBUG(g_logger, "solver", "choose %c for (%d, %d)", t, i2x(next), i2y(next));
			board_[next] = t;
			if (solve_impl(0) == true) {
				ZKS_DEBUG(g_logger, "solver", "%c solve it!", t);
				return true;
			}
			ZKS_DEBUG(g_logger, "solver", "%c failed", t);
		}
		board_[next] = '0';
		return false;
	}

	int GreedySolver::find_oppor_impl(int from, int to) {
		for (int i = from; i < to; ++i) {
			opportunities_[i].clear();
			if (board_[i] == '0') {
				opportunities_[i] = choices(i);
				if (opportunities_[i].size() == 0) {
					return -1;
				}
				return i;
			}
		}
		return -2;
	}
	bool GreedySolver::solve_impl(int start) {
		if (start<0 || start >80) {
			return false;
		}
		int next = find_opportunites(start, 81);
		ZKS_DEBUG(g_logger, "solver", "opportunites:%s", oppor_str().c_str());
		ZKS_DEBUG(g_logger, "solver", "next=%d, next_x=%d, next_y=%d", next, i2x(next), i2y(next));
		if (next == -1) {
			return false;
		}
		else if (next == -2) {
			return true;
		}
		for (auto t : opportunities_[next]) {
			ZKS_DEBUG(g_logger, "solver", "choose %c for (%d, %d)", t, i2x(next), i2y(next));
			board_[next] = t;
			if (solve_impl(next + 1) == true) {
				ZKS_DEBUG(g_logger, "solver", "%c solve it!", t);
				return true;
			}
			ZKS_DEBUG(g_logger, "solver", "%c failed", t);
		}
		board_[next] = '0';
		return false;
	}


	int BalanceSolver::find_oppor_impl(int from, int to) {
		size_t mins{ 10 };
		int mini{ -1 };
		bool finish_all{ true };
		std::array<int, 81> index;
		std::array<size_t, 81> oppor_size;

		for (int i = from; i < to; ++i) {
			opportunities_[i].clear();
			index[i] = i;
			oppor_size[i] = 0;
			if (board_[i] == '0') {
				opportunities_[i] = choices(i);
				oppor_size[i] = opportunities_[i].size();
				finish_all = false;
			}
			if (oppor_size[i] > 0) {
				if (oppor_size[i] < mins) {
					mins = oppor_size[i];
					mini = i;
				}
			}
		}
		if (finish_all) {
			return -2;
		}
		if (mini < 0) {
			return -1;
		}
		std::sort(index.begin(), index.end(), [&](int i, int j){
			return oppor_size[i] < oppor_size[j];
		});
		auto begin = std::find_if(index.begin(), index.end(), [&](int i){
			return oppor_size[i] > 0;
		});
		auto end = std::find_if(begin, index.end(), [&](int i){
			return oppor_size[i] > mins;
		});
		if (std::distance(begin, end) == 1) {
			return *(begin);
		}
		for (auto iter = begin; iter != end; ++iter) {
			if (std::any_of(iter + 1, end, [&](int idx){return opportunities_[idx] == opportunities_[*iter]; })) {
				return *iter;
			}
		}
		//for (auto iter = begin; iter != end; ++iter) {
		//	auto conn = traverse_index(*iter);
		//	if (std::any_of(iter + 1, end, [&](int idx){return opportunities_[idx] == opportunities_[*iter]; })) {
		//		return *iter;
		//	}
		//}
		return *begin;
	}
	bool BalanceSolver::solve_impl(int start) {
		LocalBackup<oppor_t> Here(opportunities_);
		int next = find_opportunites(0, 81);
		//ZKS_DEBUG(g_logger, "solver", "\nBoard:%s", board_str().c_str());
		//ZKS_DEBUG(g_logger, "solver", "opportunites:%s", oppor_str().c_str());
		//ZKS_DEBUG(g_logger, "solver", "next=%d, next_x=%d, next_y=%d", next, i2x(next), i2y(next));
		if (next == -1) {
			return false;
		}
		else if (next == -2) {
			return true;
		}

		while (opportunities_[next].size()) {
			digit_t d = pop_top(opportunities_[next], next);
			//ZKS_DEBUG(g_logger, "solver", "choose %c for (%d, %d)", d, i2x(next), i2y(next));
			board_[next] = d;
			if (solve_impl(next + 1) == true) {
				//ZKS_DEBUG(g_logger, "solver", "%c solve it!", d);
				return true;
			}
			//ZKS_DEBUG(g_logger, "solver", "%c failed", d);
		}

		board_[next] = '0';
		return false;
	}

	bool CountSolver::solve_impl(int start) {
		LocalBackup<oppor_t> Here(opportunities_);
		int next = find_opportunites(0, 81);
		//ZKS_DEBUG(g_logger, "solver", "\nBoard:%s", board_str().c_str());
		//ZKS_DEBUG(g_logger, "solver", "opportunites:%s", oppor_str().c_str());
		//ZKS_DEBUG(g_logger, "solver", "next=%d, next_x=%d, next_y=%d", next, i2x(next), i2y(next));
		if (next == -1) {
			return false;
		}
		else if (next == -2) {
			++count_;
			ZKS_DEBUG(g_logger, "solver", "solution(%d): %s", count_, board_str().c_str());
			return false;
		}

		while (opportunities_[next].size()) {
			digit_t d = pop_top(opportunities_[next], next);
			//ZKS_DEBUG(g_logger, "solver", "choose %c for (%d, %d)", d, i2x(next), i2y(next));
			board_[next] = d;
			solve_impl(next + 1);
		}
		board_[next] = '0';

		return false;
	}

}
}
}
