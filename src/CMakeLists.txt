add_subdirectory(model)
add_subdirectory(utils)

set(LEETCODE_SRC_FILE "ALL" CACHE STRING "Which src files need compiling.")
if(${LEETCODE_SRC_FILE} STREQUAL "ALL" OR NOT EXISTS ${LEETCODE_SRC_FILE})
  aux_source_directory(. SRC)
  message(${SRC})
  add_library (src ${SRC})
else()
  add_library (src ${LEETCODE_SRC_FILE})
endif()

target_link_libraries(src model utils)