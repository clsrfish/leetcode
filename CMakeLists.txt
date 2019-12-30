cmake_minimum_required(VERSION 3.0.0)
project(leetcode-cpp VERSION 0.1.0)
add_definitions(-std=c++11)

include(CTest)
enable_testing()

add_subdirectory(src)
aux_source_directory(. DIR_SRCS)
add_executable(Main ${DIR_SRCS})
target_link_libraries(Main LibSrc)

# build package installer start
include (InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE  "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
# build package installer end