cmake_minimum_required (VERSION 2.6)
# 声明了一个 library 名为 MathFunctions，他包含一个可执行文件 mysqrt.cpp
add_library(MathFunctions_Install mysqrt.cpp)

# 安装这个库，将库和头文件分别添加到 bin 和 include 文件夹中，最后移动到的地方如下
# /usr/local/bin/libMathFunctions_Install.a
# /usr/local/include/MathFunctions.h
install (TARGETS MathFunctions_Install DESTINATION bin)
install (FILES MathFunctions.h DESTINATION include)
