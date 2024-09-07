#include <iostream>
#include <cstdint>
#include <array>
#include <cmath>

template <std::uint64_t N>
std::int32_t jumpSearch(const std::array<std::int32_t, N> arr, std::int32_t x)
{
    // Finding block size to be jumped
    std::uint64_t step = sqrt(N);

    // Finding the block where element is
    // present (if it is present)
    std::int32_t prev = 0;

    while (arr[std::min(step, N) - 1] < x)
    {
        prev = step;

        step += sqrt(N);
        if (prev >= N)
            return -1;
    }

    // Doing a linear search for x in block
    // beginning with prev.
    while (arr[prev] < x)
    {
        prev++;

        // If we reached next block or end of
        // array, element is not present.
        if (prev == std::min(step, N))
            return -1;
    }
    // If element is found
    if (arr[prev] == x)
        return prev;

    return -1;
}

int main()
{
    constexpr auto static N = std::int32_t{16};

    auto constexpr arr = std::array<std::int32_t, N>{0, 1, 1, 2, 3, 5, 8, 13, 21,
                                                     34, 55, 89, 144, 233, 377, 610};

    std::int32_t x = 55;

    // Find the index of 'x' using Jump Search
    std::int32_t index = jumpSearch(arr, x);

    std::cout << "\nNumber " << x << " is at index " << index;

    return 0;
}