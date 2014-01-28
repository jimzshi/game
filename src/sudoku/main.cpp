#include "sudoku.h"

#include "libzks.h"

#include <iostream>
#include <fstream>
#include <thread>
#include <future>

using namespace std;

zks::simlog g_logger;

int main(int argc, char* argv[]) {
	if (argc < 3) {
		cerr << argv[0] << " log.ini game-file" << endl;
		return 0;
	}
	g_logger.configure(argv[1]);
	g_logger.reset();

	const int MAX_THREADS = 5;
	std::vector<std::future<bool>> res_vec;
	std::vector<zks::game::Sudoku> sudoku_vec;

	ifstream ifs(argv[2]);
	while (ifs.good()) {
		zks::StopWatch sw;
		sw.start("solve game");
		for (int i = 0; i < MAX_THREADS; ++i) {
			sudoku_vec.push_back(zks::game::Sudoku());
			sudoku_vec[i].read(ifs);
			g_logger << "\nGame(" << i << "): \n" << sudoku_vec[i].str() << "\n";
			res_vec.push_back(std::async(launch::async, &zks::game::Sudoku::solve, &sudoku_vec[i]));
		}
		g_logger.flush();
		for (int i = 0; i < MAX_THREADS; ++i) {
			ZKS_INFO(g_logger, "main", "tryit(%d)=%d", i, res_vec[i].get());
			g_logger << "\nSolution" << i << "): \n" << sudoku_vec[i].str() << "\n";
		}
		sw.tick("solved them.");
		ZKS_INFO(g_logger, "main", "%s", sw.u8str().data());
		
		break;
	}
	return 0;
}