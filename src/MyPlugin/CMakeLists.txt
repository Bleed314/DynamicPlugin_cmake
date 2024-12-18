# 查找所有源文件和头文件
file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
file(GLOB HEADERS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

# 将源文件和头文件加入到可执行文件中
add_library(MyPlugin SHARED
    ${SOURCES}
    ${HEADERS}
)

target_link_libraries(MyPlugin Qt5::Core BasePluginLib)

