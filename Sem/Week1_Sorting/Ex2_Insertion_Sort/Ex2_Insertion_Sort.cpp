// Ex2_Insertion_Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <utility>

template <class T>
void insertionSort(T* array, const unsigned size)
{
	for (size_t i = 1; i < size; i++)
	{
		int currentIndex = i - 1;
		T currentElement = array[i];
		while (currentIndex >= 0 && array[currentIndex] > currentElement)
		{
			array[currentIndex + 1] = array[currentIndex];
			currentIndex--;
		}
		array[currentIndex + 1] = currentElement;
	}
}

int main()
{
	int array[] = { 7, 6, 5, 4, 3, 2, 1 };

	int length = sizeof(array) / sizeof(array[0]);

	insertionSort<int>(array, length);
	for (size_t i = 0; i < length; i++)
	{
		std::cout << array[i] << ' ';
	}

	return 0;
}

