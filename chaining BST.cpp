#include "hashproj.h"
#include <string>
#include <iostream>
#include <math.h>

using namespace std;
Tab* insertHelper(Tab* wiggler, Tab* newNode);
Tab* deleteHelper(Tab* crawler, int key);
Tab* searchHelper(Tab* crawler, int data);

//Constructor
TableBST::TableBST()
{
	this->tableSize = 10009;
	table = new Tab * [tableSize];
	for (int i = 0; i < 10009; i++)
		table[i] = nullptr;
}

//Hash function
unsigned int TableBST::hashFunction(int key) {
	return(key % tableSize);
}

unsigned int TableBST::hashPrime(int key) {
	int x = floor(key / tableSize);
	return (x % tableSize);
}

//Insert
void TableBST::insertItem(int key) {
	Tab* newNode = new Tab;
	newNode->key = key;
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->parent = NULL;
	int index = hashFunction(key);
	Tab* root = table[index];
	Tab* temp = insertHelper(root, newNode);
}

Tab* insertHelper(Tab* wiggler, Tab* newNode) {
	if (wiggler == NULL) {
		return newNode;
	}
	else if (newNode->key < wiggler->key) {
		Tab* leftnode = insertHelper(wiggler->left, newNode);
		wiggler->left = leftnode;
		leftnode->parent = wiggler;
	}
	else if (newNode->key > wiggler->key) {
		Tab* rightnode = insertHelper(wiggler->right, newNode);
		wiggler->right = rightnode;
		rightnode->parent = wiggler;
	}
	return wiggler;
}

//Search
Tab* TableBST::searchItem(int key) {
	int index = hashFunction(key);
	Tab* root = table[index];
	Tab* info = searchHelper(root, key);
	if (info == NULL) {
		cout << "Key not found." << endl;
	}
}

Tab* searchHelper(Tab* crawler, int data) {
	if (crawler == NULL) {
		return NULL;
	}
	if (crawler->key == data) {
		return crawler;
	}
	else if (crawler->key > data) {
		return searchHelper(crawler->left, data);
	}
	else if (crawler->key < data) {
		return  searchHelper(crawler->right, data);
	}
	return crawler;
}


//Delete
void TableBST::deleteHash(int key) {
	int index = hashFunction(key);
	Tab* base = table[index];
	Tab* node = deleteHelper(base,key);
}

Tab* deleteHelper(Tab* crawler, int key) {
	if (crawler == NULL) {
		cout << "Key not found" << endl;
	}
	else if (crawler->key < key) {
		crawler->left = deleteHelper(crawler->left, key);
	}
	else if (crawler->key > key) {
			crawler->right = deleteHelper(crawler->right, key);
	}
	else {
		//No child
		if (crawler->left == NULL && crawler->right == NULL)
		{
			delete crawler;
			crawler = NULL;
		}
		//Only right child
		else if (crawler->left == NULL)
		{
			Tab* temp = crawler;
			crawler->right->parent = crawler->parent;
			crawler = crawler->right;
			delete temp;
		}
		//Only left child
		else if (crawler->right == NULL)
		{
			Tab* temp = crawler;
			crawler->left->parent = crawler->parent;
			crawler = crawler->left;
			delete temp;
		}
		//Both left and right child
		else
		{
			Tab* minValueNode = crawler->right;
			while (minValueNode->left != NULL)
			{
				minValueNode = minValueNode->left;
			}
			crawler->key = minValueNode->key;
			crawler->right = deleteHelper(crawler->right, minValueNode->key);
		}
	}
	
}