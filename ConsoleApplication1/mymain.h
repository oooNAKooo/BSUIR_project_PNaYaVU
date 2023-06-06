#pragma once
#include <iostream>
#include "locale.h"
#include "ganr.h"
#include "romantic.h"
#include "drama.h"
#include "detectiv.h"
#include "fantasy.h"
#include "shablon.cpp"
#include "textfile.cpp"
#include "windows.h"
#include "menu.h"
#include "conio.h"
#include "exp.h"
#include "algoritm.cpp"
#include "iterat.cpp"

using namespace std;

void glav()
{
	stack<detectiv>* data1 = new stack<detectiv>;
	stack<romantic>* data2 = new stack<romantic>;
	stack<fantasy>* data3 = new stack<fantasy>;
	stack<drama>* data4 = new stack<drama>;

	detectiv s1,ss1;
	romantic s2,ss2;
	fantasy s3,ss3;
	drama s4,ss4;
	menu m;
	
	algr<detectiv> al1;
	algr<romantic> al2;
	algr<fantasy> al3;
	algr<drama> al4;

	string st;

	while (1)
	{
		m.MenuProsmotra();
		bool x = true;
		int k0;
		k0 = test();
		switch (k0)
		{
		case 1:
			while (x)
			{
				system("cls");
				m.GlavMenu();
				int k1;
				k1 = test();
				switch (k1)
				{
				case 1:
				{
					system("cls");
					cin >> s1;
					data1->push(s1);
				}break;
				case 2:
				{
					system("cls");
					m.mdet();
					cout << endl;
					data1->show(0);
					system("pause");
				}break;
				case 3:
				{
					system("cls");

					File_Text<detectiv> fl_txt("D:\\text.txt");
					fl_txt.ofs_o();
					fl_txt.Remote();
					for (int i = 0; i < data1->show_razm(); i++)
					{
						fl_txt.Write_Text(s1);
					}
					cout << "Запись произведена!" << endl;
					system("pause");
				}break;
				case 4:
				{
					system("cls");
					m.mdet();
					File_Text<detectiv> _fl_txt("D:\\text.txt");
					_fl_txt.ifs_o();
					_fl_txt.Remote();
					int count = data1->show_razm();
					for (int i = 0; i < count; i++)
					{
						_fl_txt.Read_Text(s1);
					}
				//	data1->show(0);
					system("pause");
				}break;
				case 5:
				{
					system("cls");
					data1->pop_last(0);
					system("pause");
				}break;
				case 6:
				{
					system("cls");
					data1->del();
					cout << "Стек очищен!" << endl;
					system("pause");
				}break;
				case 7:
				{
					system("cls");
					int razm = data1->show_razm();
					cout << "Количество элементов в объекте cтека: " 
						 << razm << endl;
					system("pause");
				}break;
				case 8:
				{
					system("cls");
					m.mdet();
					cout << endl;
					data1->show(0);
					cout << endl;
					cin >> ss1;
					cout << endl;
					m.mdet();
					al1.poisk(data1->Begin(), ss1);
					cout << endl;
					system("pause");
					cout << endl;
				}break;
				case 9:
				{
					system("cls");
					m.menu3_1();
					s1.change();
					system("pause");
				}break;
				case 10:
				{
					system("cls");
					m.mdet();
					cout << endl;
					data1->printIterat();
					system("pause");
				}break;
				case 0:
				{
					x = false;
				}break;
				}
			}break;

		case 2:
			while (x)
			{
				system("cls");
				m.GlavMenu();
				int k1;
				k1 = test();
				switch (k1)
				{

				case 1:
				{
					system("cls");
					cin >> s2;
				}break;
				case 2:
				{
					system("cls");
					m.mrom();
					data2->show(0);
					system("pause");
				}break;
				case 3:
				{
					system("cls");
					data2->push(s2);
					File_Text<romantic> fl_txt2("D:\\text2.txt");
					fl_txt2.ofs_o();
					fl_txt2.Remote();
					for (int i = 0; i < data2->show_razm(); i++)
					{
						fl_txt2.Write_Text(s2);
					}
				}break;
				case 4:
				{
					system("cls");
					m.mrom();
					File_Text<romantic> _fl_txt2("D:\\text2.txt");
					_fl_txt2.ifs_o();
					_fl_txt2.Remote();
					int count2 = data2->show_razm();
					for (int i = 0; i < count2; i++)
					{
						_fl_txt2.Read_Text(s2);
					}
					data2->show(0);
				}break;
				case 5:
					system("cls");
					data2->pop_last(0);
					system("pause");
					break;
				case 6:
				{
					system("cls");
					data2->del();
					cout << "Стек очищен!" << endl;
					system("pause");
				}break;
				case 7:
				{
					system("cls");
					int razm = data2->show_razm();
					cout << "Количество элементов в объекте cтека: " << razm << endl;
					system("pause");
				}break;
				case 8:
				{
					system("cls");
					m.mrom();
					cout << endl;
					data2->show(0);
					cout << endl;
					cin >> ss2;
					cout << endl;
					m.mrom();
					al2.poisk(data2->Begin(), ss2);
					cout << endl;
					system("pause");
					cout << endl;
				}break;
				case 9:
				{
					system("cls");
					m.menu3_2();
					s2.change();
					system("pause");
				}break;
				case 10:
				{
					system("cls");
					m.mrom();
					cout << endl;
					data2->printIterat();
					system("pause");
				}break;
				case 0:
				{
					x = false;
				}break;
				}
			}break;

		case 3:
			while (x)
			{
				system("cls");
				m.GlavMenu();
				int k2;
				k2 = test();
				switch (k2)
				{
				case 1:
				{
					system("cls");
					cin >> s3;
				}break;
				case 2:
				{
					system("cls");
					m.mfan();
					data3->show(0);
					system("pause");
				}break;
				case 3:
				{
					system("cls");
					data3->push(s3);
					File_Text<fantasy> fl_txt3("D:\\text3.txt");
					fl_txt3.ofs_o();
					fl_txt3.Remote();
					for (int i = 0; i < data3->show_razm(); i++)
					{
						fl_txt3.Write_Text(s3);
					}
				}break;
				case 4:
				{
					system("cls");
					m.mfan();
					File_Text<fantasy> _fl_txt3("D:\\text3.txt");
					_fl_txt3.ifs_o();
					_fl_txt3.Remote();
					int count3 = data3->show_razm();
					for (int i = 0; i < count3; i++)
					{
						_fl_txt3.Read_Text(s3);
					}
					data3->show(0);
				}break;
				case 5:
				{
					system("cls");
					data3->pop_last(0);
					system("pause");
				}break;
				case 6:
				{
					system("cls");
					data3->del();
					cout << "Стек очищен!" << endl;
					system("pause");
				}break;
				case 7:
				{
					system("cls");
					int razm = data3->show_razm();
					cout << "Количество элементов в объекте cтека: " << razm << endl;
					system("pause");
				}break;
				case 8:
				{
					system("cls");
					m.mfan();
					cout << endl;
					data3->show(0);
					cout << endl;
					cin >> ss1;
					cout << endl;
					m.mfan();
					al3.poisk(data3->Begin(), ss3);
					cout << endl;
					system("pause");
					cout << endl;
				}break;
				case 9:
				{
					system("cls");
					m.menu3_3();
					s3.change();
					system("pause");
				}break;
				case 10:
				{
					system("cls");
					m.mfan();
					cout << endl;
					data3->printIterat();
					system("pause");
				}break;
				case 0:
				{
					x = false;
				}break;
				}
			}

		case 4:
			while (x)
			{
				system("cls");
				m.GlavMenu();
				int k3;
				k3 = test();
				switch (k3)
				{

				case 1:
				{
					system("cls");
					cin >> s4;
				}break;
				case 2:
				{
					system("cls");
					m.mdr();
					data4->show(0);
					system("pause");
				}break;
				case 3:
				{
					system("cls");
					data4->push(s4);
					File_Text<drama> fl_txt4("D:\\text4.txt");
					fl_txt4.ofs_o();
					fl_txt4.Remote();
					for (int i = 0; i < data4->show_razm(); i++)
					{
						fl_txt4.Write_Text(s4);
					}
				}break;
				case 4:
				{
					system("cls");
					m.mdr();
					File_Text<drama> _fl_txt4("D:\\text4.txt");
					_fl_txt4.ifs_o();
					_fl_txt4.Remote();
					int count4 = data4->show_razm();
					for (int i = 0; i < count4; i++)
					{
						_fl_txt4.Read_Text(s4);
					}
					data4->show(0);
				}break;
				case 5:
				{	
					system("cls");
					data4->pop_last(0);
					system("pause");
				}break;
				case 6:
				{
					system("cls");
					data4->del();
					cout << "Стек очищен!" << endl;
					system("pause");
				}break;
				case 7:
				{
					system("cls");
					int razm = data4->show_razm();
					cout << "Количество элементов в объекте cтека: " << razm << endl;
					system("pause");
				}break;
				case 8:
				{
					system("cls");
					m.mdr();
					cout << endl;
					data4->show(0);
					cout << endl;
					cin >> ss4;
					cout << endl;
					m.mdr();
					al4.poisk(data4->Begin(), ss4);
					cout << endl;
					system("pause");
					cout << endl;
				}break;
				case 9:
				{
					system("cls");
					m.menu3_4();
					s4.change();
					system("pause");
				}break;
				case 10:
				{
					system("cls");
					m.mdr();
					cout << endl;
					data4->printIterat();
					system("pause");
				}break;
				case 0:
				{
					x = false;
				}break;
				}
			}break;
		case 0:
		{
			system("cls");
			cout << "До скорой встречи!" << endl;
			system("pause");
		}return;
		}
	}
}
