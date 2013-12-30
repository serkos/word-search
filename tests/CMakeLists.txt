cmake_minimum_required(VERSION 2.6)

project(tests)

set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(GTEST_INCLUDE_DIR ${GTEST_PATH}/include)

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/*.cpp)
file(GLOB CORE_HEADER_FILES ${COMMON_INCLUDE_DIR}/core/*.h)
file(GLOB GTEST_HEADER_FILES ${GTEST_INCLUDE_DIR}/gtest/*.h)

include_directories("${COMMON_INCLUDE_DIR}")
include_directories("${GTEST_INCLUDE_DIR}")

add_executable(tests ${SRC_FILES} ${CORE_HEADER_FILES} ${GTEST_HEADER_FILES})
target_link_libraries(tests core gtest gtest_main)
