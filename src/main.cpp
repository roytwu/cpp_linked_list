//File name: main.cpp
//author: Roy T Wu, roywu2018@gmail.com

#include <iostream>
#include "linkedList.h"
using std::cout;
using std::endl;


int main(){
	
	LinkedList_B o_list;

	o_list.pushFront(3);
	o_list.pushFront(1);
	o_list.pushFront(2);
	o_list.pushBack('a');
	o_list.pushBack(3);
	o_list.printList(); 

	o_list.deleteNode(3);
	o_list.printList();


	o_list.reverse();
	o_list.pushFront(77);
	o_list.pushBack(0);
	o_list.printList();

	//member function of LinkedList_B only
	cout << "Data in head node:" << o_list.getFirst() << endl; 
	cout << "Data in tail node:" << o_list.getLast() << endl;


	int size = o_list.getListSize();
	printf("\nThere're %d nodes in the list.\n", size);

	cout << endl << "-----Clear list-----" << endl; 
	o_list.clear();
	
	return 0;
}