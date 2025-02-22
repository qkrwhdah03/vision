cmake_minimum_required(VERSION 3.1)

project(VISION VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# dependency
find_package(Eigen3 REQUIRED)
message(STATUS "Eigen3 found: ${EIGEN3_INCLUDE_DIR}")
include_directories(${EIGEN3_INCLUDE_DIR})


# include
#message(STATUS "Include directories: ${CMAKE_SOURCE_DIR}/include")
include_directories(${CMAKE_SOURCE_DIR}/include)

# src
file(GLOB SRC_SOURCES src/*.cpp)
add_library(vision_lib ${SRC_SOURCES})

# Test
file(GLOB TEST_SOURCES test/*.cpp)
foreach(test_file ${TEST_SOURCES})
    get_filename_component(test_name ${test_file} NAME_WE)
    add_executable(${test_name} ${test_file})
    target_link_libraries(${test_name} vision_lib) 
endforeach()

# OpenCV
#find_package(OpenCV REQUIRED)
#include_directories(${OpenCV_INCLUDE_DIRS})

# Ceres
#find_package(Ceres REQUIRED)
#include_directories(${CERES_INCLUDE_DIRS})

#target_link_libraries(calibrate ${OpenCV_LIBS} ${CERES_LIBRARIES})    