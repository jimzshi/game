#include "sudoku.h"

#include "libzks.h"

#include <iostream>
#include <fstream>

using namespace std;

zks::simlog g_logger;

int main(int argc, char* argv[]) {
	if (argc < 3) {
		cerr << argv[0] << " log.ini game-file" << endl;
		return 0;
	}
	g_logger.configure(argv[1]);
	g_logger.reset();

	zks::game::Sudoku sudoku;
	ifstream ifs(argv[2]);
	while (ifs.good()) {
		sudoku.read(ifs);
		g_logger << "\nGame: \n" << sudoku.str() << "\n";
	}
	return 0;
}