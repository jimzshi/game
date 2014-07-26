#ifndef _ZKS_SUDOKU_DEF_H
#define _ZKS_SUDOKU_DEF_H

#include "libzks/u8string.h"

#include <array>
#include <set>
#include <algorithm>
#include <iterator>
#include <string>

namespace zks {
namespace game {
namespace sudoku{

    using std::to_string;

    using index_t = int;
    using digit_t = int;
    
    inline
    std::string to_string(const digit_t* p, int sz) {
        std::string ret;
        ret.reserve(4 * sz);
        for (int i = 0; i < sz; ++i) {
            ret += to_string(*(p + i));
        }
        return ret;
    }


    inline
    std::string to_string(const digit_t g[9][9]) {
        int size = 9 * 9;
        std::string ret(size, '0');
        for (int i = 0; i < size; ++i) {
            ret[i] += *(&g[0][0] + i);
        }
        return ret;
    }
    //template<int _Len, int _Digits>
    //std::string to_string(const digit_t g[_Len][_Len][_Digits]) {
    //    std::string ret;
    //    ret.reserve(_Len * _Len * _Digits * 8);
    //    for (int i = 0; i < _Len; ++i) {
    //        for (int j = 0; j < _Len; ++j) {
    //            ret += '(' + to_string(i) + ',' + to_string(j) + ')';
    //            ret += '{' + to_string(g[i][j], _Len) + '}';
    //        }
    //    }
    //    return ret;
    //}

    inline std::string to_string(const digit_t g[9][9][10]) {
        static const std::string line{ "+-----+-----+-----+\n" };
        std::string ret;
        ret.reserve(line.size() * 16);
        ret += "\n" + line;
        for (int y = 0; y < 9; ++y) {
            ret += "|";
            for (int x = 0; x < 9; ++x) {
                ret += to_string(g[x][y], 9);
                if (x == 2 || x == 5 || x == 8) {
                    ret += "|";
                }
                else {
                    ret += " ";
                }
            }
            ret += "\n";
            if (y == 2 || y == 5 || y == 8) {
                ret += line;
            }
        }
        return ret;
    }

}
}
}

#endif // !_ZKS_SUDOKU_DEF_H
