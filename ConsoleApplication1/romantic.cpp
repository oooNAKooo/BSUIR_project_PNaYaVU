#include "romantic.h"

char* romantic::getGg()
{
	return gg;
}

int romantic::getReit() const
{
	return reit;
}

void romantic::setGg(const char* g)
{
	strcpy_s(gg, strlen(g) + 1, g);
}

void romantic::setReit(int d)
{
	this->reit = d;
}

ostream& operator<< (ostream& avt, romantic& obj2)
{
	avt << dynamic_cast<melodrama&>(obj2);
	return avt << setw(17) << obj2.gg
		       << setw(10) << obj2.reit
			   << endl;
}

istream& operator>>(istream& in, romantic& obj2)
{
	in >> dynamic_cast<melodrama&>(obj2);
	cout << endl << "[5] ������� �����: ";
	in.ignore();
	in.getline(obj2.gg, 80);
	cout << endl << "[6] �������:(�/10) ";
	in >> obj2.reit;

	return in;
}

bool romantic::operator==(romantic& other)
{
	if (!(strcmp(this->gg, other.gg)))
		return true;
	else
		return false;
}

ofstream& operator<<(ofstream& on, romantic& obj)
{
	on.write(reinterpret_cast<char*>(&obj), sizeof(romantic));
	return on;
}
ifstream& operator>>(ifstream& in, romantic& obj)
{
	in.read(reinterpret_cast<char*>(&obj), sizeof(romantic));
	return in;
}

void romantic::change()
{
	menu m;
	m.menu3_2();
	switch (_getch())
	{
	case '1':
		cout << "�������� ������: " << nazvanie << endl;
		cout << "������� ����� ��������: ";
		cin >> nazvanie; break;
	case '2':
		cout << "����������������� ������: " << pr << endl;
		cout << "������� ����� �����������������: ";
		cin >> pr; break;
	case '3':
		cout << "������������� ������: " << strana << endl;
		cout << "������� ������ �������������: ";
		cin >> strana; break;
	case '4':
		cout << "��� ������� ������: " << godik << endl;
		cout << "������� ����� ���: ";
		cin >> godik; break;
	case '5':
		cout << "������� ����� ������: " << gg << endl;
		cout << "������� ������ �������� �����: ";
		cin >> gg; break;
	case '6':
		cout << "������� ������: " << reit << endl;
		cout << "������� ����� �������: ";
		cin >> reit; break;
	default: cout << endl << "������� ���� �� ��������� ����������!"
		<< endl;
		system("pause"); break;
	}
}