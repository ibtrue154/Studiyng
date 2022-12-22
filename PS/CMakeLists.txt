cmake_minimum_required(VERSION 3.22.1)

project(bmp)	

add_library(bmp STATIC bmp.cpp filtres.cpp)	

add_executable(main main.cpp)	

target_link_libraries(main bmp)	