cmake_minimum_required(VERSION 3.16.3)

project(gbhw)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
set(CMAKE_CXX_STANDARD 20)

add_executable(
    ${PROJECT_NAME}
    main.cpp
    work.cpp
)

add_executable(
    bench
    bench.cpp
    work.cpp
)

find_package(benchmark REQUIRED)

target_link_libraries(
    bench
    pthread
    benchmark::benchmark
)
