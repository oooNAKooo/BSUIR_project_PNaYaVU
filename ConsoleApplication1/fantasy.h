#pragma once
#include "boevic.h"

class fantasy : protected boevic
{
private:
	char mif[80];
	int sbor;

public:
	fantasy(const char* per = "",
		int per1 = 0,
		const char* naz = "",
		int per12 = 0,
		const char* v = "",
		int r = 0) : boevic(per, per1, naz, per12)
	{
		strcpy_s(mif, strlen(v) + 1, v);
		this->sbor = r;
	}
	char* getMif();
	int getSbor() const;
	void setMif(const char*);
	void setSbor(int);
	void change();
	friend istream& operator>>(istream& in, fantasy& obj3);
	friend ostream& operator<<(ostream& on, fantasy& obj3);

	friend ofstream& operator<<(ofstream&, fantasy&);
	friend ifstream& operator>>(ifstream&, fantasy&);
	bool operator==(fantasy& other);
};