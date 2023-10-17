// Jonathan Essapour
// General goal: build arrays, linked lists, and mesh them together.
#include "Node.h"
#include "Array.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()

{
	Node<int> n;
	Array<int> a;
	a.intialize_node_array();
	int elements = 0;
	cout << "How many elements would you like to insert into the array of linked lists?" << endl;
	cin >> elements;
	for (int i = 0; i < elements; i++)
	{
		a.add_node_array();
	}
	a.display_node_array();

	cout << endl;
	int list_length = 0;
	cout << "How long would you like your linked list to be?" << endl;
	cin >> list_length;

	for (int i = 0; i < list_length; i++)
	{
		n.add_Node();
	}
	n.remove_Node();


	return 0;
}