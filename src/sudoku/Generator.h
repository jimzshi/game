#ifndef ZKS_SUDOKU_GEN_H_
#define ZKS_SUDOKU_GEN_H_

#include "def.h"
#include "Solver.h"

#include <array>
#include <iosfwd>
#include <string>
#include <set>
#include <array>
#include <memory>
#include <random>

namespace zks {
	namespace game {
		namespace sudoku {


            enum SudokuLevel {
                EASY = 100,
                MEDIUM = 200,
                HARD = 400
            };

			class IGenerator {
			protected:
                std::unique_ptr<BalanceCounter> pSolver_;
            
			public:
                IGenerator() {
					pSolver_.reset(new BalanceCounter);
                    pSolver_->gate(2); //only return 0, 1, 2(multi solutions).
                    pSolver_->clear_board();
				}
				virtual ~IGenerator() {}

                int generate(SudokuLevel lvl);
				std::string puzzle();

			};

			

		}
	}
}



#endif //ZKS_SUDOKU_GEN_H_