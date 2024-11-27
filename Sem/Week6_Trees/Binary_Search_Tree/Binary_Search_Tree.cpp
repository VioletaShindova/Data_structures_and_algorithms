// Binary_Search_Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BinarySearchTree.h"

int main()
{
    auto comp = [](int a, int b) { return a > b; };
    BinarySearchTree<int, decltype(comp)> tree(comp);


    tree.insert(5);
    tree.insert(10);
    tree.insert(20);
    tree.insert(3);
    tree.insert(4);
    tree.insert(1);
    std::cout << "Min node: " << tree.findMinEl();
}

