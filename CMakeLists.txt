cmake_minimum_required(VERSION 2.6)

set(PROJECT_NAME WordsSearch)
project(${PROJECT_NAME} C CXX)

if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-Wall)
endif()

if (WIN32)
    add_definitions(-D_VARIADIC_MAX=10)
    set(CMAKE_EXE_LINKER_FLAGS_DEBUG_INIT "${CMAKE_EXE_LINKER_FLAGS_DEBUG_INIT} /SUBSYSTEM:WINDOWS")
endif()

set(COMMON_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(THIRDPARTY_PATH ${PROJECT_SOURCE_DIR}/thirdparty)
set(GTEST_PATH ${THIRDPARTY_PATH}/gtest)

include_directories("${COMMON_INCLUDE_DIR}")

add_subdirectory(application)
add_subdirectory(core)
add_subdirectory(${THIRDPARTY_PATH}/gtest)
add_subdirectory(tests)
