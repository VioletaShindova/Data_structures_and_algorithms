// Ex6_First_Exam.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    std::string word;
    cin >> word;

    std::vector<std::pair<char, int>> students;
    char group;
    cin >> group;

    std::vector<size_t> positions;
    for (size_t i = 0; i < word.size(); i++) {
        students.push_back({ word[i], i });
        if (students[i].first == group)
            positions.push_back(i);
    }

    if (positions.size() == 1)
    {
        for (size_t i = 0; i < students.size(); i++)
        {
            if(i <= positions[0])
                std::cout << positions[0] - i << ' ';
            else
                std::cout << i - positions[0] << ' ';
        }
    }
    else if(positions.size() != 0)
    {
        size_t lastPosition = 0;
        for (size_t i = 0; i < positions.size(); i++)
        {
            for (size_t j = lastPosition; j < students.size(); j++)
            {
                if (j <= positions[i])
                    std::cout << positions[i] - j << ' ';
                else
                {
                    std::cout << j - positions[i] << ' ';
                    lastPosition = j + 1;
                    break;
                }
            }
        }
    }
    else
        std::cout << 0;

}

