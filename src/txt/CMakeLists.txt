file(GLOB TXT_SRC "./*.cpp")
file(GLOB TXT_HEADER "./*.h")
file(GLOB TXT_RSC "./*.rc")

include_directories (${ZKS_INCLUDE_DIR}/libzks ${wxWidgets_INCLUDE_DIRS})

if(wxWidgets_FOUND)
    SET(_gui_flag USE_GUI )
endif(wxWidgets_FOUND)

add_executable (TxtConverter ${TXT_RSC} ${TXT_SRC} ${TXT_HEADER})
SET_TARGET_PROPERTIES(TxtConverter PROPERTIES COMPILE_DEFINITIONS "${_gui_flag};${wxWidgets_DEFINITIONS};_WCHAR_H_CPLUSPLUS_98_CONFORMANCE_")
target_link_libraries (TxtConverter ${ZKS_LIBRARY} ${CMAKE_THREAD_LIBS_INIT} ${wxWidgets_LIBRARIES})

install (TARGETS TxtConverter DESTINATION bin)
install (FILES TxtConverter.ico DESTINATION share/icon)
install (DIRECTORY en zh_CN DESTINATION share/locale)
install (FILES TxtConverter.ini ITxtConverter.fbp DESTINATION etc)
install (FILES ${TXT_GAME} DESTINATION doc)
