#include "hashproj.h"
#include <iostream>
#include <string>
#include <time.h>
#include <fstream>

using namespace std;
void menu();


int main(int argc, char *argv[]) {
	//Choosing which type of hash to use
	int arrKeys[10009] = {};
	int choice = 0;
	int i = 0;
	int start, end, total, counter;
	string cell;
	TableLP lp;
	TableLL ll;
	TableBST bs;
	TableCuckoo ck;
	menu();
	cin >> choice;
	cout << "Enter number of elements to insert" << endl;
	cin >> counter;
	ifstream instream(argv[1]);
	if (instream.is_open()) {
		while (instream.good() && i != counter) {
			getline(instream, cell, ',');
			int key = stoi(cell);
			arrKeys[i] = key;
			i++;
		}
	}
	//Hashing selected implement
	//Linear probing
	if (choice == 1) {
		//Insert timing
		start = clock();
		for (int j = 0; j < counter; j++) {
			int data = arrKeys[j];
			lp.insertItem(data);
		}
		end = clock();
		total = (double)(end - start) / CLOCKS_PER_SEC;
		cout << "Run time for linear probe insert: " << total << endl;
		//going through input data and searching for each element
		start = clock();
		for (int j = 0; j < counter; j++) {
			int data = arrKeys[j];
			lp.searchItem(data);
		}
		end = clock();
		total = (double)(end - start) / CLOCKS_PER_SEC;
		cout << "Run time for linear probe search: " << total << endl;
		start = clock();
		//Deleting each element that was inserted
		for (int j = 0; j < counter; j++) {
			int data = arrKeys[j];
			lp.deleteHash(data);
		}
		end = clock();
		total = (double)(end - start) / CLOCKS_PER_SEC;
		cout << "Run time for linear probe delete: " << total << endl;
	}
	//Linked List
	if (choice == 2) {
		//Insert timing
		start = clock();
		for (int j = 0; j < counter; j++) {
			int data = arrKeys[j];
			ll.insertItem(data);
		}
		end = clock();
		total = (double)(end - start) / CLOCKS_PER_SEC;
		cout << "Run time for linked list insert: " << total << endl;
		//going through input data and searching for each element
		start = clock();
		for (int j = 0; j < counter; j++) {
			int data = arrKeys[j];
			ll.searchItem(data);
		}
		end = clock();
		total = (double)(end - start) / CLOCKS_PER_SEC;
		cout << "Run time for linked list search: " << total << endl;
		start = clock();
		//Deleting each element that was inserted
		for (int j = 0; j < counter; j++) {
			int data = arrKeys[j];
			ll.deleteHash(data);
		}
		end = clock();
		total = (double)(end - start) / CLOCKS_PER_SEC;
		cout << "Run time for linked list delete: " << total << endl;
	}
	//BST
	if (choice == 3) {
		//Insert timing
		start = clock();
		for (int j = 0; j < counter; j++) {
			int data = arrKeys[j];
			bs.insertItem(data);
		}
		end = clock();
		total = (double)(end - start) / CLOCKS_PER_SEC;
		cout << "Run time for linear probe insert: " << total << endl;
		//going through input data and searching for each element
		start = clock();
		for (int j = 0; j < counter; j++) {
			int data = arrKeys[j];
			bs.searchItem(data);
		}
		end = clock();
		total = (double)(end - start) / CLOCKS_PER_SEC;
		cout << "Run time for linear probe search: " << total << endl;
		start = clock();
		//Deleting each element that was inserted
		for (int j = 0; j < counter; j++) {
			int data = arrKeys[j];
			bs.deleteHash(data);
		}
		end = clock();
		total = (double)(end - start) / CLOCKS_PER_SEC;
		cout << "Run time for linear probe delete: " << total << endl;
	}
	//Cuckoo
	if (choice == 4) {
		//Insert timing
		start = clock();
		for (int j = 0; j < counter; j++) {
			int data = arrKeys[j];
			ck.insertItem(data, 1);
		}
		end = clock();
		total = (double)(end - start) / CLOCKS_PER_SEC;
		cout << "Run time for linear probe insert: " << total << endl;
		//going through input data and searching for each element
		start = clock();
		for (int j = 0; j < counter; j++) {
			int data = arrKeys[j];
			ck.searchItem(data);
		}
		end = clock();
		total = (double)(end - start) / CLOCKS_PER_SEC;
		cout << "Run time for linear probe search: " << total << endl;
		start = clock();
		//Deleting each element that was inserted
		for (int j = 0; j < counter; j++) {
			int data = arrKeys[j];
			ck.deleteHash(data);
		}
		end = clock();
		total = (double)(end - start) / CLOCKS_PER_SEC;
		cout << "Run time for linear probe delete: " << total << endl;
	}
	if (choice == 5) {
		cout << "exiting" << endl;
		return -1;
	}
	return 0;

}

void menu() {
	cout << "Choose which type of hash:" << endl;
	cout << "1. Linear Probing" << endl;
	cout << "2. Linked List" << endl;
	cout << "3. BST" << endl;
	cout << "4. Cuckoo" << endl;
	cout << "5. Exit" << endl;
	cout << "==========" << endl;
}