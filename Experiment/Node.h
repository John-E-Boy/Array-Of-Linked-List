
// Jonathan Essapour
// General Goal: Make a template class that includes various data types or structures
// such as arrays and linked lists
#include "Array.h"
#include <iostream>
#include <iomanip>
using namespace std;


#ifndef Node_H
#define Node_H

template <class T>
class Node;

template <class T>
class Array;


// template class

// Make a node class next
template<class T>
class Node
{
	friend class Array<T>;
private:

	Node<T>* prev; // point to previous memory location
	Node<T>* next; // point to next memory location
	T element; // hold the data
	Node<T>* begin; // root node
public:
	Node() { prev = NULL; next = NULL; element = NULL; begin = NULL; };
	~Node(); // Destructor

	void add_Node();
	void display_Nodes();
	void remove_Node();
	
};
// Destructor to delete all nodes and free memory
template<class T>
Node<T>::~Node() {
	Node<T>* current = begin;
	while (current != NULL) {
		Node<T>* nextNode = current->next;
		delete current;
		current = nextNode;
	}
}
template<class T>
void Node<T>::remove_Node()
{
	display_Nodes();
	T elem;
	cout << "Which element would you like to remove from the linked list?: " << endl;
	cin >> elem;

	Node<T>* finder ;
	finder = begin;

	
	while (finder->element != elem)
	{
		//cout << "enter 0";
		finder = finder-> next;
	}
	
	
	if (finder->element == begin->element)
	{
		begin = finder->next;
	}
	else if (finder->next == NULL)
	{
		finder->prev->next= NULL;
	}
	else
	{
		finder->prev->next = finder->next;
		finder->next->prev = finder->prev;
	}
	
	
	display_Nodes();
}

template<class T>
void Node<T>::display_Nodes()
{
	//cout << "entered";
	Node<T>* mover = begin;
	if (begin->next == NULL) 
	{
		cout << "First Node: " << begin->element << endl;
		cout << endl;
		return;
	}
	
	cout << "First Node: " << begin->element << endl;
	while (mover ->next!= NULL)
	{
		mover = mover->next;
		cout << "Previous node: " << mover->prev->element << endl;
		cout << "Current node: " << mover->element << endl;
		//cout << "Next node: " << mover->next->element << endl;
		cout << endl; 

	}
	
}

template<class T> 
void Node<T>::add_Node()
{
	T elem;
	cout << "What element should this node hold?" << endl;
	cin >> elem; 
	Node<T>* new_node = new Node<T>;
	new_node->element = elem; 
	new_node->next = NULL;
	if (begin == NULL)
	{
		new_node->prev = NULL;
		begin = new_node;
		
		return;
	}
	/*
	Pointers refer to a location in memory(RAM).When you have a null pointer it is pointing to null, 
	meaning that it isn't pointing to location in memory. As long as a pointer is null it can't be used to store any information, 
	as there is no memory backing it up.
	To use a null pointer you must first allocate memory and then have the pointer point to that newly allocated memory.
	*/
	Node<T>* tracker = begin;
	while (tracker->next != NULL)
	{
		tracker = tracker->next;
	}
	tracker->next = new_node;
	new_node->prev = tracker;
	
}

#endif