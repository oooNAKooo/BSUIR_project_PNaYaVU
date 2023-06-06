#include "boevic.h"

char* boevic::getSpec()
{
	return spec;
}

int boevic::getSer() const
{
	return ser;
}

void boevic::setSpec(const char* zn)
{
	strcpy_s(spec, strlen(zn) + 1, zn);
}

void boevic::setSer(int k)
{
	this->ser = k;
}

ostream& operator<<(ostream& on, boevic& obj1)
{
	on << dynamic_cast<ganr&>(obj1);
	return on << setw(20) << obj1.spec << setw(21) << obj1.ser;
}
bool boevic::operator==(boevic& other)
{
	if (!(strcmp(this->spec, other.spec)))
		return true;
	else
		return false;
}
istream& operator>>(istream& in, boevic& obj2)
{
	in >> dynamic_cast<ganr&>(obj2);
	cout << endl
		<< "[3] Вид спецэффектов: ";
	in.ignore(); 
	in.getline(obj2.spec, 80);
	cout << endl
		<< "[4] Количество серий: ";
	in >> obj2.ser;

	return in;
}

ofstream& operator<<(ofstream& on, boevic& ss)
{
	on.write(reinterpret_cast<char*>(&ss), sizeof(boevic));
	return on;
}
ifstream& operator>>(ifstream& in, boevic& ss)
{
	in.read(reinterpret_cast<char*>(&ss), sizeof(boevic));
	return in;
}