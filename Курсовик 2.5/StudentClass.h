#pragma once
#include <string>
#include "ZachetkaClass.h"
#include "ClassMenu.h"
#include "functions.h"
using namespace std;

class StudentClass: public ZachetkaClass
{
private:


public:
	string surName;
	string name;
	string middleName;
	string faculty;
	string department;
	string group;
	string birthDateString;
	char sex = { ' ' }; // м - мужской, ж - женский
	int startYear;

	StudentClass():ZachetkaClass()
	{
		surName = "";
		name = "";
		middleName = "";
		faculty = "";
		department = "";
		group="";
		birthDateString="";
		sex = ' ';
		startYear=1900;
	}
	
	StudentClass* getStudentNode() 
	{
		return this;
	}

	void SetSurName()
	{
		cout << "\nВведите фамилию: ";
		cin >> surName;
	}
	void SetName()
	{
		cout << "\nВведите имя: ";
		cin >> name;
	}
	void SetMiddleName()
	{
		cout << "\nВведите отчество: ";
		cin >> middleName;
	}
	void SetFaculty()
	{
		cout << "Факультет: ";
		Menu* pFacul = new Menu;
		pFacul->SetTitleOfMenu("Факультет");
		pFacul->SetItemsOfMenu("Институт кибербезопасности и цифровых технологий (ИКЦТ)");
		pFacul->SetItemsOfMenu("Институт информационных технологий (ИИТ)");
		pFacul->SetItemsOfMenu("Институт искусственного интеллекта (ИИИ)");
		pFacul->SetItemsOfMenu("Институт радиоэлектроники и информатики (ИРИ)");
		pFacul->SetItemsOfMenu("Институт перспективных технологий и индустриального программирования(ИПТИП)");
		pFacul->SetItemsOfMenu("Институт тонких химических технологий им. М.В.Ломоносова (ИТХТ)");
		pFacul->SetItemsOfMenu("Институт технологий управления (ИТУ)");
		(this->faculty) = pFacul->menu[pFacul->getVibor()].p;
		delete pFacul;		
	}
	void SetDepartment()
	{
		cout << "Кафедра: ";
		Menu* pDep = new Menu;
		pDep->SetTitleOfMenu("Кафедра");
		pDep->SetItemsOfMenu("КБ-1 \"Защита информации\"");
		pDep->SetItemsOfMenu("КБ-2");
		pDep->SetItemsOfMenu("КБ-3 \"Управление и моделирование систем\"");
		pDep->SetItemsOfMenu("КБ-4");
		(this->department) = pDep->menu[pDep->getVibor()].p;
		delete pDep;
	}
	void SetGroup()
	{
		cout << "\nВведите группу: ";
		cin >> group;
	}
	void SetBirthDateString()
	{
		cout << "\nВведите дату рождения: ";
		cin >> birthDateString;
	}
	void SetSex()
	{
		cout << "\nВведите пол: ";
		cin >> sex;
	}

	void SetStartYear()
	{
		startYear = foolproof("\nВведите год начала обучения: ", 1977, 2076);
	}
	void SetNumberZachetki()
	{
		cout << "\nВведите номер зачетки: ";
		cin >> numberZachetki;
	}


	void EditStudentData()
	{
		class Menu *pMenuEditStudentData=new Menu;
		pMenuEditStudentData->SetTitleOfMenu("Редактирование полей данных \n\t\t\t"+ this->surName +" "+ this->name+" "+ this->middleName);
		pMenuEditStudentData->SetItemsOfMenu("Фамилия");//1
		pMenuEditStudentData->SetItemsOfMenu("Имя");//2
		pMenuEditStudentData->SetItemsOfMenu("Отчество");//3
		pMenuEditStudentData->SetItemsOfMenu("Дата рождения");//4
		pMenuEditStudentData->SetItemsOfMenu("Пол");//5
		pMenuEditStudentData->SetItemsOfMenu("Номер зачетной книжки");//6		
		pMenuEditStudentData->SetItemsOfMenu("Год поступления");//7
		pMenuEditStudentData->SetItemsOfMenu("Факультет");//8
		pMenuEditStudentData->SetItemsOfMenu("Кафедра");//9
		pMenuEditStudentData->SetItemsOfMenu("Группа");//10
		pMenuEditStudentData->SetItemsOfMenu("Успеваемость");//11		

		pMenuEditStudentData->viborPunkta= pMenuEditStudentData->getVibor();
		while (pMenuEditStudentData->viborPunkta)
		{
			switch (pMenuEditStudentData->viborPunkta)
			{
				case 1:
				{
					SetSurName();
					break;
				}
				case 2:
				{
					SetName();
					break;
				}
				case 3:
				{
					SetMiddleName();
					break;
				}
				case 4:
				{
					SetBirthDateString();
					break;
				}
				case 5:
				{
					SetSex();
					break;
				}
				case 6:
				{
					SetNumberZachetki();
					break;
				}
				case 7:
				{
					SetStartYear();
					break;
				}
				case 8:
				{
					SetFaculty();
					break;
				}
				case 9:
				{
					SetDepartment();
					break;
				}
				case 10:
				{
					SetGroup();
					break;
				}
				case 11:
				{
					EditZachetka();
					break;
				}
			}
			pMenuEditStudentData->viborPunkta = pMenuEditStudentData->getVibor();
		}
	}
};