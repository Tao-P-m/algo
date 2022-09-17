# CMake 最低版本号要求
cmake_minimum_required (VERSION 3.8)

# 项目信息
project (Demo1)


aux_source_directory(. DIR_SRCS)
add_subdirectory(math)
add_subdirectory(sort)
add_subdirectory(list)
add_subdirectory(tree)
add_subdirectory(regression)

add_executable(Demo main.cpp fread.cpp super_mario.cpp)
# 指定生成目标
target_link_libraries(Demo MathFunctions)
target_link_libraries(Demo SORT)
target_link_libraries(Demo LIST)
target_link_libraries(Demo TREE)
target_link_libraries(Demo REG)

