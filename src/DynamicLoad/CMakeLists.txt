# 把源码编译成一个可执行文件
aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SRC_LIST)
add_executable(DynamicLoad ${SRC_LIST})

file(GLOB HEADERS "./*.h")
source_group("Header Files" FILES ${HEADERS})

# 链接其他库
target_link_libraries(DynamicLoad Qt5::Core BasePluginLib PluginManagerLib)





