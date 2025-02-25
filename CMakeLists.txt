
cmake_minimum_required(VERSION 3.0)

project(my_utils)

set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH "/opt/miniconda3/lib")

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} include)


add_executable(tests tests/test_str_utils.cpp)
target_link_libraries(tests GTest::GTest GTest::Main)
