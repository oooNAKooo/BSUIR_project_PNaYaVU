#include "detectiv.h"


char* detectiv::getKng()
{
	return kng;
}
int detectiv::getBudj() const
{
	return budj;
}
void detectiv::setKng(const char* c)
{
	strcpy_s(kng, strlen(c) + 1, c);
}

void detectiv::setBudj(int g)
{
	this->budj = g;
}

ostream& operator<< (ostream& avt, detectiv& obj2)
{
	avt << dynamic_cast<boevic&>(obj2);
	return avt <<setw(17) << obj2.kng << setw(22) << obj2.budj << endl;
}

istream& operator>>(istream& in, detectiv& obj2)
{
	in >> dynamic_cast<boevic&>(obj2);
	cout << endl << "[5] �����: ";
	in.ignore(); //������������� �������� ������
	in.getline(obj2.kng, 80);
	cout << endl << "[6] ������:($) ";
	in >> obj2.budj;

	return in;
}

ofstream& operator<<(ofstream& on, detectiv& obj)
{
	on.write(reinterpret_cast<char*>(&obj), sizeof(detectiv));
	return on;
}
ifstream& operator>>(ifstream& in, detectiv& obj)
{
	in.read(reinterpret_cast<char*>(&obj), sizeof(detectiv));
	return in;
}

bool detectiv::operator==(detectiv& other)
{
	if (!(strcmp(this->kng,other.kng)))
		return true;
	else
		return false;
}

void detectiv::change()
{
	menu m;
	inputexc me;
	bool n = true;

	while (n) {
		m.menu3_1();
		switch (_getch())
		{
		case '1': {
			system("CLS");
			cout << "�������� ������: " << nazvanie << endl;
			cout << "������� ����� ��������: ";
			cin >> nazvanie;
			break;

		case '2':
			system("CLS");
			cout << "����������������� ������: " << pr << endl;
			cout << "������� ����� �����������������: ";
			cin >> pr; break;
		case '3':
			system("CLS");
			cout << "C���������� ������:" << spec << endl;
			cout << "������� ����� ��� ������������: ";
			cin >> spec; break;
		case '4':
			system("CLS");
			cout << "���������� ������ ������: " << ser << endl;
			cout << "������� ����� ���������� ������: ";
			cin >> ser; break;
		case '5':
			system("CLS");
			cout << "����� ������: " << kng << endl;
			cout << "������� ����� �����: ";
			cin >> kng; break;
		case '6':
			system("CLS");
			cout << "������ ������: " << budj << endl;
			cout << "������� ����� ������: ";
			cin >> budj; break;
		case '0': n = false; break;
		default:cout << endl << "������� ���� �� ��������� ����������!"
			<< endl;
			system("pause");
			break;
		}
		}
	}
}