#include <cstdint>
#include <iostream>
#include <array>

template <std::uint64_t N>
std::int32_t search(const std::array<std::int32_t, N> arr, std::int32_t x)
{
    for (std::int32_t i = 0; i < N; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

int main()
{
    constexpr static auto N = std::int32_t{5};

    auto myarray = std::array<std::int32_t, N>{2, 3, 4, 10, 40};

    std::int32_t x = 10;

    // Function call
    std::int32_t result = search(myarray, x);

    (result == -1)
        ? std::cout << "Element is not present in array"
        : std::cout << "Element is present at index " << result;

    std::cout << "\n\n";

    return 0;
}