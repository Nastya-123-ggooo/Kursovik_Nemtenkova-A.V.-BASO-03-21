#pragma once
#include <string>
#include "functions.h"
using namespace std;
struct zapisVZachetke
{
	bool zapolneno=0;// 1 - да, 0 - нет
	string disciplina="";
	int mark=0;
};

class ZachetkaClass
{
private:

public:
	string numberZachetki;//Формат: 00Б0000
	zapisVZachetke uspevaemost[10][9];
	float avrgMark;
	ZachetkaClass()
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				uspevaemost[i][j].zapolneno = 0;
				uspevaemost[i][j].disciplina = "";
				uspevaemost[i][j].mark = 0;				
			}
		}
	}

	string ChooseSubject()
	{
		class Menu* pChooseSubject = new Menu;
		pChooseSubject->SetTitleOfMenu("Выбор дисциплины");
		pChooseSubject->SetTitleOfMenu("Выбор дисциплины");
		pChooseSubject->SetItemsOfMenu("Матанализ");
		pChooseSubject->SetItemsOfMenu("Линейная алгебра");
		pChooseSubject->SetItemsOfMenu("Дискретная математика");
		pChooseSubject->SetItemsOfMenu("Физика");
		pChooseSubject->SetItemsOfMenu("Языки программирования");
		pChooseSubject->SetItemsOfMenu("Иностранный язык");
		pChooseSubject->SetItemsOfMenu("Правоведение");
		pChooseSubject->SetItemsOfMenu("История");
		pChooseSubject->SetItemsOfMenu("Физкультура");
		pChooseSubject->SetItemsOfMenu("Введение в профессиональную деятельность");
		pChooseSubject->SetItemsOfMenu("Информатика");
		pChooseSubject->SetItemsOfMenu("Основы информационной безопасности");
		//pChooseSubject->getVibor();
		int temp = pChooseSubject->getVibor();
		if (temp != 0)
		{			
			return ((pChooseSubject->menu[temp]).p);
			delete pChooseSubject;
		}
		{
			delete pChooseSubject;
			return "";
		}			
	}
	void PutMarkToFirstEmptyPos(int _numberSem, string _disciplina, int _mark)
	{
		for (int j = 0; j < 10; j++)
		{
			if (this->uspevaemost[j][_numberSem].zapolneno == 0)
			{
				this->uspevaemost[j][_numberSem].mark = _mark;
				this->uspevaemost[j][_numberSem].zapolneno = 1;
				this->uspevaemost[j][_numberSem].disciplina = _disciplina;
				AvrgMark();
				break;
			}
		}
	}

	void EditZachetka()
	{
		bool vibor = 1;
		int nuberSem = -1;
		string tempStr = "";
		cout << "\n\tВводим/редактируем данные в зачетке.";
		while (vibor)
		{
			nuberSem = foolproof("\nВведите, пожалуйста, номер (1 - 9) семестра для редактирования / добавления отметки : ", 1, 9);
			nuberSem = nuberSem - 1;
			tempStr = ChooseSubject();
			//system("pause");
			int mayak = 0;
			if (tempStr != "")
			{
				for (int j = 0; j < 10; j++)
				{
					if ((this->uspevaemost[j][nuberSem].disciplina) == tempStr)
					{
						cout << "\nДисциплина \"" << tempStr << "\" найдена.\nСтарая отметка - " << this->uspevaemost[j][nuberSem].mark;
						this->uspevaemost[j][nuberSem].mark = foolproof("\nВведите корректировку отметки : ", 0, 5);
						cout << "\nОтметка успешно скорректирована.";
						mayak++;
						AvrgMark();
					}
					else
					{

					}
				}

				if (mayak == 0)
				{
					cout << "\nДисциплина \"" << tempStr << "\" в базе за указанный семестр не найдена.";
					for (int j = 0; j < 10; j++)
					{
						if (this->uspevaemost[j][nuberSem].zapolneno == 0)
						{
							this->uspevaemost[j][nuberSem].mark = foolproof("\nВводим отметку: ", 0, 5);
							this->uspevaemost[j][nuberSem].zapolneno = 1;
							this->uspevaemost[j][nuberSem].disciplina = tempStr;
							cout << "\nОтметка успешно введена.\n";
							AvrgMark();
							break;
						}
					}
				}
			}
			else
			{
				//break;
			}
			cout<<"\nПродолжить ввод/добавление (1 - да, 0 - нет)? :";
			cin >> vibor;
		}
	}

	void AvrgMark()//Расчет средневзвешенного балла в зачетке (зачеты не учитываются)
	{
		float summMarke = 0.0;
		float quantityMarks = 0.0;
		for (int sesNumber = 0; sesNumber < 9; sesNumber++)
		{
			for (int numberDisciplina=0; numberDisciplina < 10; numberDisciplina++)
			{
				if ((this->uspevaemost[numberDisciplina][sesNumber].zapolneno != 0)&&(this->uspevaemost[numberDisciplina][sesNumber].mark != 0)&&(this->uspevaemost[numberDisciplina][sesNumber].mark != 1))
				{
					summMarke = summMarke + this->uspevaemost[numberDisciplina][sesNumber].mark;
					quantityMarks++;
				}
			}
		}
		avrgMark=summMarke/quantityMarks;
	}

protected:


};