# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/useradd/group_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/useradd/group_project/bl

# Include any dependencies generated for this target.
include CMakeFiles/MY_LIB.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MY_LIB.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MY_LIB.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MY_LIB.dir/flags.make

CMakeFiles/MY_LIB.dir/main.c.o: CMakeFiles/MY_LIB.dir/flags.make
CMakeFiles/MY_LIB.dir/main.c.o: ../main.c
CMakeFiles/MY_LIB.dir/main.c.o: CMakeFiles/MY_LIB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/useradd/group_project/bl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/MY_LIB.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MY_LIB.dir/main.c.o -MF CMakeFiles/MY_LIB.dir/main.c.o.d -o CMakeFiles/MY_LIB.dir/main.c.o -c /home/useradd/group_project/main.c

CMakeFiles/MY_LIB.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MY_LIB.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/useradd/group_project/main.c > CMakeFiles/MY_LIB.dir/main.c.i

CMakeFiles/MY_LIB.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MY_LIB.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/useradd/group_project/main.c -o CMakeFiles/MY_LIB.dir/main.c.s

CMakeFiles/MY_LIB.dir/heap_sort_f.c.o: CMakeFiles/MY_LIB.dir/flags.make
CMakeFiles/MY_LIB.dir/heap_sort_f.c.o: ../heap_sort_f.c
CMakeFiles/MY_LIB.dir/heap_sort_f.c.o: CMakeFiles/MY_LIB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/useradd/group_project/bl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/MY_LIB.dir/heap_sort_f.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MY_LIB.dir/heap_sort_f.c.o -MF CMakeFiles/MY_LIB.dir/heap_sort_f.c.o.d -o CMakeFiles/MY_LIB.dir/heap_sort_f.c.o -c /home/useradd/group_project/heap_sort_f.c

CMakeFiles/MY_LIB.dir/heap_sort_f.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MY_LIB.dir/heap_sort_f.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/useradd/group_project/heap_sort_f.c > CMakeFiles/MY_LIB.dir/heap_sort_f.c.i

CMakeFiles/MY_LIB.dir/heap_sort_f.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MY_LIB.dir/heap_sort_f.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/useradd/group_project/heap_sort_f.c -o CMakeFiles/MY_LIB.dir/heap_sort_f.c.s

CMakeFiles/MY_LIB.dir/other_func.c.o: CMakeFiles/MY_LIB.dir/flags.make
CMakeFiles/MY_LIB.dir/other_func.c.o: ../other_func.c
CMakeFiles/MY_LIB.dir/other_func.c.o: CMakeFiles/MY_LIB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/useradd/group_project/bl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/MY_LIB.dir/other_func.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MY_LIB.dir/other_func.c.o -MF CMakeFiles/MY_LIB.dir/other_func.c.o.d -o CMakeFiles/MY_LIB.dir/other_func.c.o -c /home/useradd/group_project/other_func.c

CMakeFiles/MY_LIB.dir/other_func.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MY_LIB.dir/other_func.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/useradd/group_project/other_func.c > CMakeFiles/MY_LIB.dir/other_func.c.i

CMakeFiles/MY_LIB.dir/other_func.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MY_LIB.dir/other_func.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/useradd/group_project/other_func.c -o CMakeFiles/MY_LIB.dir/other_func.c.s

CMakeFiles/MY_LIB.dir/shaker_sort.c.o: CMakeFiles/MY_LIB.dir/flags.make
CMakeFiles/MY_LIB.dir/shaker_sort.c.o: ../shaker_sort.c
CMakeFiles/MY_LIB.dir/shaker_sort.c.o: CMakeFiles/MY_LIB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/useradd/group_project/bl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/MY_LIB.dir/shaker_sort.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MY_LIB.dir/shaker_sort.c.o -MF CMakeFiles/MY_LIB.dir/shaker_sort.c.o.d -o CMakeFiles/MY_LIB.dir/shaker_sort.c.o -c /home/useradd/group_project/shaker_sort.c

CMakeFiles/MY_LIB.dir/shaker_sort.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MY_LIB.dir/shaker_sort.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/useradd/group_project/shaker_sort.c > CMakeFiles/MY_LIB.dir/shaker_sort.c.i

CMakeFiles/MY_LIB.dir/shaker_sort.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MY_LIB.dir/shaker_sort.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/useradd/group_project/shaker_sort.c -o CMakeFiles/MY_LIB.dir/shaker_sort.c.s

CMakeFiles/MY_LIB.dir/simple_include_sort.c.o: CMakeFiles/MY_LIB.dir/flags.make
CMakeFiles/MY_LIB.dir/simple_include_sort.c.o: ../simple_include_sort.c
CMakeFiles/MY_LIB.dir/simple_include_sort.c.o: CMakeFiles/MY_LIB.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/useradd/group_project/bl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/MY_LIB.dir/simple_include_sort.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MY_LIB.dir/simple_include_sort.c.o -MF CMakeFiles/MY_LIB.dir/simple_include_sort.c.o.d -o CMakeFiles/MY_LIB.dir/simple_include_sort.c.o -c /home/useradd/group_project/simple_include_sort.c

CMakeFiles/MY_LIB.dir/simple_include_sort.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MY_LIB.dir/simple_include_sort.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/useradd/group_project/simple_include_sort.c > CMakeFiles/MY_LIB.dir/simple_include_sort.c.i

CMakeFiles/MY_LIB.dir/simple_include_sort.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MY_LIB.dir/simple_include_sort.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/useradd/group_project/simple_include_sort.c -o CMakeFiles/MY_LIB.dir/simple_include_sort.c.s

# Object files for target MY_LIB
MY_LIB_OBJECTS = \
"CMakeFiles/MY_LIB.dir/main.c.o" \
"CMakeFiles/MY_LIB.dir/heap_sort_f.c.o" \
"CMakeFiles/MY_LIB.dir/other_func.c.o" \
"CMakeFiles/MY_LIB.dir/shaker_sort.c.o" \
"CMakeFiles/MY_LIB.dir/simple_include_sort.c.o"

# External object files for target MY_LIB
MY_LIB_EXTERNAL_OBJECTS =

libMY_LIB.a: CMakeFiles/MY_LIB.dir/main.c.o
libMY_LIB.a: CMakeFiles/MY_LIB.dir/heap_sort_f.c.o
libMY_LIB.a: CMakeFiles/MY_LIB.dir/other_func.c.o
libMY_LIB.a: CMakeFiles/MY_LIB.dir/shaker_sort.c.o
libMY_LIB.a: CMakeFiles/MY_LIB.dir/simple_include_sort.c.o
libMY_LIB.a: CMakeFiles/MY_LIB.dir/build.make
libMY_LIB.a: CMakeFiles/MY_LIB.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/useradd/group_project/bl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C static library libMY_LIB.a"
	$(CMAKE_COMMAND) -P CMakeFiles/MY_LIB.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MY_LIB.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MY_LIB.dir/build: libMY_LIB.a
.PHONY : CMakeFiles/MY_LIB.dir/build

CMakeFiles/MY_LIB.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MY_LIB.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MY_LIB.dir/clean

CMakeFiles/MY_LIB.dir/depend:
	cd /home/useradd/group_project/bl && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/useradd/group_project /home/useradd/group_project /home/useradd/group_project/bl /home/useradd/group_project/bl /home/useradd/group_project/bl/CMakeFiles/MY_LIB.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MY_LIB.dir/depend

