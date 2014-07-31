#include "libzks.h"
#include "ISudoku.h"

extern zks::simlog g_logger;

namespace zks {
namespace game {
namespace sudoku {

    void ISudoku::reset() { 
        clear_board();
        if (puzzle_.size() != 81) {
            puzzle_.resize(81, '0');
        }
        int cnt = 0;
        for (auto c : puzzle_) {
            if (c<'0' || c>'9') continue;
            *(&board_[0][0] + cnt) = c - '0';
            if (++cnt == 81) break;
        }
        if (cnt != 81) {
            ZKS_DEBUG(g_logger, "WARN", "read only %d char < 81", cnt);
        }
    }

    bool ISudoku::read(std::istream& in) {
        puzzle_.clear();
        puzzle_.resize(81);
        size_t cnt{ 0 };
        char c;
        while (in.get(c)) {
            if (c<'0' || c>'9') continue;
            *(&board_[0][0] + cnt) = c - '0';
            puzzle_[cnt] = c - '0';
            if (++cnt == 81) break;
        }
        return cnt == 81 ? true : false;
    }

    int* ISudoku::calc_freq(index_t x, index_t y) const {
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
    bool ISudoku::validate() const {
        digit_t checker[10];
        for (index_t r = 0; r < 9; ++r) {
            std::fill_n(checker, 10, 0);
            for (index_t i = 0; i < 9; ++i) {
                if (board_[r][i]<0 || board_[r][i]>9 || (board_[r][i] && ++checker[board_[r][i]] > 1)) {
                    return false;
                }
            }
        }
        for (index_t c = 0; c < 9; ++c) {
            std::fill_n(checker, 10, 0);
            for (index_t i = 0; i < 9; ++i) {
                if (board_[i][c]<0 || board_[i][c]>9 || (board_[i][c] && ++checker[board_[i][c]] > 1)) {
                    return false;
                }
            }
        }
        digit_t d;
        for (index_t b = 0; b < 9; ++b) {
            std::fill_n(checker, 10, 0);
            index_t x0(b / 3 * 3), y0((b % 3) * 3);
            for (index_t i = 0; i < 3; ++i) {
                for (index_t j = 0; j < 3; ++j) {
                    d = board_[x0 + i][y0 + j];
                    if (d < 0 || d>9 || (d && ++checker[d] > 1)) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool ISudoku::equal_freq(index_t idx1, index_t idx2) {
        int* freq1 = get_freq(idx1);
        int* freq2 = get_freq(idx2);
        for (int i = 1; i < 10; ++i) {
            if ((freq1[i] == 0) ^ (freq2[i] == 0)) {
                return false;
            }
        }
        return true;
    }

    std::string ISudoku::board_str() const {
        static const std::string line{ "+-----+-----+-----+\n" };
        std::string ret;
        ret.reserve(line.size() * 16);
        ret += "\n" + line;
        for (int x = 0; x < 9; ++x) {
            ret += "|";
            for (int y = 0; y < 9; ++y) {
                ret += to_string(grid(x, y));
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
}
}
}
