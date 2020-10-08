cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(thread_pool)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_BUILD_TYPE "Release")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

# add_library(thread_pool safe_queue.h thread_pool.h)
add_executable(thread_pool_test thread_pool_test.cc)
target_link_libraries (thread_pool_test pthread)
