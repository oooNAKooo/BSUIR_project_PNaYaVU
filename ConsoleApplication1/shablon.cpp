#include "shablon.h"

template <class T>
stack<T>::~stack()
{
	del();
}

template <class T>
stack<T>::stack()
{
	h = nullptr;
	t = nullptr;
	razm = 0;
}

template <class T>
void stack<T>::push(T znach)
{
	try
	{

		nod<T>* perem = new nod<T>;
		perem->per = znach;
		perem->verh = nullptr;
		perem->niz = nullptr;
		if (!h || !t)
		{
			t = perem;
			h = perem;
		}
		else
		{
			perem->verh = t;
			t->niz = perem;
			t = perem;
		}
		razm++;
	}
	catch (bad_alloc isk)
	{
		cout << endl
			 << "Исключение: bad_alloc!" << isk.what() 
			 << endl;
		return;
	}
}


template <class T>
void stack<T>::show(int znch)
{
	try
	{
		nod<T>* new_per = t;
		if (znch != 0)
			throw 1;
		if (!t)
		{
			cout << "Cтек пуст!" << endl;
			return;
		}
		if (znch == 0)
		{
			do
			{
				cout << new_per->per;
				new_per = new_per->verh;
			} while (new_per);
		}
		return;
	}
	catch (int i)
	{
		if (i == 1)
		{
			cout << endl
				 << "Ошибка инициализации!"
				 << endl;
			return;
		}
	}
}

template <class T>
void stack<T>::pop_last(int znch)
{
	try
	{
		if (znch != 0)
			throw 1;
		if (!h || !t)
		{
			cout << "Стек пуст!" << endl;
			return;
		}
		if (znch == 0)
		{
			nod<T>* _new = t;
			t = t->verh;
			delete _new;
			razm--;
			cout << "Элемент удален!" << endl;
		}
	}
	catch (int q)
	{
		if (q == 1)
		{
			cout << endl
				 << "Ошибка инициализации!";
			return;
		}
	}
}

template <class T>
int stack<T>::show_razm()
{
	return razm;
}

template <class T>
void stack<T>::del()
{

	while (h != nullptr)
	{
		nod<T>* n = h->verh;
		delete h;
		h = n;
	}
	t = nullptr;
	razm = 0;
}

template<class T>
void stack<T>::printIterat()
{
	iterat<T> itr = 0;
	for (itr = this->Begin(); itr != this->End()->verh; ++itr)
	{
		cout << *itr;
		cout << endl;
	}
}
