class LinkedList;

class ListNode{
private:
	int m_data;
	ListNode * mp_next;
public:
	ListNode(): m_data(0), mp_next(0){};
	ListNode(int a): m_data(a), mp_next(0){};

	friend class LinkedList;
};

class LinkedList{
private:
	int m_size;
	ListNode *mp_head;
	static int new_total;
	static int free_total;
public:
	LinkedList(): mp_head(0){};
	void printList();
	void pushFront(int x);
	void pushBack(int x);
	void deleteNode(int x);
	void clear();
	void Reverse();

};

