#pragma once
#include <string>
#include "functions.h"
using namespace std;
struct zapisVZachetke
{
	bool zapolneno=0;// 1 - ��, 0 - ���
	string disciplina="";
	int mark=0;
};

class ZachetkaClass
{
private:

public:
	string numberZachetki;//������: 00�0000
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
		pChooseSubject->SetTitleOfMenu("����� ����������");
		pChooseSubject->SetTitleOfMenu("����� ����������");
		pChooseSubject->SetItemsOfMenu("���������");
		pChooseSubject->SetItemsOfMenu("�������� �������");
		pChooseSubject->SetItemsOfMenu("���������� ����������");
		pChooseSubject->SetItemsOfMenu("������");
		pChooseSubject->SetItemsOfMenu("����� ����������������");
		pChooseSubject->SetItemsOfMenu("����������� ����");
		pChooseSubject->SetItemsOfMenu("������������");
		pChooseSubject->SetItemsOfMenu("�������");
		pChooseSubject->SetItemsOfMenu("�����������");
		pChooseSubject->SetItemsOfMenu("�������� � ���������������� ������������");
		pChooseSubject->SetItemsOfMenu("�����������");
		pChooseSubject->SetItemsOfMenu("������ �������������� ������������");
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
		cout << "\n\t������/����������� ������ � �������.";
		while (vibor)
		{
			nuberSem = foolproof("\n�������, ����������, ����� (1 - 9) �������� ��� �������������� / ���������� ������� : ", 1, 9);
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
						cout << "\n���������� \"" << tempStr << "\" �������.\n������ ������� - " << this->uspevaemost[j][nuberSem].mark;
						this->uspevaemost[j][nuberSem].mark = foolproof("\n������� ������������� ������� : ", 0, 5);
						cout << "\n������� ������� ���������������.";
						mayak++;
						AvrgMark();
					}
					else
					{

					}
				}

				if (mayak == 0)
				{
					cout << "\n���������� \"" << tempStr << "\" � ���� �� ��������� ������� �� �������.";
					for (int j = 0; j < 10; j++)
					{
						if (this->uspevaemost[j][nuberSem].zapolneno == 0)
						{
							this->uspevaemost[j][nuberSem].mark = foolproof("\n������ �������: ", 0, 5);
							this->uspevaemost[j][nuberSem].zapolneno = 1;
							this->uspevaemost[j][nuberSem].disciplina = tempStr;
							cout << "\n������� ������� �������.\n";
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
			cout<<"\n���������� ����/���������� (1 - ��, 0 - ���)? :";
			cin >> vibor;
		}
	}

	void AvrgMark()//������ ����������������� ����� � ������� (������ �� �����������)
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