# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/mrybs/Data/Projects/zert

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mrybs/Data/Projects/zert

# Include any dependencies generated for this target.
include CMakeFiles/zert.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/zert.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/zert.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zert.dir/flags.make

CMakeFiles/zert.dir/main.cpp.o: CMakeFiles/zert.dir/flags.make
CMakeFiles/zert.dir/main.cpp.o: main.cpp
CMakeFiles/zert.dir/main.cpp.o: CMakeFiles/zert.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mrybs/Data/Projects/zert/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/zert.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/zert.dir/main.cpp.o -MF CMakeFiles/zert.dir/main.cpp.o.d -o CMakeFiles/zert.dir/main.cpp.o -c /home/mrybs/Data/Projects/zert/main.cpp

CMakeFiles/zert.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/zert.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mrybs/Data/Projects/zert/main.cpp > CMakeFiles/zert.dir/main.cpp.i

CMakeFiles/zert.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/zert.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mrybs/Data/Projects/zert/main.cpp -o CMakeFiles/zert.dir/main.cpp.s

# Object files for target zert
zert_OBJECTS = \
"CMakeFiles/zert.dir/main.cpp.o"

# External object files for target zert
zert_EXTERNAL_OBJECTS =

zert: CMakeFiles/zert.dir/main.cpp.o
zert: CMakeFiles/zert.dir/build.make
zert: CMakeFiles/zert.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/mrybs/Data/Projects/zert/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable zert"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/zert.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zert.dir/build: zert
.PHONY : CMakeFiles/zert.dir/build

CMakeFiles/zert.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/zert.dir/cmake_clean.cmake
.PHONY : CMakeFiles/zert.dir/clean

CMakeFiles/zert.dir/depend:
	cd /home/mrybs/Data/Projects/zert && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mrybs/Data/Projects/zert /home/mrybs/Data/Projects/zert /home/mrybs/Data/Projects/zert /home/mrybs/Data/Projects/zert /home/mrybs/Data/Projects/zert/CMakeFiles/zert.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/zert.dir/depend

