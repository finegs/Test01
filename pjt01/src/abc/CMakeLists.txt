
#add_executable(t t.cpp u.cpp mipc.cpp uu1.
add_executable(t t.cpp)
add_executable(aa aa.c)
add_executable(a a.c)



#TARGET_LINK_LIBRARIES(t ws2_32 stdc++ m pthread boost_thread boost_system boost_chrono)
TARGET_LINK_LIBRARIES(t 
	PUBLIC
    ws2_32 
    stdc++ 
    m 
    pthread 
    boost_thread
    boost_system
    boost_chrono
    mu
    )

target_link_directories(t PUBLIC ${CMAKE_SOURCE_DIR}/mutil)

INSTALL(TARGETS
	a
	RUNTIME DESTINATION ${CMAKE_SOURCE_DIR}/bin
	LIBRARY DESTINATION ${CMAKE_SOURCE_DIR}/lib
	ARCHIVE DESTINATION ${CMAKE_SOURCE_DIR}/lib/static
	)

