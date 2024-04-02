cmake_minimum_required(VERSION 3.20)
project(L5_Client)
add_subdirectory("../libpqxx-7.9.0" libpqxx-build)

add_executable(L5_Client main.cpp)
target_compile_features(L5_Client PRIVATE cxx_std_17)
target_link_libraries(L5_Client pqxx)
