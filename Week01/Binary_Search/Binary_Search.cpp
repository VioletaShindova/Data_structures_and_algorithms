// Binary_Search.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cassert>

//0(log(n)) - защото е степен на двойката (n + 1/2 + 1/4 + 1/8 + ... + 1)

using std::cin;
using std::cout;
using std::endl;

template <typename T>
int binarySearch(const T* arr, size_t size, const T& el)
{
	int leftBorder = 0;
	int rightBorder = size - 1;

	while (leftBorder != rightBorder)
	{
		int mid = (leftBorder + (rightBorder - leftBorder) / 2;
		if (arr[mid] < el)
			leftBorder = mid + 1;
		else if (arr[mid] > el)
			rightBorder = mid - 1;
		else
			return mid;
	}

	if (leftBorder == rightBorder && arr[leftBorder] == el)
		return leftBorder;

	return -1; //el is not found
}

template <typename Iterator, typename T>
Iterator binarySearchIter(Iterator begin, Iterator end, const T& el)
{
	Iterator left = begin;
	Iterator right = end;
	while (left < right)
	{
		Iterator mid =  (left + (std::distance(left, right)) / 2;
		if (*mid < el)
			left = mid + 1;
		else if (*mid > el)
			right = mid - 1;
		else
			return mid;
	}

	if (left == right && *left == el)
		return left;

	return end;
}

template <typename T>
int binarySearchRec(const T* arr, size_t left, size_t size, const T& el)
{
	if (left > size)
		return -1;

	int mid = (left + (size - left)) / 2;

	if (arr[mid] == el)
		return mid;
	else if (arr[mid] < el)
		return binarySearchRec<T>(arr, mid + 1, size, el);
	else
		return binarySearchRec<T>(arr, left, mid - 1, el);
}

template <typename Iterator, typename T>
Iterator binarySearchIterRec(Iterator begin, Iterator end, const T& el)
{
	if()
}

int main()
{
    std::vector<int> arr = { 1,2,3,4,5,6,7,10,20,40 };
	std::cout << binarySearch<int>(arr.data(), arr.size(), 3) << std::endl;

	std::vector<int>::const_iterator it;
	assert((it = binarySearchIter<std::vector<int>::const_iterator>(arr.begin(), arr.end(), 10)) != arr.end());
	cout << *it;
}

