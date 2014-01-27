#include "libzks.h"

#include "sudoku.h"

#include <iterator>
#include <algorithm>

extern zks::simlog g_logger;

namespace zks {
namespace game {
	
	const std::string Sudoku::valid_chars{ "0123456789" };
	const Sudoku::grids_t Sudoku::full_set{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

	Sudoku::grids_t Sudoku::set_diff(grids_t const& lh, grids_t const& rh) const {
		grids_t ret;
		std::set_difference(lh.cbegin(), lh.cend(),
			rh.cbegin(), rh.cend(), ret.begin(), 
			std::inserter(ret, ret.begin()));
		return ret;
	}

	Sudoku::grids_t Sudoku::traverse_x_(int i) const {
		grids_t ret;
		digit_t d;
		int y = i2y_(i);
		for (int i = 0; i < 9; ++i) {
			d = cgrid(i, y);
			ret.insert(d);
		}
		return ret;
	}
	Sudoku::grids_t Sudoku::traverse_y_(int i) const {
		grids_t ret;
		digit_t d;
		int x = i2x_(i);
		for (int i = 0; i < 9; ++i) {
			d = cgrid(x, i);
			ret.insert(d);
		}
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
		return ret;
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


}
}
