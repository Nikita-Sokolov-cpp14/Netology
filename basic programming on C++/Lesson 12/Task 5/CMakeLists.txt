CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
project(Figure)
set(source_project main.cpp)
include_directories(Lib)
add_executable(Figure ${source_project})

add_subdirectory(Lib)
target_link_libraries(Figure Figure_lib)