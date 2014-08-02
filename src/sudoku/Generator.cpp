#include "libzks.h"
#include "Generator.h"

#include "Solver.h"

#include <string>
#include <random>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>


extern zks::simlog g_logger;

namespace zks {
namespace game {
namespace sudoku {

    /*
    >1 more than 1 solutions;
    == 1 only 1 solutions;
    < 1 no solution;
    */
    int IGenerator::generate(SudokuLevel lvl) {
        ZKS_DEBUG(g_logger, "generator", "\nBoard:\n%s", pSolver_->board_str().c_str());
        //ZKS_DEBUG(g_logger, "generator", "start=%d", start);
        //auto choices = pSolver_->choices(start);
        //if (choices.size() == 0) {
        //    return 0;
        //}

        //left_cells_.erase(start);
        //while (choices.size() > 0) {
        //    auto choice_iter = choices.begin();
        //    std::advance(choice_iter, rand_() % choices.size());
        //    ZKS_DEBUG(g_logger, "generator", "fill '%c' in %d", *choice_iter, start);
        //    pSolver_->at(start) = *(choice_iter);
        //    auto tmp = pSolver_->board_;
        //    zks::StopWatch sw;
        //    sw.start("solve");
        //    int solv_ret = pSolver_->solve();
        //    sw.tick("finished");
        //    ZKS_DEBUG(g_logger, "generator", "solution number: %d, time: %d", solv_ret, sw.duration(1).count());
        //    if (solv_ret == 1) {
        //        //ZKS_DEBUG(g_logger, "generator", "it works!");
        //        ZKS_DEBUG(g_logger, "generator", "FOUND: %s", std::string(tmp.begin(), tmp.end()).c_str());
        //        return 1;
        //    }
        //    pSolver_->reset();
        //    pSolver_->board_ = std::move(tmp);
        //    if (solv_ret < 1) {
        //        ZKS_DEBUG(g_logger, "generator", "there's no solution. skip '%c' and continue next trial.", *choice_iter);
        //        choices.erase(choice_iter);
        //        continue;
        //    }
        //    ZKS_DEBUG(g_logger, "generator", "%s", "too many solutions, generate recursively.");
        //    auto next_iter = left_cells_.begin();
        //    std::advance(next_iter, rand_() % left_cells_.size());
        //    if (generate(*next_iter) == 1) {
        //        return 1;
        //    }
        //    choices.erase(choice_iter);
        //}
        //left_cells_.insert(start);
        return 0;
    }

    std::string IGenerator::puzzle() {
        //pSolver_->reset("");
        //left_cells_.clear();
        //for (Index i = 0; i < 81; ++i) {
        //	left_cells_.insert(i);
        //}
        //int ret = generate(0);
        //return ret==1 ? pSolver_->board_str() : std::string(81, '0');
        return "";
    }

}
}
}
