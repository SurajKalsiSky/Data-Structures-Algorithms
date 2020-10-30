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
    cout << "You can use 'GET' and 'SET' commands\n";
    cout << "Finish a command using '-'\n";
    cout << "Finish program with EXEC\n";
    cout << "********************************************\n\n";

    Queue queue(5); // initalise queue with a size of 5

    bool userInsertingCommands = true; // boolean used to exit while loop
    V redisCommand; // initialise vector to store Redis command

    while (userInsertingCommands) { // loop to obtain all user inputs
        string stringCommand; // initialise string for user input

        cout << "Enter command, finsh by tapping enter: ";
        cin >> stringCommand; // user input is stored to stringCommand variable

        if (stringCommand == "-") { // check if user has finished entering command
            userInsertingCommands = queue.Insert(redisCommand); // insert vector containing command into the queue. If queue is full, exit loop
            redisCommand.erase(redisCommand.begin(), redisCommand.end()); // flush the vector to enter new command
        }
        else if (stringCommand == "EXEC") { // check if user is done with program and wants to display output
            userInsertingCommands = false; // set boolean to exit loop
        }
        else {
            redisCommand.push_back(stringCommand); // insert string into vector as it is a valid command
        }
    }

    RedisHashTable* table = new RedisHashTable(17); // initialise hash table with a size that is a prime number

    while (true) { // loop through all elements in the queue
        V element = queue.Remove(); // on each iteration, remove the first element from the queue

        if (element[0] == "end") { // once end of queue is reached, exit loop
            break;
        }

        table->Insert(19, &element); // insert each element's reference into the hash table
    }

    table->Display(); // invoke hash table's Display function
}

