// 2_IS_2_3_7MI0700206.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Vector.h"

int main()
{
    Vector<bool> vec;

    vec.push_back(true);
    vec.push_back(false);
    vec.push_back(true);

    std::cout << "Vector elements after push_back: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << (*it ? "true" : "false") << " ";
    }
    std::cout << std::endl;

    auto it = vec.begin();
    ++it; 
    vec.insert(it, true);

    std::cout << "Vector elements after insert: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << (*it ? "true" : "false") << " ";
    }
    std::cout << std::endl;

    vec.remove(it);

    std::cout << "Vector elements after remove: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << (*it ? "true" : "false") << " ";
    }
    std::cout << std::endl;

    vec.pop_back();
    std::cout << "Vector elements after pop_back: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << (*it ? "true" : "false") << " ";
    }
    std::cout << std::endl;

    vec.pop_front();
    std::cout << "Vector elements after pop_front: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << (*it ? "true" : "false") << " ";
    }
    std::cout << std::endl;

    vec.resize(5);
    std::cout << "Vector elements after resize: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << (*it ? "true" : "false") << " ";
    }
    std::cout << std::endl;

    std::cout << "Vector elements in reverse: ";
    for (auto rit = vec.rbegin(); rit != vec.rend(); ++rit) {
        std::cout << (*rit ? "true" : "false") << " ";
    }
    std::cout << std::endl;

    return 0;
}