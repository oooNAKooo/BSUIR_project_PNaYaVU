#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "menu.h"
#include "exp.h"
#include "conio.h"

using namespace std;

class ganr
{
protected:
	char nazvanie[80];
	int pr;

public:
	ganr(const char* nazv = "", int p = 0)
	{
		strcpy_s(nazvanie, strlen(nazv) + 1, nazv);
		this->pr = p;
	}
	int getPr() const;
	char* getNazv();
	void setPr(int);
	void setNazv(const char*);

	friend ostream& operator<<(ostream& os, ganr& ss);
	friend istream& operator>>(istream& in, ganr& obj2);

	friend ostream& operator<<(ofstream& is, ganr& iss);
	friend istream& operator>>(ifstream& i, ganr& obj);
	bool operator==(ganr& other);
};