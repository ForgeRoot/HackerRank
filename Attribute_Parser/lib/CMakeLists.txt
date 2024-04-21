cmake_minimum_required(VERSION 3.19)
project(lib)

# Add all header files in the include directory
file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp")

# Add all source files in the src directory
file(GLOB SOURCE_LIST CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

# Add the library target
add_library(my_lib ${SOURCE_LIST} ${HEADER_LIST})

# Include the include directory
target_include_directories(my_lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

