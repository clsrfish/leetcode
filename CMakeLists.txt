cmake_minimum_required(VERSION 3.0.0)
project(leetcode VERSION 0.0.1)
include("ColoriedMessage.cmake")

set(CMAKE_CXX_STANDARD 14)
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

add_subdirectory(src)
# aux_source_directory(. SRCS)
# target_link_libraries(${PROJECT_NAME} src)

# Test case
enable_testing()

# gtest configurations
include(FetchContent)
FetchContent_Declare(
    gtest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.10.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_GetProperties(gtest)
if(NOT gtest_POPULATED)
    FetchContent_Populate(gtest)
    # message(${gtest_SOURCE_DIR} ${gtest_BINARY_DIR})
    add_subdirectory(${gtest_SOURCE_DIR} ${gtest_BINARY_DIR})
endif()

# test cases
set(LEETCODE_PROBLEM "ALL" CACHE STRING "Choose the problem to run, all problems will be build if not specified or not found.")
set(LEETCODE_PROBLEM_FINAL "ALL")
if(NOT ${LEETCODE_PROBLEM} STREQUAL "ALL")
    set(TEST_SUITE_SRC ${CMAKE_CURRENT_SOURCE_DIR}/test/${LEETCODE_PROBLEM}_test.cpp)
    if(EXISTS ${TEST_SUITE_SRC})
        set(LEETCODE_PROBLEM_FINAL ${TEST_SUITE_SRC})
    else()
        message(FATAL_ERROR "Leetcode[" ${LEETCODE_PROBLEM} "] not found, plz check your code")
    endif()
endif()

if(${LEETCODE_PROBLEM_FINAL} STREQUAL "ALL")
    message(STATUS "Building all leetcode problems.")
    aux_source_directory(./test TEST_SUIT_SRCS)
    add_executable(${PROJECT_NAME} ${TEST_SUIT_SRCS})
else()
    message(STATUS "Building leetcode[" ${LEETCODE_PROBLEM} "]")
    add_executable(${PROJECT_NAME} ${LEETCODE_PROBLEM_FINAL})
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE src gtest_main)
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

# build package installer start
include (InstallRequiredSystemLibraries)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CPACK_RESOURCE_FILE_LICENSE  "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_SET_DESTDIR ON)
include(CPack)
# build package installer end