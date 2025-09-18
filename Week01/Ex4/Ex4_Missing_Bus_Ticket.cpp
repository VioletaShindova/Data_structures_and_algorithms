#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

/*
В училищен автобус № 94 всеки ученик притежава билет с номер
Т
. Билетът се дава на всеки ученик при влизане в автобуса. 
Допустимо е двама ученици да притежават билети, които имат еднакъв номер. 
Номерът представлява цяло положително число, изключение правят билетите на учениците със специални права, техните са отрицателни числа. 
Продавачът на билети разполага със списък, на който виждат номерата на продадените билети. Идва ред на Иванчо да си купи билет. 
Билетът на Иванчо е уникален, защото той винаги е най-малкият номер от положителните номера, който липсва в списъка на продавача. 
Вашата задача е да разберете какъв е номера на билета на Иванчо.
*/

int main()
{
	size_t size;
	cin >> size;
	std::vector<std::pair<int, size_t>> tickets;

	for (size_t i = 0; i < size; i++)
	{
		int num;
		cin >> num;
		tickets.push_back({ num, i });
	}

	std::sort(tickets.begin(), tickets.end());
	int min = 1;
	int prevValue = tickets[0].first;
	for (size_t i = 0; i < size; i++)
	{
		if (0 < tickets[i].first)
		{
			if (prevValue == tickets[i].first && i != 0)
				continue;

			if (tickets[i].first != min)
				break;

			prevValue = tickets[i].first;
			min++;
		}
	}
	cout << min;
}