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
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:/GitRepo/Basics/DSACpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:/GitRepo/Basics/DSACpp

# Include any dependencies generated for this target.
include tests/CMakeFiles/DataStructures_unit_tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/CMakeFiles/DataStructures_unit_tests.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/DataStructures_unit_tests.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/DataStructures_unit_tests.dir/flags.make

tests/CMakeFiles/DataStructures_unit_tests.dir/LinkedListTests.cpp.obj: tests/CMakeFiles/DataStructures_unit_tests.dir/flags.make
tests/CMakeFiles/DataStructures_unit_tests.dir/LinkedListTests.cpp.obj: tests/CMakeFiles/DataStructures_unit_tests.dir/includes_CXX.rsp
tests/CMakeFiles/DataStructures_unit_tests.dir/LinkedListTests.cpp.obj: tests/LinkedListTests.cpp
tests/CMakeFiles/DataStructures_unit_tests.dir/LinkedListTests.cpp.obj: tests/CMakeFiles/DataStructures_unit_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:/GitRepo/Basics/DSACpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/DataStructures_unit_tests.dir/LinkedListTests.cpp.obj"
	cd E:/GitRepo/Basics/DSACpp/tests && E:/GitRepo/Basics/DSACpp/nbproject/private/tools/localhost/MinGW/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/DataStructures_unit_tests.dir/LinkedListTests.cpp.obj -MF CMakeFiles/DataStructures_unit_tests.dir/LinkedListTests.cpp.obj.d -o CMakeFiles/DataStructures_unit_tests.dir/LinkedListTests.cpp.obj -c E:/GitRepo/Basics/DSACpp/tests/LinkedListTests.cpp

tests/CMakeFiles/DataStructures_unit_tests.dir/LinkedListTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DataStructures_unit_tests.dir/LinkedListTests.cpp.i"
	cd E:/GitRepo/Basics/DSACpp/tests && E:/GitRepo/Basics/DSACpp/nbproject/private/tools/localhost/MinGW/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:/GitRepo/Basics/DSACpp/tests/LinkedListTests.cpp > CMakeFiles/DataStructures_unit_tests.dir/LinkedListTests.cpp.i

tests/CMakeFiles/DataStructures_unit_tests.dir/LinkedListTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DataStructures_unit_tests.dir/LinkedListTests.cpp.s"
	cd E:/GitRepo/Basics/DSACpp/tests && E:/GitRepo/Basics/DSACpp/nbproject/private/tools/localhost/MinGW/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:/GitRepo/Basics/DSACpp/tests/LinkedListTests.cpp -o CMakeFiles/DataStructures_unit_tests.dir/LinkedListTests.cpp.s

tests/CMakeFiles/DataStructures_unit_tests.dir/QueueTests.cpp.obj: tests/CMakeFiles/DataStructures_unit_tests.dir/flags.make
tests/CMakeFiles/DataStructures_unit_tests.dir/QueueTests.cpp.obj: tests/CMakeFiles/DataStructures_unit_tests.dir/includes_CXX.rsp
tests/CMakeFiles/DataStructures_unit_tests.dir/QueueTests.cpp.obj: tests/QueueTests.cpp
tests/CMakeFiles/DataStructures_unit_tests.dir/QueueTests.cpp.obj: tests/CMakeFiles/DataStructures_unit_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:/GitRepo/Basics/DSACpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests/CMakeFiles/DataStructures_unit_tests.dir/QueueTests.cpp.obj"
	cd E:/GitRepo/Basics/DSACpp/tests && E:/GitRepo/Basics/DSACpp/nbproject/private/tools/localhost/MinGW/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/DataStructures_unit_tests.dir/QueueTests.cpp.obj -MF CMakeFiles/DataStructures_unit_tests.dir/QueueTests.cpp.obj.d -o CMakeFiles/DataStructures_unit_tests.dir/QueueTests.cpp.obj -c E:/GitRepo/Basics/DSACpp/tests/QueueTests.cpp

tests/CMakeFiles/DataStructures_unit_tests.dir/QueueTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DataStructures_unit_tests.dir/QueueTests.cpp.i"
	cd E:/GitRepo/Basics/DSACpp/tests && E:/GitRepo/Basics/DSACpp/nbproject/private/tools/localhost/MinGW/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:/GitRepo/Basics/DSACpp/tests/QueueTests.cpp > CMakeFiles/DataStructures_unit_tests.dir/QueueTests.cpp.i

