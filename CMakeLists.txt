cmake_minimum_required(VERSION 2.8)

cmake_minimum_required(VERSION 2.8)
INCLUDE(CMakeForceCompiler)
set(ARM_PREFIX arm-frc-linux-gnueabi)
set(CMAKE_SYSTEM_NAME Linux)
CMAKE_FORCE_CXX_COMPILER(${ARM_PREFIX}-g++ GNU)
CMAKE_FORCE_C_COMPILER(${ARM_PREFIX}-gcc GNU)
set(CMAKE_CXX_FLAGS "-std=c++1y -Wformat=2 -O0 -Wall -Wextra -Werror -pedantic -Wno-psabi -Wno-unused-parameter -fPIC" CACHE STRING "" FORCE)

project(robolibc)

get_filename_component(CMAKE_ROOT . REALPATH)

file(GLOB_RECURSE NI_LIBS ni-libraries/*.so*)


file(GLOB_RECURSE SRC_FILES src/*.cpp)
include_directories(src/Athena src/Athena/FRC_FPGA_ChipObject include)


add_library(RoboLib STATIC ${SRC_FILES})
target_link_libraries(RoboLib ${NI_LIBS})
