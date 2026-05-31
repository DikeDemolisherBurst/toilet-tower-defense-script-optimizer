cmake_minimum_required(VERSION 3.10)
project(ToiletTowerDefenseScriptOptimizer)

set(CMAKE_CXX_STANDARD 17)

add_executable(ttd_optimizer src/main.cpp src/optimizer.cpp src/roblox_script.cpp)
target_include_directories(ttd_optimizer PRIVATE include)