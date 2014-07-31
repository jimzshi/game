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
				std::shared_ptr<ISolver> pSolver_;
            
			public:
				static void seed_rand();

				IGenerator();
				IGenerator(ISolver* p) : IGenerator() {
					pSolver_.reset(p);
                    pSolver_->clear_board();
				}
				virtual ~IGenerator() {}

                int generate(SudokuLevel lvl);
				int fill_random(int num);
				std::string puzzle();

			};

			

		}
	}
}



#endif //ZKS_SUDOKU_GEN_H_