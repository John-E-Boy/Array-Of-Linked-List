#include "Header.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()

{
	// declare class object 
	/*
	Array<int> ar;
	Node<int> n;

	ar.intialize_node_array();
	for (int i = 0; i < 3; i++)
	{
		ar.add_node_array(n);
	}
    ar.display_node_array(n);
	*/
	

	
	
	
	int* p;
	int num = 5;
	p = &num;
	

	cout << num << " " << &num << endl; // displays 5 then memory address
	cout << *p << " " << &p << endl; // "derefrencing" *p or ->, display what is at memory address the memory address
	




	return 0;
}