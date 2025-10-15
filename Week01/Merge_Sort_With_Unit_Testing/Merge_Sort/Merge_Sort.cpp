// Merge_Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "MergeSort.hpp"

using std::cin;
using std::cout;
using std::endl;

namespace Constants {
	constexpr size_t SIZE_ARR = 5;
}

template<typename T>
void print(const T* arr, size_t size)
{
	if (!arr || size == 0)
		throw std::logic_error("Can't print an empty array!\n");

	cout << arr[0];
	for (size_t i = 1; i < size; i++)
		cout << ", " << arr[i];
}

int main()
{
	int arr[] = { 99, 4,4,-1,-12 };
	MergeSort(arr, Constants::SIZE_ARR); //sorts in ascending order

	try {
		print(arr, Constants::SIZE_ARR);
	}
	catch (std::logic_error& log_error)
	{
		cout << log_error.what();
		return 0;
	}
}
