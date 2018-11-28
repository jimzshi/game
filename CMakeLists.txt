cmake_minimum_required (VERSION 2.6) 
project(ZksGame)

if(NOT CMAKE_BUILD_TYPE)
    set( CMAKE_BUILD_TYPE Release )
endif(NOT CMAKE_BUILD_TYPE)
string(TOLOWER ${CMAKE_BUILD_TYPE} CONFIG)
set( CMAKE_DEBUG_POSTFIX "d" )


if(CMAKE_CXX_COMPILER_ID STREQUAL Clang)
    string(CONCAT CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} " -lc++")
endif(CMAKE_CXX_COMPILER_ID STREQUAL Clang)

if(MSVC)
    string(CONCAT CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} " -D_SCL_SECURE_NO_WARNINGS -D_CRT_SECURE_NO_WARNINGS")
    
    option(MSVC_LINK_STATIC_LIB "use /MT(d) for code generation." on)
    if(MSVC_LINK_STATIC_LIB)
        string(CONCAT CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} " -D_SCL_SECURE_NO_WARNINGS -D_CRT_SECURE_NO_WARNINGS")
        foreach(CompilerFlag
                CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
                CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO
                CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE
                CMAKE_C_FLAGS_MINSIZEREL CMAKE_C_FLAGS_RELWITHDEBINFO)
        if(${CompilerFlag} MATCHES "/MD")
                string(REPLACE "/MD" "/MT" ${CompilerFlag} "${${CompilerFlag}}")
        endif(${CompilerFlag} MATCHES "/MD")
        endforeach(CompilerFlag)
    endif()
endif()

string(CONCAT CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS_DEBUG} " -DDEBUG -D_DEBUG")
string(CONCAT CMAKE_CXX_FLAGS_RELEASE ${CMAKE_CXX_FLAGS_RELEASE} " -D_NDEBUG -DZKS_DISABLE_TRIVIAL_LOG")

add_compile_options ($<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:GNU>>:-std=c++1y>)
add_compile_options ($<$<CXX_COMPILER_ID:Clang>:-stdlib=libc++>)

MESSAGE(STATUS "CONFIG : ${CONFIG}")
MESSAGE(STATUS "CMAKE_BUILD_TYPE : ${CMAKE_BUILD_TYPE}")
MESSAGE(STATUS "CMAKE_CXX_COMPILER_ID : ${CMAKE_CXX_COMPILER_ID}")
MESSAGE(STATUS "CMAKE_CXX_FLAGS_DEBUG : ${CMAKE_CXX_FLAGS_DEBUG}")
MESSAGE(STATUS "CMAKE_CXX_FLAGS_RELEASE : ${CMAKE_CXX_FLAGS_RELEASE}")
MESSAGE(STATUS "CMAKE_STANDARD_LIBRARIES : ${CMAKE_STANDARD_LIBRARIES}")
MESSAGE(STATUS "CMAKE_EXE_LINKER_FLAGS : ${CMAKE_EXE_LINKER_FLAGS}")
MESSAGE(STATUS "CMAKE_DEBUG_POSTFIX : ${CMAKE_DEBUG_POSTFIX}")

set( CMAKE_DEBUG_TARGET_PROPERTIES on )
set( CMAKE_VERBOSE_MAKEFILE on )

######################### libzks ##################################

FIND_PATH(ZKS_INCLUDE_DIR
  libzks/libzks.h
  PATHS
  "$ENV{HOME}/local/"
  "$ENV{ProgramFiles}/libzks/"
  /usr/
  /usr/local/
  #MSVC
  "$ENV{LIB_DIR}"
  "$ENV{UserProfile}/local/"
  $ENV{ZKS_INCLUDE_PATH}
  #mingw
  c:/msys/local
  PATH_SUFFIXES include
  )

FIND_LIBRARY(ZKS_LIB_D NAMES zksd libzksd PATHS 
    /usr/local/lib 
    /usr/lib 
    "$ENV{HOME}/local/lib"
    "$ENV{ProgramFiles}/libzks/"
    #MSVC
    "$ENV{UserProfile}/local/lib"
    "$ENV{LIB_DIR}/lib"
    $ENV{ZKS_LIB_PATH}
    #mingw
    c:/msys/local/lib
    PATH_SUFFIXES lib
    )
