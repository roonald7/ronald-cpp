#ifndef _BINARY_SEARCH_HPP_
#define _BINARY_SEARCH_HPP_

#include <vector>

namespace ragc
{

template <typename T>
class BinarySearch
{
private:
    template <typename U>
    using EnableIfTotallyOrderable =
        typename std::enable_if_t<std::is_convertible_v<decltype(std::declval<const U &>() < std::declval<const U &>()), bool> &&
                                  std::is_convertible_v<decltype(std::declval<const U &>() == std::declval<const U &>()), bool>>;

public:
    static int search(const std::vector<T> &list, const T &target)
    {
        size_t low = 0;
        size_t high = list.size();

        while (low < high)
        {
            size_t mid = low + (high - low) / 2;

            const T &guess = list[mid];

            if (guess == target)
            {
                return mid;
            }

            if (guess < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }

        return -1;
    }
};

} // namespace ragc

#endif
