#include "libzks.h"

#include "sudoku.h"

#include <iterator>
#include <algorithm>

extern zks::simlog g_logger;

namespace zks {
namespace game {
	
	const std::string Sudoku::valid_chars{ "0123456789" };
	const Sudoku::grids_t Sudoku::full_set{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

	std::string to_string(Sudoku::grids_t const& g) {
		std::string ret;
		for (auto c : g) {
			ret += c;
		}
		return ret;
	}

	std::string to_string(Sudoku::oppor_t const& o) {
		std::string ret;
		ret.reserve(512);
		int i = 0;
		for (auto g : o) {
			ret += "(" + std::to_string(i++) + ")";
			ret += to_string(g);
			ret += ", ";
		}
		return ret;
	}

	Sudoku::grids_t Sudoku::set_diff(grids_t const& lh, grids_t const& rh) const {
		grids_t ret;
		std::set_difference(lh.cbegin(), lh.cend(),
			rh.cbegin(), rh.cend(), std::inserter(ret, ret.begin()));
		return ret;
	}

	Sudoku::grids_t Sudoku::set_inter(grids_t const& lh, grids_t const& rh) const {
		grids_t ret;
		std::set_intersection(lh.cbegin(), lh.cend(),
			rh.cbegin(), rh.cend(), std::inserter(ret, ret.begin()));
		return ret;
	}

	Sudoku::grids_t Sudoku::set_union(grids_t const& lh, grids_t const& rh) const {
		grids_t ret;
		std::set_union(lh.cbegin(), lh.cend(),
			rh.cbegin(), rh.cend(), std::inserter(ret, ret.begin()));
		return ret;
	}

	Sudoku::grids_t Sudoku::traverse_x_(int i) const {
		grids_t ret;
		digit_t d;
		int y = i2y_(i);
		for (int p = 0; p < 9; ++p) {
			d = cgrid(p, y);
			ret.insert(d);
		}
		//ZKS_TRACE(g_logger, "solver", "traverse_x_(%d)(%d,%d):%s", i, i2x_(i), y, to_string(ret).c_str());
		return ret;
	}
	Sudoku::grids_t Sudoku::traverse_y_(int i) const {
		grids_t ret;
		digit_t d;
		int x = i2x_(i);
		for (int p = 0; p < 9; ++p) {
			d = cgrid(x, p);
			ret.insert(d);
		}
		//ZKS_TRACE(g_logger, "solver", "traverse_y_(%d)(%d,%d):%s", i, x, i2y_(i), to_string(ret).c_str());
		return ret;
	}

	Sudoku::grids_t Sudoku::traverse_r_(int i) const {
		grids_t ret;
		digit_t d;
		int x0 = i2x_(i) / 3 * 3;
		int y0 = i2y_(i) / 3 * 3;
		for (int dx = 0; dx < 3; ++dx) {
			for (int dy = 0; dy < 3; ++dy) {
				d = cgrid(x0+dx, y0+dy);
				ret.insert(d);
			}
		}
		//ZKS_TRACE(g_logger, "solver", "traverse_r_(%d)(%d,%d):%s", i, x0, y0, to_string(ret).c_str());
		return ret;
	}

	int Sudoku::find_opportunites(int from, int to) {
		size_t mins{ 10 };
		int mini{ -1 };
		bool finish_all{ true };
		for (int i = from; i < to; ++i) {
			opportunities_[i].clear();
			if (board_[i] == '0') {
				opportunities_[i] = left_digits(i);
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

	bool Sudoku::read(std::istream& in) {
		size_t cnt{ 0 };
		char c;
		while (in.get(c)) {
			if (c<'0' || c>'9') continue;
			board_[cnt] = c;
			if (++cnt == 81) break;
		}
		return cnt == 81 ? true : false;
	}

	std::string Sudoku::str() const {
		std::string ret, line{ "+-----+-----+-----+\n" };
		ret.reserve(18 * 18);
		ret += line;
		for (int y = 0; y < 9; ++y) {
			ret += "|";
			for (int x = 0; x < 9; ++x) {
				ret += cgrid(x, y);
				if (x == 2 || x == 5 || x == 8) {
					ret += "|";
				}
				else {
					ret += " ";
				}
			}
			ret += "\n";
			if (y == 2 || y == 5 || y == 8) {
				ret += line;
			}
		}
		return ret;
	}

	bool Sudoku::solve() {
		LocalBackup<oppor_t> Here(opportunities_);
		int next = find_opportunites(0, 81);
		//ZKS_DEBUG(g_logger, "solver", "opportunites:%s", to_string(opportunities_).c_str());
		//ZKS_DEBUG(g_logger, "solver", "next=%d, next_x=%d, next_y=%d", next, i2x_(next), i2y_(next));
		if (next == -1) { 
			return false;
		}
		else if (next == -2) {
			return true;
		}
		for (auto t : opportunities_[next]) {
			//ZKS_INFO(g_logger, "solver", "choose %c for (%d, %d)", t, i2x_(next), i2y_(next));
			board_[next] = t;
			if (solve() == true) {
				//ZKS_INFO(g_logger, "solver", "%c solve it!", t);
				return true;
			}
			//ZKS_INFO(g_logger, "solver", "%c failed", t);
		}
		board_[next] = '0';
		return false;
	}

}
}