FIND_LIBRARY(ZKS_LIB NAMES zks libzks PATHS 
    /usr/local
    /usr
    "$ENV{HOME}/local"
    "$ENV{ProgramFiles}/libzks"
    #MSVC
    "$ENV{UserProfile}/local"
    "$ENV{LIB_DIR}"
    $ENV{ZKS_LIB_PATH}
    #mingw
    c:/msys/local
    PATH_SUFFIXES lib
    )

string(CONCAT ZKS_LIBRARY "debug;" ${ZKS_LIB_D} ";general;" ${ZKS_LIB} )

IF (ZKS_INCLUDE_DIR AND ZKS_LIBRARY)
   SET(ZKS_FOUND TRUE)
ENDIF (ZKS_INCLUDE_DIR AND ZKS_LIBRARY)

IF (ZKS_FOUND)
   IF (NOT ZKS_FIND_QUIETLY)
      MESSAGE(STATUS "Found libzks : ${ZKS_LIBRARY}")
      MESSAGE(STATUS "Found libzks/libzks.h : ${ZKS_INCLUDE_DIR}")
   ENDIF (NOT ZKS_FIND_QUIETLY)
   include_directories (${ZKS_INCLUDE_DIR} ${ZKS_INCLUDE_DIR}/libzks)
   list(APPEND ThirdPartyLibs ${ZKS_LIBRARY})
ELSE (ZKS_FOUND)
      MESSAGE(FATAL_ERROR "Could not find LIBZKS")
ENDIF (ZKS_FOUND)

######################### thread ##################################

FIND_PACKAGE ( Threads REQUIRED )
list(APPEND ThirdPartyLibs ${CMAKE_THREAD_LIBS_INIT})

######################### thread ##################################
FIND_PACKAGE (wxWidgets REQUIRED core base aui adv propgrid richtext)
if(wxWidgets_FOUND)
    INCLUDE(${wxWidgets_USE_FILE})
    MESSAGE(STATUS "Found wxWidgets_DEFINITIONS : ${wxWidgets_DEFINITIONS}")
    MESSAGE(STATUS "Found wxWidgets_CXX_FLAGS : ${wxWidgets_CXX_FLAGS}")
    MESSAGE(STATUS "Found wxWidgets_LIBRARIES : ${wxWidgets_LIBRARIES}")
    MESSAGE(STATUS "Found wxWidgets_FOUND : ${wxWidgets_FOUND}")
    include_directories(${wxWidgets_INCLUDE_DIRS})
    add_compile_definitions(USE_GUI ${wxWidgets_DEFINITIONS} "_WCHAR_H_CPLUSPLUS_98_CONFORMANCE_")
    list(APPEND ThirdPartyLibs ${wxWidgets_LIBRARIES})
endif(wxWidgets_FOUND)

FIND_PACKAGE(png REQUIRED)
if(PNG_FOUND)
    MESSAGE(STATUS "PNG_DEFINITIONS : ${PNG_DEFINITIONS}")
    add_definitions(${PNG_DEFINITIONS})
    list(APPEND ThirdPartyLibs ${PNG_LIBRARIES})
endif()

FIND_PACKAGE(tiff REQUIRED)
if(TIFF_FOUND)
    list(APPEND ThirdPartyLibs ${TIFF_LIBRARIES})
endif()

FIND_PACKAGE(expat REQUIRED)
if(EXPAT_FOUND)
    list(APPEND ThirdPartyLibs ${EXPAT_LIBRARIES})
endif()

FIND_PACKAGE(jpeg REQUIRED)
if(JPEG_FOUND)
    list(APPEND ThirdPartyLibs ${JPEG_LIBRARIES})
endif()

FIND_PACKAGE(zlib REQUIRED)
if(ZLIB_FOUND)
    list(APPEND ThirdPartyLibs ${ZLIB_LIBRARIES})
endif()

MESSAGE(STATUS "ThirdPartyLibs : ${ThirdPartyLibs}")

add_subdirectory (src)
