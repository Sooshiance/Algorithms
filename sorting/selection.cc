#include <iostream>
#include <vector>
#include <cstdint>

void selectionSort(std::vector<std::int32_t> &arr)
{
    std::int32_t n = arr.size();

    for (int i = 0; i < n - 1; ++i)
    {
        // Find the minimum element in the unsorted part of the array
        std::int32_t minIndex = i;
        
        for (std::int32_t j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // Swap the found minimum element with the first element of the unsorted part
        std::swap(arr[i], arr[minIndex]);
    }
}

int main()
{
    std::vector<std::int32_t> data = {64, 25, 12, 22, 11};

    std::cout << "Unsorted array: ";

    for (const std::int32_t &num : data)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    selectionSort(data);

    std::cout << "Sorted array: ";

    for (const std::int32_t &num : data)
    {
        std::cout << num << " ";
    }

    std::cout << std::endl;

    return 0;
}