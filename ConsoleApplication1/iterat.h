#pragma once
#include<iostream>
#include"shablon.h"

using namespace std;

template<class T>
class iterat
{
private:
	nod<T>* it;
public:
	iterat()
	{
		it = nullptr;
	}

	iterat(nod<T>* itt)
	{
		it = itt;
	}

	iterat(const iterat& itt) : it(itt.it) {}

	~iterat() {}

	iterat& operator ++();

	iterat& operator --();

	T& operator * ();

	nod<T>* operator & ();

	bool operator == (const nod<T>*);

	bool operator != (const nod<T>*);

	iterat& operator = (const nod<T>&);
};