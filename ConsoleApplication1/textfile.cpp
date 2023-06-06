#include "textfile.h"
#include "file.h"

template <typename T>
bool File_Text<T>::ifs_o()
{
	ifs.open(fname, ios::in);
	if (!ifs)
	{
		cout << "Файл не создан!" << endl;
		return false;
	}
	else
		return true;
	ifs.close();
}
template <typename T>
bool File_Text<T>::ofs_o()
{
	ofs.open(fname, ios::in);
	if (!ofs)
	{
		cout << "Файл не создан!" << endl;
		return false;
	}
	else
		return true;
	ofs.close();
}
template <typename T>
void File_Text<T>::Remote()
{
	ifs.seekg(0, ios::beg);
	ofs.seekp(0, ios::beg);
	ifs.clear();
	ofs.clear();
}
template <typename T>
void File_Text<T>::Write_Text(T &object)
{
	ofs << object;
}
template <typename T>
void File_Text<T>::Read_Text(T &object)
{
	ifs >> object;
}

template <typename T>
bool File_Text<T>::R_end_file()
{
	if (ifs.eof())
		return true;
	else
		return false;
}
