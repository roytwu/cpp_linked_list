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
	assert( printf("memory allocated... (%d)\n", new_total) );
	(p_newNode->mp_next) = mp_head;  
	mp_head = p_newNode;
}

void LinkedList::pushBack(int x){
	Node * p_newNode = new Node(x);
	assert(new_total += 1);
	assert( printf("memory allocated... (%d)\n", new_total) );

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
	Node * p_nxtNode;

	//if the head itself hold the data to be deleted
	if(p_curNode->m_data == x){
		cout << "case1: delete head node" << endl;
		mp_head = p_curNode->mp_next; //change head node
		delete p_curNode;
		assert(free_total +=1);
		assert( printf("memory freed... (%d)\n", free_total) );
		p_curNode =0;
		return;
	}

	p_nxtNode = p_curNode->mp_next;	
	//search for the data to be deleted
	while(p_nxtNode !=0)
	{
		p_nxtNode = p_curNode->mp_next;	
		cout << "case2 accessed" << endl;
		cout << p_nxtNode->m_data << endl;
		//if the data has been found in nxt mode
		if (p_nxtNode->m_data == x){
			cout << "case2: delete node with assigned data" << endl;
			(p_curNode->mp_next) = (p_nxtNode->mp_next);
			delete p_nxtNode;
			assert(free_total +=1);
			assert( printf("memory freed... (%d)\n", free_total) );
			p_nxtNode = 0;
		}

		p_curNode = p_nxtNode; //moving one to check the next node
	}

}

void LinkedList::clear(){
	while(mp_head != 0){
		Node * p_curNode = mp_head;
		mp_head = (mp_head->mp_next);

		delete p_curNode; //free memory
		assert(free_total +=1);
		assert( printf("memory freed... (%d)\n", free_total) );
		p_curNode = 0;
	}
}