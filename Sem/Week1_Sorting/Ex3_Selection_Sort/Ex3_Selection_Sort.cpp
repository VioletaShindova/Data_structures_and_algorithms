// Ex3_Selection_Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <utility>

template <class T>
void selectionSort(T* array, const unsigned length)
{
    unsigned smallerLength = length - 1;
    for (size_t i = 0; i < smallerLength; i++)
    {
        unsigned smallestElementIndex = i;
        for (size_t j = i + 1; j < length; j++)
        {
            if (array[j] < array[smallestElementIndex])
            {
                smallestElementIndex = j;
            }
        }

        if (smallestElementIndex != i)
        {
            std::swap(array[i], array[smallestElementIndex]);
        }
    }

    return;
}

int main()
{
    int array[] = { 7,6,5,4,3,2,1 };
    unsigned length = sizeof(array) / sizeof(array[0]);

    selectionSort(array, length);

    for (size_t i = 0; i < length; i++)
    {
        std::cout << array[i] << ' ';
    }

    return 0;
}