tests/CMakeFiles/DataStructures_unit_tests.dir/QueueTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DataStructures_unit_tests.dir/QueueTests.cpp.s"
	cd E:/GitRepo/Basics/DSACpp/tests && E:/GitRepo/Basics/DSACpp/nbproject/private/tools/localhost/MinGW/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:/GitRepo/Basics/DSACpp/tests/QueueTests.cpp -o CMakeFiles/DataStructures_unit_tests.dir/QueueTests.cpp.s

tests/CMakeFiles/DataStructures_unit_tests.dir/StackTests.cpp.obj: tests/CMakeFiles/DataStructures_unit_tests.dir/flags.make
tests/CMakeFiles/DataStructures_unit_tests.dir/StackTests.cpp.obj: tests/CMakeFiles/DataStructures_unit_tests.dir/includes_CXX.rsp
tests/CMakeFiles/DataStructures_unit_tests.dir/StackTests.cpp.obj: tests/StackTests.cpp
tests/CMakeFiles/DataStructures_unit_tests.dir/StackTests.cpp.obj: tests/CMakeFiles/DataStructures_unit_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:/GitRepo/Basics/DSACpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object tests/CMakeFiles/DataStructures_unit_tests.dir/StackTests.cpp.obj"
	cd E:/GitRepo/Basics/DSACpp/tests && E:/GitRepo/Basics/DSACpp/nbproject/private/tools/localhost/MinGW/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/DataStructures_unit_tests.dir/StackTests.cpp.obj -MF CMakeFiles/DataStructures_unit_tests.dir/StackTests.cpp.obj.d -o CMakeFiles/DataStructures_unit_tests.dir/StackTests.cpp.obj -c E:/GitRepo/Basics/DSACpp/tests/StackTests.cpp

tests/CMakeFiles/DataStructures_unit_tests.dir/StackTests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DataStructures_unit_tests.dir/StackTests.cpp.i"
	cd E:/GitRepo/Basics/DSACpp/tests && E:/GitRepo/Basics/DSACpp/nbproject/private/tools/localhost/MinGW/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:/GitRepo/Basics/DSACpp/tests/StackTests.cpp > CMakeFiles/DataStructures_unit_tests.dir/StackTests.cpp.i

tests/CMakeFiles/DataStructures_unit_tests.dir/StackTests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DataStructures_unit_tests.dir/StackTests.cpp.s"
	cd E:/GitRepo/Basics/DSACpp/tests && E:/GitRepo/Basics/DSACpp/nbproject/private/tools/localhost/MinGW/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:/GitRepo/Basics/DSACpp/tests/StackTests.cpp -o CMakeFiles/DataStructures_unit_tests.dir/StackTests.cpp.s

tests/CMakeFiles/DataStructures_unit_tests.dir/Main.cpp.obj: tests/CMakeFiles/DataStructures_unit_tests.dir/flags.make
tests/CMakeFiles/DataStructures_unit_tests.dir/Main.cpp.obj: tests/CMakeFiles/DataStructures_unit_tests.dir/includes_CXX.rsp
tests/CMakeFiles/DataStructures_unit_tests.dir/Main.cpp.obj: tests/Main.cpp
tests/CMakeFiles/DataStructures_unit_tests.dir/Main.cpp.obj: tests/CMakeFiles/DataStructures_unit_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:/GitRepo/Basics/DSACpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object tests/CMakeFiles/DataStructures_unit_tests.dir/Main.cpp.obj"
	cd E:/GitRepo/Basics/DSACpp/tests && E:/GitRepo/Basics/DSACpp/nbproject/private/tools/localhost/MinGW/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tests/CMakeFiles/DataStructures_unit_tests.dir/Main.cpp.obj -MF CMakeFiles/DataStructures_unit_tests.dir/Main.cpp.obj.d -o CMakeFiles/DataStructures_unit_tests.dir/Main.cpp.obj -c E:/GitRepo/Basics/DSACpp/tests/Main.cpp

