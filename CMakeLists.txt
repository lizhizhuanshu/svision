cmake_minimum_required(VERSION 3.7.0)
project(svision)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")

include_directories(./lodepng)
aux_source_directory(. DIR_SRCS)
list(APPEND DIR_SRCS ./lodepng/lodepng.cpp)

option(LUA_ENABLE_STATIC "enable static library" OFF)

if(LUA_ENABLE_STATIC)
    add_library(${PROJECT_NAME} STATIC ${DIR_SRCS})
else()
    add_library(${PROJECT_NAME} SHARED ${DIR_SRCS})
    set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")
    install_targets(/. ${PROJECT_NAME})
endif()

