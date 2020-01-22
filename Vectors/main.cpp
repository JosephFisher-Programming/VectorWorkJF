//  main.cpp

#include "tVector.h"
#include "tLinkedList.h"
#include <iostream>

int main() 
{
	tVector<int> original;
	original.push_back(4);
	original.push_back(5);
	original.push_back(6);
	original.push_back(4);
	original.push_back(5);
	original.push_back(6);
	original.push_back(1);
	original.push_back(3);
	original.push_back(9);

	tForwardList<int> list;
	list.push_front(3);
	list.push_front(6);
	list.push_front(7);
	list.push_front(6);
	list.remove(3);

	tForwardList<int> listCpy = list;
	listCpy.resize(0);
	listCpy.push_front(3);
	list.clear();

 	tVector<int> copy = original;
	copy.pop_back(); // removes from the copy array, but not the original
	copy.pop_back();
	copy.pop_back();

//	std::cout << original.size() << std::endl; // 3
	//std::cout << copy.size() << std::endl;     // 0
	//std::cout << original.at(1) << std::endl;

	original.bubbleSort();

	for (int i = 0; i < 9; i++) 
	{
		std::cout << std::endl << original[i] << std::endl;
	}

	while (true) {}
	return 0;
}