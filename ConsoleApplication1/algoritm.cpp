#include"algoritm.h"

template <class T>
algr<T>::algr() {}

template <class T>
algr<T>::~algr() {}

template<class T>
stack<T>& algr<T>::poisk(nod<T>* x, T ob)
{
	nod<T>* znach = x;
	stack<T> value;
	while (znach != nullptr)
	{
		if (znach->per == ob)
		{
			cout << znach->per;
			value.push(znach->per);
		}
		znach = znach->verh;
	}
	return value;
}
