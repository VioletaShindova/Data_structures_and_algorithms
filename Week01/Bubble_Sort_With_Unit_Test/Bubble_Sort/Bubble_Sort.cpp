// Bubble_Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

//B.C - 0(n), A.C - 0(n^2), W.C - 0(n^2)

template <typename T>
void bubbleSort(T* arr, size_t len)
{
	if (!arr || len == 0)
		throw std::logic_error("Invalid array\n");

    size_t size = len - 1;
	
	for (size_t i = 0; i < len - 1; i++)
	{
		unsigned lastSwappedInd = 0;
		for (size_t j = 0; j < size; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				std::swap(arr[j], arr[j + 1]);
				lastSwappedInd = j;
			}
		}
		size = lastSwappedInd;
		if (lastSwappedInd == 0)
			break;
	}
}

//int main()
//{
//    std::vector<int> arr = { 3,4,1,2,4,6,7,89,4,32,2425, -1};
//
//	bubbleSort<int>(arr.data(), arr.size());
//
//	for (size_t i = 0; i < arr.size(); i++)
//		cout << arr[i] << ' ';
//
//	return 0;
//}
