#include <iostream>
#include <vector>
#include <cstdint>

std::int32_t partition(std::vector<std::int32_t> &arr, std::int32_t low, std::int32_t high)
{

    // Choose the pivot
    std::int32_t pivot = arr[high];

    // Index of smaller element and indicates
    // the right position of pivot found so far
    std::int32_t i = low - 1;

    // Traverse arr[low..high] and move all smaller
    // elements on left side. Elements from low to
    // i are smaller after every iteration
    for (std::int32_t j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    // Move pivot after smaller elements and
    // return its position
    std::swap(arr[i + 1], arr[high]);

    return i + 1;
}

void quickSort(std::vector<std::int32_t> &arr, std::int32_t low, std::int32_t high)
{

    if (low < high)
    {

        // pi is the partition return index of pivot
        std::int32_t pi = partition(arr, low, high);

        // Recursion calls for smaller elements
        // and greater or equals elements
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    std::vector<std::int32_t> arr = {10, 7, 8, 9, 1, 5};
    std::int32_t n = arr.size();

    quickSort(arr, 0, n - 1);

    std::cout << "Sorted Array\n";

    for (std::int32_t i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}