string(REPLACE ${CMAKE_SOURCE_DIR} "" libname ${CMAKE_CURRENT_SOURCE_DIR})
string(SUBSTRING ${libname} 1 -1 libname)
string(REPLACE  "/" "_" libname ${libname})

aux_source_directory(. TESTFILES)
add_executable(${libname} ${TESTFILES})
target_link_libraries(${libname} src_model src_utils src_leetcode tests_utils)

include(GoogleTest)
gtest_discover_tests(${libname} XML_OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR} TEST_PREFIX ${libname}. DISCOVERY_MODE POST_BUILD)
