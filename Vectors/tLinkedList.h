// tLinkedList.md
#pragma once

#include <iostream>

template<typename T>
class tForwardList
{
	struct Node
	{
		T data;                     // data for the element stored
		Node * next;                // pointer to node following this node
	};

	Node * head;                    // pointer to head of linked list
	int listSize;

public:
	tForwardList();                 // initializes head to null
	~tForwardList();                // delete all nodes upon destruction

	void push_front(const T& val);  // adds element to front (i.e. head)
	void pop_front();               // removes element from front
	void pop_back();               // removes element from back

	T& front();                     // returns the element at the head
	const T& front() const;         // returns the element at the head (const)

	bool empty() const;             // Returns true if there are no elements
	void clear();                   // Destroys every single node in the linked list
	void resize(size_t newSize);    // Resizes the linked list to contain the given number of elements
									// New elements are default-initialized

	class iterator
	{
		Node * cur;                                 // current node being operated upon

	public:
		iterator();                                 // initializes an empty iterator pointing to null
		iterator(Node * startNode);                 // initializes an iterator pointing to the given node

		bool operator==(const iterator& rhs) const; // returns true if the iterator points to the same node
		bool operator!=(const iterator& rhs) const; // returns false if the iterator does not point to the same node
		T& operator*() const;                       // returns a reference to the element pointed to by the current node
		iterator& operator++();                     // pre-increment (returns a reference to this iterator after it is incremented)
		iterator operator++(int);                   // post-increment (returns an iterator to current node while incrementing the existing iterator)
	};

	iterator begin();
	iterator end();

	tForwardList(const tForwardList& other);            // copy-constructor

	tForwardList& operator=(const tForwardList &rhs);   // copy-assignment

	void remove(const T& val);      // removes all elements equal to the given value
};


template<typename T>
inline typename tForwardList<T>::iterator tForwardList<T>::begin()
{
	return iterator(head);
}

template<typename T>
inline typename tForwardList<T>::iterator tForwardList<T>::end()
{
	return iterator(nullptr);
}

template<typename T>
inline tForwardList<T>::tForwardList()
{
	head = nullptr;
	listSize = 0;
}

template<typename T>
inline tForwardList<T>::~tForwardList()
{
	delete(head);
}

template<typename T>
inline void tForwardList<T>::push_front(const T & val)
{
	Node* newVal = new Node();
	newVal->data = val;
	newVal->next = this->head;
	this->head = newVal;
	listSize++;
}

template<typename T>
inline void tForwardList<T>::pop_front()
{
	if (head != nullptr) 
	{
		Node * N = head;

		head = head->next;

		delete(N);

		listSize--;
	}
}

template<typename T>
inline void tForwardList<T>::pop_back()
{
	if (head->next == nullptr) 
	{
		delete(head);
		head = nullptr;
		listSize--;
	}
	else
	{
		Node* deleter = head;
		for (int i = 0; i < listSize - 2; i++)
		{
			deleter = deleter->next;
		}
		delete(deleter->next);
		deleter->next = nullptr;
		listSize--;
	}
}



template<typename T>
inline T & tForwardList<T>::front()
{
	return head->data;
}

template<typename T>
inline const T & tForwardList<T>::front() const
{
	return head->data;
}

template<typename T>
inline bool tForwardList<T>::empty() const
{
	if (head != nullptr)
	{
		return false;
	}

	return true;
}

template<typename T>
inline void tForwardList<T>::clear()
{
	while (head != nullptr)
	{
		pop_front();
	}
}

template<typename T>
inline void tForwardList<T>::resize(size_t newSize)
{
	while (listSize > newSize) 
	{
		pop_back();
	}
}

template<typename T>
inline tForwardList<T>::tForwardList(const tForwardList & other)
{
	if (other.head != nullptr) 
	{
		push_front(other.head->data);

		Node * otherIterator = other.head;
		Node * iterator = head;

		while (otherIterator->next != nullptr) 
		{
			otherIterator = otherIterator->next;
			if (otherIterator != nullptr)
			{
				iterator->next = new Node();
			}
			iterator = iterator->next;	
			iterator->data = otherIterator->data;	
		}
	}

	listSize = other.listSize;
}

template<typename T>
inline tForwardList<T> & tForwardList<T>::operator=(const tForwardList & rhs)
{
	this = new tForwardList(rhs);

	return this;
}

template<typename T>
inline void tForwardList<T>::remove(const T & val)
{
	if (head != nullptr) 
	{
		Node * iterator = head;
		if (head->data == val)
		{
			Node * N = head;

			head = head->next;

			delete(N);

			listSize--;
		}
		Node * deleted = iterator->next;
		while (iterator->next != nullptr && head != nullptr)
		{
			deleted = iterator->next;
			if (iterator->next != nullptr && iterator->next->data == val )
			{
				iterator->next = deleted->next;
				delete(deleted);
				std::cout << "Help" << std::endl;
				listSize--;
			}
			iterator = iterator->next;
			if (iterator == nullptr) 
			{
				break;
			}
			std::cout << "Help" << std::endl;
		}
	}
}

template<typename T>
inline tForwardList<T>::iterator::iterator()
{
	cur = nullptr;
}

template<typename T>
inline tForwardList<T>::iterator::iterator(Node * startNode)
{
	cur = startNode;
}

template<typename T>
inline bool tForwardList<T>::iterator::operator==(const iterator & rhs) const
{
	if (rhs.cur == cur) 
	{
		return true;
	}
	return false;
}

template<typename T>
inline bool tForwardList<T>::iterator::operator!=(const iterator & rhs) const
{
	if (rhs.cur == cur)
	{
		return false;
	}

	return true;
}

template<typename T>
inline T & tForwardList<T>::iterator::operator*() const
{
	return cur->data;
}

template<typename T>
inline typename  tForwardList<T>::iterator & tForwardList<T>::iterator::operator++()
{
	if (cur->next != nullptr) 
	{
		cur = cur->next;
		return *cur;
	}
	return *cur;
}

template<typename T>
inline typename tForwardList<T>::iterator tForwardList<T>::iterator::operator++(int)
{
	if (cur->next != nullptr)
	{
		return cur;
		cur = cur->next;
	}
	return cur;
}
