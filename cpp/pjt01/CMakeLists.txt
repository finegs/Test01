
project(cpp_pjt01)

set(CMAKE_CONFIGURATION_TYPES "Debug" CACHE STRING "" FORCE)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set the C++ standard to 23 (which includes C++22 features)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(algo)

add_executable(a a.cpp)
add_executable(b b.cpp)
add_executable(b1 b1.cpp)
