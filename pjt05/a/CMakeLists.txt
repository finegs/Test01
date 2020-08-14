
# 빌드 대상 바이너리 추가
ADD_EXECUTABLE(a a.cpp)

ADD_EXECUTABLE(main main.c)

ADD_EXECUTABLE(t t.cpp)

TARGET_INCLUDE_DIRECTORIES(a 
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
)


TARGET_LINK_LIBRARIES(a
    PUBLIC
        my
)

TARGET_LINK_LIBRARIES(t
    PUBLIC
        my
)

TARGET_LINK_LIBRARIES(main
    PUBLIC
        my
)

