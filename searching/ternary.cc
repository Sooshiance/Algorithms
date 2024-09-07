#include <iostream>
#include <cstdint>
#include <array>

template <std::uint64_t N>
std::int32_t ternarySearch(std::int32_t key, const std::array<std::int32_t, N> arr)
{
    std::int32_t r = N - 1;
    std::int32_t l = {0};

    while (r >= l)
    {
        // Find the mid1 and mid2
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        // Check if key is present at any mid
        if (ar[mid1] == key)
        {
            return mid1;
        }
        if (ar[mid2] == key)
        {
            return mid2;
        }

        if (key < ar[mid1])
        {
            r = mid1 - 1;
        }
        else if (key > ar[mid2])
        {
            l = mid2 + 1;
        }
        else
        {
            l = mid1 + 1;
            r = mid2 - 1;
        }
    }

    return -1;
}

int main()
{
    std::int32_t l, r, p, key;

    constexpr static auto N = std::int32_t{10};

    // Get the array
    auto constexpr arr = std::array<std::int32_t, N>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Key to be searched in the array
    key = std::int32_t{5};

    // Search the key using ternarySearch
    p = ternarySearch(key, arr);

    // Print the result
    std::cout << key << p << "\n\n";

    // Key to be searched in the array
    key = std::int32_t{50};

    // Search the key using ternarySearch
    p = ternarySearch(key, arr);

    // Print the result
    std::cout << key << p << "\n\n";

    return 0;
}