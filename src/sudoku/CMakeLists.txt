file(GLOB SUDOKU_SRC "./*.cpp")
file(GLOB SUDOKU_HEADER "./*.h")
file(GLOB SUDOKU_GAME "./game*.txt")

add_executable (sudoku ${SUDOKU_SRC} ${SUDOKU_HEADER})

target_link_libraries (sudoku ${ThirdPartyLibs})

install (TARGETS sudoku DESTINATION bin)
install (FILES Sudoku.ico DESTINATION share/icon)
#install (FILES sudoku.ini SodukuFrame.fbp DESTINATION etc)
install (FILES ${SUDOKU_GAME} DESTINATION doc)
