#pragma once
#include <iostream>
#include <new>

using namespace std;
using std::bad_alloc;

template <class T>
struct nod
{
	T per;
	nod* verh=nullptr;
	nod* niz = nullptr;
};

template <class T>
class stack
{
private:
	nod<T>* h = nullptr;
	nod<T>* t = nullptr;
	int razm;
	template <class T>
	friend class iterat;
public:
	stack();
	~stack();
	nod<T>* Begin() { return h; }
	nod<T>* End() { return t; }
	void push(T);
	int show_razm();
	void show(int);
	void pop_last(int);
	void del();
	void printIterat();
};