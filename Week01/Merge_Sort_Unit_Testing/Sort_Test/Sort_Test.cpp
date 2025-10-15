#include "../Merge_Sort/MergeSort.hpp"
#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

int testErrorHasOccurred = false;

using TestFunction = void(*)(); // <=> typedef void(*TestFunction)();

bool runTest(TestFunction pfn, const char* name)
{
	cout << "Running test: \"" << name << "\"...";

	testErrorHasOccurred = false;
	pfn();

	cout << (testErrorHasOccurred ? "Failed!\n" : "OK\n");

	return testErrorHasOccurred;
}

int main()
{
}

#define TEST_CASE(name, description)				\
void name();										\
bool testvar_##name = runTest(name, description);	\
void name()


#define TEST_CASE(name)						\
void name();								\
bool testvar_##name = runTest(name, #name);	\
void name()


#define CHECK(condition) testErrorHasOccurred = (condition)

//------------------------------------------------------------------------------

template<typename T>
bool sameAsOriginal(const T* lhsArr, size_t lhsSize, const T* rhsArr, size_t rhsSize)
{
	if (!lhsArr || !rhsArr || lhsSize != rhsSize) {
		return true;
	}

	for (size_t i = 0; i < lhsSize; i++) {
		if (lhsArr[i] != rhsArr[i]) {
			return true;
		}
	}
	return false;
}

TEST_CASE(test_WithSortedArray, "Test with sorted array {1, 2, 3, 4}")
{
	int arr[] = { 1,2,3,4 };

	MergeSort(arr, 4);

	CHECK(std::is_sorted(arr, arr + 4));
}

TEST_CASE(test_WithReverseSortedArray)
{
	int arr[] = { 4,3,2,1 };
	MergeSort(arr, 4);

	CHECK(std::is_sorted(arr, arr + 4));
}

TEST_CASE(test_WithArrayOfIdenticalElements)
{
	int arr[] = { 1,1,1,1 };
	MergeSort(arr, 4);

	CHECK(std::is_sorted(arr, arr + 4));
}

TEST_CASE(test_WithArrayOfPositiveAndNegativeNumbers)
{
	int arr[] = { 4,-3,2,-10, 13 };
	MergeSort(arr, 4);

	CHECK(std::is_sorted(arr, arr + 5));
}

TEST_CASE(test_WithNullPointer)
{
	MergeSort<int>(nullptr, 10);
}

TEST_CASE(test_WithNullPointerAndNullSize)
{
	MergeSort<int>(nullptr, 0);
}


//Arrange - Act - Assert
//Each function does exactly one thing, the name must be unique and well specified by their purpose
TEST_CASE(test_WithZeroSize)
{
	int arr[] = { 4,-3,2,-10, 13 };					//arrange
	int arrCopy[] = { 4,-3,2,-10, 13 };

	MergeSort<int>(arr, 0);							//act

	CHECK(std::is_sorted(arr, arr + 5));			//assert
	CHECK(sameAsOriginal<int>(arr, 5, arrCopy, 5));
}		