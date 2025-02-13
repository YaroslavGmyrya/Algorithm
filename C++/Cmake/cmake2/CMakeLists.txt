cmake_minimum_required(VERSION 3.10) 	

project(hello_world)					

set(SOURCE_EXE "./src/main.c")					

include_directories("./include")		

add_executable(main ${SOURCE_EXE})		

add_subdirectory("./dynamic")

add_subdirectory("./static")			

#add_definitions("-DTEST_DEF=5")			

target_link_libraries(main MY_LIBD)	

target_link_libraries(main MY_LIBS)		