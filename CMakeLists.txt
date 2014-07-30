cmake_minimum_required (VERSION 2.6) 
project(game)

if(NOT CMAKE_BUILD_TYPE)
    set( CMAKE_BUILD_TYPE Release )
endif(NOT CMAKE_BUILD_TYPE)
string(TOLOWER CONFIG ${CMAKE_BUILD_TYPE})
set( CMAKE_DEBUG_POSTFIX "_d" )


if(CMAKE_CXX_COMPILER_ID STREQUAL Clang)
    string(CONCAT CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} " -lc++")
endif(CMAKE_CXX_COMPILER_ID STREQUAL Clang)
string(CONCAT CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS_DEBUG} " -DDEBUG -D_DEBUG")
string(CONCAT CMAKE_CXX_FLAGS_RELEASE ${CMAKE_CXX_FLAGS_RELEASE} " -D_NDEBUG")

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
  "$ENV{HOME}/local/include/"
  /usr/include/
  /usr/local/include/
  #MSVC
  "$ENV{LIB_DIR}/include"
  $ENV{ZKS_INCLUDE_PATH}
  #mingw
  c:/msys/local/include
  )

if(CONFIG STREQUAL debug)
    FIND_LIBRARY(ZKS_LIBRARY NAMES zks libzks PATHS 
      /usr/local/lib 
      /usr/lib 
      "$ENV{HOME}/local/lib"
      #MSVC
      "$ENV{LIB_DIR}/lib"
      $ENV{ZKS_LIB_PATH}
      #mingw
      c:/msys/local/lib
      )
else(CONFIG STREQUAL debug)
    FIND_LIBRARY(ZKS_LIBRARY NAMES zks_d libzks_d PATHS 
      /usr/local/lib 
      /usr/lib 
      "$ENV{HOME}/local/lib"
      #MSVC
      "$ENV{LIB_DIR}/lib"
      $ENV{ZKS_LIB_PATH}
      #mingw
      c:/msys/local/lib
      )
endif(CONFIG STREQUAL debug)

IF (ZKS_INCLUDE_DIR AND ZKS_LIBRARY)
   SET(ZKS_FOUND TRUE)
ENDIF (ZKS_INCLUDE_DIR AND ZKS_LIBRARY)

IF (ZKS_FOUND)
   IF (NOT ZKS_FIND_QUIETLY)
      MESSAGE(STATUS "Found libzks : ${ZKS_LIBRARY}")
      MESSAGE(STATUS "Found libzks/libzks.h : ${ZKS_INCLUDE_DIR}")
   ENDIF (NOT ZKS_FIND_QUIETLY)
ELSE (ZKS_FOUND)
      MESSAGE(FATAL_ERROR "Could not find LIBZKS")
ENDIF (ZKS_FOUND)

######################### thread ##################################

FIND_PACKAGE ( Threads REQUIRED )

######################### thread ##################################
if(WIN32)
    SET(wxWidgets_ROOT_DIR C:/local/wxWidgets-3.0.1)
    SET(wxWidgets_LIB_DIR C:/local/wxWidgets-3.0.1/lib/vc_x64_lib)
    SET(wxWidgets_CONFIGURATION mswu)
endif(WIN32)

FIND_PACKAGE (wxWidgets COMPONENTS core base aui adv propgrid richtext)
if(wxWidgets_FOUND)
    INCLUDE(${wxWidgets_USE_FILE})
    MESSAGE(STATUS "Found wxWidgets_DEFINITIONS : ${wxWidgets_DEFINITIONS}")
    MESSAGE(STATUS "Found wxWidgets_CXX_FLAGS : ${wxWidgets_CXX_FLAGS}")
    MESSAGE(STATUS "Found wxWidgets_LIBRARIES : ${wxWidgets_LIBRARIES}")
    MESSAGE(STATUS "Found wxWidgets_FOUND : ${wxWidgets_FOUND}")
endif(wxWidgets_FOUND)


add_subdirectory (src)
