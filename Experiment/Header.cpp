// Jonathan Essapour
// General goal: build arrays, linked lists, and mesh them together.
#include "Node.h"
#include "Array.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()

{
	// declare class objects
	Node<int> n;


	int n_size = 10;
	cout << "Part 2: Basic Linked List" << endl;
	cout << "How long do you want your list to be?:";
	cout << n_size;
	cout << endl;
	for (int i = 0; i < n_size; i++)
	{
		int elem;
		elem = i;
		cout << elem << " being inserted" << endl;
		n.add_Node(elem);
	}
	n.remove_Node(5);
	n.remove_Node(0);
	n.remove_Node(9);


	/*
	cout << "Part 3: Array of Linked Lists" << endl;
	int ar_n_size = 0;
	cout << "How many elements should the array hold?" << endl;
	cin >> ar_n_size; // from user input
	ar.intialize_node_array(ar_n_size);
	for (int i = 0; i < ar_n_size; i++)
	{
		ar.add_node_array();
	}
    ar.display_node_array();
	*/
	

	return 0;
}