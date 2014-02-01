#ifndef ZKS_ISUDOKU_H_
#define ZKS_ISUDOKU_H_

#include "def.h"

#include <array>
#include <iosfwd>
#include <string>
#include <set>
#include <array>

namespace zks {
namespace game {
namespace sudoku {

	struct ISudoku {
		typedef Index	index_t;
		typedef Choice	choice_t;
		typedef Digit	digit_t;
		using board_t = sudoku::Grid<digit_t, 3>;
		using oppor_t = sudoku::Grid<choice_t, 3>;

		static const choice_t full_set;

		std::string puzzle_;
		board_t board_;
		oppor_t opportunities_;

	public:
		ISudoku() : ISudoku("") {}
		ISudoku(std::string const& s) : puzzle_(s) { reset(); }
		virtual ~ISudoku() {}
		virtual void reset();

		bool read(std::istream& in);
		bool write(std::ostream& out) const;
		digit_t      & cell(int x, int y) { return board_.grid(x, y); }
		digit_t const& cell(int x, int y) const { return board_.grid(x, y); }
		std::string board_str() const;
		std::string oppor_str() const;
		std::string const& puzzle_str() const { return puzzle_;  }
		std::string solution_str() const {
			return std::string{ board_.begin(), board_.end() };
		}
	};


}
}
}

#endif //ZKS_ISUDOKU_H_