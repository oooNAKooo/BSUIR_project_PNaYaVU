#include "melodrama.h"

char* melodrama::getStrana()
{
	return strana;
}

int melodrama::getGodik() const
{
	return godik;
}

void melodrama::setStrana(const char* s)
{
	strcpy_s(strana, strlen(s) + 1, s);
}

void melodrama::setGodik(int g)
{
	this->godik = g;
}
bool melodrama::operator==(melodrama& other)
{
	if (!(strcmp(this->strana, other.strana)))
		return true;
	else
		return false;
}
ostream& operator<< (ostream& on, melodrama& obj2)
{
	on << dynamic_cast<ganr&>(obj2);
	return on << setw(27) << obj2.strana
		<< setw(16) << obj2.godik;
}

istream& operator>>(istream& in, melodrama& obj1)
{
	in >> dynamic_cast<ganr&>(obj1);
	cout << endl << "[3] Страна производитель: ";
	in.ignore(); //игнорирование символов потока
	in.getline(obj1.strana, 80);
	cout << endl << "[4] Год выпуска: ";
	in >> obj1.godik;
	return in;
}

ofstream& operator<<(ofstream& on, melodrama& ss)
{
	on.write(reinterpret_cast<char*>(&ss), sizeof(melodrama));
	return on;
}
ifstream& operator>>(ifstream& in, melodrama& ss)
{
	in.read(reinterpret_cast<char*>(&ss), sizeof(melodrama));
	return in;
}