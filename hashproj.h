#pragma once
#ifndef HASHPROJ_HPP
#define HASHPROJ_HPP

#include <string>

using namespace std;

struct Tab
{
	int key;
	struct Tab* next; //pointer for LL set up
	struct Tab* left;//pointer to left child
	struct Tab* right;//pointer to right child
	struct Tab* parent;
};

class TableLP
{
private:
	const int tableSize = 10009; //total table size given
	int currSize = 0;//counter to check if table is full
	int table[10009];
	

public:
	//Constuctor
	TableLP();
	
	
	//Insert
	void insertItem(int key);
	
	// hash function to map values to key
	unsigned int hashFunction(int key);
	unsigned int hashPrime(int key);
	
	//prints entire table front to back
	void printTable();
	
	//Searches for a key
	bool searchItem(int key);

	//Delete
	void deleteHash(int key);
	
};

class TableLL
{
private:
	int tableSize = 10009; //total table size given
	int currSize = 0;//counter to check if table is full
	Tab** table;
	

public:
	//Constuctor
	TableLL();
	

	//Insert
	void insertItem(int key);

	// hash function to map values to key
	unsigned int hashFunction(int key);
	unsigned int hashPrime(int key);

	//prints entire table front to back
	void printTable();

	//Searches for a key
	Tab* searchItem(int key);

	//Delete
	void deleteHash(int key);

};

class TableBST
{
private:
	int tableSize = 1019; //total table size given
	int currSize = 0;//counter to check if table is full
	Tab** table;
	Tab* root;
	

public:
	//Constuctor
	TableBST();
	

	//Insert
	void insertItem(int key);

	// hash function to map values to key
	unsigned int hashFunction(int key);
	unsigned int hashPrime(int key);

	//prints entire table front to back
	void printTable();

	//Searches for a key
	Tab* searchItem(int key);

	//Delete
	void deleteHash(int key);

};

class TableCuckoo
{
private:
	int tableSize = 1019; //total table size given
	int currSize = 0;//counter to check if table is full
	int tableOne[10009];
	int tableTwo[10009];

public:
	//Constuctor
	TableCuckoo();

	//Insert
	void insertItem(int key, int hasher);

	// hash function to map values to key
	unsigned int hashFunction(int key);
	unsigned int hashPrime(int key);

	//prints entire table front to back
	void printTable();

	//Searches for a key
	bool searchItem(int key);

	//Delete
	void deleteHash(int key);

};

#endif