#include "libzks.h"
#include "ISudoku.h"

extern zks::simlog g_logger;

namespace zks {
namespace game {
namespace sudoku {

	const ISudoku::choice_t ISudoku::full_set{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

	void ISudoku::reset() { 
		for (auto& c : board_) 
			c = '0';
		int cnt = 0;
		for (auto c : puzzle_) {
			if (c<'0' || c>'9') continue;
			board_[cnt] = c;
			if (++cnt == 81) break;
		}
		if (cnt != 81) {
			ZKS_DEBUG(g_logger, "WARN", "read only %d char < 81", cnt);
		}
	}

	bool ISudoku::read(std::istream& in) {
		size_t cnt{ 0 };
		char c;
		while (in.get(c)) {
			if (c<'0' || c>'9') continue;
			board_[cnt] = c;
			if (++cnt == 81) break;
		}
		return cnt == 81 ? true : false;
	}

	std::string ISudoku::puzzle_str_ex() const {
		board_t tmp;
		std::copy(puzzle_.begin(), puzzle_.end(), tmp.begin());
		return to_string(tmp);
	}

	std::string to_string(ISudoku::choice_t const& g) {
		std::string ret;
		for (auto c : g) {
			ret += c;
		}
		if (ret.empty()) {
			ret = "NULL";
		}
		return ret;
	}
	std::string ISudoku::oppor_str_ex() const {
		static const u8string dash(29, '-');
		static const u8string header{ "+" + dash + '+' + dash + '+' + dash + "+\n" };
		u8string ret;
		ret.reserve(header.size() * 16);
		ret += "\n" + header;
		for (int y = 0; y < 9; ++y) {
			ret += "|";
			for (int x = 0; x < 9; ++x) {
				ret.append(dash.size(), "%9s", to_string(opportunities_.grid(x, y)).c_str());
				if (x == 2 || x == 5 || x == 8) {
					ret += "|";
				}
				else {
					ret += " ";
				}
			}
			ret += "\n";
			if (y == 2 || y == 5 || y == 8) {
				ret += header;
			}
		}
		return std::move(ret.str());
	}

}
}
}
