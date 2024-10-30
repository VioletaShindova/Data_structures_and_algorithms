// Ex3_PartitionIsPrime.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

template <typename RandomIt, typename Predicate>
RandomIt partitionIt(RandomIt first, RandomIt last, Predicate pred)
{
	RandomIt boundary = first;

	while (boundary != last && pred(*boundary))
	{
		++boundary;
	}

	if (boundary == last)
	{
		return boundary;
	}

	for (RandomIt it = boundary + 1; it != last; ++it)
	{
		if (pred(*it))
		{
			std::swap(*it, *boundary);
			++boundary;
		}
	}

	return boundary;
}

int main()
{
    std::vector<int> numbers = { 10, 3, 5, 9, 2, 8 };

	auto isPrime = [](int n) 
	{
		bool result = true; 
		double middle = sqrt(n);
		for (size_t i = 2; i <= middle; i++)
		{
			if (n % i == 0)
			{
				result = false;
			}
		} 
		return result;
	};

    auto boundary = partitionIt(numbers.begin(), numbers.end(), isPrime);

	std::sort(numbers.begin(), boundary);

	for (int n : numbers)
	{
		std::cout << n << ' ';
	}

}

