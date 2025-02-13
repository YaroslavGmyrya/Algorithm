cmake_minimum_required(VERSION 3.10)	 
										
										

project(hello_cmake)			

set(SOURCE_EXE main.c)		
                            
set(SOURCE_LIB main.c heap_sort_f.c other_func.c shaker_sort.c simple_include_sort.c)			

add_library(MY_LIB STATIC ${SOURCE_LIB})	

add_executable(main ${SOURCE_EXE})	

target_link_libraries(main MY_LIB)		