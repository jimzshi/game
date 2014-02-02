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


			class IGenerator {
			protected:
				static std::mt19937 rand_;
				std::shared_ptr<ISolver> pSolver_;
				Selection left_cells_;

			public:
				static void seed_rand();

				IGenerator();
				IGenerator(ISolver* p) : IGenerator() {
					pSolver_.reset(p);
				}
				virtual ~IGenerator() {}

				int generate(int start);
				int fill_random(int num);
				std::string puzzle();

			};

			

		}
	}
}



#endif //ZKS_SUDOKU_GEN_H_