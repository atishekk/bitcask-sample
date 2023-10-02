cmake_minimum_required(VERSION 3.10)
project(bitcask-sample)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(src)
include_directories(include)

add_executable(main main.cpp)

target_link_libraries(main bitcask-lib)
