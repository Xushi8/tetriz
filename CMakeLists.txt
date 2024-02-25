cmake_minimum_required (VERSION 3.1)

set (CMAKE_C_STANDARD 11)
set (CMAKE_C_STANDARD_REQUIRED ON)
set (CMAKE_C_EXTENSIONS OFF)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)

if (NOT CMAKE_BUILD_TYPE)
    set (CMAKE_BUILD_TYPE Release)
endif ()

if (NOT CMAKE_LINK_WHAT_YOU_USE)
    set (CMAKE_LINK_WHAT_YOU_USE ON)
endif ()

# set (BUILD_SHARED_LIBS ON)

project (tetriz LANGUAGES C CXX VERSION 0.0.0)

include (${CMAKE_CURRENT_LIST_DIR}/cmake/options.cmake)
include (${CMAKE_CURRENT_LIST_DIR}/cmake/compiler_options.cmake)
include (${CMAKE_CURRENT_LIST_DIR}/cmake/compiler_definitions.cmake)
include (${CMAKE_CURRENT_LIST_DIR}/cmake/ccache.cmake)
include (${CMAKE_CURRENT_LIST_DIR}/cmake/package.cmake)
include (${CMAKE_CURRENT_LIST_DIR}/cmake/print_info.cmake)

add_subdirectory (src)
add_subdirectory (external)
