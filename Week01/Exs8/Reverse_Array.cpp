// Reverse_Array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdexcept>
#include <cstring>
#include <utility>

using std::cin;
using std::cout;
using std::endl;

void reverseArray(char* arr)
{
    if (!arr)
        throw std::invalid_argument("Empty array\n");

    size_t size = strlen(arr);
    if (size == 0)
        throw std::invalid_argument("Empty array\n");

    for (size_t i = 0; i < size / 2; i++)
        std::swap(arr[i], arr[size - i - 1]);
}

bool isPalindrome(const char* arr)
{
    if (!arr)
        throw std::invalid_argument("Empty array\n");

    size_t size = strlen(arr);
    if (size == 0)
        return false;

    for (size_t i = 0; i < size / 2; i++)
    {
        if (arr[i] != arr[size - 1 - i])
            return false;
    }
    return true;
}

template <typename T>
T findMinOrMaxEl(const T* arr, size_t len, bool (*pred)(const T& lhs, const T& rhs))
{
    if (!arr || len == 0)
        throw std::invalid_argument("Invalid arr\n");

    T minEl = arr[0];
    for (size_t i = 1; i < len; i++)
    {
        if (pred(arr[i], minEl))
            minEl = arr[i];
    }
    return minEl;
}

template<typename T>
T findSecondGreatestNumber(const T* arr, int len)
{
    if (!arr || len <= 1)
        throw std::invalid_argument("Empty array\n");

    T greatestNumber = arr[0];
    T secondGreatestNumber = arr[1];
    for (size_t i = 1; i < len; i++)
    {
        if (arr[i] > greatestNumber)
        {
            secondGreatestNumber = greatestNumber;
            greatestNumber = arr[i];
            continue;
        }

        if (arr[i] > secondGreatestNumber && arr[i] < greatestNumber)
            secondGreatestNumber = arr[i];
    }
    return secondGreatestNumber;
}

template <typename T>
size_t getCountOfXEl(const T* arr, size_t size, const T& el)
{
    if (!arr || size == 0)
        throw std::invalid_argument("Empty array\n");

    size_t countOfEl = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] == el)
            countOfEl++;
    }
    return countOfEl;
}

template<typename T>
bool hasDuplicates(const T* arr, size_t len)
{
    if (!arr || len == 0)
        throw std::invalid_argument("Empty array\n");

    for (size_t i = 0; i < len - 1; i++)
    {
        for (size_t j = i + 1; j < len; j++)
        {
            if (arr[j] == arr[i])
                return true;
        }
    }
    return false;
}

int main()
{
    char* arr = new char[225];

    //cin.getline(arr, 225);

    //cout << isPalindrome(arr);

    //cout << arr;

    int el[] = { 5,9,2};
    //cout << findMinOrMaxEl<int>(el, 7, [](const int& lhs, const int& rhs) {return lhs < rhs; }); //this is finding min as a lambda func

    cout << findSecondGreatestNumber<int>(el, 3);

    delete[] arr;
}