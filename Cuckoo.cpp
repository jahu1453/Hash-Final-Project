#include "hashproj.h"
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

//Constructors
TableCuckoo::TableCuckoo() {
	for (int i = 0; i < tableSize; i++) {
		tableOne[i] = -1;
	}

	for (int i = 0; i < tableSize; i++) {
		tableTwo[i] = -1;
	}
}


//Hash one
unsigned int TableCuckoo::hashFunction(int key) {
	return (key % tableSize);
}

//Hash prime
unsigned int TableCuckoo::hashPrime(int key) {
	int x = floor(key / tableSize);
	return (x % tableSize);
}


//insert
void TableCuckoo::insertItem(int key, int hasher) {
	int temp;
	if (hasher == 1) {
		int index = hashFunction(key);
		if (tableOne[index] == -1) {
			tableOne[index] = key;
		}
		else {
			temp = tableOne[index];
			tableOne[index] = key;
			insertItem(temp, 2);
		}
	}
	else {
		int index = hashPrime(key);
		if (tableTwo[index] == -1) {
			tableTwo[index] = key;
		}
		else {
			temp = tableTwo[index];
			tableTwo[index] = key;
			insertItem(temp, 1);
		}
		
	}
}

//Search
bool TableCuckoo::searchItem(int key) {
	int index = hashFunction(key);
	if (tableOne[index] == key) {
		return true;
	}
	else {
		index = hashPrime(key);
		if (tableTwo[index] == key) {
			return true;
		}
	}
	return false;
	cout << "key not found" << endl;
}

//Delete
void TableCuckoo::deleteHash(int key) {
	int index = hashFunction(key);
	if (tableOne[index] == key) {
		tableOne[index] = -1;
	}
	else {
		index = hashPrime(key);
		if (tableTwo[index] == key) {
			tableTwo[index] = -1;
		}
	}
}
