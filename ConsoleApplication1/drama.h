#pragma once
#include "melodrama.h"

class drama : protected melodrama
{
private:
	char prod[80];
	int ocen;

public:
	drama(const char* str_na = "",
		int per1 = 0,
		const char* naz = "",
		int god = 0,
		const char* p = "",
		int o = 0) : melodrama(str_na, per1, naz, god)
	{
		strcpy_s(prod, strlen(p) + 1, p);
		this->ocen = o;
	}
	char* getProd();
	int getOcen() const;
	void setProd(const char*);
	void setOcen(int);
	void change();
	friend ostream& operator<<(ostream& on, drama& obj4);
	friend istream& operator>>(istream& in, drama& obj4);

	friend ofstream& operator<<(ofstream& on, drama& ss);
	friend ifstream& operator>>(ifstream& in, drama& ss);
	bool operator==(drama& other);
};