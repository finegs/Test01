cmake_minimum_required(VERSION 3.14)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_C_FLAGS "")
set(CMAKE_CXX_FLAGS "")

add_definitions("-std=c++17 -Wall -Wextra -Wno-unused-parameter")

INCLUDE_DIRECTORIES($ENV{BOOST_HOME}/../boost_inc inc)
LINK_DIRECTORIES($ENV{BOOST_HOME}/lib)

add_executable(t t.cpp u.cpp mipc.cpp uu1.cpp)

#TARGET_LINK_LIBRARIES(t ws2_32 stdc++ m pthread boost_thread boost_system boost_chrono)
TARGET_LINK_LIBRARIES(t ws2_32 stdc++ m pthread boost_thread-mgw81-mt-d-x64-1_70 boost_system-mgw81-mt-d-x64-1_70 boost_chrono-mgw81-mt-d-x64-1_70)

