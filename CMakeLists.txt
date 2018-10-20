cmake_minimum_required(VERSION 2.6) # cmake的最小版本
project(Tutorial) # 定义一个 project
project(Tutorial_B)
project(Tutorial_C)

# set(KEY VALUE) 这个方法可以用来添加键值对，需要使用 ${KEY} 这种形式来获取
set(Tutorial_VERSION_MAJOR 1)
set(Tutorial_VERSION_MINOR 0)

# 可以用来测试当前平台下是否有这个函数，需要在 confiture 之前
include (CheckFunctionExists)
check_function_exists (log HAVE_LOG)
check_function_exists (exp HAVE_EXP)

# 这里可以设置一个配置文件，我们可以在 TutorialConfig.h.in 中配置 set() 中设置的键值对
# PROJECT_SOURCE_DIR 表示的是源代码的路径
# PROJECT_BINARY_DIR 表示的是cmake build 的路径
configure_file("tutorial/TutorialConfig.h.in"
        "${PROJECT_BINARY_DIR}/TutorialConfig.h")

# include_directores 用于添加寻找头文件
include_directories("${PROJECT_BINARY_DIR}")

configure_file("${PROJECT_SOURCE_DIR}/Configure.h.in"
        "${PROJECT_BINARY_DIR}/Configure.h")

# 添加可选参数，这里表示是否使用和编译 MathFunctions 库
# 这里的 USE_MYMATH 可以在代码中使用
option(USE_MYMATH "use tutorial provided math implementation" OFF)

if(USE_MYMATH)
    include_directories("${PROJECT_SOURCE_DIR}/mathfunction")
    # add_subdirectory 用于添加源文件
    add_subdirectory(mathfunction)
    set(EXTRA_LIBS MathFunctions)
endif()

add_executable(Tutorial tutorial/tutorial.cpp) # 将文件 turorial.cpp加入Tutorial
add_executable(Tutorial_B tutorial/tutorial_b.cpp)
add_executable(Tutorial_C tutorial/tutorial_c.cpp)

# 将 MathFunctions 与 Tutorial_C 连接起来
target_link_libraries(Tutorial_C ${EXTRA_LIBS})

# 将库和头文件分别添加到 bin 和 include 文件夹中，最后移动到的地方如下
# /usr/local/bin/Tutorial
# /usr/local/include/TutorialConfig.h
# /usr/local/bin/libMathFunctions.a
# /usr/local/include/MathFunctions.h
install (TARGETS Tutorial DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h"
        DESTINATION include)

# 下面可以用来测试 install 是否成功
include(CTest)
# does the application run
add_test (TutorialRuns Tutorial 25)
# does it sqrt of 25
add_test (TutorialComp25 Tutorial 25)

# 添加包括当前平台所需要的任何运行时库
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
# 加入 Cpack 模块
include(Cpack)



