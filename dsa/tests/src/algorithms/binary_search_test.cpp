#include "algorithms/binary_search.hpp"
#include <catch2/catch_all.hpp>

namespace ragc
{

TEST_CASE("Binary Search must return the index for sorted data (O(log n))", "[search][binary_only]")
{
    const std::vector<int> data_large = {1, 5, 8, 12, 15, 18, 20, 25, 30, 33, 40, 42, 50, 60, 70, 85, 90, 99};

    const std::vector<int> data_negatives = {-50, -30, -10, 0, 5, 8, 15, 100};

    const std::vector<int> data_odd_size = {2, 4, 6, 8, 10};
    const std::vector<int> data_even_size = {1, 3, 5, 7};
    const std::vector<int> data_empty = {};
    const std::vector<int> data_single = {42};

    SECTION("Large dataset - Target at Edges and Middle")
    {
        REQUIRE(BinarySearch<int>::search(data_large, 1) == 0);
        REQUIRE(BinarySearch<int>::search(data_large, 99) == 17);
        REQUIRE(BinarySearch<int>::search(data_large, 33) == 9);
        REQUIRE(BinarySearch<int>::search(data_large, 15) == 4);
    }

    SECTION("Negative numbers and zero handling")
    {
        REQUIRE(BinarySearch<int>::search(data_negatives, -30) == 1);
        REQUIRE(BinarySearch<int>::search(data_negatives, 0) == 3);
        REQUIRE(BinarySearch<int>::search(data_negatives, 100) == 7);
    }

    SECTION("Small lists (Odd and Even sizes)")
    {
        REQUIRE(BinarySearch<int>::search(data_odd_size, 6) == 2);
        REQUIRE(BinarySearch<int>::search(data_even_size, 5) == 2);
    }

    SECTION("Target NOT present in the list")
    {
        REQUIRE(BinarySearch<int>::search(data_large, 100) == -1);
        REQUIRE(BinarySearch<int>::search(data_large, 0) == -1);
        REQUIRE(BinarySearch<int>::search(data_large, 35) == -1);
    }

    // --- Casos de Borda Críticos ---

    SECTION("Critical Edge Cases")
    {
        REQUIRE(BinarySearch<int>::search(data_empty, 1) == -1);
        REQUIRE(BinarySearch<int>::search(data_single, 42) == 0);
        REQUIRE(BinarySearch<int>::search(data_single, 5) == -1);
    }
}

} // namespace ragc
