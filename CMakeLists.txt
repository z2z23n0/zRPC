# 设置cmake的最低版本
cmake_minimum_required(VERSION 3.0)

# 设置项目名称
project(zRPC)

# 设置C++版本
set(CMAKE_CXX_STANDARD 11)

# 设置编译选项
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -g)

# 设置项目可执行文件的输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
# 设置项目库文件的输出路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# 设置项目头文件搜索路径
include_directories(${PROJECT_SOURCE_DIR}/src/include)
include_directories(${PROJECT_SOURCE_DIR}/examples)
# 设置项目库文件搜索路径
link_directories(${PROJECT_SOURCE_DIR}/lib)

# src包含了zrpc框架所有的相关代码
add_subdirectory(src)
# examples包含了zrpc框架使用的示例代码
add_subdirectory(examples)