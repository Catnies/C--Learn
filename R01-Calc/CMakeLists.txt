# cmake -G "MinGW Makefiles"
# Cmake -> 对应操作系统的MakeFiles -> 使用Make/ninja调用编译器进行构建

# Cmake的最低适配版本
cmake_minimum_required(VERSION 3.31)

# 项目名称, 项目版本, 使用语言...
project(CLearn VERSION 0.1.0 LANGUAGES CXX)

# 目标为可执行程序, 使用的源代码为 OpenCalc.cpp
add_executable(CLearn CalcMain.cpp OpenCalc.cpp)

