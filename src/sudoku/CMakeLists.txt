file(GLOB SUDOKU_SRC "./*.cpp")
file(GLOB SUDOKU_HEADER "./*.h")
file(GLOB SUDOKU_GAME "./game*.txt")

include_directories (${ZKS_INCLUDE_DIR} ${wxWidgets_INCLUDE_DIRS})

add_executable (sudoku ${SUDOKU_SRC} )
SET_TARGET_PROPERTIES(sudoku PROPERTIES COMPILE_DEFINITIONS "USE_GUI")
target_link_libraries (sudoku ${ZKS_LIBRARY} ${wxWidgets_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} $<$<CXX_COMPILER_ID:Clang>:c++>)

install (TARGETS sudoku DESTINATION bin)
install (FILES sudoku.ini DESTINATION etc)
install (FILES ${SUDOKU_GAME} DESTINATION doc)
