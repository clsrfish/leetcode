cmake_minimum_required(VERSION 3.5.0)
cmake_path(GET CMAKE_SOURCE_DIR FILENAME projectFolder)
project(${projectFolder} VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
if("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
# https://github.com/google/sanitizers/wiki/AddressSanitizer
    set(CMAKE_CXX_FLAGS "-Wall -Werror=return-type -fsanitize=address,undefined -fno-omit-frame-pointer ${CMAKE_CXX_FLAGS}")
else()
    set(CMAKE_CXX_FLAGS "-O0 ${CMAKE_CXX_FLAGS}")
endif()

message(${CMAKE_CXX_FLAGS})

include_directories(
    /usr/local/include
    ${PROJECT_BINARY_DIR}
)
link_directories(
    /usr/local/lib
    ${PROJECT_BINARY_DIR}
)

# Test case
enable_testing()
include(${CMAKE_SOURCE_DIR}/cmake/gtest.cmake)

add_subdirectory(src)
add_subdirectory(tests)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
