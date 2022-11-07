
// Jonathan Essapour
// General Goal: Make a template class that includes various data types or structures
// such as arrays, linked lists, etc
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
	Node<T>** array_nodes; // array of which each slot is linked lists, also had an error earlier that said required template arguements needed <T>
// https://docs.microsoft.com/en-us/cpp/error-messages/tool-errors/linker-tools-error-lnk2019?view=msvc-170
// Link is for line below as for what parameters to use for overriding a template ostream 
template<class T> friend ostream& operator << (ostream& o, const Array<T>& ar); // THIS LINE 
// line above can also be -> template<typename T> friend ostream& operator << (ostream& o, const Array<T>& ar); 
template<class T> friend ostream& operator << (ostream& o, Node<T>& n1);


friend class Node<T>; // Node class can access private memebers of Array


private:
	T *ar; // make this dynamic in intialization and delete
	int size_ar; // size of the array
	int num_elem; // number of elements in the array
public:

	// regular array functions
	void remove_elem(); // remove an element from the array 
	void insert_element_ar(T elem, int slot); // add element to array, to certian slot of array
	void intialize(); // intialize array
	void intialize_node_array();
	void add_node_array(Node<T>& n1);
	void display_node_array(Node<T>& n1);
	void display(); // display the array
	~Array() { delete []ar; }; // deconstructor
	
};

// Make a node class next
template<class T>
class Node
{
	friend class Array<T>;
	//Array<T>**node_array;
private:

	Node<T>* prev;
	Node<T>* next;
	T element;
	Node<T>* begin; // root node
public:
	Node() { prev = NULL; next = NULL; element = NULL;  };
	Node<T>* add_Node();
	void display_Nodes();
	void remove_Node();
	
};

template<class T>
void Node<T>::remove_Node()
{
	T elem;
	display_Nodes();
	cout << "Which element would you like to remove from the linked list?" << endl;
	cin >> elem;

	Node<T>* finder ;
	finder = begin;

	
	while (finder->element != elem)
	{
		cout << "enter 0";
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
	cout << "First Node: " << begin->element << endl;
	mover = mover->next;
	cout << endl;
	while (mover != NULL)
	{
		cout << "Previous node: " << mover->prev->element << endl;
		cout << "Current node: " << mover->element << endl;
		//cout << "Next node: " << mover->next->element << endl;
		cout << endl; 

		mover = mover->next;
	}
}

template<class T> 
Node<T>* Node<T>::add_Node()
{
	T elem;
	cout << "What element should this node hold?" << endl;
	cin >> elem; 
	Node<T>* new_node = new Node<T>;
	new_node->element = elem; 

	if (begin == NULL)
	{
		new_node->prev = NULL;
		new_node->next = NULL;
		begin = new_node;
		/*
		//begin->prev = NULL; 
		begin->element = new_node->element; // this wasn't working before because it HAS TO POINT TO A MEMORY LOCATION
		begin->next = NULL;
		*/
		return begin;
	}
	/* For line 82
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
	return tracker->next;
}
// This function intializes the array 
template<class T>
void Array <T>::intialize()
{
	cout << "How many elements should the array hold?" << endl;
	cin >> size_ar; // from user input
	num_elem = size_ar;
	ar = new T[size_ar];

	for (int i = 0; i < size_ar; i++)
	{
		T elem; 
		cout << "What element would you like to insert at slot " << i << ": ";
		cin >> elem;
		insert_element_ar(elem,i);
	}
}

template <class T>
void::Array <T>::intialize_node_array()
{
	cout << "How many elements should the array hold?" << endl;
	cin >> size_ar; // from user input
	num_elem = size_ar;
	Node<T>**ar = new Node<T>*[size_ar];
	for (int i = 0; i < size_ar; i++)
	{
		ar[i] = NULL;
	}
	array_nodes = ar;
}

template <class T>
void::Array<T>::add_node_array(Node<T>& n1)
{
	int slot = 0;
	cout << "What slot do you want to insert in?" << endl;
	cin >> slot;
	while (slot < 0 || slot > size_ar)
	{
		cout << "The slot in which you want to insert the element does not exist, enter in another slot: ";
		cin >> slot;
	}
	
	

	/*
	Node<T>* tracker = begin;
	while (tracker->next != NULL)
	{
		tracker = tracker->next;
	}
	tracker->next = new_node;
	new_node->prev = tracker;
	return tracker;
	*/
	//n1.begin = array_nodes[slot];

	/*
	if (array_nodes[slot] == NULL)
	{
		n1.begin = array_nodes[slot];
		array_nodes[slot]= n1.add_Node();
		array_nodes[slot]->next = NULL;
		array_nodes[slot]->prev = NULL;
	}
	*/
	if (array_nodes[slot] == NULL)
	{
		array_nodes[slot] = n1.add_Node();
	}

	else 
	{
		array_nodes[slot]->next = n1.add_Node();	
	}

}
template <class T>
void Array<T>::display_node_array(Node<T>& n1)
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
void Array<T>:: insert_element_ar(T elem, int slot)
{
	while (slot < 0 || slot > size_ar)
	{
		cout << "The slot in which you want to insert the element does not exist, enter in another slot: ";
		cin >> slot;
	}
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
	cout << "The array size is: " << ar.size_ar << endl;
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
	cout << ". Which element would you like to remove (type in the element itself not the slot it's located at): " << endl;
	cin >> elem;

	for (int i = 0; i < num_elem; i++)
	{
		if (ar[i] == elem)
		{
			ar[num_elem] = ar[i]; // take the element that wants to be removed and puts it at the end of the array
			num_elem--; // decreases the number of elements so that element can't be accessed anymore
			for (int j = i; j < num_elem; j++) // j starts at where the element is found and shifts the rest of the elements 
			{
				ar[j] = ar[j + 1];
			}
			cout << "The array is now: ";
			display();
			return;
		}
	}
	
}
#endif