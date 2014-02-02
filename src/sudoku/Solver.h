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


	class IGenerator;

	class ISolver : protected ISudoku {
		friend class IGenerator;

	protected:
		virtual int find_oppor_impl(index_t from, index_t to) = 0;
		virtual int solve_impl(index_t start) = 0;

	public:
		ISolver() : ISudoku() { }
		ISolver(std::string const& s) : ISudoku(s) {}
		virtual ~ISolver() {}

		choice_t choices(index_t i) const {
			return set_diff<digit_t>(full_set, board_.traverse(i));
		}
		int rank(digit_t d, index_t i);
		digit_t pop_top(choice_t& g, index_t i);

		int find_opportunites(int from, int to) {
			return find_oppor_impl(from, to);
		}
		int solve() {
			return solve_impl(0);
		}

		using ISudoku::reset;

		using ISudoku::board_str;
		using ISudoku::oppor_str;
		using ISudoku::puzzle_str;
		using ISudoku::board_str_ex;
		using ISudoku::oppor_str_ex;
		using ISudoku::puzzle_str_ex;
	};

	class BrutalSolver : public ISolver {
	public:
		BrutalSolver() : ISolver() {}
		BrutalSolver(std::string const& s) : ISolver(s) {}
		virtual ~BrutalSolver() {}
	protected:
		virtual int find_oppor_impl(index_t from, index_t to);
		virtual int solve_impl(index_t start);
	};

	class GreedySolver : public ISolver {
	public:
		GreedySolver() : ISolver() {}
		GreedySolver(std::string const& s) : ISolver(s) {}
		virtual ~GreedySolver() {}
	protected:
		virtual int find_oppor_impl(index_t from, index_t to);
		virtual int solve_impl(index_t start);
	};

	class BalanceSolver : public ISolver {
	public:
		BalanceSolver() : ISolver() {}
		BalanceSolver(std::string const& s) : ISolver(s) {}
		virtual ~BalanceSolver() {}
	protected:
		virtual int find_oppor_impl(index_t from, index_t to);
		virtual int solve_impl(index_t start);
	};

	class CountSolver : public BalanceSolver {
	public:
		CountSolver() : CountSolver("", -1) {}
		CountSolver(std::string const& s, int gate = -1) : BalanceSolver(s), count_(0), gate_(gate) {}
		virtual ~CountSolver() {}
		virtual void reset() {
			BalanceSolver::reset();
			count_ = 0;
		}
		int count_solve() { solve_impl(0); return count_; }
		int count() const { return count_; }
		int gate(int g) { int old = gate_; gate_ = g; return old; }
		int gate() const { return gate_; }

	protected:
		virtual int solve_impl(index_t start);
		int count_;
		int gate_;
	};

}
}
}



#endif //ZKS_SOLVER_H_