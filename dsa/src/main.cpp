#include "binary-search.hpp"

using namespace ragc;

int main(int argc, char const *argv[])
{
    std::vector<uint8_t> list = {1, 3,4,5,9,10,12,13,41,55,98,102};

    BinarySearch::search(list, (uint8_t)9);
    BinarySearch::search(list, (uint8_t)4);
    BinarySearch::search(list, (uint8_t)41);
    BinarySearch::search(list, (uint8_t)98);
    
    return 0;
}
