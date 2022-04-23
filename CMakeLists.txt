cmake_minimum_required(VERSION 3.7.0)
project(svision)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")

option(SVISION_SHARED "build shared library" ON)
option(SVISION_STATIC "build static library" OFF)

include_directories(./lodepng)
aux_source_directory(. DIR_SRCS)
list(APPEND DIR_SRCS ./lodepng/lodepng.cpp)

if(SVISION_SHARED)
    add_library(${PROJECT_NAME} SHARED ${DIR_SRCS})
    target_link_libraries(${PROJECT_NAME})
    set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")
endif()

if(SVISION_STATIC)
    add_library(${PROJECT_NAME}_static STATIC ${DIR_SRCS})
    target_link_libraries(${PROJECT_NAME}_static)
endif()