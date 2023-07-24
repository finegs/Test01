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
	INCLUDE_DIRECTORIES($ENV{BOOST_HOME}/../boost_inc include)
	LINK_DIRECTORIES($ENV{BOOST_HOME}/lib lib mutil)
ELSE()
	ADD_DEFINITIONS("-Wall -Wextra -Wno-unused-parameter -posix")
ENDIF()

ADD_DEFINITIONS("-DUSE_NBOOST")


#add_subdirectory(abc)
#add_subdirectory(mutil)
##add_subdirectory(net)
#add_subdirectory(plot)
#add_subdirectory(algo)

add_executable(a a.cpp)
add_executable(b b.cpp)
add_executable(b1 b1.cpp)

#TARGET_LINK_LIBRARIES(t ws2_32 stdc++ m pthread boost_thread boost_system boost_chrono)
IF (WIN32 OR WIN64)
	TARGET_LINK_LIBRARIES(a 
		PUBLIC
		ws2_32 
		stdc++ 
		m 
		pthread 
		boost_thread
		boost_system
		boost_chrono
		mu
	)
	TARGET_LINK_LIBRARIES(b 
		PUBLIC
		ws2_32 
		stdc++ 
		m 
		pthread 
		boost_thread
		boost_system
		boost_chrono
		mu
	)
	TARGET_LINK_LIBRARIES(b1 
		PUBLIC
		ws2_32 
		stdc++ 
		m 
		pthread 
		boost_thread
		boost_system
		boost_chrono
		mu
	)
ELSE ()
	TARGET_LINK_LIBRARIES(a 
		PUBLIC
		stdc++ 
		m 
		pthread 
	)
	TARGET_LINK_LIBRARIES(b 
		PUBLIC
		stdc++ 
		m 
		pthread 
	)
	TARGET_LINK_LIBRARIES(b1 
		PUBLIC
		stdc++ 
		m 
		pthread 
	)
ENDIF ()
ENDIF ()

# target_link_directories(a PUBLIC ${CMAKE_SOURCE_DIR}/mutil)

# INSTALL(TARGETS
# 	a
# 	RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/bin
# 	LIBRARY DESTINATION ${CMAKE_SOURCE_DIR}/lib
# 	ARCHIVE DESTINATION ${CMAKE_SOURCE_DIR}/lib/static
# )

