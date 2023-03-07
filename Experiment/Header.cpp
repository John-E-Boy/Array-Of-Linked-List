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
	Array<int> ar;
	Node<int> n;


	
	/*
	cout << "Part 1: Basic Array" << endl;
	int size = 10;
	cout << "The capacity of the array intialized is 10.";
	cout << endl;
	ar.intialize(size);
	
	ar.insert_element_ar(0,5);
	ar.insert_element_ar(1,43);
	ar.insert_element_ar(2,23);
	ar.insert_element_ar(3,78);
	ar.insert_element_ar(4,90);
	ar.insert_element_ar(5,22);
	ar.insert_element_ar(6,116);
	ar.insert_element_ar(7,9);
	ar.insert_element_ar(8,18);
	ar.insert_element_ar(9,67);
	cout << endl;
	ar.remove_elem();
	cout << endl;
	ar.display();
	cout << endl;
	cout << ar;
	*/
	int n_size = 0;
	cout << "Part 2: Basic Linked List" << endl;
	cout << "How long do you want your list to be?:";
	cin >> n_size;
	for (int i = 0; i < n_size; i++)
	{
		n.add_Node();
	}
	n.remove_Node();


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