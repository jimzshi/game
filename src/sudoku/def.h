#ifndef _ZKS_SUDOKU_DEF_H
#define _ZKS_SUDOKU_DEF_H

#include "u8string.h"

#include <array>
#include <set>
#include <algorithm>
#include <iterator>
#include <string>

namespace zks {
namespace game {
namespace sudoku{

	using std::to_string;

	template<typename _Tp>
	using Set = std::set<_Tp>;

	template<typename _Tp>
	inline Set<_Tp> set_diff(Set<_Tp> const& lh, Set<_Tp> const& rh) {
		Set<_Tp> ret;
		std::set_difference(lh.cbegin(), lh.cend(), rh.cbegin(), rh.cend(),
			std::inserter(ret, ret.begin()));
		return ret;
	}
	template<typename _Tp>
	inline Set<_Tp> set_union(Set<_Tp> const& lh, Set<_Tp> const& rh) {
		Set<_Tp> ret;
		std::set_union(lh.cbegin(), lh.cend(), rh.cbegin(), rh.cend(),
			std::inserter(ret, ret.begin()));
		return ret;
	}
	template<typename _Tp>
	inline Set<_Tp> set_inter(Set<_Tp> const& lh, Set<_Tp> const& rh) {
		Set<_Tp> ret;
		std::set_intersection(lh.cbegin(), lh.cend(), rh.cbegin(), rh.cend(),
			std::inserter(ret, ret.begin()));
		return ret;
	}

	using Index = int;
	using Digit = char;
	
	using Selection = Set<Index>;
	using Choice = Set<Digit>;

	template<int GRADE_>
	struct GridLength {
		static const int v = GRADE_*GRADE_;
	};

	template<int GRADE_ = 3>
	Index xy2i(Index x, Index y) { return y % GridLength<GRADE_>::v * GridLength<GRADE_>::v + x % GridLength<GRADE_>::v; }
	template<int GRADE_ = 3>
	Index i2x(Index idx) { return idx % GridLength<GRADE_>::v; }
	template<int GRADE_ = 3>
	Index i2y(Index idx) { return idx / GridLength<GRADE_>::v; }

	template<int GRADE_ = 3>
	Selection traverse_index(Index idx) {
		Selection ret;
		Index y{ i2y<GRADE_>(idx) }, x{ i2x<GRADE_>(idx) };
		Index x0{ i2x<GRADE_>(idx) / GRADE_ * GRADE_ }, y0{ i2y<GRADE_>(idx) / GRADE_ * GRADE_ };
		for (int p = 0; p < GridLength<GRADE_>::v; ++p) {
			ret.insert(xy2i<GRADE_>(p, y));
			ret.insert(xy2i<GRADE_>(x, p));
		}
		for (int dx = 0; dx < GRADE_; ++dx) {
			for (int dy = 0; dy < GRADE_; ++dy) {
				ret.insert(xy2i<GRADE_>(x0 + dx, y0 + dy));
			}
		}
		//ret.erase(idx);
		return ret;
	}

	template<typename Tp_, int GRADE_ = 3>
	struct Grid : public std::array<Tp_, GRADE_*GRADE_*GRADE_*GRADE_> {
		static const int LEN = GridLength<GRADE_>::v;
		using base_type = std::array<Tp_, GRADE_*GRADE_*GRADE_*GRADE_>;
		using value_type = typename base_type::value_type;

		Set<value_type> traverse(Index idx) const {
			Set<value_type> ret;
			for (auto i : traverse_index<GRADE_>(idx)){
				ret.insert(this->at(i));
			}
			return ret;
		}

		value_type & grid(Index x, Index y) { return this->at(xy2i<GRADE_>(x, y)); }
		value_type const& grid(Index x, Index y) const { return this->at(xy2i<GRADE_>(x, y)); }
	};

	template<typename _Tp, int GRADE_>
	std::string to_string(Grid<_Tp, GRADE_> const& g) {
		u8string ret;
		for (size_t i = 0; i < g.size(); ++i) {
			ret.append(GRADE_*GRADE_+13, "(%d)%s", i, to_string(g[i]).c_str());
		}
		return std::move(ret.str());
	}

	template<>
	inline std::string to_string<>(Grid<Digit> const& g) {
		static const std::string line{ "+-----+-----+-----+\n" };
		std::string ret;
		ret.reserve(line.size() * 16);
		ret += "\n" + line;
		for (int y = 0; y < 9; ++y) {
			ret += "|";
			for (int x = 0; x < 9; ++x) {
				ret += g.grid(x, y);
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
}

#endif // !_ZKS_SUDOKU_DEF_H
