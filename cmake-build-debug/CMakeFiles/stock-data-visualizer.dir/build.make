# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/stock-data-visualizer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/stock-data-visualizer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/stock-data-visualizer.dir/flags.make

Debug/stock-data-visualizer/stock-data-visualizer.app/Contents/Resources/CinderApp.icns: /Users/anishmeka/Desktop/cinder_0.9.2_mac/samples/data/CinderApp.icns
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Copying OS X content Debug/stock-data-visualizer/stock-data-visualizer.app/Contents/Resources/CinderApp.icns"
	$(CMAKE_COMMAND) -E copy /Users/anishmeka/Desktop/cinder_0.9.2_mac/samples/data/CinderApp.icns Debug/stock-data-visualizer/stock-data-visualizer.app/Contents/Resources/CinderApp.icns

CMakeFiles/stock-data-visualizer.dir/apps/cinder_app_main.cc.o: CMakeFiles/stock-data-visualizer.dir/flags.make
CMakeFiles/stock-data-visualizer.dir/apps/cinder_app_main.cc.o: ../apps/cinder_app_main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/stock-data-visualizer.dir/apps/cinder_app_main.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stock-data-visualizer.dir/apps/cinder_app_main.cc.o -c /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/apps/cinder_app_main.cc

CMakeFiles/stock-data-visualizer.dir/apps/cinder_app_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stock-data-visualizer.dir/apps/cinder_app_main.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/apps/cinder_app_main.cc > CMakeFiles/stock-data-visualizer.dir/apps/cinder_app_main.cc.i

CMakeFiles/stock-data-visualizer.dir/apps/cinder_app_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stock-data-visualizer.dir/apps/cinder_app_main.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/apps/cinder_app_main.cc -o CMakeFiles/stock-data-visualizer.dir/apps/cinder_app_main.cc.s

CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_training_data_factory.cc.o: CMakeFiles/stock-data-visualizer.dir/flags.make
CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_training_data_factory.cc.o: ../src/core/momentum-prediction/momentum_training_data_factory.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_training_data_factory.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_training_data_factory.cc.o -c /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/src/core/momentum-prediction/momentum_training_data_factory.cc

CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_training_data_factory.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_training_data_factory.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/src/core/momentum-prediction/momentum_training_data_factory.cc > CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_training_data_factory.cc.i

CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_training_data_factory.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_training_data_factory.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/src/core/momentum-prediction/momentum_training_data_factory.cc -o CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_training_data_factory.cc.s

CMakeFiles/stock-data-visualizer.dir/src/core/date.cc.o: CMakeFiles/stock-data-visualizer.dir/flags.make
CMakeFiles/stock-data-visualizer.dir/src/core/date.cc.o: ../src/core/date.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/stock-data-visualizer.dir/src/core/date.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stock-data-visualizer.dir/src/core/date.cc.o -c /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/src/core/date.cc

CMakeFiles/stock-data-visualizer.dir/src/core/date.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stock-data-visualizer.dir/src/core/date.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/src/core/date.cc > CMakeFiles/stock-data-visualizer.dir/src/core/date.cc.i

CMakeFiles/stock-data-visualizer.dir/src/core/date.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stock-data-visualizer.dir/src/core/date.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/src/core/date.cc -o CMakeFiles/stock-data-visualizer.dir/src/core/date.cc.s

CMakeFiles/stock-data-visualizer.dir/src/core/data_processor.cc.o: CMakeFiles/stock-data-visualizer.dir/flags.make
CMakeFiles/stock-data-visualizer.dir/src/core/data_processor.cc.o: ../src/core/data_processor.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/stock-data-visualizer.dir/src/core/data_processor.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stock-data-visualizer.dir/src/core/data_processor.cc.o -c /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/src/core/data_processor.cc

CMakeFiles/stock-data-visualizer.dir/src/core/data_processor.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stock-data-visualizer.dir/src/core/data_processor.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/src/core/data_processor.cc > CMakeFiles/stock-data-visualizer.dir/src/core/data_processor.cc.i

CMakeFiles/stock-data-visualizer.dir/src/core/data_processor.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stock-data-visualizer.dir/src/core/data_processor.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/src/core/data_processor.cc -o CMakeFiles/stock-data-visualizer.dir/src/core/data_processor.cc.s

CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_calculator.cc.o: CMakeFiles/stock-data-visualizer.dir/flags.make
CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_calculator.cc.o: ../src/core/momentum-prediction/momentum_calculator.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_calculator.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_calculator.cc.o -c /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/src/core/momentum-prediction/momentum_calculator.cc

CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_calculator.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_calculator.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/src/core/momentum-prediction/momentum_calculator.cc > CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_calculator.cc.i

CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_calculator.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_calculator.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/src/core/momentum-prediction/momentum_calculator.cc -o CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_calculator.cc.s

CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_model.cc.o: CMakeFiles/stock-data-visualizer.dir/flags.make
CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_model.cc.o: ../src/core/momentum-prediction/momentum_model.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_model.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_model.cc.o -c /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/src/core/momentum-prediction/momentum_model.cc

CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_model.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_model.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/src/core/momentum-prediction/momentum_model.cc > CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_model.cc.i

CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_model.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_model.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/src/core/momentum-prediction/momentum_model.cc -o CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_model.cc.s

CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_calculator.cc.o: CMakeFiles/stock-data-visualizer.dir/flags.make
CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_calculator.cc.o: ../src/core/volatility-prediction/volatility_calculator.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_calculator.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_calculator.cc.o -c /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/src/core/volatility-prediction/volatility_calculator.cc

CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_calculator.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_calculator.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/src/core/volatility-prediction/volatility_calculator.cc > CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_calculator.cc.i

CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_calculator.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_calculator.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/src/core/volatility-prediction/volatility_calculator.cc -o CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_calculator.cc.s

CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_model.cc.o: CMakeFiles/stock-data-visualizer.dir/flags.make
CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_model.cc.o: ../src/core/volatility-prediction/volatility_model.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_model.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_model.cc.o -c /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/src/core/volatility-prediction/volatility_model.cc

CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_model.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_model.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/src/core/volatility-prediction/volatility_model.cc > CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_model.cc.i

CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_model.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_model.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/src/core/volatility-prediction/volatility_model.cc -o CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_model.cc.s

CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_training_data_factory.cc.o: CMakeFiles/stock-data-visualizer.dir/flags.make
CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_training_data_factory.cc.o: ../src/core/volatility-prediction/volatility_training_data_factory.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_training_data_factory.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_training_data_factory.cc.o -c /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/src/core/volatility-prediction/volatility_training_data_factory.cc

CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_training_data_factory.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_training_data_factory.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/src/core/volatility-prediction/volatility_training_data_factory.cc > CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_training_data_factory.cc.i

CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_training_data_factory.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_training_data_factory.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/src/core/volatility-prediction/volatility_training_data_factory.cc -o CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_training_data_factory.cc.s

CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_classifier.cc.o: CMakeFiles/stock-data-visualizer.dir/flags.make
CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_classifier.cc.o: ../src/core/momentum-prediction/momentum_classifier.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_classifier.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_classifier.cc.o -c /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/src/core/momentum-prediction/momentum_classifier.cc

CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_classifier.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_classifier.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/src/core/momentum-prediction/momentum_classifier.cc > CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_classifier.cc.i

CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_classifier.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_classifier.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/src/core/momentum-prediction/momentum_classifier.cc -o CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_classifier.cc.s

CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_classifier.cc.o: CMakeFiles/stock-data-visualizer.dir/flags.make
CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_classifier.cc.o: ../src/core/volatility-prediction/volatility_classifier.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_classifier.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_classifier.cc.o -c /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/src/core/volatility-prediction/volatility_classifier.cc

CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_classifier.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_classifier.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/src/core/volatility-prediction/volatility_classifier.cc > CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_classifier.cc.i

CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_classifier.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_classifier.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/src/core/volatility-prediction/volatility_classifier.cc -o CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_classifier.cc.s

CMakeFiles/stock-data-visualizer.dir/src/visualizer/automated_finadvisor_app.cc.o: CMakeFiles/stock-data-visualizer.dir/flags.make
CMakeFiles/stock-data-visualizer.dir/src/visualizer/automated_finadvisor_app.cc.o: ../src/visualizer/automated_finadvisor_app.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/stock-data-visualizer.dir/src/visualizer/automated_finadvisor_app.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stock-data-visualizer.dir/src/visualizer/automated_finadvisor_app.cc.o -c /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/src/visualizer/automated_finadvisor_app.cc

CMakeFiles/stock-data-visualizer.dir/src/visualizer/automated_finadvisor_app.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stock-data-visualizer.dir/src/visualizer/automated_finadvisor_app.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/src/visualizer/automated_finadvisor_app.cc > CMakeFiles/stock-data-visualizer.dir/src/visualizer/automated_finadvisor_app.cc.i

