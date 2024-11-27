// 1_IS_1_3_7MI0700206.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <ctime>
#include <type_traits>
#include "BrowserTab.h"

int main()
{
    BrowserTab<std::string, time_t> browser;

    std::string command = "", url = "";
    
    do
    {
        std::cin >> command;

        if (command == "$")
        {
            continue;
        }
        else if (command == "GO")
        {
            std::cin >> url;
            browser.go(url);
        }
        else if (command == "INSERT")
        {
            std::cin >> url;
            browser.insert(url);
        }
        else if (command == "BACK")
        {
            browser.back();
        }
        else if (command == "FORWARD")
        {
            browser.forward();
        }
        else if (command == "REMOVE")
        {
            browser.remove();
        }
        else if (command == "PRINT")
        {
            browser.print();
        }
        else if (command == "SORT")
        {
            std::cin >> command;

            if (command == "URL")
            {

            }
            else if (command == "TIME")
            {
                browser.sortByTime();
            }
        }
        else if(command == "STOP")
        {
            break;
        }

    } while (true);

}