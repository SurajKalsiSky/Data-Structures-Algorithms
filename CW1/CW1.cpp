// CW1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "Queue.h"
#include "RedisHashTable.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using V = vector<string>; // alias for a vector string

int main()
{
    cout << "********************************************\n";
    cout << "Welcome to the C++ Redis database!\n";
    cout << "You can use......\n";
    cout << "Finish a command by\n";
    cout << "Finish all commands with EXEC\n";
    cout << "Example usage........\n";
    cout << "Please enter your commands\n";
    cout << "********************************************\n\n";

    Queue queue(3);

    bool userInsertingCommands = true;
    V redisCommand;

    while (userInsertingCommands) {
        string stringCommand;

        cout << "Enter command, finsh by tapping enter: ";
        cin >> stringCommand;

        if (stringCommand == "-") {
            userInsertingCommands = queue.Insert(redisCommand);
            redisCommand.erase(redisCommand.begin(), redisCommand.end());
        }
        else if (stringCommand == "EXEC") {
            userInsertingCommands = false;
        }
        else {
            redisCommand.push_back(stringCommand);
        }
    }

    RedisHashTable* table = new RedisHashTable(17);

    while (true) {
        V element = queue.Remove();

        if (element[0] == "end") {
            break;
        }

        table->Insert(10, &element);
    }

    table->Display();
}

