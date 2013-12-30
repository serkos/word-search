cmake_minimum_required(VERSION 2.6)

project(core)

set (PROJECT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/*.cpp)
file(GLOB HEADER_FILES ${PROJECT_INCLUDE_DIR}/*.h)

include_directories("${PROJECT_INCLUDE_DIR}")

add_library(core SHARED ${SRC_FILES} ${HEADER_FILES})
