cmake_minimum_required (VERSION 2.6) 
project(game)

add_compile_options ($<$<CXX_COMPILER_ID:Clang>:-std=c++1y>)
add_compile_options ($<$<CXX_COMPILER_ID:Clang>:-stdlib=libc++>)
add_compile_options ($<$<CXX_COMPILER_ID:Clang>:-g>)
add_compile_options ($<$<CXX_COMPILER_ID:Clang>:-O2>)

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
FIND_PACKAGE (wxWidgets REQUIRED net gl core base)

add_subdirectory (src)
