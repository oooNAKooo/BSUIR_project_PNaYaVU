#pragma once
#include "boevic.h"

class detectiv : protected boevic
{
private:
	char kng[80];
	int budj;

public:
	detectiv(const char* naz = "",
		int per1 = 0,
		const char* h = "",
		int k = 0,
		const char* c = "",
		int g = 0) : boevic(h, per1, naz, k)
	{
		strcpy_s(kng, strlen(c) + 1, c);
		this->budj = g;
	}
	char* getKng();
	int getBudj() const;
	void setKng(const char*);
	void setBudj(int);
	void change();
	friend istream& operator>>(istream&, detectiv&);
	friend ostream& operator<<(ostream&, detectiv&);

	friend ofstream& operator<<(ofstream&, detectiv&);
	friend ifstream& operator>>(ifstream&, detectiv&);
	bool operator==(detectiv& other);
};