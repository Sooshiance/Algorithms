#include <iostream>
#include <vector>
#include <cstdint>

void bubbleSort(std::vector<std::int32_t> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i)
    {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // If no two elements were swapped by inner loop, then break
        if (!swapped)
            break;
    }
}

int main()
{
    std::vector<std::int32_t> data = {64, 34, 25, 12, 22, 11, 90};

    std::cout << "Unsorted array: ";
    for (const int &num : data)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    bubbleSort(data);

    std::cout << "Sorted array: ";
    for (const int &num : data)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
