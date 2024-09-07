#include <iostream>
#include <cstdint>
#include <array>
template <std::uint64_t N>
std::int32_t interpolationSearch(const std::array<std::int32_t, N> &arr, std::int32_t lo, std::int32_t hi, std::int32_t x)
{
    if (lo <= hi && x >= arr[lo] && x <= arr[hi])
    {
        std::int32_t pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));

        if (arr[pos] == x)
            return pos;

        if (arr[pos] < x)
            return interpolationSearch(arr, pos + 1, hi, x);

        if (arr[pos] > x)
            return interpolationSearch(arr, lo, pos - 1, x);
    }
    return -1;
}

int main()
{
    constexpr static auto N = std::int64_t{15};

    auto arr = std::array<std::int32_t, N>{10, 12, 13, 16, 18, 19, 20, 21,
                                           22, 23, 24, 33, 35, 42, 47};

    std::int32_t x = 18;

    std::int32_t index = interpolationSearch(arr, 0, N - 1, x);

    if (index != -1)
        std::cout << "Element found at index " << index;
    else
        std::cout << "Element not found.";

    std::cout << "\n\n";

    return 0;
}