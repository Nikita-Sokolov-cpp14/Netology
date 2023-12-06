CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
project(Racing)
set(source_project main.cpp)
include_directories(Lib)
add_executable(Racing ${source_project})

add_subdirectory(Lib)
target_link_libraries(Racing Racing_lib)