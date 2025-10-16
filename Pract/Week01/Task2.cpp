// Task2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

int heightChecker(std::vector<int>& heights) {
    std::vector<int> expected = heights;

    std::sort(expected.begin(), expected.end());

    int count = 0;
    for (size_t i = 0; i < heights.size(); ++i)
    {
        if (heights[i] != expected[i])
            count++;
    }
    return count;
}

int main()
{
    std::vector<int> cost = { 3,2,1 };

    std::cout << heightChecker(cost);

}
