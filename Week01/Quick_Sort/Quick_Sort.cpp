// Quick_Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include "QuickSort.hpp"

using std::cin;
using std::cout;
using std::endl;

bool hasOccuredMistake = false;
using TestFuncPtr = void(*)();

bool runTest(TestFuncPtr fn, const char* name)
{
    cout << "Running test... \"" << name << "\" ";

    hasOccuredMistake = false;
    fn();
    cout << ((!hasOccuredMistake) ? "OK!\n" : "FAILED!\n");

    return hasOccuredMistake;
}

#define TEST_CASE(name)                         \
void name();                                    \
bool testvar_##name = runTest(name, #name);     \
void name()

#define CHECK(condition) hasOccuredMistake = condition

TEST_CASE(test_WithAlreadySortedElements)
{
    int arr[] = { 1,2,3,4,5 };

    QuickSort<int>(arr, 5);

    CHECK(!std::is_sorted(arr, arr + 5));
}

TEST_CASE(test_WithAlreadySortedElementsInDescendingOrder)
{
    int arr[] = { 5,4,3,2,1 };

    QuickSort<int>(arr, 5);

    CHECK(!std::is_sorted(arr, arr + 5));
}

TEST_CASE(test_WithIdenticalElements)
{
    int arr[] = { 1,1,1,1,1 };

    QuickSort<int>(arr, 5);

    CHECK(!std::is_sorted(arr, arr + 5));
}

TEST_CASE(test_WithPositiveAndNegativeNUmbers)
{
    int arr[] = { 1,-2,0,-5,-9,13 };

    QuickSort<int>(arr, 5);

    CHECK(!std::is_sorted(arr, arr + 6));
}

int main()
{
}

