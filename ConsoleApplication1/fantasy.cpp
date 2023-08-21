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
	cout << endl << "[5] Миф: ";
	in.ignore(); //игнорирование символов потока
	in.getline(obj2.mif, 80);
	cout << endl << "[6] Кассовые сборы: ";
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
		cout << "Название сейчас: " << nazvanie << endl;
		cout << "Введите новое название: ";
		cin >> nazvanie; break;
	case '2':
		system("CLS");
		cout << "Продолжительность сейчас: " << pr << endl;
		cout << "Введите новую продолжительность: ";
		cin >> pr; break;
	case '3':
		system("CLS");
		cout << "Спецэффекты сейчас: " << spec << endl;
		cout << "Введите новый вид спецэффектов: ";
		cin >> spec; break;
	case '4':
		system("CLS");
		cout << "Количество частей сейчас: " << ser << endl;
		cout << "Введите новое количество частей: ";
		cin >> ser; break;
	case '5':
		system("CLS");
		cout << "Миф сейчас: " << mif << endl;
		cout << "Введите новый миф: ";
		cin >> mif; break;
	case '6':
		system("CLS");
		cout << "Кассовый сбор сейчас: " << sbor << endl;
		cout << "Введите новый кассовый сбор: ";
		cin >> sbor; break;
	default: cout << endl << "Введите один из указанных параметров!"
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
