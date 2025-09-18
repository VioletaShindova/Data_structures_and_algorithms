#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

//Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

void rotate(std::vector<int>& nums, int k) 
{
	for (size_t i = 0; i < k; i++)
	{
		int last = nums.back();
		nums.pop_back();
		nums.insert(nums.begin(), last);
	}
}

int main()
{
	std::vector<int> nums;

	size_t size;
	cin >> size;

	int k;
	cin >> k;

	for (size_t i = 0; i < size; i++)
	{
		int num;
		cin >> num;
		nums.push_back(num);
	}

	rotate(nums, k);

	for (size_t i = 0; i < size; i++)
		cout << nums[i] << ' ';
}