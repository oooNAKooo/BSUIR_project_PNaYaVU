#pragma once
#include "shablon.h"

template<class T>
class algr
{
public:
	algr();
	~algr();
	stack<T>& poisk(nod<T>* i, T _obj);
};
