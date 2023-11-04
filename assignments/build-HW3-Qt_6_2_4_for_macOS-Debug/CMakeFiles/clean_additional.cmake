# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/HW3_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/HW3_autogen.dir/ParseCache.txt"
  "HW3_autogen"
  )
endif()
