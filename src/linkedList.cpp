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
	ListNode *p_curNode = mp_head;  
	while(p_curNode !=0){
		cout << (p_curNode->m_data) << " ";
		p_curNode = (p_curNode->mp_next); //traseverse to next node
	}
	cout << endl;
}

void LinkedList::pushFront(int x){
	ListNode * p_newNode = new ListNode(x); //allocate new memory
	new_total += 1;
	cout << "memory allocated: " << "(" << new_total << ")" << endl;
	(p_newNode->mp_next) = mp_head;  
	mp_head = p_newNode;
}

void LinkedList::pushBack(int x){
	ListNode * p_newNode = new ListNode(x);
	new_total += 1;
	cout << "memory allocated: " << "(" << new_total << ")" << endl;

	//if the list is empty, the newNode will be head node
	if (mp_head == 0){
		mp_head = p_newNode;
		return;
	}

	ListNode * p_curNode = mp_head;
	while(p_curNode->mp_next != 0 ){
		p_curNode = (p_curNode->mp_next);	
	}
	p_curNode->mp_next = p_newNode;
}

void LinkedList::deleteNode(int x){

}

void LinkedList::clear(){
	while(mp_head != 0){
		ListNode * p_curNode = mp_head;
		mp_head = (mp_head->mp_next);
		delete p_curNode; //free memory
		free_total +=1;
		cout << "memory freed: " << "(" << free_total << ")" << endl;
		p_curNode = 0;
		
	}
}