
# 빌드 대상 바이너리 추가
ADD_EXECUTABLE(t_main test_main.cpp)
ADD_EXECUTABLE(ThreadPool ThreadPool.cpp)

TARGET_INCLUDE_DIRECTORIES(t_main 
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
)


TARGET_LINK_LIBRARIES(t_main
    PUBLIC
        my
)

TARGET_INCLUDE_DIRECTORIES(ThreadPool 
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
)

TARGET_LINK_LIBRARIES(ThreadPool
    PUBLIC
        my
)