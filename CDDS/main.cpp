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
	std::cout << "push front (5) 3x\n";
	dList.push_front(5);
	dList.push_front(5);
	dList.push_front(5);
	if (!dList.empty())
	{
		std::cout << "not empty\n";
	}
	std::cout << "clear\n";
	dList.clear();
	if (dList.empty())
	{
		std::cout << "empty\n";
	}
	std::cout << "push front 1-10 in order\n";
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
	std::cout << "iterator loop front to back\n";
	for (auto it = dList.begin(); it != dList.end(); ++it)
	{
		std::cout << (*it) << std::endl;
	}
	std::cout << "\n";

	std::cout << "iterator loop reverse\n";
	for (auto it = dList.rbegin(); it != dList.rend(); --it)
	{
		std::cout << (*it) << std::endl;
	}
	std::cout << "\n";
	dList.resize(2);
	std::cout << "iterator loop front to back after resize\n";
	for (auto it = dList.begin(); it != dList.end(); ++it)
	{
		std::cout << (*it) << std::endl;
	}
	std::cout << "\n";

	std::cout << "iterator loop reverse after resize\n";
	
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
	dList.push_back(10);
	dList.push_back(10);
	dList.push_back(10);
	std::cout << "pushfront/back many 10s\n";
	std::cout << "in order iterator before remove 10\n";
	for (auto it = dList.begin(); it != dList.end(); ++it)
	{
		std::cout << (*it) << std::endl;
	}
	std::cout << "\n";
	dList.remove(10);

	std::cout << "in order iterator after remove 10\n";
	for (auto it = dList.begin(); it != dList.end(); ++it)
	{
		std::cout << (*it) << std::endl;
	}
	std::cout << "\n";

	if (!dList.empty())
	{
		std::cout << "not empty before clear\n";
	}
	dList.clear();
	if (dList.empty())
	{
		std::cout << "empty after clear\n";
	}
	return 0;
}