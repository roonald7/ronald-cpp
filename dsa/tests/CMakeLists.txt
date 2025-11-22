cmake_minimum_required(VERSION 3.10)

find_package(Catch2 CONFIG REQUIRED)

add_executable(
    ${PROJECT_NAME}Test

    src/algorithms/binary_search_test.cpp
    src/data_structures/linked_list_test.cpp
)

target_link_libraries(
    ${PROJECT_NAME}Test

    PRIVATE
        ${PROJECT_NAME}Lib
        Catch2::Catch2WithMain
)

target_compile_definitions(
    ${PROJECT_NAME}Test

    PRIVATE
        cxx_std_17
)

include(CTest)
add_test(
    NAME ${PROJECT_NAME}UnitTest
    COMMAND ${PROJECT_NAME}Test
)