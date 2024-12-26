// Circular_Queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CircularQueue.h"

int main()
{
    CircularQueue<int> q = CircularQueue<int>();
    
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    std::cout << q.peek() << std::endl;
    
    q.dequeue();
    std::cout << q.peek();
}
