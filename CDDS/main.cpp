#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "tForwardList.h"

int main() 
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
	fList.push_front(7);
	fList.push_front(1);
	fList.push_front(2);
	fList.push_front(3);
	for (auto it = fList.begin(); it != fList.end(); ++it)
	{
		std::cout << (*it) << std::endl;
	}
	if (fList.empty())
	{
		std::cout << "empty\n";
	}
	fList.clear();
	return 0;
}