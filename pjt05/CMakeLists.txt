# 요구 CMake 최소 버전
CMAKE_MINIMUM_REQUIRED ( VERSION 3.0.0 )
 
# 프로젝트 이름 및 버전
PROJECT ( pjt05 )

SET ( PROJECT_VERSION_MAJOR 0 )
SET ( PROJECT_VERSION_MINOR 1 )
 
# 빌드 형상(Configuration) 및 주절주절 Makefile 생성 여부
SET ( CMAKE_C_COMPILER gcc)
SET ( CMAKE_CXX_COMPILER g++)
SET ( CMAKE_BUILD_TYPE Release )
SET ( CMAKE_VERBOSE_MAKEFILE true )

SET (BOOST_INC "D:/Programs/boost/boost_1_70_0/include/boost-1_70")
SET (BOOST_LIB "D:/Programs/boost/boost_1_70_0/lib" )


# 빌드 대상 바이너리 파일명 및 소스파일 목록
SET ( OUTPUT_ELF "${CMAKE_PROJECT_NAME}-${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}")
 
# 공통 헤더 파일 Include 디렉토리 (-I)
IF(WIN32)
	INCLUDE_DIRECTORIES ( ${BOOST_INC}  )
	INCLUDE_DIRECTORIES ( ${workspaceDir}/include )
ENDIF()
 
# 공통 컴파일 옵션, 링크 옵션
SET(CMAKE_C_FLAGS -std=c11)
SET(CMAKE_CXX_FLAGS -std=c++17)

# 공통 링크 라이브러리 (-l)
IF(WIN32)
	LINK_LIBRARIES( -lws2_32 -pthread )
ENDIF()
 
 
# "Debug" 형상 한정 컴파일 옵션, 링크 옵션
SET ( CMAKE_C_FLAGS_DEBUG "-g " )
SET ( CMAKE_EXE_LINKER_FLAGS_DEBUG  )
 
# "Release" 형상 한정 컴파일 옵션, 링크 옵션
SET ( CMAKE_C_FLAGS_RELEASE "-O2" )
SET ( CMAKE_EXE_LINKER_FLAGS_RELEASE )
 
# 출력 디렉토리
SET ( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BUILD_TYPE} )
SET ( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BUILD_TYPE}/lib )
SET ( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BUILD_TYPE}/lib )
 
ADD_SUBDIRECTORY(a)
ADD_SUBDIRECTORY(b)
ADD_SUBDIRECTORY(my)
ADD_SUBDIRECTORY(test)

ADD_DEPENDENCIES(t my)

IF (WIN32)

	LINK_DIRECTORIES ( ${BOOST_LIB} )

ELSE()
	ADD_SUBDIRECTORY(sht25)
	TARGET_LINK_LIBRARIES(sht2x "-lwiringPi -lcrypt -pthread -lm -lrt")
ENDIF()