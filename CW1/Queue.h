#pragma once

#include <vector>
#include <string>

using namespace std;
using V = vector<string>; // alias for a vector string

class Queue {
private:
	int count; // number of items in queue
	V* data; // pointer to data
	int front; // pointer to front of the queue
	int rear;  // pointer to rear of the queue
	int size;  // size of the array
public:
	Queue(int size) {
		this->size = size; // initialise size (class) variable
		data = new V[size]; // initialise array to hold the queue (with allocated size)
		front = 0;  // initialise front pointer
		rear = -1; // initialise rear pointer
		count = 0; // initialise count variable
	}
	V PeakFront() { // returns front element of the queue
		return data[front];
	}
	bool IsEmpty() { // returns whether queue is empty or not
		return count == 0;
	}
	bool IsFull() { // returns whether queue is full or not
		return count == size;
	}
	bool Insert(V item) { // insert an item into the queue
		if (IsFull()) {
			return false; // do not insert if queue is full
		}
		if (rear == size-1) { // wrap around as this is a circular queue
			rear = -1; // set rear pointer to -1 as it will be incremented
		}
		rear++; // increment rear pointer
		data[rear] = item; // set new item in the rear position
		count++; // increment the count
		return true;
	}
	V Remove() { // remove an item from the queue
		if (IsEmpty()) {
			V empty(1, "end");
			return empty; // do not remove if the queue is empty
		}
		V frontValue = PeakFront(); // get item at front of queue
		if (front == size - 1) { // wrap around as this is a circular queue
			front = -1; // set front pointer to -1 as it will be incremented
		}
		front++; // increment front pointer
		count--; // decrement the count
		return frontValue;
	}
};