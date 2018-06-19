class LinkedList;

class Node{
private:
	int m_data;
	Node * mp_next;
public:
	Node(): m_data(0), mp_next(0){};
	Node(int a): m_data(a), mp_next(0){};

	friend class LinkedList;
};

class LinkedList{
private:
	int m_size;
	Node * mp_head;
	static int new_total;
	static int free_total;
public:
	LinkedList(): mp_head(0){};
	void printList(); //print out linked list
	void pushFront(int x); //adding node from the front 
	void pushBack(int x);  //addiing node from the bact
	void deleteNode(int x); //deleting a node with data x
	void clear();  //destroy the list and free the memory
	void Reverse();

};

