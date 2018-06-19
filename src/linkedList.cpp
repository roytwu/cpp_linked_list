//#define NDEBUG  //work with assert()
#include <assert.h>
#include <iostream>
#include "linkedList.h"
using std::cout;
using std::endl;

// //constructor
// LinkedList::LinkedList(){}

int LinkedList::new_total = 0;
int LinkedList::free_total = 0;


void LinkedList::printList(){
	if(mp_head == 0){
		cout << "List is empty.\n";
	}
	//curNode: current node
	Node *p_curNode = mp_head;  
	while(p_curNode !=0){
		cout << (p_curNode->m_data) << " ";
		p_curNode = (p_curNode->mp_next); //traseverse to next node
	}
	cout << endl;
}

void LinkedList::pushFront(int x){
	Node * p_newNode = new Node(x); //allocate new memory
	assert(new_total += 1);
	assert(cout << "memory allocated: " << "(" << new_total << ")" << endl);
	(p_newNode->mp_next) = mp_head;  
	mp_head = p_newNode;
}

void LinkedList::pushBack(int x){
	Node * p_newNode = new Node(x);
	assert(new_total += 1);
	assert(cout << "memory allocated: " << "(" << new_total << ")" << endl);

	//if the list is empty, the newNode will be head node
	if (mp_head == 0){
		mp_head = p_newNode;
		return;
	}

	Node * p_curNode = mp_head;
	while(p_curNode->mp_next != 0 ){
		p_curNode = (p_curNode->mp_next);	
	}
	p_curNode->mp_next = p_newNode;
}

void LinkedList::deleteNode(int x){	
	if (mp_head == 0){ return; }

	Node * p_curNode = mp_head;

	//if the head itself hod the data to be deleted
	//search for the data to be deleted
	
}

void LinkedList::clear(){
	while(mp_head != 0){
		Node * p_curNode = mp_head;
		mp_head = (mp_head->mp_next);

		delete p_curNode; //free memory
		assert(free_total +=1);
		assert(cout << "memory freed: " << "(" << free_total << ")" << endl);
		
		p_curNode = 0;
	}
}