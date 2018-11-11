cmake_minimum_required (VERSION 2.6)
project (Tutorial_Mylib_Table)

# 可以用来测试当前平台下是否有这个函数，需要在 confiture 之前
include (CheckFunctionExists)
check_function_exists (log HAVE_LOG)
check_function_exists (exp HAVE_EXP)

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
    set (EXTRA_LIBS MathFunctions_Table)
endif (USE_MYMATH)

add_executable (Tutorial_Mylib_Table tutorial.cpp)

# 将library 与 project 进行链接，使得 project 中可以调用 library 中的函数
target_link_libraries (Tutorial_Mylib_Table ${EXTRA_LIBS})

