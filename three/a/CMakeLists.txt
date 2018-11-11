cmake_minimum_required (VERSION 2.6)
project (Tutorial_Mylib_Install)

set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

configure_file (
        "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
        "${PROJECT_BINARY_DIR}/TutorialConfig.h"
)

# 添加一个是否使用我们自己的库的开关 USE_MYMATH，这个开关可以在 cmake 中直接使用
option (USE_MYMATH
        "Use tutorial provided math implementation" ON)

# 定义一个文件来储存 USE_MYMATH，以便在 cpp 文件中使用
configure_file("${PROJECT_SOURCE_DIR}/Configure.h.in"
        "${PROJECT_BINARY_DIR}/Configure.h")

include_directories("${PROJECT_BINARY_DIR}")

# 如果我们把开关设置为 ON，那么就将 mylib 集成进编译中，否则就不集成。
if (USE_MYMATH)
    include_directories ("${PROJECT_SOURCE_DIR}/mylib")
    add_subdirectory (mylib)
    set (EXTRA_LIBS MathFunctions_Install)
endif (USE_MYMATH)

add_executable (Tutorial_Mylib_Install tutorial.cpp)

# 将library 与 project 进行链接，使得 project 中可以调用 library 中的函数
target_link_libraries (Tutorial_Mylib_Install ${EXTRA_LIBS})

# TARGETS包含六种形式：ARCHIVE, LIBRARY, RUNTIME, OBJECTS, FRAMEWORK,  BUNDLE。注意Mathfunction_Install安装的是LIBRARY，Tutorial_Mylib_Install 是RUNTIME类型。
# FILE 将给定的文件复制到指定目录。如果没有给定权限参数，则由该表单安装的文件默认为OWNER_WRITE、OWNER_READ、GROUP_READ和WORLD_READ。
# TARGETS和FILE可指定为相对目录和绝对目录。
# DESTINATION在这里是一个相对路径，取默认值。在unix系统中指向 /usr/local 在windows上c:/Program Files/${PROJECT_NAME}。
# 也可以通过设置CMAKE_INSTALL_PREFIX这个变量来设置安装的路径，那么安装位置不指向/usr/local，而指向你所指定的目录。

# 安装这个可执行文件，将可执行文件和头文件分别添加到 bin 和 include 文件夹中，最后移动到的地方如下
# /usr/local/bin/Tutorial_Mylib_Install
# /usr/local/include/TutorialConfig.h
install (TARGETS Tutorial_Mylib_Install DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h"
         DESTINATION include)

