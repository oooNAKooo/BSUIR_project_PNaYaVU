#include "fantasy.h"

char* fantasy::getMif()
{
	return mif;
}

int fantasy::getSbor() const
{
	return sbor;
}

void fantasy::setMif(const char* v)
{
	strcpy_s(mif, strlen(v) + 1, v);
}

void fantasy::setSbor(int r)
{
	this->sbor = r;
}

ostream& operator<< (ostream& avt, fantasy& obj2)
{
	avt << dynamic_cast<boevic&>(obj2);
	return avt << setw(13) << obj2.mif <<setw(10)<< obj2.sbor
			   << endl;
}

istream& operator>>(istream& in, fantasy& obj2)
{
	in >> dynamic_cast<boevic&>(obj2);
	cout << endl << "[5] ���: ";
	in.ignore(); //������������� �������� ������
	in.getline(obj2.mif, 80);
	cout << endl << "[6] �������� �����: ";
	in >> obj2.sbor;

	return in;
}

bool fantasy::operator==(fantasy& other)
{
	if (!(strcmp(this->mif, other.mif)))
		return true;
	else
		return false;
}
void fantasy::change()
{
	menu m;
	m.menu3_3();
	switch (_getch())
	{
	case '1':
		system("CLS");
		cout << "�������� ������: " << nazvanie << endl;
		cout << "������� ����� ��������: ";
		cin >> nazvanie; break;
	case '2':
		system("CLS");
		cout << "����������������� ������: " << pr << endl;
		cout << "������� ����� �����������������: ";
		cin >> pr; break;
	case '3':
		system("CLS");
		cout << "����������� ������: " << spec << endl;
		cout << "������� ����� ��� ������������: ";
		cin >> spec; break;
	case '4':
		system("CLS");
		cout << "���������� ������ ������: " << ser << endl;
		cout << "������� ����� ���������� ������: ";
		cin >> ser; break;
	case '5':
		system("CLS");
		cout << "��� ������: " << mif << endl;
		cout << "������� ����� ���: ";
		cin >> mif; break;
	case '6':
		system("CLS");
		cout << "�������� ���� ������: " << sbor << endl;
		cout << "������� ����� �������� ����: ";
		cin >> sbor; break;
	default: cout << endl << "������� ���� �� ��������� ����������!"
		<< endl;
		system("pause"); break;
	}
}

ofstream& operator<<(ofstream& on, fantasy& obj)
{
	on.write(reinterpret_cast<char*>(&obj), sizeof(fantasy));
	return on;
}
ifstream& operator>>(ifstream& in, fantasy& obj)
{
	in.read(reinterpret_cast<char*>(&obj), sizeof(fantasy));
	return in;
}