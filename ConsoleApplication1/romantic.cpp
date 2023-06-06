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
	cout << endl << "[5] Главный герой: ";
	in.ignore();
	in.getline(obj2.gg, 80);
	cout << endl << "[6] Рейтинг:(х/10) ";
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
		cout << "Название сейчас: " << nazvanie << endl;
		cout << "Введите новое название: ";
		cin >> nazvanie; break;
	case '2':
		cout << "Продолжительность сейчас: " << pr << endl;
		cout << "Введите новую продолжительность: ";
		cin >> pr; break;
	case '3':
		cout << "Производитель сейчас: " << strana << endl;
		cout << "Введите нового производителя: ";
		cin >> strana; break;
	case '4':
		cout << "Год выпуска сейчас: " << godik << endl;
		cout << "Введите новый год: ";
		cin >> godik; break;
	case '5':
		cout << "Главный герой сейчас: " << gg << endl;
		cout << "Введите нового главного героя: ";
		cin >> gg; break;
	case '6':
		cout << "Рейтинг сейчас: " << reit << endl;
		cout << "Введите новый рейтинг: ";
		cin >> reit; break;
	default: cout << endl << "Введите один из указанных параметров!"
		<< endl;
		system("pause"); break;
	}
}