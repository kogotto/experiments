cmake_minimum_required(VERSION 3.16)

project(mmap-hello)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

find_package(Boost REQUIRED COMPONENTS iostreams)

add_executable(
    ${PROJECT_NAME}
    main.cpp
)

target_link_libraries(
    ${PROJECT_NAME}
    Boost::iostreams
)
