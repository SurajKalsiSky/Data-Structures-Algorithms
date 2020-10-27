#pragma once

#include <vector>
#include <string>
#include <iostream>

using namespace std;
using V = vector<string>; // alias for a vector string

class RedisHashTable {
private:
	V** data;
	int size;
	int HashFunction(int key) {
		return key % size;
	}
public:
	RedisHashTable(int size) {
		this->size = size;
		data = new V* [size];
		for (int i = 0; i < size; i++)
			data[i] = NULL;
	}
	void Display() {
		for (int i = 0; i < size; i++)
			if (data[i] != NULL)
				cout << "Index: " << i << " Contents: " << data[i] << endl;
	}
	void Insert(int key, V* item) {
		int hash = HashFunction(key);
		while (data[hash] != NULL) {
			++hash;
			hash %= size;
		}
		data[hash] = item;

	}
};

