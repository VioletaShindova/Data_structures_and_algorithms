// Insertion_Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

//B.C - 0(n), A.C - 0(n^2), W.C - 0(n^2)

template<typename T>
void naiveInsertionSort(std::vector<T>& arr, size_t len)
{
	for (size_t i = 0; i < len; i++)
	{
		int minIdx = i;

		while (minIdx > 0 && arr[minIdx] < arr[minIdx - 1])
		{
			std::swap(arr[minIdx], arr[minIdx - 1]);
			minIdx--;
		}
	}
}

template <typename T>
void insertionSort(std::vector<T>& arr, size_t len)
{
	for (size_t i = 1; i < len; i++)
	{
		T minElement = arr[i];
		int elIdx = i - 1;
		while (elIdx >= 0 && arr[elIdx] > minElement)
		{
			arr[elIdx + 1] = arr[elIdx];
			elIdx--;
		}
		arr[elIdx + 1] = minElement;
	}
}

int main()
{
	std::vector<int> arr = { 3,4,1,2,4,6,7,89,4,32,2425, -1 };

	insertionSort<int>(arr, arr.size());

	for (size_t i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << ' ';
	}

	return 0;
}
