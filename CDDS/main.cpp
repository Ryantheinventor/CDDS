#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "tDoubleLinkList.h"

int main() 
{

	tDoubleLinkList<int> dList;
	if (dList.empty())
	{
		std::cout << "empty\n";
	}
	dList.push_front(5);
	dList.push_front(5);
	dList.push_front(5);
	dList.clear();
	if (dList.empty())
	{
		std::cout << "empty\n";
	}

	dList.push_front(1);
	dList.push_front(2);
	dList.push_front(3);
	dList.push_front(4);
	dList.push_front(5);
	dList.push_front(6);
	dList.push_front(7);
	dList.push_front(8);
	dList.push_front(9);
	dList.push_front(10);
	for (auto it = dList.begin(); it != dList.end(); ++it)
	{
		std::cout << (*it) << std::endl;
	}
	std::cout << "\n";

	for (auto it = dList.rbegin(); it != dList.rend(); --it)
	{
		std::cout << (*it) << std::endl;
	}
	std::cout << "\n";
	dList.resize(2);
	for (auto it = dList.rbegin(); it != dList.rend(); --it)
	{
		std::cout << (*it) << std::endl;
	}
	std::cout << "\n";
	tDoubleLinkList<int> aList;
	aList = dList;//assignment 

	//dList.push_front(100);

	//std::cout << aList.front();
	//std::cout << "\n";
	dList.push_front(10);
	dList.push_front(10);
	dList.push_front(10);
	dList.push_front(10);
	dList.push_front(10);
	dList.push_front(10);
	dList.remove(10);

	for (auto it = dList.rbegin(); it != dList.rend(); --it)
	{
		std::cout << (*it) << std::endl;
	}

	if (dList.empty())
	{
		std::cout << "empty\n";
	}
	dList.clear();
	return 0;
}