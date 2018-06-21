//File name: linkedList.h
//author: Roy T Wu, roywu2018@gmail.com


class LinkedList_A;
class LinkedList_B;

// ----- ----- ----- ----- -----
class Node{
private:
	int m_data;
	Node * mp_next;
public:
	Node(): m_data(0), mp_next(0){};
	Node(int a): m_data(a), mp_next(0){};

	friend class LinkedList_A;
	friend class LinkedList_B;
};
// ----- ----- ----- ----- -----


// ----- ----- ----- ----- -----
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
	LinkedList_A(): m_size(0), mp_head(0){};
	void printList(); //print out linked list
	void pushFront(int x); //adding node from the front 
	void pushBack(int x);  //addiing node from the back
	void deleteNode(int x); //deleting a node with data x
	void clear();  //destroy the list and free the memory
	void reverse();

	int getListSize();
};
// ----- ----- ----- ----- -----


// ----- ----- ----- ----- -----
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
	LinkedList_B(): m_size(0), mp_head(0), mp_tail(0){};
	void printList(); //print out linked list
	void pushFront(int x); //adding node from the front
	void pushBack(int x);  //addiing node from the back
	void deleteNode(int x); //deleting a node with data x
	void clear();  //destroy the list and free the memory
	void reverse();

	int getListSize();
};
// ----- ----- ----- ----- -----