CMakeFiles/stock-data-visualizer.dir/src/visualizer/automated_finadvisor_app.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stock-data-visualizer.dir/src/visualizer/automated_finadvisor_app.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/src/visualizer/automated_finadvisor_app.cc -o CMakeFiles/stock-data-visualizer.dir/src/visualizer/automated_finadvisor_app.cc.s

CMakeFiles/stock-data-visualizer.dir/src/visualizer/technical_chart_visualizer.cc.o: CMakeFiles/stock-data-visualizer.dir/flags.make
CMakeFiles/stock-data-visualizer.dir/src/visualizer/technical_chart_visualizer.cc.o: ../src/visualizer/technical_chart_visualizer.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/stock-data-visualizer.dir/src/visualizer/technical_chart_visualizer.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stock-data-visualizer.dir/src/visualizer/technical_chart_visualizer.cc.o -c /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/src/visualizer/technical_chart_visualizer.cc

CMakeFiles/stock-data-visualizer.dir/src/visualizer/technical_chart_visualizer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stock-data-visualizer.dir/src/visualizer/technical_chart_visualizer.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/src/visualizer/technical_chart_visualizer.cc > CMakeFiles/stock-data-visualizer.dir/src/visualizer/technical_chart_visualizer.cc.i

CMakeFiles/stock-data-visualizer.dir/src/visualizer/technical_chart_visualizer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stock-data-visualizer.dir/src/visualizer/technical_chart_visualizer.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/src/visualizer/technical_chart_visualizer.cc -o CMakeFiles/stock-data-visualizer.dir/src/visualizer/technical_chart_visualizer.cc.s

CMakeFiles/stock-data-visualizer.dir/src/visualizer/candlestick_chart_visualizer.cc.o: CMakeFiles/stock-data-visualizer.dir/flags.make
CMakeFiles/stock-data-visualizer.dir/src/visualizer/candlestick_chart_visualizer.cc.o: ../src/visualizer/candlestick_chart_visualizer.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/stock-data-visualizer.dir/src/visualizer/candlestick_chart_visualizer.cc.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stock-data-visualizer.dir/src/visualizer/candlestick_chart_visualizer.cc.o -c /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/src/visualizer/candlestick_chart_visualizer.cc

CMakeFiles/stock-data-visualizer.dir/src/visualizer/candlestick_chart_visualizer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stock-data-visualizer.dir/src/visualizer/candlestick_chart_visualizer.cc.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/src/visualizer/candlestick_chart_visualizer.cc > CMakeFiles/stock-data-visualizer.dir/src/visualizer/candlestick_chart_visualizer.cc.i

CMakeFiles/stock-data-visualizer.dir/src/visualizer/candlestick_chart_visualizer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stock-data-visualizer.dir/src/visualizer/candlestick_chart_visualizer.cc.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/src/visualizer/candlestick_chart_visualizer.cc -o CMakeFiles/stock-data-visualizer.dir/src/visualizer/candlestick_chart_visualizer.cc.s

# Object files for target stock-data-visualizer
stock__data__visualizer_OBJECTS = \
"CMakeFiles/stock-data-visualizer.dir/apps/cinder_app_main.cc.o" \
"CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_training_data_factory.cc.o" \
"CMakeFiles/stock-data-visualizer.dir/src/core/date.cc.o" \
"CMakeFiles/stock-data-visualizer.dir/src/core/data_processor.cc.o" \
"CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_calculator.cc.o" \
"CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_model.cc.o" \
"CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_calculator.cc.o" \
"CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_model.cc.o" \
"CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_training_data_factory.cc.o" \
"CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_classifier.cc.o" \
"CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_classifier.cc.o" \
"CMakeFiles/stock-data-visualizer.dir/src/visualizer/automated_finadvisor_app.cc.o" \
"CMakeFiles/stock-data-visualizer.dir/src/visualizer/technical_chart_visualizer.cc.o" \
"CMakeFiles/stock-data-visualizer.dir/src/visualizer/candlestick_chart_visualizer.cc.o"

# External object files for target stock-data-visualizer
stock__data__visualizer_EXTERNAL_OBJECTS =

