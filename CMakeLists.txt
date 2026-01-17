cmake_minimum_required(VERSION 4.1)
project(olympiad)

set(CMAKE_CXX_STANDARD 20)

add_executable(dfs graphs/dfs.cpp)
add_executable(bfs graphs/bfs.cpp)
add_executable(dijkstra graphs/dijkstra.cpp)
add_executable(kruskal graphs/kruskal.cpp)
add_executable(kmp texts/kmp.cpp)