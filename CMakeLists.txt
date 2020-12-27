cmake_minimum_required(VERSION 3.0.0)
project(main VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(
    /usr/local/include
    ${PROJECT_BINARY_DIR}
)
link_directories(
    /usr/local/lib
    ${PROJECT_BINARY_DIR}
)

add_subdirectory(src)
aux_source_directory(. DIR_SRCS)
add_executable(Main ${DIR_SRCS})
target_link_libraries(Main LibSrc)

# Test case
include(CTest)
enable_testing()

# build package installer start
include (InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE  "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
# build package installer end