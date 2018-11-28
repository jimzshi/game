file(GLOB TXT_SRC "./*.cpp")
file(GLOB TXT_HEADER "./*.h")
file(GLOB TXT_RSC "./*.rc")

include_directories (${ZKS_INCLUDE_DIR}/libzks ${wxWidgets_INCLUDE_DIRS})

add_executable (TxtConverter ${TXT_RSC} ${TXT_SRC} ${TXT_HEADER})

target_link_libraries (TxtConverter ${ThirdPartyLibs})

install (TARGETS TxtConverter DESTINATION bin)
install (FILES TxtConverter.ico DESTINATION share/icon)
install (DIRECTORY en zh_CN DESTINATION share/locale)
install (FILES TxtConverter.ini DESTINATION etc)
install (FILES ${TXT_GAME} DESTINATION doc)
