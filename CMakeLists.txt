cmake_minimum_required(VERSION 3.31.1)  # cmake版本最低要求
project(DynamicLoadDemo)  # 设置工程名称

# set(CMAKE_CXX_STANDARD 11)  # 指定 C++ 版本
#set(CMAKE_BUILD_TYPE Release)  # 调试使用Debug，可以查看中间变量；发布使用Release，运行速度快

# 强制使用 Release 构建类型，生成调试符号
set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Zi /DEBUG")
set(CMAKE_LINKER_FLAGS_RELEASE "${CMAKE_LINKER_FLAGS_RELEASE} /DEBUG")

#指定调试文件生成目录
set(CMAKE_PDB_OUTPUT_DIRECTORY "./pdbs")

# 手动设置 Qt5 根目录路径
find_package(Qt5 REQUIRED COMPONENTS Widgets Core Gui)
message(STATUS "Qt5Core include directories: ${Qt5Core_INCLUDE_DIRS}")


# 设置全局头文件路径和库文件路径
set(GLOBAL_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/src")
set(GLOBAL_LIB_DIR "${CMAKE_SOURCE_DIR}/bin")

# 添加全局 include 和 library 路径
include_directories(${GLOBAL_INCLUDE_DIR})
link_directories(${GLOBAL_LIB_DIR})

message("${PROJECT_SOURCE_DIR}=" ${PROJECT_SOURCE_DIR})

# 这里设置好路径后，进入子模块的cmake时不用再次设置
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)  # 设置可执行文件的输出目录
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)	   # 设置库文件的输出目录

ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/src/BasePluginLib)     # 会调用该目录中的CMakeLists.txt进行编译生成静态库
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/src/DynamicLoad)     # 会调用该目录中的CMakeLists.txt进行编译生成静态库
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/src/MyPlugin)     # 会调用该目录中的CMakeLists.txt进行编译生成动态库
ADD_SUBDIRECTORY(${PROJECT_SOURCE_DIR}/src/PluginManagerLib)    # 会调用该目录中的CMakeLists.txt进行编译生成可执行文件

# 在 Visual Studio 中设置调试目标
set_target_properties(DynamicLoad PROPERTIES
    VS_DEBUGGER_COMMAND "${CMAKE_BINARY_DIR}/DynamicLoad"
)

