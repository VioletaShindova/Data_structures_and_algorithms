#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

/*
Дадено ви е цяло число, представено като целочислен масив от цифри, където всеки елемент на позиция i е i-тата цифра на числото. 
Числото се чете отляво надясно и не съдържа водещи нули.

Увеличете числото с едно и върнете получения масив от цифри.
*/

int main()
{
	std::vector<int> a;
	unsigned size;
	cin >> size;

	for (size_t i = 0; i < size; i++)
	{
		int num;
		cin >> num;
		a.push_back(num);
	}

	int currInd = size - 1;
	while (0 <= currInd && a[currInd] == 9)
	{
		a[currInd--] = 0;
	}

	if (currInd < 0)
	{
		a[0] = 1;
		a.push_back(0);
		size++;
	}
	else
		a[currInd]++;

	for (size_t i = 0; i < size; i++)
	{
		cout << a[i];
	}
}
