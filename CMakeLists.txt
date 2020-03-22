cmake_minimum_required(VERSION 3.1)
project(xframe-examples)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(xtl REQUIRED)
find_package(xtensor REQUIRED)

add_executable(example1 src/example1.cpp)
add_executable(example4 src/example4.cpp)

if(MSVC)
    set(CMAKE_EXE_LINKER_FLAGS /MANIFEST:NO)
endif()

target_link_libraries(example1 xtensor xtensor::use_xsimd)  #xtensor::optimize)
target_link_libraries(example4 xtensor xtensor::use_xsimd)  #xtensor::optimize)
