#include "Solver.h"
#include "Generator.h"
#include "worker.h"

#include "libzks.h"

#include <iostream>
#include <fstream>
#include <thread>
#include <future>

using namespace std;

zks::simlog g_logger;

int main(int argc, char* argv[]) {
	if (argc < 4) {
		cerr << argv[0] << " [solve|generate|count] log.ini game-file" << endl;
		return 0;
	}
	g_logger.configure(argv[2]);
	g_logger.reset();

	zks::u8string cmd{argv[1]};
	cmd = cmd.tolower();
	ZKS_INFO(g_logger, "main", "read in command: %s %s %s %s", argv[0], argv[1], argv[2], argv[3]);
	if(cmd=="solve") {
		zks::game::sudoku::solve(zks::game::sudoku::solver_thread, argv[3]);
	} else if(cmd == "generate") {
		zks::game::sudoku::generate(zks::game::sudoku::generate_thread, 10);
	} else if(cmd == "count") {
		zks::game::sudoku::solve(zks::game::sudoku::count_thread, argv[3]);
	}

	return 0;
}
