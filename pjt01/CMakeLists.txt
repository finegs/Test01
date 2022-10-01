cmake_minimum_required(VERSION 3.14)

PROJECT(my.test.pjt01)


#SET(CMAKE_C_COMPILER gcc)
#SET(CMAKE_CXX_COMPILER g++)
#SET(CMAKE_C_FLAGS "-g -std=c11")
#SET(CMAKE_CXX_FLAGS "-g -std=c++17")

SET(RUNTIME_OUTPUT_DIRECTORY bin)
SET(LIBRARY_OUTPUT_DIRECTORY lib)
SET(ARCHIVE_OUTPUT_DIRECTORY lib/static)


IF(MSVC)
	ADD_DEFINITIONS("-Wall")
	ADD_DEFINITIONS("-DUSE_NBOOST")
ELSE (MSVC)
	ADD_DEFINITIONS("-Wall -Wextra -Wno-unused-parameter -Wpedantic-ms-format -posix")
	ADD_DEFINITIONS("-DUSE_NBOOST")
ENDIF()


INCLUDE_DIRECTORIES($ENV{BOOST_HOME}/../boost_inc inc)
LINK_DIRECTORIES($ENV{BOOST_HOME}/lib)

#add_executable(t t.cpp u.cpp mipc.cpp uu1.cpp)
#add_executable(aa aa.c)
add_executable(a a.c)
add_executable(tt02 tt02.cpp)

#TARGET_LINK_LIBRARIES(t ws2_32 stdc++ m pthread boost_thread boost_system boost_chrono)
TARGET_LINK_LIBRARIES(a 
    #ws2_32 
	#    stdc++ 
	#m 
	#    pthread 
	#    boost_thread
	#    boost_system
	#    boost_chrono
    )

TARGET_LINK_LIBRARIES(tt02 ws2_32)

INSTALL(TARGETS
	a
	RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/bin
	LIBRARY DESTINATION ${CMAKE_SOURCE_DIR}/lib
	ARCHIVE DESTINATION ${CMAKE_SOURCE_DIR}/lib/static
	)

