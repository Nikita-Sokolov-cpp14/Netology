CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
project(Leaver)
set(source_project main.cpp)
include_directories(Lib)
add_executable(Leaver ${source_project})

add_subdirectory(Lib)
target_link_libraries(Leaver Leaver_lib)