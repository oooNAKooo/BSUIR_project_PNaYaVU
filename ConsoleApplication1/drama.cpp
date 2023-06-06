#include "drama.h"

char* drama::getProd()
{
	return prod;
}

int drama::getOcen() const
{
	return ocen;
}

void drama::setProd(const char* p)
{
	strcpy_s(prod, strlen(p) + 1, p);
}

void drama::setOcen(int v)
{
	this->ocen = v;
}

ostream& operator<< (ostream& avt, drama& obj2)
{
	avt << dynamic_cast<melodrama&>(obj2);
	return avt 	<< setw(17) << obj2.prod
			    << setw(15) << obj2.ocen
				<< endl;
}

istream& operator>>(istream& in, drama& obj2)
{
	in >> dynamic_cast<melodrama&>(obj2);
	cout << endl << "[5] ���������: ";
	in.ignore();
	in.getline(obj2.prod, 80);
	cout << endl << "[6] ������: ";
	in >> obj2.ocen;

	return in;
}
bool drama::operator==(drama& other)
{
	if (!(strcmp(this->prod, other.prod)))
		return true;
	else
		return false;
}
ofstream& operator<<(ofstream& on, drama& obj)
{
	on.write(reinterpret_cast<char*>(&obj), sizeof(drama));
	return on;
}

ifstream& operator>>(ifstream& in, drama& obj)
{
	in.read(reinterpret_cast<char*>(&obj), sizeof(drama));
	return in;
}

void drama::change()
{
	menu m;
	m.menu3_4();
	switch (_getch())
	{
	case '1':
		system("CLS");
		cout << "�������� ������: " << nazvanie << endl;
		cout << "������� ����� ���: ";
		cin >> nazvanie; break;
	case '2':
		system("CLS");
		cout << "����������������� ������:" << pr << endl;
		cout << "������� ����� �����������������: ";
		cin >> pr; break;
	case '3':
		system("CLS");
		cout << "������������� ������: " << strana << endl;
		cout << "������� ������ �������������: ";
		cin >> strana; break;
	case '4':
		system("CLS");
		cout << "��� ������� ������: " << godik << endl;
		cout << "������� ����� ���: ";
		cin >> godik; break;
	case '5':
		system("CLS");
		cout << "�������� ������: " << prod << endl;
		cout << "������� ������ ����������: ";
		cin >> prod; break;
	case '6':
		system("CLS");
		cout << "������ ������: " << ocen << endl;
		cout << "������� ����� ������: ";
		cin >> ocen; break;
	default: cout << endl << "������� ���� �� ��������� ����������!"
		<< endl;
		system("pause"); break;
	}
}