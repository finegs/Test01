cmake_minimum_required(VERSION 3.15)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(masynclogger)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Threads REQUIRED)

add_executable(main Application.cpp
  AsyncLogger.cpp
  WorkerThread.cpp)

target_link_libraries(main Threads::Threads)

add_executable(ThreadPool ThreadPool.cpp)
target_link_libraries(ThreadPool Threads::Threads)
