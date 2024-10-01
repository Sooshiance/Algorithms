#include <iostream>
#include <cstdint>

void printArray(int *arr, std::int32_t length)
{
    for (std::int32_t i = 0; i < length; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void merge(int *arr, std::int32_t low, std::int32_t mid, std::int32_t high)
{
    std::int32_t i, j, k;
    std::int32_t lengthLeft = mid - low + 1;
    std::int32_t lengthRight = high - mid;

    // Creating two temp arrays to store left and right sub-arrays
    int *arrLeft = new std::int32_t[lengthLeft];
    int *arrRight = new std::int32_t[lengthRight];

    // Copying the data from the actual array to left and right temp arrays
    for (std::int32_t a = 0; a < lengthLeft; a++)
    {
        arrLeft[a] = arr[low + a];
    }
    for (std::int32_t a = 0; a < lengthRight; a++)
    {
        arrRight[a] = arr[mid + 1 + a];
    }

    // Merging the temp arrays back into the actual array
    i = 0;
    j = 0;
    k = low;

    while (i < lengthLeft && j < lengthRight)
    {
        if (arrLeft[i] <= arrRight[j])
        {
            arr[k] = arrLeft[i];
            i++;
        }
        else
        {
            arr[k] = arrRight[j];
            j++;
        }
        k++;
    }

    while (i < lengthLeft)
    {
        arr[k] = arrLeft[i];
        k++;
        i++;
    }

    while (j < lengthRight)
    {
        arr[k] = arrRight[j];
        k++;
        j++;
    }

    delete[] arrLeft;
    delete[] arrRight;
}

void mergeSort(int *arr, std::int32_t low, std::int32_t high)
{
    if (low < high)
    {
        std::int32_t mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

int main()
{
    // Initializing the array
    std::int32_t arr[]{9, 14, 4, 6, 5, 8, 7};

    // Calculating the length of the array
    std::int32_t length = sizeof(arr) / sizeof(int);

    // Printing the array before sorting
    std::cout << "Array before calling mergeSort(): ";
    printArray(arr, length);

    // Calling the mergeSort() function
    mergeSort(arr, 0, length - 1);

    // Printing the array after sorting
    std::cout << "Array after calling mergeSort(): ";
    printArray(arr, length);

    return 0;
}
