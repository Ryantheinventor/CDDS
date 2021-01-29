#include "pool.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
int main() 
{

	tObjectPool<int> testPool = tObjectPool<int>(3);
	auto number = testPool.retrieve();
	auto number1 = testPool.retrieve();
	auto number2 = testPool.retrieve();
	auto number3 = testPool.retrieve();
	testPool.recycle(number1);//this is not working as expected
	auto number4 = testPool.retrieve();
	std::cout << number->data;
	number->data = 2;
	std::cout << number->data;
	return 0;
}