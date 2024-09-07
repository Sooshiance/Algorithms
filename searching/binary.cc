#include <iostream>
#include <cstdint>
#include <array>

template <std::uint64_t N>
std::int32_t binarySearch(const std::array<std::int32_t, N> arr, std::int32_t x)
{
    std::int32_t low = {0};
    std::uint64_t high = N;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // Check if x is present at mid
        if (arr[mid] == x)
            return mid;

        // If x greater, ignore left half
        if (arr[mid] < x)
            low = mid + 1;

        // If x is smaller, ignore right half
        else
            high = mid - 1;
    }

    // If we reach here, then element was not present
    return -1;
}

int main()
{
    constexpr static auto N = std::int32_t{5};

    auto constexpr arr = std::array<std::int32_t, N>{2, 3, 4, 10, 40};

    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = binarySearch(arr, x);

    if (result == -1)
        std::cout << "Element is not present in array";
    else
        std::cout << "Element is present at index " << result;

    std::cout << "\n\n";

    return 0;
}