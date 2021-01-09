#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "tForwardList.h"

void main() 
{

	tForwardList<int> fList;
	if (fList.empty()) 
	{
		std::cout << "empty\n";
	}
	fList.push_front(5);
	fList.push_front(5);
	fList.push_front(5);
	fList.clear();
	if (fList.empty())
	{
		std::cout << "empty\n";
	}

	fList.push_front(5);
	std::cout << fList.front();
	fList.push_front(7);
	std::cout << fList.front();
	
	std::cout << fList.front();
	if (fList.empty())
	{
		std::cout << "empty\n";
	}
	fList.clear();

}