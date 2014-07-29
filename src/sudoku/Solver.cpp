#include "libzks.h"

#include "Solver.h"

#include <iterator>
#include <algorithm>

extern zks::simlog g_logger;

namespace zks {
namespace game {
namespace sudoku {

    int ISolver::freq(digit_t d, index_t x, index_t y) {
        if (d < 1 || d>9) {
            return -1;
        }
        return *(calc_freq(x, y) + d);
    }
    digit_t ISolver::pop_top(digit_t* g, index_t x, index_t y) {
        auto iter = std::max_element(g, g + 9);
        if (*iter < 1)
            return 0;
        *iter = 0;
        return std::distance(g, iter);
    }

    int BrutalSolver::find_oppor_impl(int from, int to) {
        for (int i = from; i < to; ++i) {
            if (grid(i) != 0) {
                continue;
            }
            int* freq = calc_freq(i / 9, i % 9);
            for (int d = 1; d < 10; ++d) {
                if (freq[d] == 0) {
                    return i;
                }
            }
            return -1;
        }
        return -2;
    }
    
    int BrutalSolver::solve_impl(int start) {
        ++complexity_;
        int next = find_opportunites(start, 81);
        ZKS_DEBUG(g_logger, "solver", "\nBoard:%s", board_str().c_str());
        ZKS_DEBUG(g_logger, "solver", "freq:%s", freq_str().c_str());
        ZKS_DEBUG(g_logger, "solver", "next=%d, next_x=%d, next_y=%d", next, next / 9, next % 9);
        if (next == -1) {
            return -1;
        }
        else if (next == -2) {
            return 1;
        }
        int* freq = get_freq(next);
        for (int d = 1; d <= 9; ++d) {
            if (freq[d] != 0) {
                continue;
            }
            ZKS_DEBUG(g_logger, "solver", "choose %d for (%d, %d)", d, next / 9, next % 9);
            grid(next) = d;
            if (solve_impl(next + 1) > 0) {
                ZKS_DEBUG(g_logger, "solver", "%d solve it!", d);
                return 1;
            }
            ZKS_DEBUG(g_logger, "solver", "%d failed", d);
        }
        grid(next) = 0;
        return 0;
    }

    int BalanceSolver::find_oppor_impl(int from, int to) {
        int mins{ 11 };
        int mini{ -1 };
        bool finish_all{ true };
        int index[81];
        std::fill_n(index, 81, 81);
        int oppor_size[82];
        std::fill_n(oppor_size, 81, -1);
        oppor_size[81] = 99;
        int* freq;
        for (int i = from; i < to; ++i) {
            if (grid(i) != 0) {
                continue;
            }
            finish_all = false;
            index[i] = i;
            freq = calc_freq(i/9, i%9);
            oppor_size[i] = std::count_if(freq + 1, freq + 10, [](int f){ return f == 0; });
            if (oppor_size[i] == 0) {
                return -1;
            }
            if (oppor_size[i] < mins) {
                mins = oppor_size[i];
                mini = i;
            }
        }
        if (finish_all) {
            return -2;
        }
        std::sort(index + from, index + to, [&](int i, int j){
            return oppor_size[i] < oppor_size[j];
        });
        int *beg, *end;
        std::tie(beg, end) = std::equal_range(index + from, index + to, mini, 
            [&](int idx1, int idx2){ return oppor_size[idx1] < oppor_size[idx2]; });
        if (std::distance(beg, end) == 1) {
            return *beg;
        }
        for (auto iter = beg; iter != end; ++iter) {
            if (std::any_of(iter + 1, end, [&](int idx){ return equal_freq(idx, *iter); })) {
                return *iter;
            }
        }
        return *beg;
    }
    int BalanceSolver::solve_impl(int start) {
        ++complexity_;
        int next = find_opportunites(start, 81);
        ZKS_DEBUG(g_logger, "solver", "\nBoard:%s", board_str().c_str());
        ZKS_DEBUG(g_logger, "solver", "freq:%s", freq_str().c_str());
        ZKS_DEBUG(g_logger, "solver", "next=%d, next_x=%d, next_y=%d", next, next / 9, next % 9);
        if (next == -1) {
            return -1;
        }
        else if (next == -2) {
            return 1;
        }
        int* freq = get_freq(next);
        for (int d = 1; d <= 9; ++d) {
            if (freq[d] != 0) {
                continue;
            }
            ZKS_DEBUG(g_logger, "solver", "choose %d for (%d, %d)", d, next / 9, next % 9);
            grid(next) = d;
            if (solve_impl(0) > 0) {
                ZKS_DEBUG(g_logger, "solver", "%d solve it!", d);
                return 1;
            }
            ZKS_DEBUG(g_logger, "solver", "%d failed", d);
        }
        grid(next) = 0;
        return 0;
    }

    int CountSolver::solve_impl(int start) {
        int next = find_opportunites(0, 81);
        ZKS_DEBUG(g_logger, "solver", "\nBoard:%s", board_str().c_str());
        ZKS_DEBUG(g_logger, "solver", "freq:%s", freq_str().c_str());
        ZKS_DEBUG(g_logger, "solver", "next=%d, next_x=%d, next_y=%d", next, next / 9, next % 9);
        if (next == -1) {
            return -1;
        }
        else if (next == -2) {
            ++count_;
            ZKS_DEBUG(g_logger, "solver", "solution(%d): %s", count_, board_str().c_str());
            return count_;
        }

        int* freq = get_freq(next);
        for (int d = 1; d <= 9; ++d) {
            if (freq[d] != 0) {
                continue;
            }
            ZKS_DEBUG(g_logger, "solver", "choose %d for (%d, %d)", d, next / 9, next % 9);
            grid(next) = d;
            solve_impl(0);
            if (gate_ > 0 && count_ >= gate_) {
                return count_;
            }
        }
        grid(next) = 0;
        return count_;
    }

}
}
}
