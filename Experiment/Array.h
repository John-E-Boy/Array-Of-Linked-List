#pragma once
#include "Node.h"
#include <iostream>
#include <iomanip>
using namespace std;


#ifndef Array_H
#define Array_H

template <class T>
class Node;

template <class T>
class Array;


// template class
template<class T>
class Array {
	friend class Node<T>;
	Node<T>* *array_nodes; // array of which each slot is linked lists, also had an error earlier that said required template arguements needed <T>
	// https://docs.microsoft.com/en-us/cpp/error-messages/tool-errors/linker-tools-error-lnk2019?view=msvc-170
	// Link is for line below as for what parameters to use for overriding a template ostream 
	template<class T> friend ostream& operator << (ostream& o, const Array<T>& ar); // THIS LINE 
	// line above can also be -> template<typename T> friend ostream& operator << (ostream& o, const Array<T>& ar); 
	template<class T> friend ostream& operator << (ostream& o, Node<T>& n1);


	friend class Node<T>; // Node class can access private memebers of Array


private:
	T* ar; // make this dynamic in intialization and delete
	int size_ar; // size of the array
	int num_elem; // number of elements in the array
public:

	// regular array functions
	void remove_elem(); // remove an element from the array 
	void insert_element_ar(int slot,T elem); // add element to array, to certian slot of array
	void intialize(int size); // intialize array
	void intialize_node_array(int size); // intializenode array
	void add_node_array(); // add to array of linked list
	void display_node_array(); // display array of linked list
	void display(); // display the array
	~Array() { delete[]ar; }; // deconstructor

};
// This function intializes the array 
template<class T>
void Array <T>::intialize(int size)
{
	size_ar = size; // capacity of the array
	num_elem = size_ar; // user input
	ar = new T[size_ar]; // new dynamic array

}
// This function intializes the linked lists array
template <class T>
void::Array <T>::intialize_node_array(int size)
{

	size_ar = size; // capacity of array
	num_elem = size_ar; 
	Node<T>* *ar = new Node<T>*[size_ar]; //Well, if a regular pointer is to refer to an object in memory, then a double pointer is a variable that points to another pointer which in turn, points to an object in memory.
	for (int i = 0; i < size_ar; i++) // Each slot is set to NULL
	{
		ar[i] = NULL;
	}
	array_nodes = ar;
}

// This function adds another element to the linked list array
template <class T>
void::Array<T>::add_node_array()
{
	int slot = 0;
	cout << "What slot in the array do you want to insert in?" << endl;
	cin >> slot;
	while (slot <= 0 || slot > size_ar) // if user input is over or under array capacity
	{
		cout << "The slot in which you want to insert the element does not exist, enter in another slot: ";
		cin >> slot;
	}
	T elem;
	cout << "What element do you want to insert?:" << endl; // ask user for input
	cin >> elem; // user input
	slot = slot - 1; // this done acting off the assumption that the user doesn't know that arrays have a "zero" slot, so if they enter one, then the input will actually go into ar[0]
	Node<T>* el = new Node<T>; // create new node
	el->element = elem; // set element equal to user input
	el->next = NULL; // if the element is the first in the list then set its next pointer to NULL
	if (array_nodes[slot] == NULL) 
	{
		el->prev = NULL; // if the element is the first in the list then set its prev pointer to NULL
		array_nodes[slot] = el;
	}

	else // if the element is not the beginning of the list at that index in the array
	{
		Node<T>* tracker = array_nodes[slot]; // start at the beginning of the list 
		while (tracker->next != NULL) // while the pointer isn't equal to NULL
		{
			tracker = tracker->next; // traverse all the way to the end of the list 
		}
		tracker->next = el; // add the new element
		el->prev = tracker; // connect new elements prev pointer to the previous element
	}


}// this function will display the array of linked lists
template <class T>
void Array<T>::display_node_array()
{
	for (int i = 0; i < size_ar; i++)
	{
		cout << "In slot " << i + 1 << ":" << endl;
		Node<T>* track = array_nodes[i];
		while (track != NULL)
		{
			cout << "Element: " << track->element << endl;
			track = track->next;
		}
		cout << endl;
	}

}

// this function inserts the element into the array at a specific spot
template<class T>
void Array<T>::insert_element_ar(int slot,T elem)
{
	// This lower section is commentted out because this is handled in the .cpp
	/*
	int slot;
	cout << "What slot in the array would you like to insert?:" << endl;
	cin >> slot;

	while (slot <= 0 || slot > size_ar)
	{
		cout << "The slot in which you want to insert the element does not exist, enter in another slot: ";
		cin >> slot;
	}
	slot = slot - 1;
	T elem;
	cout << "What element would you like to insert?" << endl;
	cin >> elem;
	*/

	ar[slot] = elem;
}

template<class T>
void Array<T>::display()
{
	for (int i = 0; i < num_elem; i++)
	{
		cout << ar[i] << " ";
	}
}


// https://docs.microsoft.com/en-us/cpp/error-messages/tool-errors/linker-tools-error-lnk2019?view=msvc-170
// This functions logic was easy, but hard to debug due to parameter errors above. 
// See link above as to how to overload with a template class, about 3/4 of the way down the page.
// Error was something that said "unresolved externals"
template <class T>
ostream& operator<< (ostream& o, const Array<T>& ar)
{
	cout << "The array size is: " << ar.num_elem << endl;
	cout << "The elements in the array are: ";
	for (int i = 0; i < ar.num_elem; i++)
	{
		o << ar.ar[i] << " ";
	}
	return o;
}


template<class T>
void Array<T>::remove_elem()
{
	T elem;
	cout << "The current elements in the array are: ";
	display();
	cout << ". Which element would you like to remove \n (type in the element itself not the slot it's located at): " << endl;
	cin >> elem;

	T temp;
	for (int i = 0; i < num_elem; i++)
	{
		if (ar[i] == elem)
		{
			temp = ar[i]; // take the element that wants to be removed and puts it at the end of the array
			num_elem--; // decreases the number of elements so that element can't be accessed anymore
			for (int j = i; j < num_elem; j++) // j starts at where the element is found and shifts the rest of the elements 
			{
				ar[j] = ar[j + 1];
			}
			ar[num_elem] = temp;
			cout << "The array is now: ";
			display();
			return;
		}
	}

}
#endif

