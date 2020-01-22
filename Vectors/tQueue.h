// tQueue.h
#pragma once

#include "tVector.h"

template <typename T>
class tQueue
{
	tVector<T> vec;                       // contains the data for a queue

public:
	tQueue();                             // default initializes the queue
	tQueue(size_t count, const T& value); // constructs a queue with the given number of elements 
										  // each element is initialized by copying the given value

	void push(const T& value);            // adds an element to the top of the Queue
	void pop();                           // drops the top-most element of the Queue

	T& front();                           // returns the front-most element
	const T& front() const;

	size_t size() const;                  // returns current number of elements

	bool empty() const;
};

template<typename T>
inline tQueue<T>::tQueue()
{
	vec = new tVector();
}

template<typename T>
inline tQueue<T>::tQueue(size_t count, const T & value)
{
	tVector<T> standIn = new tVector();
	standIn.reserve(count);
	standIn.push_back(value);
	vec = new tVector();
}

template<typename T>
inline void tQueue<T>::push(const T & value)
{
	vec.push_back(value);
}

template<typename T>
inline void tQueue<T>::pop()
{
	vec.pop_front();
}

template<typename T>
inline T & tQueue<T>::front()
{
	return vec.arr[0];
}

template<typename T>
inline const T & tQueue<T>::front() const
{
	return vec.size();
}

template<typename T>
inline size_t tQueue<T>::size() const
{
	return vec.arrSize;
}

template<typename T>
inline bool tQueue<T>::empty() const
{
	if (vec.arrSize == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
