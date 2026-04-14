cmake_minimum_required(VERSION 3.16)

project(qb)

find_package(GTest REQUIRED)

add_executable(
    test

    test.cpp
    )

target_link_libraries(
    test
    GTest::gtest
    GTest::gtest_main
    )
