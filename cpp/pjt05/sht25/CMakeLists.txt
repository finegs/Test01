
# 빌드 대상 바이너리 추가
ADD_EXECUTABLE(sht25 sht2x_main.c)

IF (NOT WIN32)
	find_library(WIRINGPI_LIB wiringPi)
	if(WIRINGPI_LIB)
  		message(FATAL_ERROR "wiringPi library found")
		ADD_SUBDIRECTORY(sht25)
		TARGET_LINK_LIBRARIES(sht2x "-lwiringPi -lcrypt -lthread -lm -lrt")
    else()
		message(INFO " : wiringPi library not found")
	endif(){
ENDIF()}
