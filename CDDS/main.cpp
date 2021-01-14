#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "tForwardList.h"

int main() 
{

	tForwardList<int> dList;
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

	dList.resize(2);
	for (auto it = dList.begin(); it != dList.end(); ++it)
	{
		std::cout << (*it) << std::endl;
	}
	std::cout << "\n";

	//I have no clue how to iterate backwards
	/*for (auto it = dList.end(); it != dList.begin(); --it)
	{
		std::cout << (*it) << std::endl;
	}*/
	if (dList.empty())
	{
		std::cout << "empty\n";
	}
	dList.clear();
	return 0;
}