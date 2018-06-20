#include <iostream>
#include "linkedList.h"
using std::cout;
using std::endl;


int main(){
	
	LinkedList o_list;

	o_list.pushFront(1);
	o_list.pushFront(2);
	o_list.pushBack(3);
	o_list.pushBack(4);
	o_list.printList();

	o_list.deleteNode(2);



	cout << endl << "-----Clear list-----" << endl; 
	o_list.clear();
	return 0;
}