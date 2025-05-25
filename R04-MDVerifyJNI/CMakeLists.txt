# cmake -G "MinGW Makefiles" -DCMAKE_TOOLCHAIN_FILE=F:/Vcpkg/scripts/buildsystems/vcpkg.cmake -DVCPKG_TARGET_TRIPLET=x64-mingw-dynamic .
# mingw32-make

# 构建流程: Cmake生成对应操作系统的MakeFiles -> 使用Make/ninja调用编译器读取Makefiles构建



# =========================
# 项目信息
# =========================

# Cmake的最低适配版本
cmake_minimum_required(VERSION 3.31)

# 项目信息
project(MDVerifyJNI 
    VERSION 0.1.0
    LANGUAGES CXX
)


# =========================
# 依赖管理
# =========================

find_package(Java REQUIRED Development)  # 查找 Java 开发环境 (JDK), "Development" 表示需要 JDK
find_package(JNI REQUIRED)               # JNI 库
find_package(CURL REQUIRED)              # CURL 库

# 创建库
add_library(mdverifyjni SHARED cn_chengzhiya_mhdfverify_Verify.cpp) # 创建动态库（SHARED）目标

# 目标文件夹
set_target_properties(mdverifyjni PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

# 依赖管理
target_include_directories(mdverifyjni PRIVATE
    ${JNI_INCLUDE_DIRS}     # 包含 JNI 头文件
)   

target_link_libraries(mdverifyjni PRIVATE 
    CURL::libcurl           # 链接 CURL
)           



# =========================
# 跨平台特定配置
# =========================

# Windows特定配置
if(WIN32)
    message(STATUS "配置Windows平台...")
    
    if(MINGW)
        message(STATUS "使用 MinGW 静态链接...")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -static-libgcc -static-libstdc++")
    endif()

    # Windows编译选项
    target_compile_definitions(mdverifyjni PRIVATE
        WIN32_LEAN_AND_MEAN     # 减少Windows头文件大小
        NOMINMAX                # 避免min/max宏冲突
    )
    
    # Windows链接器优化
    target_link_options(mdverifyjni PRIVATE
        -Wl,--gc-sections       # 移除未使用的代码段
        -Wl,--strip-all         # 移除调试信息
        -s                      # 压缩符号表
    )

# Linux特定配置
elseif(UNIX AND NOT APPLE)
    message(STATUS "配置Linux平台...")
    
    # Linux编译选项
    target_compile_options(mdverifyjni PRIVATE
        -fPIC  # 位置无关代码
    )
    
    # Linux可能需要链接pthread
    find_package(Threads REQUIRED)
    target_link_libraries(mdverifyjni PRIVATE Threads::Threads)

# macOS特定配置
elseif(APPLE)
    message(STATUS "配置macOS平台...")
    
    # macOS编译选项
    target_compile_options(mdverifyjni PRIVATE
        -fPIC
    )
    
    # macOS可能需要链接Foundation框架
    target_link_libraries(mdverifyjni PRIVATE "-framework Foundation")
    
endif()