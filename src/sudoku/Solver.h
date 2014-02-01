#ifndef ZKS_SOLVER_H_
#define ZKS_SOLVER_H_

#include "ISudoku.h"

#include <array>
#include <iosfwd>
#include <string>
#include <set>
#include <array>

namespace zks {
namespace game {
namespace sudoku {


	class ISolver : protected ISudoku {
	protected:
		choice_t choices(index_t i) const {
			return set_diff<digit_t>(full_set, board_.traverse(i));
		}
		int rank(digit_t d, index_t i);
		digit_t pop_top(choice_t& g, index_t i);
	
		virtual int find_oppor_impl(index_t from, index_t to) = 0;
		virtual bool solve_impl(index_t start) = 0;

	public:
		ISolver() : ISudoku() { }
		ISolver(std::string const& s) : ISudoku(s) {}
		virtual ~ISolver() {}

		int find_opportunites(int from, int to) {
			return find_oppor_impl(from, to);
		}
		bool solve() {
			return solve_impl(0);
		}
		using ISudoku::board_str;
		using ISudoku::oppor_str;
		using ISudoku::puzzle_str;
		using ISudoku::solution_str;
	};

	class BrutalSolver : public ISolver {
	public:
		BrutalSolver() : ISolver() {}
		BrutalSolver(std::string const& s) : ISolver(s) {}
		virtual ~BrutalSolver() {}
	protected:
		virtual int find_oppor_impl(index_t from, index_t to);
		virtual bool solve_impl(index_t start);
	};

	class GreedySolver : public ISolver {
	public:
		GreedySolver() : ISolver() {}
		GreedySolver(std::string const& s) : ISolver(s) {}
		virtual ~GreedySolver() {}
	protected:
		virtual int find_oppor_impl(index_t from, index_t to);
		virtual bool solve_impl(index_t start);
	};

	class BalanceSolver : public ISolver {
	public:
		BalanceSolver() : ISolver() {}
		BalanceSolver(std::string const& s) : ISolver(s) {}
		virtual ~BalanceSolver() {}
	protected:
		virtual int find_oppor_impl(index_t from, index_t to);
		virtual bool solve_impl(index_t start);
	};

	class CountSolver : public BalanceSolver {
	public:
		CountSolver() : CountSolver("") {}
		CountSolver(std::string const& s) : BalanceSolver(s), count_(0) {}
		virtual ~CountSolver() {}

		int count_solve() { solve_impl(0); return count_; }
		int count() const { return count_; }
	protected:
		virtual bool solve_impl(index_t start);
		int count_;
	};

}
}
}



#endif //ZKS_SOLVER_H_