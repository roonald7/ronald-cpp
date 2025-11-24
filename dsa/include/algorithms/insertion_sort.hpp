#ifndef _INSERTION_SORT_HPP_
#define _INSERTION_SORT_HPP_

#include <iostream>
#include <vector>

namespace ragc
{

template <typename T>
class InsertionSort
{
public:
    /**
     * @brief Implementa o Insertion Sort.
     * * O algoritmo é in-place, por isso recebe uma referência NÃO-CONSTANTE
     * para modificar o vetor original.
     * * @param list O vetor a ser ordenado.
     */
    static void sort(std::vector<T> &list)
    {
        if (list.size() < 2)
        {
            return;
        }

        for (size_t j = 1; j < list.size(); ++j)
        {
            T key = std::move(list[j]);

            long long i;

            for (i = j - 1; i >= 0; --i)
            {
                if (list[i] > key)
                {
                    list[i + 1] = std::move(list[i]);
                }
                else
                {
                    break;
                }
            }

            list[i + 1] = std::move(key);
        }
    }
};

} // namespace ragc

#endif
