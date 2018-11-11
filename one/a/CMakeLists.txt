# 一个 cmake 组织的项目最少有下面这三行代码
cmake_minimum_required (VERSION 2.6) # 表示cmake的最小版本
project (Tutorial)# 新建一个project，这个project的名字叫Tutorial
add_executable(Tutorial tutorial.cpp) # 为 Tutorial 这个 project 添加一个可执行的文件tutorial.cpp

# 1.cmake的语法支持大小、小写和大小写混合例如上面的 project 可以写成 PROJECT