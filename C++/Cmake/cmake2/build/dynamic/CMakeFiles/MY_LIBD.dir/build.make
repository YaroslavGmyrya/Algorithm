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
CMAKE_SOURCE_DIR = /home/useradd/Cmake/cmake2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/useradd/Cmake/cmake2/build

# Include any dependencies generated for this target.
include dynamic/CMakeFiles/MY_LIBD.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include dynamic/CMakeFiles/MY_LIBD.dir/compiler_depend.make

# Include the progress variables for this target.
include dynamic/CMakeFiles/MY_LIBD.dir/progress.make

# Include the compile flags for this target's objects.
include dynamic/CMakeFiles/MY_LIBD.dir/flags.make

dynamic/CMakeFiles/MY_LIBD.dir/div.c.o: dynamic/CMakeFiles/MY_LIBD.dir/flags.make
dynamic/CMakeFiles/MY_LIBD.dir/div.c.o: ../dynamic/div.c
dynamic/CMakeFiles/MY_LIBD.dir/div.c.o: dynamic/CMakeFiles/MY_LIBD.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/useradd/Cmake/cmake2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object dynamic/CMakeFiles/MY_LIBD.dir/div.c.o"
	cd /home/useradd/Cmake/cmake2/build/dynamic && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT dynamic/CMakeFiles/MY_LIBD.dir/div.c.o -MF CMakeFiles/MY_LIBD.dir/div.c.o.d -o CMakeFiles/MY_LIBD.dir/div.c.o -c /home/useradd/Cmake/cmake2/dynamic/div.c

dynamic/CMakeFiles/MY_LIBD.dir/div.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MY_LIBD.dir/div.c.i"
	cd /home/useradd/Cmake/cmake2/build/dynamic && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/useradd/Cmake/cmake2/dynamic/div.c > CMakeFiles/MY_LIBD.dir/div.c.i

dynamic/CMakeFiles/MY_LIBD.dir/div.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MY_LIBD.dir/div.c.s"
	cd /home/useradd/Cmake/cmake2/build/dynamic && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/useradd/Cmake/cmake2/dynamic/div.c -o CMakeFiles/MY_LIBD.dir/div.c.s

# Object files for target MY_LIBD
MY_LIBD_OBJECTS = \
"CMakeFiles/MY_LIBD.dir/div.c.o"

# External object files for target MY_LIBD
MY_LIBD_EXTERNAL_OBJECTS =

dynamic/libMY_LIBD.so: dynamic/CMakeFiles/MY_LIBD.dir/div.c.o
dynamic/libMY_LIBD.so: dynamic/CMakeFiles/MY_LIBD.dir/build.make
dynamic/libMY_LIBD.so: dynamic/CMakeFiles/MY_LIBD.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/useradd/Cmake/cmake2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library libMY_LIBD.so"
	cd /home/useradd/Cmake/cmake2/build/dynamic && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MY_LIBD.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
dynamic/CMakeFiles/MY_LIBD.dir/build: dynamic/libMY_LIBD.so
.PHONY : dynamic/CMakeFiles/MY_LIBD.dir/build

dynamic/CMakeFiles/MY_LIBD.dir/clean:
	cd /home/useradd/Cmake/cmake2/build/dynamic && $(CMAKE_COMMAND) -P CMakeFiles/MY_LIBD.dir/cmake_clean.cmake
.PHONY : dynamic/CMakeFiles/MY_LIBD.dir/clean

dynamic/CMakeFiles/MY_LIBD.dir/depend:
	cd /home/useradd/Cmake/cmake2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/useradd/Cmake/cmake2 /home/useradd/Cmake/cmake2/dynamic /home/useradd/Cmake/cmake2/build /home/useradd/Cmake/cmake2/build/dynamic /home/useradd/Cmake/cmake2/build/dynamic/CMakeFiles/MY_LIBD.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : dynamic/CMakeFiles/MY_LIBD.dir/depend

