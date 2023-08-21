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
	cout << endl << "[5] Книга: ";
	in.ignore(); //игнорирование символов потока
	in.getline(obj2.kng, 80);
	cout << endl << "[6] Бюджет:($) ";
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
			cout << "Название сейчас: " << nazvanie << endl;
			cout << "Введите новое название: ";
			cin >> nazvanie;
			break;

		case '2':
			system("CLS");
			cout << "Продолжительность сейчас: " << pr << endl;
			cout << "Введите новую продолжительность: ";
			cin >> pr; break;
		case '3':
			system("CLS");
			cout << "Cпецэффекты сейчас:" << spec << endl;
			cout << "Введите новый вид спецэффектов: ";
			cin >> spec; break;
		case '4':
			system("CLS");
			cout << "Количество частей сейчас: " << ser << endl;
			cout << "Введите новое количество частей: ";
			cin >> ser; break;
		case '5':
			system("CLS");
			cout << "Книга сейчас: " << kng << endl;
			cout << "Введите новую книгу: ";
			cin >> kng; break;
		case '6':
			system("CLS");
			cout << "Бюджет сейчас: " << budj << endl;
			cout << "Введите новый бюджет: ";
			cin >> budj; break;
		case '0': n = false; break;
		default:cout << endl << "Введите один из указанных параметров!"
			<< endl;
			system("pause");
			break;
		}
		}
	}
}
