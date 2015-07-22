file(GLOB guess_SRC "./*.cpp")
file(GLOB guess_HEADER "./*.h")
file(GLOB guess_GAME "./game*.txt")

include_directories (${ZKS_INCLUDE_DIR}/libzks ${wxWidgets_INCLUDE_DIRS})

if(wxWidgets_FOUND)
    SET(_gui_flag USE_GUI )
endif(wxWidgets_FOUND)

add_executable (guess ${guess_SRC} ${guess_HEADER})
SET_TARGET_PROPERTIES(guess PROPERTIES COMPILE_DEFINITIONS "${_gui_flag};${wxWidgets_DEFINITIONS};_WCHAR_H_CPLUSPLUS_98_CONFORMANCE_")
target_link_libraries (guess ${ZKS_LIBRARY} ${CMAKE_THREAD_LIBS_INIT} ${wxWidgets_LIBRARIES})

install (TARGETS guess DESTINATION bin)
install (FILES guess.ico DESTINATION bin)
#install (FILES sudoku.ini IGuessFrame.fbp DESTINATION etc)
#install (FILES ${guess_GAME} DESTINATION doc)
