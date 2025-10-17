// Task3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

int largestPerimeter(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());

	for (int i = nums.size() - 2; i >= 0; --i)
	{
		for (int j = i - 1; j >=0 ; --j)
		{
			if (nums[i] + nums[j] > nums[i + 1])
				return nums[i] + nums[j] + nums[i + 1];
		}
	}
	return 0;
}

int main()
{
	std::vector<int> nums = { 3,6,2,3 };

	std::cout << largestPerimeter(nums);
}

