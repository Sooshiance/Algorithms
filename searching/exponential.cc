#include <iostream>
#include <cstdint>
#include <array>
#include <algorithm> // For std::min

template <std::uint64_t N>
std::int32_t binarySearch(const std::array<std::int32_t, N> &arr, std::int32_t low, std::int32_t high, std::int32_t x)
{
    while (low <= high)
    {
        std::int32_t mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

template <std::uint64_t N>
std::int32_t exponentialSearch(const std::array<std::int32_t, N> &arr, std::int32_t x)
{
    if (arr[0] == x)
        return 0;

    std::int32_t i = 1;
    while (i < N && arr[i] <= x)
        i *= 2;

    return binarySearch(arr, i / 2, std::min(i, static_cast<std::int32_t>(N - 1)), x);
}

int main()
{
    constexpr static auto N = std::int64_t{15};

    auto arr = std::array<std::int32_t, N>{10, 12, 13, 16, 18, 19, 20, 21,
                                           22, 23, 24, 33, 35, 42, 47};

    std::int32_t x = 18;

    std::int32_t index = exponentialSearch(arr, x);

    if (index != -1)
        std::cout << "Element found at index " << index;
    else
        std::cout << "Element not found.";

    std::cout << "\n\n";

    return 0;
}