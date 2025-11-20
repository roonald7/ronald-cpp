#ifndef _BINARY_SEARCH_H_
#define _BINARY_SEARCH_H_

#include <vector>

namespace ragc {

class BinarySearch {
public:
  template <typename T> static int search(const std::vector<T> &list, T item) {
    int low = 0;
    int high = list.size() - 1;
    int steps = 0;

    while (low <= high) {
      int mid = (low + high) / 2;
      T guess = list.at(mid);
      steps++;

      if (guess == item) {
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
