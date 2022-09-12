cmake_minimum_required(VERSION 3.12 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 11)
project(automated-finadvisor)

# This tells the compiler to not aggressively optimize and
# to include debugging information so that the debugger
# can properly read what's going on.
set(CMAKE_BUILD_TYPE Debug)

# Let's ensure -std=c++xx instead of -std=g++xx
set(CMAKE_CXX_EXTENSIONS OFF)

# Let's nicely support folders in IDE's
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Warning flags
if(MSVC)
    # warning level 3 and all warnings as errors
    add_compile_options(/W3 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wpedantic -Werror)
endif()

# FetchContent added in CMake 3.11, downloads during the configure step
include(FetchContent)

# FetchContent_MakeAvailable was not added until CMake 3.14
if(${CMAKE_VERSION} VERSION_LESS 3.14)
    include(cmake/add_FetchContent_MakeAvailable.cmake)
endif()

FetchContent_Declare(
        catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v2.11.1
)

# Adds Catch2 testing library
FetchContent_GetProperties(catch2)
if(NOT catch2_POPULATED)
    FetchContent_Populate(catch2)
    add_library(catch2 INTERFACE)
    target_include_directories(catch2 INTERFACE ${catch2_SOURCE_DIR}/single_include)
endif()

get_filename_component(CINDER_PATH ".." ABSOLUTE)
get_filename_component(APP_PATH "final-project-Anishmeka" ABSOLUTE)

include("${CINDER_PATH}/proj/cmake/modules/cinderMakeApp.cmake")

list(APPEND CORE_SOURCE_FILES src/core/momentum-prediction/momentum_training_data_factory.cc src/core/date.cc
        src/core/data_processor.cc src/core/momentum-prediction/momentum_calculator.cc
        src/core/momentum-prediction/momentum_model.cc src/core/volatility-prediction/volatility_calculator.cc
        src/core/volatility-prediction/volatility_model.cc src/core/volatility-prediction/volatility_training_data_factory.cc
        src/core/momentum-prediction/momentum_classifier.cc src/core/volatility-prediction/volatility_classifier.cc)

list(APPEND SOURCE_FILES    ${CORE_SOURCE_FILES}
        src/visualizer/automated_finadvisor_app.cc src/visualizer/technical_chart_visualizer.cc
        src/visualizer/candlestick_chart_visualizer.cc)

list(APPEND TEST_FILES tests/test_data_processor.cc tests/test_volatility_training_data_factory.cc
        tests/test_volatility_calculator.cc tests/test_momentum_training_data_factory.cc
        tests/test_momentum_calculator.cc)

add_executable(train-model apps/train_model_main.cc ${CORE_SOURCE_FILES})
target_include_directories(train-model PRIVATE include)

ci_make_app(
        APP_NAME        stock-data-visualizer
        CINDER_PATH     ${CINDER_PATH}
        SOURCES apps/cinder_app_main.cc ${SOURCE_FILES}
        INCLUDES include
)

ci_make_app(
        APP_NAME        automated-finadvisor-test
        CINDER_PATH     ${CINDER_PATH}
        SOURCES tests/test_main.cc ${SOURCE_FILES} ${TEST_FILES}
        INCLUDES include
        LIBRARIES       catch2
)

if(MSVC)
    set_property(TARGET final-project-test APPEND_STRING PROPERTY LINK_FLAGS " /SUBSYSTEM:CONSOLE")
endif()