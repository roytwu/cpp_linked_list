//This linked list structure has head node and tail node
//File name: linkedList_B.cpp
//author: Roy T Wu, roywu2018@gmail.com

// #define NDEBUG  //work with assert()
#include <assert.h>
#include <iostream>
#include "linkedList.h"
using std::cout;
using std::endl;

int LinkedList_B::new_total = 0;
int LinkedList_B::free_total = 0;


/*-----private functions-----*/
void LinkedList_B::debug_memAlloc(){
	assert(new_total += 1);
	assert( printf("memory allocated... (%d)\n", new_total) );
	return;
}

void LinkedList_B::debug_memFree(){
	assert(free_total += 1);
	assert( printf("memory freed... (%d)\n", free_total) );
	return;
}

void LinkedList_B::push(int x, bool front){
	Node * p_newNode = new Node(x);
	debug_memAlloc();

	if(mp_head == 0){
		//if the list is empty, set up head node and tail mode
		mp_head = p_newNode;
		mp_tail = p_newNode; 
	} else if(front == true){
		// add a node in front of the head node
		(p_newNode->mp_next) = mp_head;  
		mp_head = p_newNode;
	} else{
		// add a node after the tail node
		(p_newNode->mp_next) = 0;  //point new node to NULL 
		mp_tail->mp_next =p_newNode; //link tail node and the new node
		mp_tail = p_newNode;  //let new node become tail node	
	}
	m_size++;
}

/*-----public functions-----*/
//constructor
//LinkedList::LinkedList(){}


void LinkedList_B::printList(){ //same as LinkedList_A
	cout << endl;
	if(mp_head == 0){
		cout << "List is empty.\n";
	}
	//curNode: current node
	Node *p_curNode = mp_head;  
	while( p_curNode !=0)
	{
		cout << (p_curNode->m_data) << " ";
		p_curNode = (p_curNode->mp_next); //traverse to next node
	}
	cout << endl << endl;
}


void LinkedList_B::pushFront(int x){ 
	push(x, true);
}


void LinkedList_B::pushBack(int x){ 
	push(x, false);
}


void LinkedList_B::deleteNode(int x){	
	if (mp_head == 0){ return; }

	Node * p_curNode = mp_head;
	Node * p_nxtNode;

	//if the head itself hold the data to be deleted
	if(p_curNode->m_data == x){
		assert(cout << "case1: delete head node" << endl);

		mp_head = p_curNode->mp_next; //change head node

		//if the new head is NULL, reset the taill as well
		if (mp_head == 0){
			mp_tail = 0;
		} 
		
		delete p_curNode;
		debug_memFree();

		//setting unused pointer to NULL, defensive style
		p_curNode =0;
		m_size--;
		return;
	}

	//traverse to search for the data to be deleted	
	p_nxtNode = p_curNode->mp_next;	
	while(p_nxtNode !=0) 	
	{	
		p_nxtNode = p_curNode->mp_next;	
		assert(cout << "case2 accessed" << endl);

		//if the data has been found in nxt mode
		if(p_nxtNode->m_data == x){
			assert(cout << "case2: delete a middle/tail node" << endl);

			(p_curNode->mp_next) = (p_nxtNode->mp_next); //re-link

			//if the to-be-delete node is tail node, redirect tail node
			if(mp_tail == p_nxtNode){
				mp_tail = p_curNode; 
			}

			delete p_nxtNode;
			debug_memFree();

			//setting unused pointer to NULL, defensive style
			p_nxtNode = 0;
			m_size--;
			return;
		}

		p_curNode = p_curNode->mp_next; //moving on to check the next node

		//already traverse to tail and find nothing 
		if(p_curNode == mp_tail) { 
			assert( cout << "Can't find matched node, return" << endl );
			return; 
		}
	} //while

}


void LinkedList_B::clear(){
	while(mp_head != 0)
	{
		//let curNode traverse, starting from head node 
		Node * p_curNode = mp_head;
		
		//reset head mode
		mp_head = (mp_head->mp_next);

		delete p_curNode; //free memory
		debug_memFree();

		//setting unused pointer to NULL, defensive style
		p_curNode = 0; 
	} //while	

	//after cleaning all the node, reset size to 0
	m_size = 0;
}


void LinkedList_B::reverse(){
	//if list is empty or list has only 1 node
	if (mp_head==0 || mp_head->mp_next==0){return;}

	//delcare 3 nodes in order to traverse
	Node * p_prevNode = 0;                //previous node
	Node * p_curNode = mp_head;           //current node
	Node * p_nxtNode = mp_head->mp_next;  //next node

	mp_tail = mp_head; //the new tail node is the old head node

	while( p_nxtNode != 0  )
	{
		(p_curNode->mp_next) = p_prevNode; //reverse the link

		p_prevNode = p_curNode;  //move nodes
		p_curNode = p_nxtNode;   //move nodes
		p_nxtNode = p_nxtNode->mp_next; //move nodes
	}

	p_curNode->mp_next = p_prevNode; //reverse the last node
	mp_head = p_curNode; //the last node became the head node

}

int LinkedList_B::getListSize(){
	return(m_size);	
}