// Ex1_Bubble_Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <utility>

template <class T>
void bubbleSort(T* array, const unsigned length)
{
	unsigned end = length - 1;
	for (size_t i = 0; i < length; i++)
	{
		unsigned lastSwappedIndex = 0;

		for (size_t j = 0; j < end; j++)
		{
			if (array[j] > array[j + 1])
			{
				std::swap(array[j], array[j + 1]);
				lastSwappedIndex = j;
			}
		}
		end = lastSwappedIndex;
		if (lastSwappedIndex == 0)
		{
			return; //because the array is already sortedx
		}
	}
}

int main()
{
	int array[] = { 7, 6, 5, 4, 3, 2, 1 };
	bubbleSort<int>(array, 7);

	for (size_t i = 0; i < 7; i++)
	{
		std::cout << array[i] << ' ';
	}

	return 0;
}
