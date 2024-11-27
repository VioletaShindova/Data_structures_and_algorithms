// Ex4_Merge_Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

template <class T>
void Merge(const T* firstArray, const size_t firstSize, const T* secondArray, const size_t secondSize, T* resultArray)
{
    size_t resultIter = 0;
    size_t firstIter = 0;
    size_t secondIter = 0;

    while (firstIter < firstSize && secondIter < secondSize)
    {
        resultArray[resultIter++] = (firstArray[firstIter] < secondArray[secondIter]) ? firstArray[firstIter++] : secondArray[secondIter++];
    }

    while (firstIter < firstSize)
    {
        resultArray[resultIter++] = firstArray[firstIter++];
    }

    while (secondIter < secondSize)
    {
        resultArray[resultIter++] = secondArray[secondIter++];
    }
}

//wrapper function
template <class T>
void MergeSortStep(T* pArray, const size_t size, T* pBuffer)
{
    if (size <= 1)
    {
        return;
    }

    unsigned mid = size / 2;
    MergeSortStep(pArray, mid, pBuffer); //left side
    MergeSortStep(pArray + mid, size - mid, pBuffer); //right side
    Merge(pArray, mid, pArray + mid, size - mid, pBuffer);
    for (size_t i = 0; i < size; i++)
    {
        pArray[i] = pBuffer[i];
    }
}

template <class T>
void MergeSort(T* pArray, const size_t size)
{
    if (!pArray || size == 0)
    {
        return;
    }

    T* buffer = new T[size];
    MergeSortStep(pArray, size, buffer);
    delete[] buffer;
}

constexpr size_t SIZE = 15;

int main()
{
    int array[] = { 15,14,13,12,11,30,90,8,7,6,5,4,3,2,1 };
    MergeSort(array, SIZE);

    for (size_t i = 0; i < SIZE; i++)
    {
        cout << array[i] << ' ';
    }   
    return 0;
}
