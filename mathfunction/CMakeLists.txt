# 添加了一个库
#add_library(MathFunctions mysqrt.cpp)
project(MakeTable)

add_executable(MakeTable MakeTable.cpp)

# 1.输出 Table 文件
# 2.将 Table 文件作为参数传入 MakeTable 项目中，并运行它
add_custom_command(OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
        COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
        DEPENDS MakeTable)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
# 将生成的表一起编译到 MathFunctions 中去
add_library(MathFunctions mysqrt.cpp ${CMAKE_CURRENT_BINARY_DIR}/Table.h)

# 将库添加到系统的 bin 目录中去
install(TARGETS MathFunctions DESTINATION bin)

# 将头文件添加到系统的 include 目录中去
install(FILES MathFunctions.h DESTINATION include)
