cmake_minimum_required(VERSION 3.10)	 
										
										

project(hello)			

set(SOURCE_EXE main.c)		
                            
set(SOURCE_LIB main.c main_func.c other_func.c)			

add_library(MY_LIB STATIC ${SOURCE_LIB})	

add_executable(main ${SOURCE_EXE})	

target_link_libraries(main MY_LIB m)		