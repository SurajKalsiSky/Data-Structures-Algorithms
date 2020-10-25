// CW1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "Queue.h" // import queue class
#include <iostream>

using namespace std;

int main()
{
    cout << "Hello World!\n";

    Queue queue(4);
    queue.Insert(4);
    queue.Insert(6);
    queue.Insert(3);
    queue.Insert(8);
    queue.Insert(1);
    

    cout << queue.Remove();
    cout << queue.Remove();
    cout << queue.Remove();
    cout << queue.Remove();
    cout << queue.Remove();
}

