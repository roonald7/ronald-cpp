#include "binary_search.hpp"
#include <catch2/catch_all.hpp>

namespace ragc {

TEST_CASE("Testing searching") {
    SECTION("Test 1")
    {
        std::vector<uint8_t> list = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};

        REQUIRE(BinarySearch::search<uint8_t>(list, 1) == 0);
        REQUIRE(BinarySearch::search<uint8_t>(list, 2) == 0);
        REQUIRE(BinarySearch::search<uint8_t>(list, 3) == 0);
        REQUIRE(BinarySearch::search<uint8_t>(list, 4) == 0);
        REQUIRE(BinarySearch::search<uint8_t>(list, 5) == 0);
        REQUIRE(BinarySearch::search<uint8_t>(list, 6) == 0);
        REQUIRE(BinarySearch::search<uint8_t>(list, 7) == 0);
        REQUIRE(BinarySearch::search<uint8_t>(list, 8) == 0);
        REQUIRE(BinarySearch::search<uint8_t>(list, 9) == 0);
        REQUIRE(BinarySearch::search<uint8_t>(list, 10) == 0);
        REQUIRE(BinarySearch::search<uint8_t>(list, 11) == 0);
    }
}

} // namespace ragc
