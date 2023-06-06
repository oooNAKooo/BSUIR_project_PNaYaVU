#pragma once
#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

class file
{
protected:
	char fname[30];
	ifstream ifs;
	ofstream ofs;

public:
	file(const char* fn = " ")
	{
		strcpy_s(fname, strlen(fn) + 1, fn);
	}
	~file() {}
};