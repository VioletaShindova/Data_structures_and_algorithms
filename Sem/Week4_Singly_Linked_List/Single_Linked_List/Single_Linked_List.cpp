// Single_Linked_List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SinglyLinkedList.h"

bool testPushFront()
{
    SinglyLinkedList<int> list;
    list.pushFront(10);
    list.pushFront(20);
    return list.front() == 20 && list.back() == 10 && list.getSize() == 2;
}

int main()
{
    std::cout << "Test Push Front: " << testPushFront() << std::endl;
}

