# cmake -G "MinGW Makefiles" -> 根据 CmakeLists 生成 MakeFiles .
# mingw32-make ->  根据 MakeFiles 去生成最终的文件.
# Cmake -> 对应操作系统的MakeFiles -> 使用Make/ninja调用编译器进行构建

# Cmake的最低适配版本
cmake_minimum_required(VERSION 3.31)

# 项目名称, 项目版本, 使用语言...
project(SimpleLib VERSION 0.1.0 LANGUAGES CXX)

# 创建库
add_library(simplelib_shared SHARED SimpleLib.cpp) # 创建动态库（SHARED）目标
add_library(simplelib_static STATIC SimpleLib.cpp) # 创建静态库（STATIC）目标

# 目标文件夹
set_target_properties(simplelib_shared PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)
set_target_properties(simplelib_static PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)