tests/CMakeFiles/DataStructures_unit_tests.dir/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DataStructures_unit_tests.dir/Main.cpp.i"
	cd E:/GitRepo/Basics/DSACpp/tests && E:/GitRepo/Basics/DSACpp/nbproject/private/tools/localhost/MinGW/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:/GitRepo/Basics/DSACpp/tests/Main.cpp > CMakeFiles/DataStructures_unit_tests.dir/Main.cpp.i

tests/CMakeFiles/DataStructures_unit_tests.dir/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DataStructures_unit_tests.dir/Main.cpp.s"
	cd E:/GitRepo/Basics/DSACpp/tests && E:/GitRepo/Basics/DSACpp/nbproject/private/tools/localhost/MinGW/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:/GitRepo/Basics/DSACpp/tests/Main.cpp -o CMakeFiles/DataStructures_unit_tests.dir/Main.cpp.s

# Object files for target DataStructures_unit_tests
DataStructures_unit_tests_OBJECTS = \
"CMakeFiles/DataStructures_unit_tests.dir/LinkedListTests.cpp.obj" \
"CMakeFiles/DataStructures_unit_tests.dir/QueueTests.cpp.obj" \
"CMakeFiles/DataStructures_unit_tests.dir/StackTests.cpp.obj" \
"CMakeFiles/DataStructures_unit_tests.dir/Main.cpp.obj"

# External object files for target DataStructures_unit_tests
DataStructures_unit_tests_EXTERNAL_OBJECTS =

tests/DataStructures_unit_tests.exe: tests/CMakeFiles/DataStructures_unit_tests.dir/LinkedListTests.cpp.obj
tests/DataStructures_unit_tests.exe: tests/CMakeFiles/DataStructures_unit_tests.dir/QueueTests.cpp.obj
tests/DataStructures_unit_tests.exe: tests/CMakeFiles/DataStructures_unit_tests.dir/StackTests.cpp.obj
tests/DataStructures_unit_tests.exe: tests/CMakeFiles/DataStructures_unit_tests.dir/Main.cpp.obj
tests/DataStructures_unit_tests.exe: tests/CMakeFiles/DataStructures_unit_tests.dir/build.make
tests/DataStructures_unit_tests.exe: tests/CMakeFiles/DataStructures_unit_tests.dir/linklibs.rsp
tests/DataStructures_unit_tests.exe: tests/CMakeFiles/DataStructures_unit_tests.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:/GitRepo/Basics/DSACpp/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable DataStructures_unit_tests.exe"
	cd E:/GitRepo/Basics/DSACpp/tests && "C:/Program Files/CMake/bin/cmake.exe" -E rm -f CMakeFiles/DataStructures_unit_tests.dir/objects.a
	cd E:/GitRepo/Basics/DSACpp/tests && E:/msys64/mingw64/bin/ar.exe cr CMakeFiles/DataStructures_unit_tests.dir/objects.a @CMakeFiles/DataStructures_unit_tests.dir/objects1.rsp
	cd E:/GitRepo/Basics/DSACpp/tests && E:/GitRepo/Basics/DSACpp/nbproject/private/tools/localhost/MinGW/g++.exe -g3 -gdwarf-2 -Wl,--whole-archive CMakeFiles/DataStructures_unit_tests.dir/objects.a -Wl,--no-whole-archive -o DataStructures_unit_tests.exe -Wl,--out-implib,libDataStructures_unit_tests.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/DataStructures_unit_tests.dir/linklibs.rsp

# Rule to build all files generated by this target.
tests/CMakeFiles/DataStructures_unit_tests.dir/build: tests/DataStructures_unit_tests.exe
.PHONY : tests/CMakeFiles/DataStructures_unit_tests.dir/build

tests/CMakeFiles/DataStructures_unit_tests.dir/clean:
	cd E:/GitRepo/Basics/DSACpp/tests && $(CMAKE_COMMAND) -P CMakeFiles/DataStructures_unit_tests.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/DataStructures_unit_tests.dir/clean

tests/CMakeFiles/DataStructures_unit_tests.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" E:/GitRepo/Basics/DSACpp E:/GitRepo/Basics/DSACpp/tests E:/GitRepo/Basics/DSACpp E:/GitRepo/Basics/DSACpp/tests E:/GitRepo/Basics/DSACpp/tests/CMakeFiles/DataStructures_unit_tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/DataStructures_unit_tests.dir/depend

