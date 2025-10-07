// Selection_Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

//B.C - 0(n^2), A.C - 0(n^2), W.C - 0(n^2)

template <typename T>
void selectionSort(std::vector<T>& arr, size_t len)
{
    size_t size = len - 1;
	for (size_t i = 0; i < size; i++)
	{
		size_t minIndex = i;
		for (size_t j = i + 1; j < len; j++)
		{
			if (arr[j] < arr[minIndex])
				minIndex = j;
		}

		if (minIndex != i)
			std::swap(arr[minIndex], arr[i]);
	}
}

int main()
{
	std::vector<int> arr = { 3,4,1,2,4,6,7,89,4,32,2425, -1 };

	selectionSort<int>(arr, arr.size());

	for (size_t i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << ' ';
	}

	return 0;
}

