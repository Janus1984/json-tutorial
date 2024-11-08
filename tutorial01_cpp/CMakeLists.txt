cmake_minimum_required (VERSION 3.12)
project (leptjson_test CXX)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -ansi -pedantic -Wall")
endif()

add_library(leptjson leptjson.cpp)
add_executable(leptjson_test test.cpp)

target_include_directories(leptjson_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(leptjson_test leptjson)
