cmake_minimum_required(VERSION 3.19)
project(Attribute_Parser)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(lib)

add_executable(${PROJECT_NAME} main.cpp)


target_link_libraries(${PROJECT_NAME} PRIVATE my_lib)