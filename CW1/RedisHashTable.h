#pragma once

#include <vector>
#include <string>
#include <iostream>

using namespace std;
using V = vector<string>; // alias for a vector string

class RedisHashTable {
private:
	V** data; // pointer to a pointer for data attribute of a vector type
	int size; // size of the hash table
	int HashFunction(int key) { // function to hash key to find a free index
		return size - (key % size); // double hashing algorithm
	}
public:
	RedisHashTable(int size) {
		this->size = size; // initialise size (class) variable
		data = new V* [size]; // initialise hash table with correct size
		for (int i = 0; i < size; i++)
			data[i] = NULL; // assign each element inside hash table a value of NULL
	}
	void Display() {
		cout << '\n';
		for (int i = 0; i < size; i++) // iterate over all elements in hash table
			if (data[i] != NULL) { // true only when element has been set
				cout << "Index: " << i << " Pointer reference: " << data[i] << endl; // prints the index and reference of the vector
			}
	}
	void Insert(int key, V* item) { // function takes key and a pointer to the vector being stored
		cout << '\n';
		int hash = HashFunction(key); // get index value via hash function
		while (data[hash] != NULL) { // if there already is a value at that index, find a new slot
			++hash; // increment hash value
			hash = HashFunction(hash); // get new index value via hash function
		}
		data[hash] = item; // set reference value in hash table
		V redisCommand = *item; // get actual vector from pointer reference
		for (string ele : redisCommand) // loop through elements in the vector
			cout << "Set: " << ele << endl; // print each element
	}
};

