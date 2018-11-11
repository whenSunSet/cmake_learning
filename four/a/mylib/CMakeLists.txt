project(MakeTable)

add_executable(MakeTable MakeTable.cpp)

# 1.输出 Table 文件
# 2.将 Table 文件作为参数传入 MakeTable 项目中，并运行它
# 3.Table 的生成是依赖于 MakeTable 这个 project 的
# CMAKE_CURRENT_BINARY_DIR 表示某个 cmake 文件build之后的文件夹，比如这里就是指 build/mylib
add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
        COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
        DEPENDS MakeTable)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
# 将生成的表一起编译到 MathFunctions_Table 中去，供给
add_library(MathFunctions_Table mysqrt.cpp ${CMAKE_CURRENT_BINARY_DIR}/Table.h)
