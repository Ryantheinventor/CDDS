#pragma once


//at this point pointers are still a bit confusing for me so i may be doing this all wrong

template <typename T>
class tForwardList 
{
	struct Node
	{
		T data;// data for the element stored
		Node *next = NULL;// pointer to node following this node
		Node *prev = NULL;
	};

	Node *head;// pointer to head of linked list
	Node *tail;


	class iterator 
	{
		Node *cur;// current node being operated upon
	public:
		iterator()// initializes an empty iterator pointing to null
		{
			cur = NULL;
		}
		iterator(Node *startNode)// initializes an iterator pointing to the given node
		{
			cur = startNode;
		}
		bool operator==(const iterator &rhs) const// returns true if the iterator points to the same node
		{
			return cur == rhs.cur;
		}
		bool operator!=(const iterator &rhs) const// returns false if the iterator does not point to the same node
		{
			return !operator==(rhs);//No clue if this works
		}
		T &operator*() const// returns a reference to the element pointed to by the current node
		{
			return cur->data;
		}
		iterator operator++() // pre-increment (returns a reference to this iterator after it is incremented)
		{
			cur = cur->next;
			return *this;
		}
		iterator operator++(int)// post-increment (returns an iterator to current while incrementing the existing it)
		{
			iterator newIt = iterator(cur);
			cur = cur->next;
			return newIt;
		}
		iterator operator--() // pre-increment (returns a reference to this iterator after it is incremented)
		{
			cur = cur->prev;
			return *this;
		}
		iterator operator--(int)// post-increment (returns an iterator to current while incrementing the existing it)
		{
			iterator newIt = iterator(cur);
			cur = cur->prev;
			return newIt;
		}
	};
	

public:
	iterator begin()
	{
		return iterator(head);
	}
	iterator end()
	{
		return iterator(tail);
	}
	tForwardList(); // initializes head to null
	tForwardList(const tForwardList &other);// copy-constructor
	tForwardList &operator=(const tForwardList &rhs);// copy-assignment
	~tForwardList(); // delete all nodes upon destruction

	void push_front(const T &val);// adds element to front (i.e. head)
	void pop_front();// removes element from front

	T &front();// returns the element at the head
	const T &front() const;// returns the element at the head (const)
	T &back();// returns the element at the head
	const T &back() const;// returns the element at the head (const)

	void remove(const T &val); // removes all elements equal to the given value
	bool empty() const;// Returns true if there are no elements
	void clear();// Destroys every single node in the linked list
	void resize(size_t newSize);// Resizes the linked list to contain the given number of elements. New elements are default-initialized
private:
	void clearAfter(Node *startNode);
	
	
	
};

template <typename T>
tForwardList<T>::tForwardList() 
{
	head = NULL;
}

template <typename T>
tForwardList<T>::~tForwardList() 
{
	clear();
}

template <typename T>
void tForwardList<T>::push_front(const T &val) 
{
	Node *newNode = new Node();
	newNode->data = val;
	if (head != NULL)
	{
		newNode->next = head;
	}
	else 
	{
		newNode->next = NULL;
	}
	head = newNode;
}

template <typename T>
void tForwardList<T>::pop_front()
{
	Node *cur = head;
	head = head->next;
	delete cur;
}

template <typename T>
bool tForwardList<T>::empty() const
{
	return head == NULL;
}



template <typename T>
void tForwardList<T>::clear() 
{
	while (!empty()) 
	{
		pop_front();
	}
}

template <typename T>
T &tForwardList<T>::front()
{
	return head->data;
}

template <typename T>
const T &tForwardList<T>::front() const
{
	return front();
}

template <typename T>
T &tForwardList<T>::back()
{
	return tail->data;
}

template <typename T>
const T &tForwardList<T>::back() const
{
	return back();
}

template <typename T>
void tForwardList<T>::resize(size_t newSize)
{
	//resize to 0
	if (newSize == 0)
	{
		if (!empty()) {
			clear();
		}
		return;
	}
	if (head != NULL)
	{
		size_t i = 1;
		Node *cur = head;
		Node *next = head->next;
		while (next != NULL)
		{


			if (i == newSize)
			{
				//destroy all remaining Nodes
				Node *dest = next;
				next = next->next;
				delete dest;
				continue;
			}
			next = next->next;
			i++;
		}
		cur->next = NULL;
	}
	//create nodes if there are not a newSize amount
	while (i < newSize) 
	{
		//cur->next
	}
}

//something is wrong here
template <typename T>
void tForwardList<T>::clearAfter(Node *startNode)
{
	Node *nextNode = startNode->next;
	while (nextNode != NULL)
	{
		Node *cur = nextNode;
		nextNode = nextNode->next;
		delete *cur;
	}
	startNode->next = NULL;
}

