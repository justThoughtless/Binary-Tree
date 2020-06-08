cmake_minimum_required(VERSION 3.16)
project(binary_tree)

set(CMAKE_CXX_STANDARD 14)

add_executable(binary_tree main.cpp node.cpp node.h btree.cpp btree.h)