cmake_minimum_required (VERSION 2.6)
project (Tutorial_A)
# 我们可以在 cmake 的程序中添加键值对 set(KEY VALUE)，下面就是一个键值对的设置方式。
# 如果想要在 cmake 文件中取出这个键值对则需要使用 ${KEY} 的方式
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

## 这里可以设置一个配置文件，我们可以在 TutorialConfig.h.in 中配置 set() 中设置的键值对
## PROJECT_SOURCE_DIR 表示的是源代码的路径
## PROJECT_BINARY_DIR 表示的是cmake build 的路径
configure_file (
        "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
        "${PROJECT_BINARY_DIR}/TutorialConfig.h"
)

# 将 cmake 的 build 目录添加到cmake 寻找 include 文件的目录列表中，这样一来 cmake 就能找到前面生成的 TutorialConfig.h 配置文件
include_directories("${PROJECT_BINARY_DIR}")

add_executable(Tutorial_A tutorial.cpp)
