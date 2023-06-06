#include"iterat.h"

template<class T>
iterat<T>& iterat<T>::operator ++()
{
	if (it->verh == nullptr)
	{
		it = nullptr;
		return *this;
	}
	it = it->verh;
	return *this;
}

template<class T>
iterat<T>& iterat<T>::operator --()
{
	if (it->niz == nullptr)
	{
		it = nullptr;
		return *this;
	}
	it = it->niz;
	return *this;
}

template<typename T>
T& iterat<T>::operator * ()
{
	return it->per;
}

template<typename T>
nod<T>* iterat<T>::operator & ()
{
	return it;
}

template<class T>
bool iterat<T>::operator == (const nod<T>* itt)
{
	if (this->it == itt)
	{
		return true;
	}
	return false;
}

template<class T>
bool iterat<T>::operator != (const nod<T>* itt)
{
	if (this->it != itt)
	{
		return true;
	}
	return false;
}

template<class T>
iterat<T>& iterat<T>::operator = (const nod<T>& itt)
{
	if (this->it != itt)
	{
		it = itt;
	}
	return *this;
}

