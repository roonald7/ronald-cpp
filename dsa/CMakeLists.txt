cmake_minimum_required(VERSION 3.10)

PROJECT(
    DataStructuredAlgorithms

    LANGUAGES CXX
)

add_library(
    ${PROJECT_NAME}Lib

    STATIC

    src/main.cpp
)

target_include_directories(
    ${PROJECT_NAME}Lib

    PUBLIC
        ./include
)

target_compile_definitions(
    ${PROJECT_NAME}Lib

    PRIVATE
        cxx_std_17
)

if (NOT CROSSCOMPILE)
    add_subdirectory(tests) 
endif()