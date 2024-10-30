// Ex4_SortLinear.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

void countingSort(std::vector<int>& array, size_t size)
{
	const unsigned int offset = 100;
    const size_t range = 201; //[-100,100]

	size_t* countArr = new size_t[range]{ 0 }; //2,3,4,5,6

	for (int i = 0; i < size; i++)
	{
		countArr[array[i] + offset]++;
	}

	for (int i = 1; i < range; i++)
	{
		countArr[i] += countArr[i - 1];
	}

	int* result = new int[size];
	for (int i = size - 1; i >= 0; i--)
	{
		int& currentNum = array[i];
		size_t index = --countArr[currentNum + offset];
		result[index] = currentNum;
	}

	for (int i = 0; i < size; i++)
	{
		array[i] = result[i];
	}

	delete[] result;
	delete[] countArr;
}

int main()
{
    std::vector<int> array = { 55, -19, 27, 0, -100, 100, -35, 11 };
    countingSort(array, sizeof(array) / sizeof(int));

	for (int num : array)
	{
		std::cout << num << ' ';
	}
	return 0;
}
