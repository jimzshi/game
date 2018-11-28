file(GLOB guess_SRC "./*.cpp")
file(GLOB guess_HEADER "./*.h")
file(GLOB guess_GAME "./game*.txt")

add_executable (guess ${guess_SRC} ${guess_HEADER})

target_link_libraries (guess ${ThirdPartyLibs})

install (TARGETS guess DESTINATION bin)
install (FILES guess.ico DESTINATION share/icon)
#install (FILES sudoku.ini IGuessFrame.fbp DESTINATION etc)
#install (FILES ${guess_GAME} DESTINATION doc)
