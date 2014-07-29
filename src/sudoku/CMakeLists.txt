file(GLOB SUDOKU_SRC "./*.cpp")
file(GLOB SUDOKU_HEADER "./*.h")
file(GLOB SUDOKU_GAME "./game*.txt")

include_directories (${ZKS_INCLUDE_DIR}/libzks ${wxWidgets_INCLUDE_DIRS})

if(wxWidgets_FOUND)
    SET(_gui_flag USE_GUI )
endif(wxWidgets_FOUND)

add_executable (sudoku ${SUDOKU_SRC} )
SET_TARGET_PROPERTIES(sudoku PROPERTIES COMPILE_DEFINITIONS "${_gui_flag};${wxWidgets_DEFINITIONS};_WCHAR_H_CPLUSPLUS_98_CONFORMANCE_")
target_link_libraries (sudoku ${ZKS_LIBRARY} ${CMAKE_THREAD_LIBS_INIT} ${wxWidgets_LIBRARIES} $<$<CXX_COMPILER_ID:Clang>:c++>)

install (TARGETS sudoku DESTINATION bin)
install (FILES sudoku.ini DESTINATION etc)
install (FILES ${SUDOKU_GAME} DESTINATION doc)
