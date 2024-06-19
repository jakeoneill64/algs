cmake_minimum_required(VERSION 3.21)
project(nth_palindrome_length)

set(CMAKE_CXX_STANDARD 20)
link_directories(lib)
include_directories(${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/src/main)

file(GLOB_RECURSE LIB_SOURCES ${CMAKE_SOURCE_DIR}/src/main/*)
add_library(nth_palindrome_length STATIC ${LIB_SOURCES})

add_executable(nth_palindrome_suite src/test/NthPalindromeSuite.cpp src/main/NthPalindromeLength.h)
target_link_libraries(nth_palindrome_suite gtest.a nth_palindrome_length)

add_test(NAME nth_palindrome_suite COMMAND nth_palindrome_suite)
