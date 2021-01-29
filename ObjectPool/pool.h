#pragma once
#include <vector>

#include <iostream>
#include <cstdio>
#include <cstdlib>

template<typename T>
class tObjectPool
{
	struct object
	{
		T data;
		bool isFree = true;
		size_t myIndex = 0;
	};

	std::vector<object> pool;
	int used = 0;
public:
	tObjectPool();
	tObjectPool(size_t initalCap);
	~tObjectPool();

	object *retrieve();

	void recycle(object *obj);
};


template<typename T>
tObjectPool<T>::tObjectPool() 
{
	pool = std::vector<object>(1);
}

template<typename T>
tObjectPool<T>::tObjectPool(size_t initalCap)
{
	pool = std::vector<object>(initalCap);
}

template<typename T>
tObjectPool<T>::~tObjectPool() 
{
	pool.clear();
}

template<typename T>
typename tObjectPool<T>::object *tObjectPool<T>::retrieve()
{
	if (used == pool.size())
	{
		return NULL;
	}
	pool[used].isFree = false;
	pool[used].myIndex = used;
	//pool[used].data = T();
	used++;
	return &pool[used-1];
}

template<typename T>
void tObjectPool<T>::recycle(object *obj)
{
	obj->isFree = true;
	used--;
	if (used == 0 || &pool[used] == obj)
	{	
		return;
	}
	object *temp = &pool[used];
	pool[used] = *obj;
	pool[obj->myIndex] = *temp;
	obj = NULL;
}

