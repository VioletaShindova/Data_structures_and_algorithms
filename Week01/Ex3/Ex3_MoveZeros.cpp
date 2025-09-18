#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

/*
Даден е масив А от цели числа с дължина N. Задачата ви е да преместите всички срещания на числото 0 в края на масива, 
като запазите относителния ред на останалите му елементи.

Решете задачата in-place (без допълнителна памет).
*/

int main()
{
    size_t size;
    cin >> size;
    std::vector<int> arr(size);

    for (size_t i = 0; i < size; i++)
        cin >> arr[i];

    int position = 0;
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] != 0)
            arr[position++] = arr[i];
    }

    while (position < size)
        arr[position++] = 0;

    for (size_t i = 0; i < size; i++)
        cout << arr[i] << ' ';
}
