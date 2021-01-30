#pragma once


//at this point pointers are still a bit confusing for me so i may be doing this all wrong

template <typename T>
class tDoubleLinkList 
{
	struct Node
	{
		T data;// data for the element stored
		Node *next = nullptr;// pointer to node following this node
		Node *prev = nullptr;
	};

	Node *head;// pointer to head of linked list
	Node *tail;

	
	class iterator 
	{
		Node *cur;// current node being operated upon
	public:
		iterator()// initializes an empty iterator pointing to null
		{
			cur = nullptr;
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
			return !(*this == rhs);
		}
		T &operator*() const// returns a reference to the element pointed to by the current node
		{
			return cur->data;
		}
		iterator &operator++() // pre-increment (returns a reference to this iterator after it is incremented)
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
		iterator &operator--() // pre-increment (returns a reference to this iterator after it is incremented)
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
		return nullptr;
	}
	iterator rbegin()
	{
		return iterator(tail);
	}
	iterator rend()
	{
		return nullptr;
	}
	tDoubleLinkList(); // initializes head to null
	tDoubleLinkList(const tDoubleLinkList &other);// copy-constructor
	tDoubleLinkList &operator=(const tDoubleLinkList &rhs);// copy-assignment
	~tDoubleLinkList(); // delete all nodes upon destruction

	void push_front(const T &val);// adds element to front (i.e. head)
	void pop_front();// removes element from front
	void push_back(const T &val);// adds element to front (i.e. head)
	void pop_back();// removes element from front

	T &front();// returns the element at the head
	const T &front() const;// returns the element at the head (const)
	T &back();// returns the element at the tail
	const T &back() const;// returns the element at the tail (const)

	void remove(const T &val); // removes all elements equal to the given value
	bool empty() const;// Returns true if there are no elements
	void clear();// Destroys every single node in the linked list
	void resize(size_t newSize);// Resizes the linked list to contain the given number of elements. New elements are default-initialized
	
	
	
};

template <typename T>
tDoubleLinkList<T>::tDoubleLinkList()
{
	head = nullptr;
	tail = nullptr;
}

template <typename T>
tDoubleLinkList<T>::tDoubleLinkList(const tDoubleLinkList &other)
{
	Node *cur = other.head;
	while (cur != nullptr)
	{
		push_back(cur->data);
		cur = cur->next;
	}
}

template <typename T>
tDoubleLinkList<T> &tDoubleLinkList<T>::operator=(const tDoubleLinkList &rhs)
{
	clear();
	Node *cur = rhs.head;
	while (cur != nullptr)
	{
		push_back(cur->data);
		cur = cur->next;
	}
	return *this;
}

template <typename T>
tDoubleLinkList<T>::~tDoubleLinkList() 
{
	clear();
}

template <typename T>
void tDoubleLinkList<T>::push_front(const T &val) 
{
	Node *newNode = new Node();
	newNode->data = val;
	if (head == nullptr && tail == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else 
	{
		Node *temp = head;
		head = newNode;
		head->next = temp;
		temp->prev = newNode;
	}
}

template <typename T>
void tDoubleLinkList<T>::push_back(const T &val)
{
	Node *newNode = new Node();
	newNode->data = val;
	if (head == nullptr && tail == nullptr)
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		Node *end = tail;
		end->next = newNode;
		newNode->prev = end;
		tail = newNode;
	}
}

template <typename T>
void tDoubleLinkList<T>::pop_front()
{
	Node *cur = head;
	if (head == tail)
	{
		head = nullptr;
		tail = nullptr;
	}
	else 
	{
		head = head->next;
		head->prev = nullptr;
	}
	delete cur;
}

template <typename T>
void tDoubleLinkList<T>::pop_back()
{
	Node *cur = tail;
	if (head == tail)
	{
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		tail = tail->prev;
		tail->next = nullptr;
	}
	delete cur;
}

template <typename T>
bool tDoubleLinkList<T>::empty() const
{
	return head == nullptr;
}



template <typename T>
void tDoubleLinkList<T>::clear() 
{
	while (!empty()) 
	{
		pop_front();
	}
}

template <typename T>
T &tDoubleLinkList<T>::front()
{
	return head->data;
}

template <typename T>
const T &tDoubleLinkList<T>::front() const
{
	return front();
}

template <typename T>
T &tDoubleLinkList<T>::back()
{
	return tail->data;
}

template <typename T>
const T &tDoubleLinkList<T>::back() const
{
	return back();
}


template <typename T>
void tDoubleLinkList<T>::resize(size_t newSize)
{
	//resize to 0
	if (newSize == 0)
	{
		if (!empty()) {
			clear();
		}
		return;
	}
	size_t i = 0;
	if (!empty())
	{
		i++;
		Node *nodeAtI = head;
		while (nodeAtI->next != nullptr && i < newSize)
		{
			nodeAtI = nodeAtI->next;
			i++;
		}
		if (i == newSize) 
		{
			Node *next = nodeAtI->next;
			nodeAtI->next = nullptr;
			tail = nodeAtI;
			while (next != nullptr)
			{
				Node *cur = next;
				next = next->next;
				delete cur;
			}
			
		}
	}
	//create nodes if there are not a newSize amount
	while (i < newSize) 
	{
		//cur->next
		i++;
		push_back(T());
	}
}

template <typename T>
void tDoubleLinkList<T>::remove(const T &val)
{
	Node *cur = head;
	while (cur != nullptr)
	{
		if (cur->data == val)
		{
			if (cur->prev == nullptr)
			{
				head = cur->next;
			}
			else
			{
				cur->prev->next = cur->next;
			}

			if (cur->next == nullptr)
			{
				tail = cur->prev;
			}
			else
			{
				cur->next->prev = cur->prev;
			}
			Node *deleteMe = cur;
			cur = cur->next;
			delete deleteMe;
		}
		else 
		{
			cur = cur->next;
		}
	}
}
