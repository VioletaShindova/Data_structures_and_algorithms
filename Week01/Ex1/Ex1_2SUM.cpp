#include <iostream>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;

/*
Даден ви е масив A с дължина N от цели числа, както и цяло число Z, което е вашата цел. Трябва да изведете на стандартния изход индексите на две числа от масива, които имат сума числото Z.

Гарантирано ви е, че винаги ще има точно една валидна двойка индекси на задачата.

Отговорът трябва да се върне във възходящ ред на индексите.
*/

int main()
{
  /*  std::vector<int> a;
    int size, z;
    cin >> size >> z;

    for (size_t i = 0; i < size; i++)
    {
        int el;
        cin >> el;
        a.push_back(el);
    }

    std::sort(a.begin(), a.end());

    int lIdx = 0;
    int rIdx = size - 1;

    while (lIdx < rIdx)
    {
        int res = a[lIdx] + a[rIdx];
        if (res < z)
            lIdx++;
        else if (res > z)
            rIdx--;
        else
        {
            cout << lIdx << ' ' << rIdx;
            break;
        }
    }*/

   std::vector<int> a;
   int size, z;
   cin >> size >> z;

   for (size_t i = 0; i < size; i++)
   {
       int el;
       cin >> el;
       a.push_back(el);
   }
    
   for (size_t i = 0; i < size - 1; i++)
   {
       for (size_t j = i + 1; j < size; j++)
       {
           if (a[i] + a[j] == z)
               cout << i << ' ' << j;
       }
   }
}

