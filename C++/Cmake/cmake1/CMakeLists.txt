cmake_minimum_required(VERSION 3.10)	 
										
										

project(main)			

set(SOURCE_EXE threads.c)		
                            
set(SOURCE_LIB threads.c threadFunctions.c)			

add_library(MY_LIB STATIC ${SOURCE_LIB})	

add_executable(main ${SOURCE_EXE})	

target_link_libraries(main MY_LIB)		