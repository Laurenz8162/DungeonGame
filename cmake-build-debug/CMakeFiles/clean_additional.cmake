# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\DungeonGame_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\DungeonGame_autogen.dir\\ParseCache.txt"
  "DungeonGame_autogen"
  )
endif()
