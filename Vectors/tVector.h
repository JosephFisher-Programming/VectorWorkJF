//  tVector.h
#pragma once

template <typename T>
class tVector
{
	const static size_t GROWTH_FACTOR = 2;

	T *arr;                             // pointer to underlying array
	size_t arrSize;                     // stores the number of elements currently used
	size_t arrCapacity;                 // stores the capacity of the underlying array

public:
	tVector();                          // initializes the vector's default values

	tVector(const tVector &cpy);              // copy constructs a vector from another vector

	tVector& operator=(const tVector &cpy);   // copies the contents of the provided vector into this vector

	~tVector();                         // destroys the underlying array

	T *data();                          // returns a pointer to the underlying array

	void reserve(size_t newCapacity);   // reallocates the underlying array to at least the given capacity

	void push_back(const T &value);     // adds an element to the end of the vector
	void pop_back();                    // destroys and removes the last element of the vector

	//void push_front(const T &value);	// adds an element to the start of the vector
	void pop_front();					// destroys and removes the first element of the vector

	void bubbleSort();

	T &at(size_t index);                // returns the element at the given index
	T& operator[] (size_t index);       // returns the object at the given index

	size_t size() const;                // returns current number of elements
	size_t capacity() const;            // returns maximum number of elements we can store
};

template<typename T>
inline tVector<T>::tVector()
{
	arrSize = 0;
	arrCapacity = 5;
	arr = new T[arrCapacity];
}

template<typename T>
inline tVector<T>::tVector(const tVector &cpy)
{
	arrSize = cpy.arrSize;
	arrCapacity = cpy.arrCapacity;
	arr = new T[arrCapacity];

	for (int i = 0; i < arrSize; i++) 
	{
		arr[i] = cpy.arr[i];
	}
}

template<typename T>
inline tVector<T>& tVector<T>::operator=(const tVector &cpy)
{
	this = new tVector(cpy);

	return this;
}

template<typename T>
inline tVector<T>::~tVector()
{
}

template<typename T>
inline T * tVector<T>::data()
{
	return *arr;
}

template<typename T>
inline void tVector<T>::reserve(size_t newCapacity)
{
	if (arrCapacity < newCapacity) 
	{
		T * saveVal = new T[newCapacity];

		for (int i = 0; i < arrSize; i++) 
		{
			saveVal[i] = arr[i];
		}

		arr = new T[newCapacity];
		for (int i = 0; i < arrSize; i++)
		{
			arr[i] = saveVal[i];
		}
		delete(saveVal);
	}
}

template<typename T>
inline void tVector<T>::push_back(const T & value)
{
	reserve(arrSize + 1);
	arr[arrSize] = value;
	arrSize++;
}

template<typename T>
inline void tVector<T>::pop_back()
{
	arrSize--;
}

/*template<typename T>
inline void tVector<T>::push_front(const T & value)
{
	arrSize++;
	reserve(arrSize);
	for (int i = arrSize; i > 0; i++) 
	{
		arr[i] = arr[i - 1];
	}
	arr[0] = value;
}*/

template<typename T>
inline void tVector<T>::pop_front()
{
	arrSize--;
	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = arr[i+1];
	}
}

template<typename T>
inline void tVector<T>::bubbleSort()
{
	int loopLen = arrSize - 1;
	bool isSorted = false;
	while (!isSorted)
	{
		isSorted = true;
		for (int i = 0; i < loopLen; i++)
		{
			if (arr[i] < arr[i + 1])
			{
				std::swap(arr[i], arr[i + 1]);
				isSorted = false;
			}
		}
	}
}

template<typename T>
inline T & tVector<T>::at(size_t index)
{
	return arr[index];
}

template<typename T>
inline T & tVector<T>::operator[](size_t index)
{
	return arr[index];
}

template<typename T>
inline size_t tVector<T>::size() const
{
	return arrSize;
}

template<typename T>
inline size_t tVector<T>::capacity() const
{
	return arrCapacity;
}