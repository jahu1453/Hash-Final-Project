#include "hashproj.h"
#include <string>
#include <iostream>
#include <list>
#include <math.h>

using namespace std;


//Constructor
TableLL::TableLL()
{
	this->tableSize = 10009;
	table = new Tab * [tableSize];
	for (int i = 0; i < 10009; i++)
		table[i] = nullptr;
}

//HashFunction
unsigned int TableLL::hashFunction(int key) {
	return(key % tableSize);
}

unsigned int TableLL::hashPrime(int key) {
	int x = floor(key / tableSize);
	return (x % tableSize);
}

//Search for a key
Tab* TableLL::searchItem(int key)
{
	//Compute the index by using the hash function
	int index = hashFunction(key);

	//Search the list 
	Tab* temp = table[index];
	while (temp != NULL) {

		if (temp->key == key)
			return temp;
		temp = temp->next;
	}
	return NULL;
}

void TableLL::insertItem(int key)
{
	if (!searchItem(key)){
		int index = hashFunction(key);
		// create a new node with the key and insert it in this slot's list
		Tab* newNode = new Tab;
		newNode->key = key;
		newNode->next = table[index];
		table[index] = newNode;
	}
	else {
		cout << "Duplicate entry: " << key << endl;
		
	}
}

void TableLL::printTable()
{
	for (int i = 0; i < tableSize; i++) {
		cout << i << "|| ";
		Tab* temp = table[i];
		while (temp != NULL) {
			cout << temp->key << " ";
			temp = temp->next;
		}
		cout << endl;
	}

}

void TableLL::deleteHash(int key) {
	if (searchItem(key)) {
		int index = hashFunction(key);
		Tab* temp = table[index];
		if (temp->key == key) {
			temp->next = table[index];
			delete temp;
		}
		else {
			Tab* curr = temp;
			temp = temp->next;
			while (temp->key != key && temp != NULL) {
				curr = curr->next;
				temp = temp->next;
			}
			curr->next = temp->next;
			delete temp;
		}
	}
	else {
		cout << "Item not found in table" << endl;
	}
}