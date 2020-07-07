# 요구 CMake 최소 버전
CMAKE_MINIMUM_REQUIRED ( VERSION 2.8 )
 
# 프로젝트 이름 및 버전
PROJECT ( main )
SET ( PROJECT_VERSION_MAJOR 0 )
SET ( PROJECT_VERSION_MINOR 1 )
 
# 빌드 형상(Configuration) 및 주절주절 Makefile 생성 여부
SET ( CMAKE_BUILD_TYPE Debug )
SET ( CMAKE_VERBOSE_MAKEFILE true )
 
# 빌드 대상 바이너리 파일명 및 소스파일 목록
SET ( OUTPUT_ELF
		"${CMAKE_PROJECT_NAME}-${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}"
    )
SET ( SRC_FILES
     a.cpp
	 b.c
	 pool.c
#     b.c
    )
 
# 공통 컴파일러
SET ( CMAKE_C_COMPILER g++ )
 
# 공통 헤더 파일 Include 디렉토리 (-I)
IF(WIN32)
	INCLUDE_DIRECTORIES ( D:/Programs/boost/boost_1_70_0/include/boost-1_70 )
ENDIF()
 
# 공통 컴파일 옵션, 링크 옵션
ADD_COMPILE_OPTIONS ( -std=c++17 )
#SET ( CMAKE_EXE_LINKER_FLAGS "-lws2_32" "-pthread" )
 
# 공통 링크 라이브러리 (-l)
IF(WIN32)
	LINK_LIBRARIES( -lws2_32 -pthread )
ELSE()
	#	add_executable(my_sht21 sht21.c myi2c.c)
ENDIF()
 
# 공통 링크 라이브러리 디렉토리 (-L)
IF(WIN32)
	LINK_DIRECTORIES ( D:/Programs/boost/boost_1_70_0/lib )
ENDIF()
 
# "Debug" 형상 한정 컴파일 옵션, 링크 옵션
SET ( CMAKE_C_FLAGS_DEBUG "-g " )
#SET ( CMAKE_EXE_LINKER_FLAGS_DEBUG "-lws2_32" "-pthread" )
SET ( CMAKE_EXE_LINKER_FLAGS_DEBUG  )
 
# "Release" 형상 한정 컴파일 옵션, 링크 옵션
SET ( CMAKE_C_FLAGS_RELEASE "-O2" )
#SET ( CMAKE_EXE_LINKER_FLAGS_RELEASE "-lws2_32" "-pthread" )
SET ( CMAKE_EXE_LINKER_FLAGS_RELEASE )
 
# 출력 디렉토리
SET ( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BUILD_TYPE} )
SET ( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BUILD_TYPE}/lib )
SET ( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BUILD_TYPE}/lib )
 
# 빌드 대상 바이너리 추가
ADD_EXECUTABLE( ${OUTPUT_ELF} ${SRC_FILES} )

IF(NOT WIN32)
	ADD_EXECUTABLE(t t.cpp)
ENDIF()


add_executable(hello a.cpp b.c)
#add_executable(sht21 sht21.c myi2c.c)
IF(!WIN32)
	add_executable(sht2x sht2x.c sht2x_main.c)
	target_link_libraries(sht2x "-lwiringPi -lcrypt -pthread -lm -lrt")
ENDIF()

