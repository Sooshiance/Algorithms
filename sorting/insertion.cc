#include <iostream>
#include <vector>
#include <cstdint>

void insertionSort(std::vector<std::int32_t> &arr)
{
    std::int32_t n = arr.size();
    for (std::int32_t i = 1; i < n; ++i)
    {
        std::int32_t key = arr[i];
        std::int32_t j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    std::vector<std::int32_t> data = {12, 11, 13, 5, 6};

    std::cout << "Unsorted array: ";
    for (const auto &num : data)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    insertionSort(data);

    std::cout << "Sorted array: ";
    for (const auto &num : data)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
