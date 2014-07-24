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

                const digit_t* choices(digit_t x, index_t y) const {
                    return this->calc_freq(x, y);
                }
                const digit_t* choices(index_t i) const {
                    return this->calc_freq(i / 9, i % 9);
                }
                int freq(digit_t d, index_t i) {
                    return freq(d, i / 9, i % 9);
                }
                int freq(digit_t d, index_t x, index_t y);
                digit_t pop_top(digit_t* g, index_t i) {
                    return pop_top(g, i / 9, i % 9);
                }
                digit_t pop_top(digit_t* g, index_t x, index_t y);

                int find_opportunites(int from, int to) {
                    return find_oppor_impl(from, to);
                }
                int solve() {
                    return solve_impl(0);
                }

                using ISudoku::reset;

                using ISudoku::board_str;
                using ISudoku::freq_str;
                using ISudoku::puzzle_str;
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