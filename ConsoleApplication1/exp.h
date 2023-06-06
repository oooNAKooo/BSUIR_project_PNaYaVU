#pragma once
#include <iostream>

using namespace std;

class myexc
{
protected:
	char expp[80] = "";
	int num = 0;

public:
	myexc(int n = 0, const char* e = "")
	{

		strcpy_s(expp, strlen(e) + 1, e);
		this->num = n;
	}
	myexc(const myexc& ME)
	{
		strcpy_s(expp, strlen(ME.expp) + 1, ME.expp);
		num = ME.num;
	}
	~myexc() {};
	
};

class inputexc : protected myexc
{
protected:
	int num1;
	char per[80];

public:
	inputexc(int n = 0, const char* e = "", int n1 = 0, const char* p = "") : myexc(n, e)
	{

		strcpy_s(per, strlen(p) + 1, p);
		this->num1 = n1;
	}
	inputexc(const inputexc& ME)
	{
		strcpy_s(per, strlen(ME.per) + 1, ME.per);
		num1 = ME.num1;
	}
	void viv()
	{
		for (int i = 0; i < per[i]; i++)
		{
			cout << per[i];
		}
		cout << endl;
	}
};

inline char* exc(istream& obj)
{
	bool a = false;
	int i = 0;
	char* strk2;
	strk2 = new char[80];
	do
	{
		try
		{
			char strk[80];
			obj.getline(strk, 80);
			strcpy_s(strk2, strlen(strk) + 1, strk);
			for (; strk2[i];)
			{
				if (strk[i] == '^')
				{
					i++;
				}
				if (strk[i] >= '1999')
				{
					i++;
				}
				else if (strk[i] < 'A' || strk[i]>'z')
				{
					throw inputexc(1, "Некорректный ввод! Допустимы лишь английские символы!");
				}
			}
		}
		catch (inputexc obj)
		{
			a = true;
			obj.viv();
			rewind(stdin);
		}
	} while (a == true);
	return strk2;
}

inline int test(istream& obj)
{
	int k;
	bool poka;
	do
	{
		rewind(stdin);
		try
		{
			rewind(stdin);
			poka = false;
			obj >> k;
			if (k < 0 ||!obj.good() || obj.peek() != '\n')
				throw overflow_error("Введен неверный номер пункта!");
		}
		catch (overflow_error ob)
		{
			obj.clear();
			rewind(stdin);
			cout << "Исключение: " << ob.what() << endl;
			poka = true;
		}
	} while (poka);
	return k;
}

inline int test()
{
	int k;
	bool poka;
	do
	{
		try
		{
			rewind(stdin);
			poka = false;
			cin >> k;
			if (k < 0 || !cin.good() || cin.peek() != '\n')
				throw overflow_error("Введен неверный номер пункта!");
		}
		catch (overflow_error ob)
		{
			cin.clear();
			rewind(stdin);
			cout << "Исключение: " << ob.what() << endl;
			poka = true;
		}
	} while (poka);
	return k;
}


