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
	cout << endl << "[5] Продюссер: ";
	in.ignore();
	in.getline(obj2.prod, 80);
	cout << endl << "[6] Оценка: ";
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
		cout << "Название сейчас: " << nazvanie << endl;
		cout << "Введите новое имя: ";
		cin >> nazvanie; break;
	case '2':
		system("CLS");
		cout << "Продолжительность сейчас:" << pr << endl;
		cout << "Введите новую продолжительность: ";
		cin >> pr; break;
	case '3':
		system("CLS");
		cout << "Производитель сейчас: " << strana << endl;
		cout << "Введите нового производителя: ";
		cin >> strana; break;
	case '4':
		system("CLS");
		cout << "Год выпуска сейчас: " << godik << endl;
		cout << "Введите новый год: ";
		cin >> godik; break;
	case '5':
		system("CLS");
		cout << "Продюсер сейчас: " << prod << endl;
		cout << "Введите нового продюссера: ";
		cin >> prod; break;
	case '6':
		system("CLS");
		cout << "Оценка сейчас: " << ocen << endl;
		cout << "Введите новую оценку: ";
		cin >> ocen; break;
	default: cout << endl << "Введите один из указанных параметров!"
		<< endl;
		system("pause"); break;
	}
}