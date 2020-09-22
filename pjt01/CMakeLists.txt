cmake_minimum_required(VERSION 3.14)

project(my.test.pjt01)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_C_FLAGS "-g")
set(CMAKE_CXX_FLAGS "-g")

add_definitions("-std=c++17 -Wall -Wextra -Wno-unused-parameter")

INCLUDE_DIRECTORIES($ENV{BOOST_HOME}/../boost_inc inc)
LINK_DIRECTORIES($ENV{BOOST_HOME}/lib)

add_executable(t t.cpp u.cpp mipc.cpp uu1.cpp)
add_executable(aa aa.c)
add_executable(a a.c)

#TARGET_LINK_LIBRARIES(t ws2_32 stdc++ m pthread boost_thread boost_system boost_chrono)
TARGET_LINK_LIBRARIES(t 
    ws2_32 
    stdc++ 
    m 
    pthread 
    boost_thread-mgw81-mt-d-x64-1_70 
    boost_system-mgw81-mt-d-x64-1_70 
    boost_chrono-mgw81-mt-d-x64-1_70
    )

