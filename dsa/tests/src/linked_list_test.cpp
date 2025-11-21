#include "linked_list.hpp"
#include <catch2/catch_all.hpp>

namespace ragc
{
    
TEST_CASE("Test insertions")
{
    std::vector<int> data = {1,10,50,30,25,40,2,4,7};

    LinkedList<uint8_t> linked_list;

    for (const auto &d : data)
    {        
        linked_list.insert_at_head(d);
    }

    
}

} // namespace ragc
