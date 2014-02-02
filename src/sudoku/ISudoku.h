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
		void reset(std::string const& s) { puzzle_ = s; reset(); }
		bool read(std::istream& in);
		std::ostream& write(std::ostream& out) const { 
			out << board_str();
			return out;
		}
		digit_t      & cell(index_t x, index_t y) { return board_.grid(x, y); }
		digit_t const& cell(index_t x, index_t y) const { return board_.grid(x, y); }
		digit_t const& operator[](index_t idx) const { return board_[idx]; }
		digit_t      & at(index_t idx) { return board_.at(idx); }

		std::string board_str() const {
			return std::string{ board_.begin(), board_.end() };
		}
		std::string oppor_str() const {
			return to_string(opportunities_);
		}
		std::string const& puzzle_str() const { return puzzle_; }


		std::string board_str_ex() const {
			return to_string(board_);
		}
		std::string oppor_str_ex() const;
		std::string puzzle_str_ex() const;

	};


}
}
}

#endif //ZKS_ISUDOKU_H_