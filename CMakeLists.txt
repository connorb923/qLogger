cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 23)

project ("qLogger")

add_executable (qLogger 
    "src/logger.cpp"
    "src/logger.hpp"
 "test/test.cpp")