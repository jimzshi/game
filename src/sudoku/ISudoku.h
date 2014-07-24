#ifndef ZKS_ISUDOKU_H_
#define ZKS_ISUDOKU_H_

#include "def.h"

#include <array>
#include <iosfwd>
#include <string>
#include <set>
#include <array>
#include <algorithm>

namespace zks {
namespace game {
namespace sudoku {

    struct ISudoku {
        std::string puzzle_;
        digit_t board_[9][9];
        mutable int freq_[9][9][10];

    public:
        ISudoku() : ISudoku("") {}
        ISudoku(std::string const& s) : puzzle_(s) { reset(); }
        virtual ~ISudoku() {}

        virtual void reset();
        void reset(std::string const& s) { puzzle_ = s; reset(); }
        bool read(std::istream& in);
        std::ostream& write(std::ostream& out) const { 
            out << str();
            return out;
        }
        digit_t      & grid(index_t x, index_t y) { return board_[x][y]; }
        digit_t const& grid(index_t x, index_t y) const { return board_[x][y]; }
        digit_t const& grid(index_t idx) const { return *(&board_[0][0] + idx); }
        digit_t      & grid(index_t idx) { return *(&board_[0][0] + idx); }

        int* calc_freq(index_t x, index_t y) const {
            std::fill_n(freq_[x][y], 10, 0);
            for (index_t i = 0; i < 9; ++i) {
                *(freq_[x][y] + board_[x][i]) += 1;
                *(freq_[x][y] + board_[i][y]) += 1;
            }
            index_t x0(x / 3 * 3), y0(y / 3 * 3);
            for (index_t i = 0; i < 3; ++i) {
                for (index_t j = 0; j < 3; ++j) {
                    *(freq_[x][y] + board_[x0 + i][y0 + j]) += 1;
                }
            }
            return freq_[x][y];
        }
        int* get_freq(index_t x, index_t y) const {
            return freq_[x][y];
        }
        int* get_freq(index_t i) const {
            return &freq_[0][0][0] + i * 10;
        }
        bool equal_freq(index_t idx1, index_t idx2) {
            int* freq1 = get_freq(idx1);
            int* freq2 = get_freq(idx2);
            for (int i = 1; i < 10; ++i) {
                if ((freq1[i] == 0) ^ (freq2[i] == 0)) {
                    return false;
                }
            }
            return true;
        }

        std::string board_str() const {
            static const std::string line{ "+-----+-----+-----+\n" };
            std::string ret;
            ret.reserve(line.size() * 16);
            ret += "\n" + line;
            for (int x = 0; x < 9; ++x) {
                ret += "|";
                for (int y = 0; y < 9; ++y) {
                    ret += to_string(grid(x,y));
                    if (y == 2 || y == 5 || y == 8) {
                        ret += "|";
                    }
                    else {
                        ret += " ";
                    }
                }
                ret += "\n";
                if (x == 2 || x == 5 || x == 8) {
                    ret += line;
                }
            }
            return ret;
        }
        std::string const& puzzle_str() const { return puzzle_; }
        std::string freq_str() const { return to_string(freq_); }
        std::string str() const { return to_string(board_); }

    };


}
}
}

#endif //ZKS_ISUDOKU_H_