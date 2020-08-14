
# 빌드 대상 바이너리 추가
ADD_LIBRARY(my my.cpp pool.c)

TARGET_INCLUDE_DIRECTORIES(my
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

