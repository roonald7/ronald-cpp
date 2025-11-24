#include "algorithms/insertion_sort.hpp"
#include <catch2/catch_all.hpp>

namespace ragc
{

TEST_CASE("InsertionSort should correctly sort various lists and data types", "[sort][insertion]")
{

    std::vector<int> data_unsorted = {5, 2, 8, 1, 9, 4};
    const std::vector<int> expected_sorted = {1, 2, 4, 5, 8, 9};

    std::vector<int> data_duplicates = {4, 1, 3, 4, 2, 1};
    const std::vector<int> expected_duplicates = {1, 1, 2, 3, 4, 4};

    std::vector<int> data_reversed = {10, 8, 6, 4, 2};
    const std::vector<int> expected_reversed = {2, 4, 6, 8, 10};

    std::vector<int> data_already_sorted = {1, 3, 5, 7, 9};
    const std::vector<int> expected_already_sorted = {1, 3, 5, 7, 9};

    std::vector<std::string> string_data = {"banana", "apple", "grape", "cherry"};
    const std::vector<std::string> expected_strings = {"apple", "banana", "cherry", "grape"};

    SECTION("Sorts a randomly ordered list of integers")
    {
        InsertionSort<int>::sort(data_unsorted);
        REQUIRE(data_unsorted == expected_sorted);
    }

    SECTION("Sorts a list containing duplicate elements")
    {
        InsertionSort<int>::sort(data_duplicates);
        REQUIRE(data_duplicates == expected_duplicates);
    }

    SECTION("Sorts a reversed ordered list (pior caso O(n^2))")
    {
        InsertionSort<int>::sort(data_reversed);
        REQUIRE(data_reversed == expected_reversed);
    }

    SECTION("Handles an already sorted list (melhor caso O(n))")
    {
        InsertionSort<int>::sort(data_already_sorted);
        REQUIRE(data_already_sorted == expected_already_sorted);
    }

    SECTION("Handles edge case: empty list")
    {
        std::vector<int> data_empty = {};
        InsertionSort<int>::sort(data_empty);
        REQUIRE(data_empty.empty());
    }

    SECTION("Handles edge case: single element list")
    {
        std::vector<int> data_single = {7};
        InsertionSort<int>::sort(data_single);
        REQUIRE(data_single == std::vector<int>{7});
    }

    SECTION("Sorts a list of std::strings lexicographically (validation of T)")
    {
        InsertionSort<std::string>::sort(string_data);
        REQUIRE(string_data == expected_strings);
    }
}

} // namespace ragc
