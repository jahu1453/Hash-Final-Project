#include "hashproj.h"
#include <string>
#include <iostream>
#include <math.h>

using namespace std;

//Class implement for linear probing

//Constructor
TableLP::TableLP() {
	for (int i = 0; i < tableSize; i++)
		table[i] = -1;
	
}

//Hash inputed key
unsigned int TableLP::hashFunction(int key) {
	return (key % tableSize);
}

unsigned int TableLP::hashPrime(int key) {
	int x = floor(key / tableSize);
	return (x % tableSize);
}

//Insert item into table using linear probing 
void TableLP::insertItem(int key) {
		unsigned int index = hashFunction(key);
		if (table[index] == -1) {
			table[index] = key;
		}
		else {
			cout << index << endl;
			while (table[index] != -1) {
				if (index == tableSize) {
					
					index = 0;
					
				}
				else {
					index++;
				}	
			}
			table[index] = key;
		}
	
}



bool TableLP::searchItem(int key) {
	//Compute the index by using the hash function
	unsigned int index = hashFunction(key);
	if (table[index] == key) {
		
		return true;
	}
	else if (table[index] != key) {
		while (table[index] != key) {
			if (index == tableSize) {
				index = 0;
			}
			else {
				index++;
			}
			
		}
		return true;
	}
	return false;
}

void TableLP::deleteHash(int key) {
	unsigned int index = hashFunction(key);
	if (table[index] == key) {
		table[index] = -1;
	}
	else if (table[index] != key) {
		while (table[index] != key) {
			if (index == tableSize) {
				index = 0;
			}
			else {
				index++;
			}

		}
		table[index] = -1;
	}
}