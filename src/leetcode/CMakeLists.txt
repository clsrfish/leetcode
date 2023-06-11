string(REPLACE ${CMAKE_SOURCE_DIR} "" libname ${CMAKE_CURRENT_SOURCE_DIR})
string(SUBSTRING ${libname} 1 -1 libname)
string(REPLACE  "/" "_" libname ${libname})

aux_source_directory(. TESTFILES)
add_library(${libname} SHARED ${TESTFILES})