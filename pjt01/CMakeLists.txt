cmake_minimum_required(VERSION 3.14)

PROJECT(my.test.pjt01)

SET(CMAKE_C_COMPILER gcc)
SET(CMAKE_CXX_COMPILER g++)
SET(CMAKE_C_FLAGS "-g -std=c11")
SET(CMAKE_CXX_FLAGS "-g -std=c++17")

SET(RUNTIME_OUTPUT_DIRECTORY bin)
SET(LIBRARY_OUTPUT_DIRECTORY lib)
SET(ARCHIVE_OUTPUT_DIRECTORY lib/static)

IF (WIN32 OR WIN64)
	ADD_DEFINITIONS("-Wall -Wextra -Wno-unused-parameter -Wpedantic-ms-format -posix")
ELSE()
	ADD_DEFINITIONS("-Wall -Wextra -Wno-unused-parameter -posix")
ENDIF()

ADD_DEFINITIONS("-DUSE_NBOOST")


INCLUDE_DIRECTORIES($ENV{BOOST_HOME}/../boost_inc include)
LINK_DIRECTORIES($ENV{BOOST_HOME}/lib lib mutil)

add_subdirectory(abc)
add_subdirectory(mutil)
#add_subdirectory(net)
add_subdirectory(plot)
add_subdirectory(algo)

add_dependencies(t mu)

