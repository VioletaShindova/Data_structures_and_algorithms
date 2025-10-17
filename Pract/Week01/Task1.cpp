// Task1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

int minimumCost(std::vector<int>& cost) {
	std::sort(cost.begin(), cost.end());

	int sum = 0;
	for (int i = cost.size() - 1; i >= 0; i -= 3)
	{
		if (i == 0)
		{
			sum += cost[i];
			break;
		}
		sum += (cost[i] + cost[i - 1]);
	}

	return ((sum == 0) ? cost[0] : sum);
}

int main()
{
	std::vector<int> cost = { 1,2,3 };

	std::cout << minimumCost(cost);
}