Debug/stock-data-visualizer/stock-data-visualizer.app/Contents/MacOS/stock-data-visualizer: CMakeFiles/stock-data-visualizer.dir/apps/cinder_app_main.cc.o
Debug/stock-data-visualizer/stock-data-visualizer.app/Contents/MacOS/stock-data-visualizer: CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_training_data_factory.cc.o
Debug/stock-data-visualizer/stock-data-visualizer.app/Contents/MacOS/stock-data-visualizer: CMakeFiles/stock-data-visualizer.dir/src/core/date.cc.o
Debug/stock-data-visualizer/stock-data-visualizer.app/Contents/MacOS/stock-data-visualizer: CMakeFiles/stock-data-visualizer.dir/src/core/data_processor.cc.o
Debug/stock-data-visualizer/stock-data-visualizer.app/Contents/MacOS/stock-data-visualizer: CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_calculator.cc.o
Debug/stock-data-visualizer/stock-data-visualizer.app/Contents/MacOS/stock-data-visualizer: CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_model.cc.o
Debug/stock-data-visualizer/stock-data-visualizer.app/Contents/MacOS/stock-data-visualizer: CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_calculator.cc.o
Debug/stock-data-visualizer/stock-data-visualizer.app/Contents/MacOS/stock-data-visualizer: CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_model.cc.o
Debug/stock-data-visualizer/stock-data-visualizer.app/Contents/MacOS/stock-data-visualizer: CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_training_data_factory.cc.o
Debug/stock-data-visualizer/stock-data-visualizer.app/Contents/MacOS/stock-data-visualizer: CMakeFiles/stock-data-visualizer.dir/src/core/momentum-prediction/momentum_classifier.cc.o
Debug/stock-data-visualizer/stock-data-visualizer.app/Contents/MacOS/stock-data-visualizer: CMakeFiles/stock-data-visualizer.dir/src/core/volatility-prediction/volatility_classifier.cc.o
Debug/stock-data-visualizer/stock-data-visualizer.app/Contents/MacOS/stock-data-visualizer: CMakeFiles/stock-data-visualizer.dir/src/visualizer/automated_finadvisor_app.cc.o
Debug/stock-data-visualizer/stock-data-visualizer.app/Contents/MacOS/stock-data-visualizer: CMakeFiles/stock-data-visualizer.dir/src/visualizer/technical_chart_visualizer.cc.o
Debug/stock-data-visualizer/stock-data-visualizer.app/Contents/MacOS/stock-data-visualizer: CMakeFiles/stock-data-visualizer.dir/src/visualizer/candlestick_chart_visualizer.cc.o
Debug/stock-data-visualizer/stock-data-visualizer.app/Contents/MacOS/stock-data-visualizer: CMakeFiles/stock-data-visualizer.dir/build.make
Debug/stock-data-visualizer/stock-data-visualizer.app/Contents/MacOS/stock-data-visualizer: /Users/anishmeka/Desktop/cinder_0.9.2_mac/lib/macosx/Debug/libcinder.a
Debug/stock-data-visualizer/stock-data-visualizer.app/Contents/MacOS/stock-data-visualizer: /Users/anishmeka/Desktop/cinder_0.9.2_mac/lib/macosx/libboost_system.a
Debug/stock-data-visualizer/stock-data-visualizer.app/Contents/MacOS/stock-data-visualizer: /Users/anishmeka/Desktop/cinder_0.9.2_mac/lib/macosx/libboost_filesystem.a
Debug/stock-data-visualizer/stock-data-visualizer.app/Contents/MacOS/stock-data-visualizer: CMakeFiles/stock-data-visualizer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Linking CXX executable Debug/stock-data-visualizer/stock-data-visualizer.app/Contents/MacOS/stock-data-visualizer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stock-data-visualizer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/stock-data-visualizer.dir/build: Debug/stock-data-visualizer/stock-data-visualizer.app/Contents/MacOS/stock-data-visualizer
CMakeFiles/stock-data-visualizer.dir/build: Debug/stock-data-visualizer/stock-data-visualizer.app/Contents/Resources/CinderApp.icns

.PHONY : CMakeFiles/stock-data-visualizer.dir/build

CMakeFiles/stock-data-visualizer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/stock-data-visualizer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/stock-data-visualizer.dir/clean

CMakeFiles/stock-data-visualizer.dir/depend:
	cd /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/cmake-build-debug /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/cmake-build-debug /Users/anishmeka/Desktop/cinder_0.9.2_mac/my-projects/final-project-Anishmeka/cmake-build-debug/CMakeFiles/stock-data-visualizer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/stock-data-visualizer.dir/depend

