#include "libzks.h"
#include "ISudoku.h"

extern zks::simlog g_logger;

namespace zks {
namespace game {
namespace sudoku {

    void ISudoku::reset() { 
        for (int i = 0; i < 81; ++i) {
            *(&board_[0][0] + i) = 0;
        }
        int cnt = 0;
        if (puzzle_.size() != 81) {
            puzzle_.resize(81, '0');
        }
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
}
}
}
