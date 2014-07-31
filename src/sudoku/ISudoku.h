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

    class ISudoku {
    protected:
        std::string puzzle_;
        digit_t board_[9][9];
        mutable int freq_[9][9][10];

        int* calc_freq(index_t x, index_t y) const;
        bool validate() const;
        int* get_freq(index_t x, index_t y) const { return freq_[x][y]; }
        int* get_freq(index_t i) const { return &freq_[0][0][0] + i * 10; }
        bool equal_freq(index_t idx1, index_t idx2);
    public:
        ISudoku() : ISudoku("") {}
        ISudoku(std::string const& s) : puzzle_(s) { reset(); }
        virtual ~ISudoku() {}

        virtual void    reset();
        void            reset(std::string const& s) { puzzle_ = s; reset(); }
        bool            read(std::istream& in);
        std::ostream&   write(std::ostream& out) const { return out << str(); }
        
        void           clear_board() { std::fill_n(&board_[0][0], 81, 0); }
        digit_t      & grid(index_t x, index_t y) { return board_[x][y]; }
        digit_t const& grid(index_t x, index_t y) const { return board_[x][y]; }
        digit_t const& grid(index_t idx) const { return *(&board_[0][0] + idx); }
        digit_t      & grid(index_t idx) { return *(&board_[0][0] + idx); }

        std::string board_str() const;
        std::string const& puzzle_str() const { return puzzle_; }
        std::string freq_str() const { return to_string(freq_); }
        std::string str() const { return to_string(board_); }
    };


}
}
}

#endif //ZKS_ISUDOKU_H_