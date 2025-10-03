// Linear_Search.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cassert> //c++ style, assert.h - older c version 

template <typename T>
int linearSeach(const T* arr, size_t size, const T& el)
{
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] == el)
			return i;
	}
	return -1;
}

template <typename Iterator, typename T>
Iterator linearSearchIterator(const Iterator begin, const Iterator end, const T& el)
{
	for (Iterator it = begin; it != end; ++it)
	{
		if (*it == el)
			return it;
	}
	return end;
}

template<typename T>
int linearSearchRec(const T* arr, size_t size, const T& el, int index = 0)
{
	if (index == size)
		return -1;

	if (arr[index] == el)
		return index;

	return linearSearchRec<T>(arr, size, el, index + 1);
}

template<typename Iterator, typename T>
Iterator linearSeachIteratorRec(Iterator begin, Iterator end, const T& el)
{
	if (begin == end)
		return end;

	if (*begin == el)
		return begin;

	return linearSeachIteratorRec<Iterator, T>(begin + 1, end, el);
}

int main()
{
	std::vector<int> arr = { 1,4,2,5,6 };
	std::vector<int>::const_iterator it = linearSearchIterator<std::vector<int>::iterator>(arr.begin(), arr.end(), 4);
	std::cout << ((it != arr.end()) ? *it : -1) << std::endl;

	std::cout << arr[linearSearchRec<int>(arr.data(), arr.size(), 5)] << std::endl;

	assert((it = linearSeachIteratorRec<std::vector<int>::const_iterator, int>(arr.begin(), arr.end(), 2)) != arr.end());

	std::cout << *it;
}
