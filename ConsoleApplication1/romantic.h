#pragma once
#include "melodrama.h"

class romantic : protected melodrama
{
private:
	char gg[80];
	int reit;

public:
	romantic(const char* naz = "Romantic",
		int per1 = 0,
		const char* str_na = "No_Info",
		int god = 0,
		const char* g = "No_Info",
		int r = 0) : melodrama(str_na, per1, naz, god)
	{
		strcpy_s(gg, strlen(g) + 1, g);
		this->reit = r;
	}
	char* getGg();
	int getReit() const;
	void setGg(const char*);
	void setReit(int);
	void change();
	void Shapka();
	friend istream& operator>>(istream& in, romantic& obj2);
	friend ostream& operator<<(ostream& on, romantic& obj2);

	friend ofstream& operator<<(ofstream& on, romantic& ss);
	friend ifstream& operator>>(ifstream& in, romantic& ss);
	bool operator==(romantic& other);
};