# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /home/mrybs/JetBrains/clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/mrybs/JetBrains/clion/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mrybs/Projects/zert

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mrybs/Projects/zert/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/zert.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/zert.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/zert.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zert.dir/flags.make

CMakeFiles/zert.dir/main.cpp.o: CMakeFiles/zert.dir/flags.make
CMakeFiles/zert.dir/main.cpp.o: ../main.cpp
CMakeFiles/zert.dir/main.cpp.o: CMakeFiles/zert.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mrybs/Projects/zert/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/zert.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/zert.dir/main.cpp.o -MF CMakeFiles/zert.dir/main.cpp.o.d -o CMakeFiles/zert.dir/main.cpp.o -c /home/mrybs/Projects/zert/main.cpp

CMakeFiles/zert.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zert.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mrybs/Projects/zert/main.cpp > CMakeFiles/zert.dir/main.cpp.i

CMakeFiles/zert.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zert.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mrybs/Projects/zert/main.cpp -o CMakeFiles/zert.dir/main.cpp.s

CMakeFiles/zert.dir/lexer.cpp.o: CMakeFiles/zert.dir/flags.make
CMakeFiles/zert.dir/lexer.cpp.o: ../lexer.cpp
CMakeFiles/zert.dir/lexer.cpp.o: CMakeFiles/zert.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mrybs/Projects/zert/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/zert.dir/lexer.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/zert.dir/lexer.cpp.o -MF CMakeFiles/zert.dir/lexer.cpp.o.d -o CMakeFiles/zert.dir/lexer.cpp.o -c /home/mrybs/Projects/zert/lexer.cpp

CMakeFiles/zert.dir/lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zert.dir/lexer.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mrybs/Projects/zert/lexer.cpp > CMakeFiles/zert.dir/lexer.cpp.i

CMakeFiles/zert.dir/lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zert.dir/lexer.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mrybs/Projects/zert/lexer.cpp -o CMakeFiles/zert.dir/lexer.cpp.s

CMakeFiles/zert.dir/token.cpp.o: CMakeFiles/zert.dir/flags.make
CMakeFiles/zert.dir/token.cpp.o: ../token.cpp
CMakeFiles/zert.dir/token.cpp.o: CMakeFiles/zert.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mrybs/Projects/zert/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/zert.dir/token.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/zert.dir/token.cpp.o -MF CMakeFiles/zert.dir/token.cpp.o.d -o CMakeFiles/zert.dir/token.cpp.o -c /home/mrybs/Projects/zert/token.cpp

CMakeFiles/zert.dir/token.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zert.dir/token.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mrybs/Projects/zert/token.cpp > CMakeFiles/zert.dir/token.cpp.i

CMakeFiles/zert.dir/token.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zert.dir/token.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mrybs/Projects/zert/token.cpp -o CMakeFiles/zert.dir/token.cpp.s

# Object files for target zert
zert_OBJECTS = \
"CMakeFiles/zert.dir/main.cpp.o" \
"CMakeFiles/zert.dir/lexer.cpp.o" \
"CMakeFiles/zert.dir/token.cpp.o"

# External object files for target zert
zert_EXTERNAL_OBJECTS =

zert: CMakeFiles/zert.dir/main.cpp.o
zert: CMakeFiles/zert.dir/lexer.cpp.o
zert: CMakeFiles/zert.dir/token.cpp.o
zert: CMakeFiles/zert.dir/build.make
zert: CMakeFiles/zert.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mrybs/Projects/zert/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable zert"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/zert.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zert.dir/build: zert
.PHONY : CMakeFiles/zert.dir/build

CMakeFiles/zert.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/zert.dir/cmake_clean.cmake
.PHONY : CMakeFiles/zert.dir/clean

CMakeFiles/zert.dir/depend:
	cd /home/mrybs/Projects/zert/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mrybs/Projects/zert /home/mrybs/Projects/zert /home/mrybs/Projects/zert/cmake-build-debug /home/mrybs/Projects/zert/cmake-build-debug /home/mrybs/Projects/zert/cmake-build-debug/CMakeFiles/zert.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/zert.dir/depend

