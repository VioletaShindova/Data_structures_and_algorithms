// Ex5_UnionOfIntervals.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> mergeIntervals(std::vector<std::vector<int>>& intervals) 
{
    sort(intervals.begin(), intervals.end());

    std::vector<std::vector<int>> merged;

    for (const auto& interval : intervals) 
    {    
        if (merged.empty() || merged.back()[1] < interval[0]) {
            merged.push_back(interval);
        }
        else 
        {
            merged.back()[1] = std::max(merged.back()[1], interval[1]);
        }
    }

    return merged;
}

int main()
{

    std::vector<std::vector<int>> allIntervals = { {1,3}, {2,4}, {5,7}, {6,8} };
    std::vector<std::vector<int>> mergedIntervals = mergeIntervals(allIntervals);

    for (auto intervals : mergedIntervals)
    {
        std::cout << '{' << intervals[0] << ',' << intervals[1] << "} ";
    }

}
