cmake_minimum_required(VERSION 3.0.0)

project(main)

add_library(Server SHARED Servers.cpp)
add_executable(Client Client.cpp)
target_link_libraries(Client Server)