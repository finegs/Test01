You could do it in the following way:

CMakeLists.txt in your MainProject directory:

project(MainProject)

add_subdirectory(LibProject/src)
add_subdirectory(MainProject/src)
CMakeLists.txt in your LibProject/src directory:

include_directories(${PROJECT_SOURCE_DIR}/LibProject/inc/)
add_library(LibProject test.cpp)
CMakeLists.txt in your MainProject/src directory:

include_directories(${PROJECT_SOURCE_DIR}/MainProject/inc/)
add_executable(MainProject main.cpp)
target_link_libraries(MainProject LibProject)

