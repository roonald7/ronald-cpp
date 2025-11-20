#include "binary_search.hpp"
#include <catch2/catch_all.hpp>

namespace ragc {

TEST_CASE("Testing searching") {
  std::vector<uint8_t> list = {1, 2,  3,  4,  5,  6,  7,  8,
                               9, 10, 11, 13, 14, 15, 16, 17};

  std::vector<std::pair<uint8_t, int>> test_cases = {
      {1, 0},   {2, 1},   {3, 2},   {4, 3},   {5, 4},   {6, 5},
      {7, 6},   {8, 7},   {9, 8},   {10, 9},  {11, 10}, {13, 11},
      {14, 12}, {15, 13}, {16, 14}, {17, 15}, {12, -1}, {18, -1}};

  for (const auto &[value, expected_index] : test_cases) {
    SECTION("Searching for value " + std::to_string(value)) {
      int actual_index = BinarySearch::search<uint8_t>(list, value);

      REQUIRE(actual_index == expected_index);

      // Isso imprime o que falhou, útil para debugar
      INFO("Value: " << (int)value << ", Expected: " << expected_index
                     << ", Actual: " << actual_index);
    }
  }
}

TEST_CASE("Binary Search Performance Benchmark") {
  const std::vector<uint8_t> list = {1, 2,  3,  4,  5,  6,  7,  8,
                                     9, 10, 11, 13, 14, 15, 16, 17};
  uint8_t target_found = 17;
  uint8_t target_not_found = 12;

  BENCHMARK("Search for item 17 (Worst Case)") {
    return BinarySearch::search<uint8_t>(list, target_found);
  };

  BENCHMARK("Search for item 12 (Not Found Case)") {
    return BinarySearch::search<uint8_t>(list, target_not_found);
  };
}

} // namespace ragc
