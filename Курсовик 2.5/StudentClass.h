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
	char sex = { ' ' }; // � - �������, � - �������
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
		cout << "\n������� �������: ";
		cin >> surName;
	}
	void SetName()
	{
		cout << "\n������� ���: ";
		cin >> name;
	}
	void SetMiddleName()
	{
		cout << "\n������� ��������: ";
		cin >> middleName;
	}
	void SetFaculty()
	{
		cout << "���������: ";
		Menu* pFacul = new Menu;
		pFacul->SetTitleOfMenu("���������");
		pFacul->SetItemsOfMenu("�������� ����������������� � �������� ���������� (����)");
		pFacul->SetItemsOfMenu("�������� �������������� ���������� (���)");
		pFacul->SetItemsOfMenu("�������� �������������� ���������� (���)");
		pFacul->SetItemsOfMenu("�������� ���������������� � ����������� (���)");
		pFacul->SetItemsOfMenu("�������� ������������� ���������� � ��������������� ����������������(�����)");
		pFacul->SetItemsOfMenu("�������� ������ ���������� ���������� ��. �.�.���������� (����)");
		pFacul->SetItemsOfMenu("�������� ���������� ���������� (���)");
		(this->faculty) = pFacul->menu[pFacul->getVibor()].p;
		delete pFacul;		
	}
	void SetDepartment()
	{
		cout << "�������: ";
		Menu* pDep = new Menu;
		pDep->SetTitleOfMenu("�������");
		pDep->SetItemsOfMenu("��-1 \"������ ����������\"");
		pDep->SetItemsOfMenu("��-2");
		pDep->SetItemsOfMenu("��-3 \"���������� � ������������� ������\"");
		pDep->SetItemsOfMenu("��-4");
		(this->department) = pDep->menu[pDep->getVibor()].p;
		delete pDep;
	}
	void SetGroup()
	{
		cout << "\n������� ������: ";
		cin >> group;
	}
	void SetBirthDateString()
	{
		cout << "\n������� ���� ��������: ";
		cin >> birthDateString;
	}
	void SetSex()
	{
		cout << "\n������� ���: ";
		cin >> sex;
	}

	void SetStartYear()
	{
		startYear = foolproof("\n������� ��� ������ ��������: ", 1977, 2076);
	}
	void SetNumberZachetki()
	{
		cout << "\n������� ����� �������: ";
		cin >> numberZachetki;
	}


	void EditStudentData()
	{
		class Menu *pMenuEditStudentData=new Menu;
		pMenuEditStudentData->SetTitleOfMenu("�������������� ����� ������ \n\t\t\t"+ this->surName +" "+ this->name+" "+ this->middleName);
		pMenuEditStudentData->SetItemsOfMenu("�������");//1
		pMenuEditStudentData->SetItemsOfMenu("���");//2
		pMenuEditStudentData->SetItemsOfMenu("��������");//3
		pMenuEditStudentData->SetItemsOfMenu("���� ��������");//4
		pMenuEditStudentData->SetItemsOfMenu("���");//5
		pMenuEditStudentData->SetItemsOfMenu("����� �������� ������");//6		
		pMenuEditStudentData->SetItemsOfMenu("��� �����������");//7
		pMenuEditStudentData->SetItemsOfMenu("���������");//8
		pMenuEditStudentData->SetItemsOfMenu("�������");//9
		pMenuEditStudentData->SetItemsOfMenu("������");//10
		pMenuEditStudentData->SetItemsOfMenu("������������");//11		

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