#include <iostream>
#include <windows.h>
#include "ClassMenu.h"
#include <string>
#include "FileManagerClass.h"
#include "DataBaseOfStudents.h"
DataBaseOfStudents* pDbs=NULL;
string fileNameSet = "dataBaseOfStudents.txt";
using namespace std;

StudentClass* SelectionStudents()
{
	class Menu* pEdite = new Menu;
	pEdite->SetTitleOfMenu("Редактирование данных студента");
	string str;
	StudentClass* tempMass[1111];
	int k = 0;
	for (int i = 0; i < 1111; i++)
	{
		if ((pDbs->DataBaseOfStudentsMassiv[i]) != NULL)
		{
			str = "";
			str = pDbs->DataBaseOfStudentsMassiv[i]->surName + " " + pDbs->DataBaseOfStudentsMassiv[i]->name + " " + pDbs->DataBaseOfStudentsMassiv[i]->middleName + ", " + pDbs->DataBaseOfStudentsMassiv[i]->group;
			pEdite->SetItemsOfMenu(str);
			tempMass[k] = (pDbs->DataBaseOfStudentsMassiv[i]);
			k++;
		}
	}
	
	pEdite->viborPunkta = pEdite->getVibor();

	if (pEdite->viborPunkta != 0)
	{		
		int temp = pEdite->viborPunkta;
		delete pEdite;
		return tempMass[temp -1];		
	}
	else
	{
		delete pEdite;
		return NULL;		
	}	
	cout << "Удаление меню студентов"; 
	system("pause");	
}


int main()
{
	SetConsoleCP(1251); SetConsoleOutputCP(1251); system("cls");
	class Menu m0("ГЛАВНОЕ", "", "", "Работа с файлом", "Работа с БД", "", "", "", "", "");
	
	class Menu m01;
	m01.SetTitleOfMenu(m0.menu[1].p);
	m01.SetItemsOfMenu("Сохранить БД в новый файл");
	m01.SetItemsOfMenu("Сохранить БД в файл по умолчанию");
	m01.SetItemsOfMenu("Загрузить данные из файла по умолчанию");
	m01.SetItemsOfMenu("Загрузить данные из файла по указанному пути");

	class Menu m02(m0.menu[2].p, "Просмотр БД", "Добавить студента(-ов) в БД", "Редактировать данные студента", "", "", "", "", "", "Выборка по варианту №50");
	
	class Menu m023;
	m023.SetTitleOfMenu("Редактировать данные студента");
	m023.SetItemsOfMenu("Редактировать данные студента");
	m023.SetItemsOfMenu("Удалить студента из БД");

	pDbs = new DataBaseOfStudents;//Создание БД

	int tekVibor = 1;

	while (m0.viborPunkta != 0)
	{
		m0.viborPunkta = m0.getVibor();
		switch (m0.viborPunkta)
		{
		case 1:
		{
			while ((m01.viborPunkta = m01.getVibor()) != 0)
			{
				switch (m01.viborPunkta)
				{
				case 1:
				{
					char ch = ' ';
					string fileNameSet ="";
					cout << "\nВведите, пожалуйста, полный путь к файлу: ";
					cin.get();
					for (int i = 0; (ch = cin.get()) != '\n'; i++)
					{
						fileNameSet = fileNameSet + ch;
					}
					pDbs->SaveDataToFile(fileNameSet);
					break;
				}
				case 2:
				{
					pDbs->SaveDataToFile(fileNameSet);
					Crypt();
					break;
				}
				case 3:
				{
					Decrypt();
					pDbs->ReadDataFromFile(fileNameSet);
					Crypt();
					break;
				}
				case 4:
				{
					char ch = ' ';
					string fileNameSet = "";
					cout << "\nВведите, пожалуйста, полный путь к файлу: ";
					cin.get();
					for (int i = 0; (ch = cin.get()) != '\n'; i++)
					{
						fileNameSet = fileNameSet + ch;
					}
					pDbs->ReadDataFromFile(fileNameSet);
					break;
				}
				
				case 5://Резерв
				{
					negotovPunkt();
					break;
				}

				default:
				{
					m01.viborPunkta = 0;
					break;
				}
				}
			}
			break;
		}

		case 2:
		{
			while ((m02.viborPunkta = m02.getVibor()) != 0)
			{
				switch (m02.viborPunkta)
				{
				case 1:
				{
					pDbs->DisplayStudent();
					break;
				}
				case 2:
				{
					pDbs->AddStudent();
					system("pause");
					break;
				}
				case 3:
				{
					m023.viborPunkta = m023.getVibor();
					while (m023.viborPunkta != 0)
					{
						switch (m023.viborPunkta)
						{
						case 1:
							{
								StudentClass* studForChange = SelectionStudents();
								if (studForChange != NULL)
								{
									studForChange->EditStudentData();
								}
								else
								{
									;
								}
								break;
							}
						case 2:
							{
								StudentClass *studDel = SelectionStudents();
								if (studDel !=NULL)
								{
								
									for (int i = 0; i < 1111; i++)
									{
										if ((pDbs->DataBaseOfStudentsMassiv[i]) == studDel)
										{
											(pDbs->DataBaseOfStudentsMassiv[i]) =NULL;
										}
									}
									delete studDel;
								}
								else
								{
									;
								}
								break;
							}
						}
						m023.viborPunkta = m023.getVibor();
					}
					break;
				}
				case 4:
				{	
					pDbs->Variant50();
					break;
				}
				case 5:
				{
					negotovPunkt();
					break;
				}

				default:
				{
					m02.viborPunkta = 0;
					break;
				}
				}
			}
			break;
		}
		}
	}
	cout << "\nДеструктор отработал. БД в ОЗУ уничтожена, резервирование ОЗУ снято.\n";
}