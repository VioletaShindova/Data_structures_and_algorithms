// Ex5_Quick_Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

constexpr size_t SIZE = 15;

template <class T>
size_t partition(T* pArray, const size_t SIZE)
{
	if (pArray[0] > pArray[SIZE - 1])
	{
		std::swap(pArray[0], pArray[SIZE - 1]);
	}

	T& partitioningElement = pArray[SIZE - 1];

	size_t left = 0;
	size_t right = SIZE - 1;

	while (true)
	{
		while (pArray[++left] < partitioningElement)
			;

		while (pArray[--right] > partitioningElement)
		{
			if (left == right)
			{
				break;
			}
		}

		if (left >= right)
		{
			break;
		}

		std::swap(pArray[left], pArray[right]);
	}

	std::swap(pArray[left], partitioningElement);

	return left;

}

template <class T>
size_t advancedPartition(T* pArr, const size_t size)
{
	if (pArr[0] > pArr[size - 1])
	{
		std::swap(pArr[0], pArr[size - 1]);
	}

	T pivotElement = pArr[size - 1];
	size_t left = 0;
	size_t right = size - 1;

	while (true)
	{
		while (pArr[left] < pivotElement)
		{
			left++;
		}
		while (pArr[right] > pivotElement)
		{
			if (left == right)
			{
				break;
			}
			right--;	
		}

		if (right <= left)
		{
			break;
		}
		std::swap(pArr[right], pArr[left]);
	}

	std::swap(pArr[left], pivotElement);
	return left;
}

template <class T>
void myQuickSort(T* array, const size_t len)
{
	if (len <= 1)
	{
		return;
	}

	size_t pivotIndex = partition(array, len);

	myQuickSort(array, pivotIndex);
	myQuickSort(array + pivotIndex + 1, len - pivotIndex - 1);
}

int main()
{
    int array[] = { 15,14,13,12,11,30,90,8,7,6,5,4,3,2,1 };
	myQuickSort<int>(array, SIZE);

	for (size_t i = 0; i < SIZE; i++)
	{
		cout << array[i] << ' ';
	}
	
	return 0;
}

