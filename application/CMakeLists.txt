cmake_minimum_required(VERSION 2.6)

project(application)

set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/*.cpp)
file(GLOB HEADER_FILES ${COMMON_INCLUDE_DIR}/core/*.h)

include_directories("${COMMON_INCLUDE_DIR}")

add_executable(application ${SRC_FILES} ${HEADER_FILES})
target_link_libraries(application core)
