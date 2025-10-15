#include "../Bubble_Sort/Bubble_Sort.cpp"
#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

bool errorHasOccurred = false;

using TestCasefn = void(*)();

bool runTest(TestCasefn pfn, const char* name)
{
    cout << "Testing: " << name << endl;

    errorHasOccurred = false;

    pfn();

    cout << (errorHasOccurred ? "Error!\n" : "OK!\n");

    return errorHasOccurred;
}

int main()
{
}

#define TEST_CASE_WITH_DESCRIPTION(name, description)              \
void name();                                      \
bool testvar_##name = runTest(name, description); \
void name()

#define TEST_CASE(name)                      \
void name();                                 \
bool testvar_##name = runTest(name, #name);  \
void name() 

#define CHECK(condition) errorHasOccurred = condition

TEST_CASE_WITH_DESCRIPTION(test_SortWithIdenticalElements, "Test array with identical elements {1, 1, 1, 1}")
{
    int arr[] = { 1,1,1,1 };

    bubbleSort<int>(arr, 4);

    CHECK(!std::is_sorted(arr, arr + 4));
}

TEST_CASE(test_SortSortedArray)
{
    int arr[] = { 1,2,3,4 };

    bubbleSort<int>(arr, 4);

    CHECK(!std::is_sorted(arr, arr + 4));
}

TEST_CASE(test_SortReverseSortedArray)
{
    int arr[] = { 4,3,2,1 };

    bubbleSort<int>(arr, 4);

    CHECK(!std::is_sorted(arr, arr + 4));
}

TEST_CASE(test_ArrayWithPositiveAndNegativeNumbers)
{
    int arr[] = { 1,-2,10,-3,5 };

    bubbleSort<int>(arr, 5);

    CHECK(!std::is_sorted(arr, arr + 5));
}

TEST_CASE(test_ForNullPointer)
{
    //bubbleSort<int>(nullptr, 3);
}

TEST_CASE(test_ForNullPointerAndOrNullSize)
{
    int arr[] = { 1,-2,10,-3,5 };

    //bubbleSort<int>(arr, 0);
}