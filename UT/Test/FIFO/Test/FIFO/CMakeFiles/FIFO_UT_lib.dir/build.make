# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/rzesz/Desktop/Coding/STM_Code/Slider_Controller/UT

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/rzesz/Desktop/Coding/STM_Code/Slider_Controller/UT/Test/FIFO

# Include any dependencies generated for this target.
include Test/FIFO/CMakeFiles/FIFO_UT_lib.dir/depend.make

# Include the progress variables for this target.
include Test/FIFO/CMakeFiles/FIFO_UT_lib.dir/progress.make

# Include the compile flags for this target's objects.
include Test/FIFO/CMakeFiles/FIFO_UT_lib.dir/flags.make

Test/FIFO/CMakeFiles/FIFO_UT_lib.dir/mnt/c/Users/rzesz/Desktop/Coding/STM_Code/Slider_Controller/Core/Src/FIFO.c.o: Test/FIFO/CMakeFiles/FIFO_UT_lib.dir/flags.make
Test/FIFO/CMakeFiles/FIFO_UT_lib.dir/mnt/c/Users/rzesz/Desktop/Coding/STM_Code/Slider_Controller/Core/Src/FIFO.c.o: /mnt/c/Users/rzesz/Desktop/Coding/STM_Code/Slider_Controller/Core/Src/FIFO.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/rzesz/Desktop/Coding/STM_Code/Slider_Controller/UT/Test/FIFO/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object Test/FIFO/CMakeFiles/FIFO_UT_lib.dir/mnt/c/Users/rzesz/Desktop/Coding/STM_Code/Slider_Controller/Core/Src/FIFO.c.o"
	cd /mnt/c/Users/rzesz/Desktop/Coding/STM_Code/Slider_Controller/UT/Test/FIFO/Test/FIFO && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/FIFO_UT_lib.dir/mnt/c/Users/rzesz/Desktop/Coding/STM_Code/Slider_Controller/Core/Src/FIFO.c.o   -c /mnt/c/Users/rzesz/Desktop/Coding/STM_Code/Slider_Controller/Core/Src/FIFO.c

Test/FIFO/CMakeFiles/FIFO_UT_lib.dir/mnt/c/Users/rzesz/Desktop/Coding/STM_Code/Slider_Controller/Core/Src/FIFO.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/FIFO_UT_lib.dir/mnt/c/Users/rzesz/Desktop/Coding/STM_Code/Slider_Controller/Core/Src/FIFO.c.i"
	cd /mnt/c/Users/rzesz/Desktop/Coding/STM_Code/Slider_Controller/UT/Test/FIFO/Test/FIFO && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/c/Users/rzesz/Desktop/Coding/STM_Code/Slider_Controller/Core/Src/FIFO.c > CMakeFiles/FIFO_UT_lib.dir/mnt/c/Users/rzesz/Desktop/Coding/STM_Code/Slider_Controller/Core/Src/FIFO.c.i

Test/FIFO/CMakeFiles/FIFO_UT_lib.dir/mnt/c/Users/rzesz/Desktop/Coding/STM_Code/Slider_Controller/Core/Src/FIFO.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/FIFO_UT_lib.dir/mnt/c/Users/rzesz/Desktop/Coding/STM_Code/Slider_Controller/Core/Src/FIFO.c.s"
	cd /mnt/c/Users/rzesz/Desktop/Coding/STM_Code/Slider_Controller/UT/Test/FIFO/Test/FIFO && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/c/Users/rzesz/Desktop/Coding/STM_Code/Slider_Controller/Core/Src/FIFO.c -o CMakeFiles/FIFO_UT_lib.dir/mnt/c/Users/rzesz/Desktop/Coding/STM_Code/Slider_Controller/Core/Src/FIFO.c.s

# Object files for target FIFO_UT_lib
FIFO_UT_lib_OBJECTS = \
"CMakeFiles/FIFO_UT_lib.dir/mnt/c/Users/rzesz/Desktop/Coding/STM_Code/Slider_Controller/Core/Src/FIFO.c.o"

# External object files for target FIFO_UT_lib
FIFO_UT_lib_EXTERNAL_OBJECTS =

Test/FIFO/libFIFO_UT_lib.a: Test/FIFO/CMakeFiles/FIFO_UT_lib.dir/mnt/c/Users/rzesz/Desktop/Coding/STM_Code/Slider_Controller/Core/Src/FIFO.c.o
Test/FIFO/libFIFO_UT_lib.a: Test/FIFO/CMakeFiles/FIFO_UT_lib.dir/build.make
Test/FIFO/libFIFO_UT_lib.a: Test/FIFO/CMakeFiles/FIFO_UT_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/rzesz/Desktop/Coding/STM_Code/Slider_Controller/UT/Test/FIFO/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libFIFO_UT_lib.a"
	cd /mnt/c/Users/rzesz/Desktop/Coding/STM_Code/Slider_Controller/UT/Test/FIFO/Test/FIFO && $(CMAKE_COMMAND) -P CMakeFiles/FIFO_UT_lib.dir/cmake_clean_target.cmake
	cd /mnt/c/Users/rzesz/Desktop/Coding/STM_Code/Slider_Controller/UT/Test/FIFO/Test/FIFO && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FIFO_UT_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Test/FIFO/CMakeFiles/FIFO_UT_lib.dir/build: Test/FIFO/libFIFO_UT_lib.a

.PHONY : Test/FIFO/CMakeFiles/FIFO_UT_lib.dir/build

Test/FIFO/CMakeFiles/FIFO_UT_lib.dir/clean:
	cd /mnt/c/Users/rzesz/Desktop/Coding/STM_Code/Slider_Controller/UT/Test/FIFO/Test/FIFO && $(CMAKE_COMMAND) -P CMakeFiles/FIFO_UT_lib.dir/cmake_clean.cmake
.PHONY : Test/FIFO/CMakeFiles/FIFO_UT_lib.dir/clean

Test/FIFO/CMakeFiles/FIFO_UT_lib.dir/depend:
	cd /mnt/c/Users/rzesz/Desktop/Coding/STM_Code/Slider_Controller/UT/Test/FIFO && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/rzesz/Desktop/Coding/STM_Code/Slider_Controller/UT /mnt/c/Users/rzesz/Desktop/Coding/STM_Code/Slider_Controller/UT/Test/FIFO /mnt/c/Users/rzesz/Desktop/Coding/STM_Code/Slider_Controller/UT/Test/FIFO /mnt/c/Users/rzesz/Desktop/Coding/STM_Code/Slider_Controller/UT/Test/FIFO/Test/FIFO /mnt/c/Users/rzesz/Desktop/Coding/STM_Code/Slider_Controller/UT/Test/FIFO/Test/FIFO/CMakeFiles/FIFO_UT_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Test/FIFO/CMakeFiles/FIFO_UT_lib.dir/depend

