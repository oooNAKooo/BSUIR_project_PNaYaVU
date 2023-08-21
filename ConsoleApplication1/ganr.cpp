#include "ganr.h"


int ganr::getPr()const
{
	return pr;
}

char* ganr::getNazv()
{
	return nazvanie;
}

void ganr::setNazv(const char* nazv)
{
	strcpy_s(nazvanie, strlen(nazv) + 1, nazv);
}

void ganr::setPr(int s)
{
	this->pr = s;
}

bool ganr::operator==(ganr& other)
{
	if (!(strcmp(this->nazvanie, other.nazvanie)))
		return true;
	else
		return false;
}
ostream& operator<< (ostream& os, ganr& ss)
{
	cout << setiosflags(ios::left);
	return os << setw(14) << ss.nazvanie << setw(25) << ss.pr;
}

istream& operator>>(istream& in, ganr& obj2)
{
	cout << "Заполните данные о фильме:" << endl;
	cout << endl << "[1] Название фильма: ";
	rewind(stdin);
	in.getline(obj2.nazvanie, 80);
	cout << endl << "[2] Продолжительность фильма:(мин) ";
	in >> obj2.pr;

	return in;
}

ostream& operator<<(ofstream& is, ganr& iss)
{
	is.write(reinterpret_cast<char*>(&iss), sizeof(ganr));
	return is;
}
istream& operator>>(ifstream& i, ganr& obj)
{
	i.read(reinterpret_cast<char*>(&obj), sizeof(ganr));
	return i;
}
