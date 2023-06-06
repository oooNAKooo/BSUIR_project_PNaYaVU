#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include"file.h"

using namespace std;

template<typename T>
class File_Text : public file
{
public:
	File_Text(const char* fn) :file(fn){}
	~File_Text()
	{
		ifs.close();
		ofs.close();
	}
	bool ifs_o();
	bool ofs_o();
	void Remote();
	void Write_Text(T& object);
	void Read_Text(T& object);
	bool R_end_file();
};
