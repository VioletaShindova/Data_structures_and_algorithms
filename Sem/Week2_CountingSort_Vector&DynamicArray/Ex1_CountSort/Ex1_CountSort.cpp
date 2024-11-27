// Ex1_CountSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

struct Student 
{
    std::string name;
    int grade;
};

void countSortForGrades(Student* array, size_t size)
{
    const unsigned GRADES_VALUES_COUNT = 5; //2,3,4,5,6

    size_t* countArray = new size_t[GRADES_VALUES_COUNT]{0};

    for (size_t i = 0; i < size; i++)
    {
        countArray[array[i].grade - 2]++;
    }


}

int main()
{
    Student array[] = { {"Petur", 4}, {"Ivan", 6}, {"Alex", 4}, {"Vladimir", 5}, {"Katerina", 5} };

    countSortForGrades(array, sizeof(array) / sizeof(Student));
}
