#include <iostream>

template<typename T>
size_t partition(T* pArr, size_t size)
{
	if (pArr[0] > pArr[size - 1])
		std::swap(pArr[0], pArr[size - 1]);

	T& partitioningElement = pArr[size - 1];
	size_t left = 0;
	int right = size - 1;

	while (true)
	{
		while (pArr[++left] < partitioningElement)
			;

		while (pArr[--right] > partitioningElement)
		{
			if (left == right)
				break;
		}

		if (left >= right)
			break;

		std::swap(pArr[left], pArr[right]);
	}

	std::swap(pArr[left], partitioningElement);
	return left;
	
}

template<typename T>
void QuickSort(T* arr, size_t size)
{
	if (!arr || size <= 1)
		return;

	size_t pivot = partition(arr, size);
	QuickSort<T>(arr, pivot);
	QuickSort<T>(arr + pivot + 1, size - pivot - 1);
}