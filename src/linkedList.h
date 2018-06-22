//File name: linkedList.h
//author: Roy T Wu, roywu2018@gmail.com


class LinkedList_A;
class LinkedList_B;

//------ ----- ----- ----- -----
class Node{
private:
	int m_data;
	Node * mp_next;
public:
	/*initialize pointer to NULL, defensive style*/
	Node(): m_data(0), mp_next(0){};
	Node(int a): m_data(a), mp_next(0){};

	friend class LinkedList_A;
	friend class LinkedList_B;
};//---- ----- ----- ----- -----


//------ ----- ----- ----- -----
//Singly linked list with head node only
class LinkedList_A{ 
private:
	int m_size;
	Node * mp_head;

	static int new_total;
	static int free_total;
	void debug_memAlloc();
	void debug_memFree();

public:
	/*initialize pointer to NULL, defensive style*/
	LinkedList_A(): m_size(0), mp_head(0){};
	void printList(); //print out linked list
	void pushFront(int x); //adding node from the front 
	void pushBack(int x);  //addiing node from the back
	void deleteNode(int x); //deleting a node with data x
	void clear();  //destroy the list and free the memory
	void reverse(); //reverse the list

	bool isEmpty(); //tell if the list is empty or not
	int getListSize(); //get the number of members in the list
	int getAt(int pos); //get data from 'pos'-th node
	
};//---- ----- ----- ----- -----


//------ ----- ----- ----- -----
//Singly linked list with head node and tail node
class LinkedList_B{ 
private:
	int m_size;
	Node * mp_head;
	Node * mp_tail;

	static int new_total;
	static int free_total;
	void debug_memAlloc();
	void debug_memFree();
	void push(int x, bool front);

public:
	/*initialize pointer to NULL, defensive style*/
	LinkedList_B(): m_size(0), mp_head(0), mp_tail(0){};
	void printList(); //print out linked list
	void pushFront(int x); //adding node from the front
	void pushBack(int x);  //addiing node from the back
	void deleteNode(int x); //deleting a node with data x
	void clear();  //destroy the list and free the memory
	void reverse(); //reverse the list

	/*the following function are useful in message queue*/
	bool isEmpty(); //tell if the list is empty or not
	int getListSize(); //get the number of members in the list
	int getFirst(); //get data from the head node
	int getLast();  //get data from the tail node
	int getAt(int pos); //get data from 'pos'-th node
	

};//---- ----- ----- ----- -----
