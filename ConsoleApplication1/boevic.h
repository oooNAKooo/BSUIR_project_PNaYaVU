#pragma once
#include "ganr.h"

class boevic : protected ganr
{
protected:
	char spec[80];
	int ser;
public:
	boevic(const char* zn = "",
		int s = 0,
		const char* sss = "",
		int per1 = 0) : ganr(sss, per1)
	{
		strcpy_s(spec, strlen(zn) + 1, zn);
		this->ser = s;
	}
	char* getSpec();
	int getSer() const;
	void setSpec(const char*);
	void setSer(int);
	friend istream& operator>>(istream& in, boevic& obj1);
	friend ostream& operator<<(ostream& on, boevic& obj1);

	friend ofstream& operator<<(ofstream& on, boevic& ss);
	friend ifstream& operator>>(ifstream& in, boevic& ss);
	bool operator==(boevic& other);

};