#ifndef _BINARY_SEARCH_H_
#define _BINARY_SEARCH_H_

#include <iostream>
#include <vector>

namespace ragc {

class BinarySearch {
public:
  template <typename T>
  static size_t search(const std::vector<T> &list, T item) {
    size_t low = 0;
    size_t high = list.size() - 1;
    size_t steps = 0;

    while (low <= high) {
      size_t mid = (low + high) / 2;
      T guess = list.at(mid);
      steps++;

      if (guess == item) {
        std::cout << "Item found in " << steps << " steps!" << std::endl;
        return mid;
      }
      if (guess > item) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }

    return -1;
  }
};

} // namespace ragc

#endif
