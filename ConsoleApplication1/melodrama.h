#pragma once
#include "ganr.h"

class melodrama : protected ganr
{
protected:
	char strana[80];
	int godik;
public:
	melodrama(const char* str_na = "",
		int god = 0,
		const char* sss = "",
		int per1 = 0) : ganr(sss, per1)
	{
		strcpy_s(strana, strlen(str_na) + 1, str_na);
		this->godik = god;
	}
	char* getStrana();
	int getGodik() const;
	void setStrana(const char*);
	void setGodik(int);
	friend istream& operator>>(istream& in, melodrama& obj1);
	friend ostream& operator<<(ostream& on, melodrama& obj1);

	friend ofstream& operator<<(ofstream& on, melodrama& ss);
	friend ifstream& operator>>(ifstream& in, melodrama& ss);
	bool operator==(melodrama& other);
};