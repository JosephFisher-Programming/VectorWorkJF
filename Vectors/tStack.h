// tStack.h
#pragma once

#include "tVector.h"

template <typename T>
class tStack
{
	tVector<T> vec;                     // contains the data for a stack

public:
	tStack();                           // initializes the stack's default values

	void push(const T& value);          // adds an element to the top of the Stack
	void pop();                         // drops the top-most element of the Stack

	T& top();                           // returns the top-most element at the given element

	size_t size() const;                // returns current number of elements
	const T& top() const;				// returns the top-most element at the given element (const-qualified)
	bool empty() const;					// returns true if empty, otherwise false
};

template<typename T>
inline tStack<T>::tStack()
{
	vec = new tVector();
}

template<typename T>
inline void tStack<T>::push(const T & value)
{
	vec.push_back(value);
}

template<typename T>
inline void tStack<T>::pop()
{
	vec.pop_back();
}

template<typename T>
inline T & tStack<T>::top()
{
	return vec.at(vec.arrSize);
}

template<typename T>
inline size_t tStack<T>::size() const
{
	return vec.arrSize();
}

template<typename T>
inline const T & tStack<T>::top() const
{
	return vec.at(vec.arrSize);
}

template<typename T>
inline bool tStack<T>::empty() const
{
	if(vec.arrSize == 0)
	{
		return true;
	}
	else 
	{
		return false;
	}
}
