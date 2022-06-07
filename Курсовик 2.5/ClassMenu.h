#pragma once

#include <windows.h>
#include<iostream>
#include<string>
#include <fstream>
using namespace std;


class Menu
{
private:
	
	struct punktMenu
	{
		int nomerPunkta=0;
		string p="";
	};
	int kolPunktMenu = 0;

public:
	punktMenu menu[1111];
	int viborPunkta;
	string shapkaMenu;

	Menu(string shapka, string p01, string p02, string p03, string p04, string p05, string p06, string p07, string p08, string p09)
	{
		menu[0].p = "Выход"; menu[1].p = p01; menu[2].p = p02; menu[3].p = p03; menu[4].p = p04; menu[5].p = p05; menu[6].p = p06; menu[7].p = p07; menu[8].p = p08; menu[9].p = p09;// Можно убрать номер пункта меню
		menu[0].nomerPunkta = 0;
		kolPunktMenu = 0;
		shapkaMenu = shapka;
		viborPunkta = 1;
		for (int i = 1; i < 10; i++)
		{
			if (menu[i].p != "")
			{
				kolPunktMenu++;
				menu[kolPunktMenu].nomerPunkta = kolPunktMenu;
				menu[kolPunktMenu].p = menu[i].p;				
			}
		}
	}

	Menu()
	{
		menu[0].p = "Выход";
		menu[0].nomerPunkta = 0;
		kolPunktMenu = 0;
	}

	bool SetTitleOfMenu(string _title)
	{
		shapkaMenu = _title;
		return true;
	}
	bool SetItemsOfMenu(string _item)
	{
		kolPunktMenu++;
		menu[kolPunktMenu].p = _item;
		menu[kolPunktMenu].nomerPunkta = kolPunktMenu;
		return true;
	}
	void otrisovkaMenu()
	{
		system("cls");
		cout << "\n\t\t =============================================================================================== \n";
		cout << "\t\t|                                                                                               |\n";
		cout << "\t\t|                                      Студенческая СУБД                                        |\n";
		cout << "\t\t|                                                           Автор: Немтенкова А.В., БАСО-03-21  |\n";
		cout << "\t\t =============================================================================================== \n";
		cout << "\n\n\n\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n";
		cout << "\t\t                                                                                                 \n";
		cout << "\t\t                                              М Е Н Ю:" << " " << shapkaMenu << "                \n";
		cout << "\t\t                                                                                                 \n";//97


		for (int i = 1; i <= kolPunktMenu; i++)
		{
			//if (menu[i].p != "")
			{

				cout << "\t\t " << menu[i].nomerPunkta << "). " << menu[i].p << "\n";
			}
		}
		cout << "\t\t " << menu[0].nomerPunkta << "). " << menu[0].p << "                                               \n";
		cout << "\t\t ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n\n";

	}

	int getVibor()
	{
		int viborGetVibor = -1;
		int viborGetVibor2 = -1;
		char viborGetViborChar[15];
		char * pTempStr = NULL;
		while ((viborGetVibor < 0) || (viborGetVibor > kolPunktMenu))
		{
			otrisovkaMenu();
			cout << "                    Ваш выбор: "; 
			pTempStr = NULL;
			cin >> viborGetViborChar;
			pTempStr = viborGetViborChar;
			viborGetVibor=(char)viborGetViborChar[0]-48;
			viborGetVibor2 = atoi(pTempStr);
			if ((viborGetVibor < 0) || (viborGetVibor > kolPunktMenu))
			{
				viborGetVibor=-1;
				cout << "\n\n\n\t ВНИМАНИЕ!!! Ошибка! Повторите, пожалуйста, ввод.\n";
				system("pause");
			}
			else
			{
				;
			}
		}
		return viborGetVibor2;
	}

protected:

};