#pragma once
#include "StudentClass.h"
#include <string>
#include <iostream>
#include <fstream>
//#include <vector>

class DataBaseOfStudents: public StudentClass 
{
private:

public:
	StudentClass *DataBaseOfStudentsMassiv[1111];
	int nextFreePosition;
	int currentPosition;
	int temp;
	DataBaseOfStudents()
	{
		nextFreePosition = 0;
		currentPosition = 0;
		for (int i = 0; i < 1111; i++)
		{
			DataBaseOfStudentsMassiv[i] = NULL;
		}
		//AddStatikStudent();//����� �����������������, ���� ����� ��������
	}
	~DataBaseOfStudents()
	{
		for (int i = 0; i < 1000; i++)
		{
			delete DataBaseOfStudentsMassiv[i];
			system("pause");
		}
	}
	void AddStudent()
	{
		nextFreePosition = FindFreePositionInBase();
		currentPosition = nextFreePosition;
		//nextFreePosition++;
		//string tempStr = "";
		DataBaseOfStudentsMassiv[currentPosition] = new StudentClass;
		
		system("cls");
		cout << "\n�������, ����������, ������ �� ��������.\n\n";
				
		cout << "�������: ";
		cin >> DataBaseOfStudentsMassiv[currentPosition]->surName;
		
		cout << "���: ";
		cin >> DataBaseOfStudentsMassiv[currentPosition]->name;

		cout << "��������: ";
		cin >> DataBaseOfStudentsMassiv[currentPosition]->middleName;

		cout << "���� ��������: ";
		cin >> DataBaseOfStudentsMassiv[currentPosition]->birthDateString;

		cout << "��� (� - �������, � - �������): ";
		cin >> DataBaseOfStudentsMassiv[currentPosition]->sex;

		DataBaseOfStudentsMassiv[currentPosition]->SetStartYear();
		//cout << "��� ������ ��������: ";
		//cin >> DataBaseOfStudentsMassiv[currentPosition]->startYear;
		
		cout << "����� �������: ";
		cin >> DataBaseOfStudentsMassiv[currentPosition]->numberZachetki;

		DataBaseOfStudentsMassiv[currentPosition]->SetFaculty();

		DataBaseOfStudentsMassiv[currentPosition]->SetDepartment();

		DataBaseOfStudentsMassiv[currentPosition]->SetGroup();
		
		//AddDataToZachetka(currentPosition);
		DataBaseOfStudentsMassiv[currentPosition]->EditZachetka();
	}

	bool DisplayZachetkaOfStudent(StudentClass* _student)
	{
		int zapoSubjects = 0;
		//_student->AvrgMark();
		printf_s("\n���������������� ���� �������� ����� : %.2f", _student->avrgMark);
		//cout << "\n���������������� ���� �������� �����: " << _student->avrgMark;		
		for (int sem = 0; sem < 9; sem++)
		{
		cout << "\n\n\t������ �" << sem + 1;//sem
			for (int subj = 0; subj < 10; subj++)
			{				
				if (_student->uspevaemost[subj][sem].zapolneno!=0)
				{
					zapoSubjects++;
					cout <<"\n\t\t" << _student->uspevaemost[subj][sem].disciplina << " - " << _student->uspevaemost[subj][sem].mark << ";\t";
				}
			}
			cout << "\n\n\t**************************************************************";
		}
		if (zapoSubjects == 0)
		{
			cout << "\n� ���������, ��� �� ����� ����������� ������ �� �������� " << _student->surName << " " << _student->name << " " << _student->middleName;
			return 0;
		}
		else
		{
			return 1;
		}
	}

	void DisplayStudent()
	{
		cout << "\n� ��������� ����� � �� ������� ��������� ������:\n\n";		
		for (int i = 0; i < 1111; i++)
		{
			if (DataBaseOfStudentsMassiv[i] != NULL)
			{
				cout << "\n\t�"<< i + 1;
				cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
				cout << "\n�������: "<< DataBaseOfStudentsMassiv[i]->surName;
				cout << "\n���: "<< DataBaseOfStudentsMassiv[i]->name;
				cout << "\n��������: "<< DataBaseOfStudentsMassiv[i]->middleName;
				cout << "\n���� ��������: "<< DataBaseOfStudentsMassiv[i]->birthDateString;
				cout << "\n���: " << DataBaseOfStudentsMassiv[i]->sex;
				cout << "\n��� ������ ��������: "<< DataBaseOfStudentsMassiv[i]->startYear;
				cout << "\n����� �������: "<< DataBaseOfStudentsMassiv[i]->numberZachetki;
				cout << "\n���������: "<< DataBaseOfStudentsMassiv[i]->faculty;
				cout << "\n�������: " << DataBaseOfStudentsMassiv[i]->department; 
								
				cout << "\n������: "<< DataBaseOfStudentsMassiv[i]->group;
				DisplayZachetkaOfStudent(DataBaseOfStudentsMassiv[i]);
				
				cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			}
		}		
		system("pause");
	}

	void AddStatikStudent()//��������� ��������� (��������, ���� �� ������� �������)
	{
		//������� �1
		DataBaseOfStudentsMassiv[currentPosition] = new StudentClass;
		currentPosition = nextFreePosition;
		nextFreePosition++;

		//cout << "�������: ";
		DataBaseOfStudentsMassiv[currentPosition]->surName="�������";

		//cout << "���: ";
		DataBaseOfStudentsMassiv[currentPosition]->name="����";

		//cout << "��������: ";
		DataBaseOfStudentsMassiv[currentPosition]->middleName="���������";
		//cout << "���� ��������: ";
		DataBaseOfStudentsMassiv[currentPosition]->birthDateString="01.01.2001";
		//cout << "��� (� - �������, � - �������): ";
		DataBaseOfStudentsMassiv[currentPosition]->sex='�';

		//cout << "��� ������ ��������: ";
		DataBaseOfStudentsMassiv[currentPosition]->startYear=2021;

		//cout << "����� �������: ";
		DataBaseOfStudentsMassiv[currentPosition]->numberZachetki="21�0125";

		(DataBaseOfStudentsMassiv[currentPosition]->faculty) = "��-1 \"������ ����������\"";

		(DataBaseOfStudentsMassiv[currentPosition]->department) = "�������� ����������������� � �������� ���������� (����)";
		//delete pDep;
		//cout << "������: ";
		DataBaseOfStudentsMassiv[currentPosition]->group="����-03-21";

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[0][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[0][0]).disciplina = "�������� �������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[0][0]).mark = 5;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[1][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[1][0]).disciplina = "������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[1][0]).mark = 5;


		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[2][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[2][0]).disciplina = "�������� � ���������������� ������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[2][0]).mark = 4;


		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[3][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[3][0]).disciplina = "����� ����������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[3][0]).mark = 1;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[4][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[4][0]).disciplina = "���������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[4][0]).mark = 4;


		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[5][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[5][0]).disciplina = "������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[5][0]).mark = 1;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[6][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[6][0]).disciplina = "�����������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[6][0]).mark = 4;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[7][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[7][0]).disciplina = "������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[7][0]).mark = 5;

		//2-�� �������
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[0][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[0][1]).disciplina = "�������� �������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[0][1]).mark = 4;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[1][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[1][1]).disciplina = "������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[1][1]).mark = 4;


		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[2][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[2][1]).disciplina = "�������� � ���������������� ������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[2][1]).mark = 3;


		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[3][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[3][1]).disciplina = "����� ����������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[3][1]).mark = 1;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[4][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[4][1]).disciplina = "���������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[4][1]).mark = 5;


		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[5][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[5][1]).disciplina = "������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[5][1]).mark = 1;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[6][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[6][1]).disciplina = "�����������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[6][1]).mark = 4;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[7][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[7][1]).disciplina = "������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[7][1]).mark = 5;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[8][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[8][1]).disciplina = "����� ����������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[8][1]).mark = 5;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[9][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[9][1]).disciplina = "����������� ����";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[9][1]).mark = 5;

		//������� �2		
		currentPosition = nextFreePosition;
		nextFreePosition++;
		DataBaseOfStudentsMassiv[currentPosition] = new StudentClass;

		//cout << "�������: ";
		DataBaseOfStudentsMassiv[currentPosition]->surName = "������-������";

		//cout << "���: ";
		DataBaseOfStudentsMassiv[currentPosition]->name = "����";

		//cout << "��������: ";
		DataBaseOfStudentsMassiv[currentPosition]->middleName = "����������";
		//cout << "���� ��������: ";
		DataBaseOfStudentsMassiv[currentPosition]->birthDateString = "02.02.2002";
		//cout << "��� (� - �������, � - �������): ";
		DataBaseOfStudentsMassiv[currentPosition]->sex = '�';

		//cout << "��� ������ ��������: ";
		DataBaseOfStudentsMassiv[currentPosition]->startYear = 2021;

		//cout << "����� �������: ";
		DataBaseOfStudentsMassiv[currentPosition]->numberZachetki = "21�0127";

		(DataBaseOfStudentsMassiv[currentPosition]->faculty) = "�������� ������������� ���������� � ��������������� ����������������(�����)";

		(DataBaseOfStudentsMassiv[currentPosition]->department) = "�� - 3 \"���������� � ������������� ������\"";

		DataBaseOfStudentsMassiv[currentPosition]->group = "����-03-21";

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[0][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[0][0]).disciplina = "�������� �������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[0][0]).mark = 5;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[1][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[1][0]).disciplina = "������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[1][0]).mark = 5;


		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[2][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[2][0]).disciplina = "�������� � ���������������� ������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[2][0]).mark = 5;


		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[3][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[3][0]).disciplina = "����� ����������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[3][0]).mark = 1;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[4][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[4][0]).disciplina = "���������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[4][0]).mark = 5;


		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[5][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[5][0]).disciplina = "������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[5][0]).mark = 1;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[6][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[6][0]).disciplina = "�����������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[6][0]).mark = 4;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[7][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[7][0]).disciplina = "������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[7][0]).mark = 5;

		//2-�� �������
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[0][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[0][1]).disciplina = "�������� �������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[0][1]).mark = 4;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[1][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[1][1]).disciplina = "������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[1][1]).mark = 4;


		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[2][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[2][1]).disciplina = "�������� � ���������������� ������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[2][1]).mark = 3;


		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[3][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[3][1]).disciplina = "����� ����������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[3][1]).mark = 1;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[4][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[4][1]).disciplina = "���������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[4][1]).mark = 5;


		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[5][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[5][1]).disciplina = "������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[5][1]).mark = 1;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[6][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[6][1]).disciplina = "�����������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[6][1]).mark = 4;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[7][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[7][1]).disciplina = "������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[7][1]).mark = 5;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[8][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[8][1]).disciplina = "����� ����������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[8][1]).mark = 5;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[9][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[9][1]).disciplina = "����������� ����";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[9][1]).mark = 5;


		//������� �3
		currentPosition = nextFreePosition;
		nextFreePosition++;
		DataBaseOfStudentsMassiv[currentPosition] = new StudentClass;

		//cout << "�������: ";
		DataBaseOfStudentsMassiv[currentPosition]->surName = "�����";

		//cout << "���: ";
		DataBaseOfStudentsMassiv[currentPosition]->name = "����������";

		//cout << "��������: ";
		DataBaseOfStudentsMassiv[currentPosition]->middleName = "������������";

		//cout << "���� ��������: ";
		DataBaseOfStudentsMassiv[currentPosition]->birthDateString = "03.03.2003";

		//cout << "��� (� - �������, � - �������): ";
		DataBaseOfStudentsMassiv[currentPosition]->sex = '�';

		//cout << "��� ������ ��������: ";
		DataBaseOfStudentsMassiv[currentPosition]->startYear = 2020;

		//cout << "����� �������: ";
		DataBaseOfStudentsMassiv[currentPosition]->numberZachetki = "21�0787";

		(DataBaseOfStudentsMassiv[currentPosition]->faculty) = "�������� �������������� ���������� (���)";

		(DataBaseOfStudentsMassiv[currentPosition]->department) = "�� - 4 ";

		DataBaseOfStudentsMassiv[currentPosition]->group = "����-03-21";

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[0][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[0][0]).disciplina = "�������� �������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[0][0]).mark = 5;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[1][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[1][0]).disciplina = "������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[1][0]).mark = 3;


		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[2][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[2][0]).disciplina = "�������� � ���������������� ������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[2][0]).mark = 3;


		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[3][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[3][0]).disciplina = "����� ����������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[3][0]).mark = 1;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[4][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[4][0]).disciplina = "���������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[4][0]).mark = 4;


		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[5][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[5][0]).disciplina = "������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[5][0]).mark = 1;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[6][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[6][0]).disciplina = "�����������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[6][0]).mark = 4;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[7][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[7][0]).disciplina = "������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[7][0]).mark = 5;

		//2-�� �������
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[0][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[0][1]).disciplina = "�������� �������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[0][1]).mark = 4;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[1][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[1][1]).disciplina = "������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[1][1]).mark = 4;


		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[2][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[2][1]).disciplina = "�������� � ���������������� ������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[2][1]).mark = 3;


		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[3][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[3][1]).disciplina = "����� ����������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[3][1]).mark = 1;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[4][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[4][1]).disciplina = "���������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[4][1]).mark = 5;


		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[5][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[5][1]).disciplina = "������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[5][1]).mark = 1;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[6][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[6][1]).disciplina = "�����������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[6][1]).mark = 4;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[7][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[7][1]).disciplina = "������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[7][1]).mark = 5;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[8][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[8][1]).disciplina = "����� ����������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[8][1]).mark = 5;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[9][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[9][1]).disciplina = "����������� ����";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[9][1]).mark = 5;

		//������� �4
		currentPosition = nextFreePosition;
		nextFreePosition++;
		DataBaseOfStudentsMassiv[currentPosition] = new StudentClass;

		//cout << "�������: ";
		DataBaseOfStudentsMassiv[currentPosition]->surName = "��������";

		//cout << "���: ";
		DataBaseOfStudentsMassiv[currentPosition]->name = "�������";

		//cout << "��������: ";
		DataBaseOfStudentsMassiv[currentPosition]->middleName = "��������";

		//cout << "���� ��������: ";
		DataBaseOfStudentsMassiv[currentPosition]->birthDateString = "04.04.2004";

		//cout << "��� (� - �������, � - �������): ";
		DataBaseOfStudentsMassiv[currentPosition]->sex = '�';

		//cout << "��� ������ ��������: ";
		DataBaseOfStudentsMassiv[currentPosition]->startYear = 2019;

		//cout << "����� �������: ";
		DataBaseOfStudentsMassiv[currentPosition]->numberZachetki = "19�0223";

		(DataBaseOfStudentsMassiv[currentPosition]->faculty) = "�������� ������������� ���������� � ��������������� ����������������(�����)";
		
		(DataBaseOfStudentsMassiv[currentPosition]->department) = "�� - 3 \"���������� � ������������� ������\"";

		DataBaseOfStudentsMassiv[currentPosition]->group = "����-01-19";

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[0][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[0][0]).disciplina = "�������� �������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[0][0]).mark = 3;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[1][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[1][0]).disciplina = "������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[1][0]).mark = 4;


		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[2][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[2][0]).disciplina = "�������� � ���������������� ������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[2][0]).mark = 3;


		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[3][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[3][0]).disciplina = "����� ����������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[3][0]).mark = 1;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[4][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[4][0]).disciplina = "���������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[4][0]).mark = 5;


		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[5][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[5][0]).disciplina = "������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[5][0]).mark = 1;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[6][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[6][0]).disciplina = "�����������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[6][0]).mark = 5;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[7][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[7][0]).disciplina = "������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[7][0]).mark = 3;

		//2-�� �������
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[0][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[0][1]).disciplina = "�������� �������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[0][1]).mark = 5;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[1][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[1][1]).disciplina = "������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[1][1]).mark = 4;


		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[2][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[2][1]).disciplina = "�������� � ���������������� ������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[2][1]).mark = 3;


		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[3][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[3][1]).disciplina = "����� ����������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[3][1]).mark = 1;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[4][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[4][1]).disciplina = "���������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[4][1]).mark = 5;


		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[5][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[5][1]).disciplina = "������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[5][1]).mark = 1;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[6][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[6][1]).disciplina = "�����������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[6][1]).mark = 4;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[7][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[7][1]).disciplina = "������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[7][1]).mark = 4;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[8][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[8][1]).disciplina = "����� ����������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[8][1]).mark = 4;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[9][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[9][1]).disciplina = "����������� ����";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[9][1]).mark = 5;

		//������� �5
		currentPosition = nextFreePosition;
		nextFreePosition++;
		DataBaseOfStudentsMassiv[currentPosition] = new StudentClass;

		//cout << "�������: ";
		DataBaseOfStudentsMassiv[currentPosition]->surName = "������";

		//cout << "���: ";
		DataBaseOfStudentsMassiv[currentPosition]->name = "����������";

		//cout << "��������: ";
		DataBaseOfStudentsMassiv[currentPosition]->middleName = "����������";

		//cout << "���� ��������: ";
		DataBaseOfStudentsMassiv[currentPosition]->birthDateString = "05.05.2005";

		//cout << "��� (� - �������, � - �������): ";
		DataBaseOfStudentsMassiv[currentPosition]->sex = '�';

		DataBaseOfStudentsMassiv[currentPosition]->startYear = 2021;
		DataBaseOfStudentsMassiv[currentPosition]->numberZachetki = "21�0129";

		(DataBaseOfStudentsMassiv[currentPosition]->faculty) = "�������� ������������� ���������� � ��������������� ����������������(�����)";
		(DataBaseOfStudentsMassiv[currentPosition]->department) = "�� - 3 \"���������� � ������������� ������\"";

		DataBaseOfStudentsMassiv[currentPosition]->group = "����-03-21";

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[0][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[0][0]).disciplina = "�������� �������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[0][0]).mark = 3;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[1][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[1][0]).disciplina = "������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[1][0]).mark = 3;


		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[2][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[2][0]).disciplina = "�������� � ���������������� ������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[2][0]).mark = 3;


		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[3][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[3][0]).disciplina = "����� ����������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[3][0]).mark = 1;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[4][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[4][0]).disciplina = "���������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[4][0]).mark = 5;


		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[5][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[5][0]).disciplina = "������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[5][0]).mark = 1;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[6][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[6][0]).disciplina = "�����������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[6][0]).mark = 4;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[7][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[7][0]).disciplina = "������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[7][0]).mark = 5;

		//2-�� �������
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[0][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[0][1]).disciplina = "�������� �������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[0][1]).mark = 4;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[1][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[1][1]).disciplina = "������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[1][1]).mark = 4;


		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[2][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[2][1]).disciplina = "�������� � ���������������� ������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[2][1]).mark = 3;


		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[3][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[3][1]).disciplina = "����� ����������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[3][1]).mark = 1;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[4][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[4][1]).disciplina = "���������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[4][1]).mark = 5;


		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[5][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[5][1]).disciplina = "������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[5][1]).mark = 1;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[6][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[6][1]).disciplina = "�����������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[6][1]).mark = 4;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[7][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[7][1]).disciplina = "������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[7][1]).mark = 5;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[8][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[8][1]).disciplina = "����� ����������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[8][1]).mark = 5;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[9][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[9][1]).disciplina = "����������� ����";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[9][1]).mark = 5;


		//������� �6
		currentPosition = nextFreePosition;
		nextFreePosition++;
		DataBaseOfStudentsMassiv[currentPosition] = new StudentClass;

		//cout << "�������: ";
		DataBaseOfStudentsMassiv[currentPosition]->surName = "������";

		//cout << "���: ";
		DataBaseOfStudentsMassiv[currentPosition]->name = "�����";

		//cout << "��������: ";
		DataBaseOfStudentsMassiv[currentPosition]->middleName = "��������";

		//cout << "���� ��������: ";
		DataBaseOfStudentsMassiv[currentPosition]->birthDateString = "06.06.2006";

		//cout << "��� (� - �������, � - �������): ";
		DataBaseOfStudentsMassiv[currentPosition]->sex = '�';

		DataBaseOfStudentsMassiv[currentPosition]->startYear = 2021;
		DataBaseOfStudentsMassiv[currentPosition]->numberZachetki = "21�0123";

		(DataBaseOfStudentsMassiv[currentPosition]->faculty) = "�������� ������������� ���������� � ��������������� ����������������(�����)";
		(DataBaseOfStudentsMassiv[currentPosition]->department) = "�� - 3 \"���������� � ������������� ������\"";

		DataBaseOfStudentsMassiv[currentPosition]->group = "����-03-21";

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[0][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[0][0]).disciplina = "�������� �������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[0][0]).mark = 4;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[1][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[1][0]).disciplina = "������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[1][0]).mark = 4;


		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[2][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[2][0]).disciplina = "�������� � ���������������� ������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[2][0]).mark = 5;


		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[3][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[3][0]).disciplina = "����� ����������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[3][0]).mark = 1;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[4][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[4][0]).disciplina = "���������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[4][0]).mark = 3;


		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[5][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[5][0]).disciplina = "������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[5][0]).mark = 1;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[6][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[6][0]).disciplina = "�����������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[6][0]).mark = 3;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[7][0]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[7][0]).disciplina = "������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[7][0]).mark = 5;

		//2-�� �������
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[0][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[0][1]).disciplina = "�������� �������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[0][1]).mark = 5;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[1][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[1][1]).disciplina = "������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[1][1]).mark = 3;


		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[2][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[2][1]).disciplina = "�������� � ���������������� ������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[2][1]).mark = 5;


		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[3][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[3][1]).disciplina = "����� ����������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[3][1]).mark = 1;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[4][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[4][1]).disciplina = "���������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[4][1]).mark = 5;


		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[5][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[5][1]).disciplina = "������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[5][1]).mark = 1;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[6][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[6][1]).disciplina = "�����������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[6][1]).mark = 5;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[7][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[7][1]).disciplina = "������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[7][1]).mark = 5;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[8][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[8][1]).disciplina = "����� ����������������";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[8][1]).mark = 4;

		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[9][1]).zapolneno = 1;
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[9][1]).disciplina = "����������� ����";
		(DataBaseOfStudentsMassiv[currentPosition]->uspevaemost[9][1]).mark = 4;
	}	


	void Variant50()
	{		
		struct oneYearStud
		{
			int yearPostupl;
			int nextPos;
			bool isFree;
			StudentClass* studentsOneYear[1111];
		};
		oneYearStud *DataBaseOfStudentsMassivForVariant50 = new  oneYearStud[101];
		//oneYearStud DataBaseOfStudentsMassivForVariant50[100];
		StudentClass* pTempStudent=NULL;
		for (int i = 0; i < 101; i++)
		{
			DataBaseOfStudentsMassivForVariant50[i].yearPostupl = (1976 + i);
			//cout << "\n\t�����   : " << DataBaseOfStudentsMassivForVariant50[i].yearPostupl;
			DataBaseOfStudentsMassivForVariant50[i].nextPos = 0;
			DataBaseOfStudentsMassivForVariant50[i].isFree = 1;
			for (int j = 0; j < 1111; j++)
			{
				DataBaseOfStudentsMassivForVariant50[i].studentsOneYear[j] = NULL;
			}
		}
		DataBaseOfStudentsMassivForVariant50[0].yearPostupl = 0;
		DataBaseOfStudentsMassivForVariant50[0].nextPos = 0;
		for (int i = 1; i < 101; i++)
		{
			for (int j = 0; j < 1111; j++)
			{								
				if (DataBaseOfStudentsMassiv[j]!=NULL)
				{					
					if (i == 1)
					{
						DataBaseOfStudentsMassiv[j]->AvrgMark();
					}					
					if ((DataBaseOfStudentsMassivForVariant50[i].yearPostupl) == (DataBaseOfStudentsMassiv[j]->startYear))
					{				
						DataBaseOfStudentsMassivForVariant50[i].studentsOneYear[DataBaseOfStudentsMassivForVariant50[i].nextPos] = DataBaseOfStudentsMassiv[j];
						DataBaseOfStudentsMassivForVariant50[i].nextPos++;
						DataBaseOfStudentsMassivForVariant50[i].isFree = 0;	
					}
				}
			}
		}
		
		for (int i = 1; i < 101; i++)
		{		
			if (((DataBaseOfStudentsMassivForVariant50[i].nextPos)-1) == 0)
			{
				DataBaseOfStudentsMassivForVariant50[0].studentsOneYear[DataBaseOfStudentsMassivForVariant50[0].nextPos] = DataBaseOfStudentsMassivForVariant50[i].studentsOneYear[0]; //DataBaseOfStudentsMassiv[j];
				DataBaseOfStudentsMassivForVariant50[0].nextPos++;
				DataBaseOfStudentsMassivForVariant50[0].isFree = 0;
				DataBaseOfStudentsMassivForVariant50[i].isFree = 1;
			}
		}
		
		
		for (int i = 0; i < 101; i++)
		{
			if (DataBaseOfStudentsMassivForVariant50[i].isFree == 0)
			{
				for (int j = 0; j < 1111; j++)
				{
					for (int k = j+1; k < 1111; k++)
					{
						if ((DataBaseOfStudentsMassivForVariant50[i].studentsOneYear[k]!=NULL) && (DataBaseOfStudentsMassivForVariant50[i].studentsOneYear[j] != NULL))  //					if ((DataBaseOfStudentsMassiv[j] != NULL)&& (DataBaseOfStudentsMassiv[k] != NULL) && (DataBaseOfStudentsMassivForVariant50[i].studentsOneYear[k]!=NULL) && (DataBaseOfStudentsMassivForVariant50[i].studentsOneYear[j] != NULL))
						{
							if ((DataBaseOfStudentsMassivForVariant50[i].studentsOneYear[j]->avrgMark) > (DataBaseOfStudentsMassivForVariant50[i].studentsOneYear[k]->avrgMark))
							{
								pTempStudent = DataBaseOfStudentsMassivForVariant50[i].studentsOneYear[j];
								DataBaseOfStudentsMassivForVariant50[i].studentsOneYear[j] = DataBaseOfStudentsMassivForVariant50[i].studentsOneYear[k];
								DataBaseOfStudentsMassivForVariant50[i].studentsOneYear[k] = pTempStudent;
							}							
						}
					}
				}
			}
		}
		
		cout << "\n������� ���������, ����������� � ���� ���, �� ������������ (������������ �� �����������) \n";
		for (int i = 1; i < 101; i++)
		{
			if ((DataBaseOfStudentsMassivForVariant50[i].isFree) == 0)
			{
				cout << "\n\t**************************************************************************************";
				cout << "\n\t��� ����������� � ���: " << DataBaseOfStudentsMassivForVariant50[i].yearPostupl << " �.";
			}
			for (int j = 0; j < 1111; j++)
			{
				if ((DataBaseOfStudentsMassivForVariant50[i].isFree) == 0)
				{
					if (DataBaseOfStudentsMassivForVariant50[i].studentsOneYear[j] != NULL)
					{
						cout << "\n\t\t" << DataBaseOfStudentsMassivForVariant50[i].studentsOneYear[j]->surName << " " << DataBaseOfStudentsMassivForVariant50[i].studentsOneYear[j]->name << " " << DataBaseOfStudentsMassivForVariant50[i].studentsOneYear[j]->middleName << ", " << DataBaseOfStudentsMassivForVariant50[i].studentsOneYear[j]->group;
						printf_s("; �������: %.2f", DataBaseOfStudentsMassivForVariant50[i].studentsOneYear[j]->avrgMark);						
					}
				}
			}			
		}
		for (int j = 0; j < 1111; j++)
		{
			if ((DataBaseOfStudentsMassivForVariant50[0].isFree) == 0)
			{
				if (DataBaseOfStudentsMassivForVariant50[0].studentsOneYear[j] != NULL)
				{
					if (j == 0)
					{
						cout << "\n\n\n\n������� ���������, ����������� � ���� ������ ����, �� ������������ (������������ �� �����������)\n";
						cout << "\n        ********************************************************************************************\n";
					}
					cout << "\n\t\t" << DataBaseOfStudentsMassivForVariant50[0].studentsOneYear[j]->surName << " " << DataBaseOfStudentsMassivForVariant50[0].studentsOneYear[j]->name << " " << DataBaseOfStudentsMassivForVariant50[0].studentsOneYear[j]->middleName << ", " << DataBaseOfStudentsMassivForVariant50[0].studentsOneYear[j]->group;
					printf_s("; �������: %.2f", DataBaseOfStudentsMassivForVariant50[0].studentsOneYear[j]->avrgMark);
					cout << ", ��� �����������: " << DataBaseOfStudentsMassivForVariant50[0].studentsOneYear[j]->startYear;
				}
			}
		}
		cout << "\n\n";
		system("pause");
		delete DataBaseOfStudentsMassivForVariant50;

	}

	/*
	void Variant50_2()
	{
		struct oneYearStud
		{
			int yearPostupl;
			//int nextPos;
			int size=0;
			vector<StudentClass*> oneYearStudVector;
			//StudentClass* studentsOneYear[1111];
		};
		vector<oneYearStud> groupingByYear(1);

		//oneYearStud* DataBaseOfStudentsMassivForVariant50 = new  oneYearStud[101];
		//oneYearStud DataBaseOfStudentsMassivForVariant50[100];
		StudentClass* pTempStudent = NULL;
		/*
		for (int i = 0; i < 101; i++)
		{
			DataBaseOfStudentsMassivForVariant50[i].yearPostupl = (1976 + i);
			//cout << "\n\t�����   : " << DataBaseOfStudentsMassivForVariant50[i].yearPostupl;
			DataBaseOfStudentsMassivForVariant50[i].nextPos = 0;
			DataBaseOfStudentsMassivForVariant50[i].isFree = 1;
			for (int j = 0; j < 1111; j++)
			{
				DataBaseOfStudentsMassivForVariant50[i].studentsOneYear[j] = NULL;
			}
		}
		
		//groupingByYear.push_back;
		groupingByYear[0].size = 0;
		groupingByYear[0].yearPostupl = 0;
		//DataBaseOfStudentsMassivForVariant50[0].yearPostupl = 0;
		//DataBaseOfStudentsMassivForVariant50[0].nextPos = 0;






		
		for (int j = 0; j < 1111; j++)
		{
			DataBaseOfStudentsMassiv[j]->AvrgMark();
			if (DataBaseOfStudentsMassiv[j] != NULL)
			{	for(int nubVek=0; nubVek< groupingByYear.size(); nubVek++)
					if ((DataBaseOfStudentsMassiv[j]->startYear == groupingByYear[nubVek].yearPostupl))
					{
						groupingByYear[nubVek].oneYearStudVector = DataBaseOfStudentsMassiv[j];
					}
					else
					{
						groupingByYear.push_back();
						groupingByYear.
					}

					
					if ((DataBaseOfStudentsMassivForVariant50[i].yearPostupl) == (DataBaseOfStudentsMassiv[j]->startYear))//////////---
					{
						DataBaseOfStudentsMassivForVariant50[i].studentsOneYear[DataBaseOfStudentsMassivForVariant50[i].nextPos] = DataBaseOfStudentsMassiv[j];
						DataBaseOfStudentsMassivForVariant50[i].nextPos++;
						DataBaseOfStudentsMassivForVariant50[i].isFree = 0;
					}
			}
		}
	

		for (int i = 1; i < 101; i++)
		{
			if (((DataBaseOfStudentsMassivForVariant50[i].nextPos) - 1) == 0)
			{
				DataBaseOfStudentsMassivForVariant50[0].studentsOneYear[DataBaseOfStudentsMassivForVariant50[0].nextPos] = DataBaseOfStudentsMassivForVariant50[i].studentsOneYear[0]; //DataBaseOfStudentsMassiv[j];
				DataBaseOfStudentsMassivForVariant50[0].nextPos++;
				DataBaseOfStudentsMassivForVariant50[0].isFree = 0;
				DataBaseOfStudentsMassivForVariant50[i].isFree = 1;
			}
		}


		for (int i = 0; i < 101; i++)
		{
			if (DataBaseOfStudentsMassivForVariant50[i].isFree == 0)
			{
				for (int j = 0; j < 1111; j++)
				{
					for (int k = j + 1; k < 1111; k++)
					{
						if ((DataBaseOfStudentsMassivForVariant50[i].studentsOneYear[k] != NULL) && (DataBaseOfStudentsMassivForVariant50[i].studentsOneYear[j] != NULL))  //					if ((DataBaseOfStudentsMassiv[j] != NULL)&& (DataBaseOfStudentsMassiv[k] != NULL) && (DataBaseOfStudentsMassivForVariant50[i].studentsOneYear[k]!=NULL) && (DataBaseOfStudentsMassivForVariant50[i].studentsOneYear[j] != NULL))
						{
							if ((DataBaseOfStudentsMassivForVariant50[i].studentsOneYear[j]->avrgMark) > (DataBaseOfStudentsMassivForVariant50[i].studentsOneYear[k]->avrgMark))
							{
								pTempStudent = DataBaseOfStudentsMassivForVariant50[i].studentsOneYear[j];
								DataBaseOfStudentsMassivForVariant50[i].studentsOneYear[j] = DataBaseOfStudentsMassivForVariant50[i].studentsOneYear[k];
								DataBaseOfStudentsMassivForVariant50[i].studentsOneYear[k] = pTempStudent;
							}
						}
					}
				}
			}
		}

		cout << "\n������� ���������, ����������� � ���� ���, �� ������������ (������������ �� �����������) \n";
		for (int i = 1; i < 101; i++)
		{

			if ((DataBaseOfStudentsMassivForVariant50[i].isFree) == 0)
			{
				cout << "\n\t**************************************************************************************";
				cout << "\n\t��� ����������� � ���: " << DataBaseOfStudentsMassivForVariant50[i].yearPostupl << " �.";
			}
			for (int j = 0; j < 1111; j++)
			{
				if ((DataBaseOfStudentsMassivForVariant50[i].isFree) == 0)
				{
					if (DataBaseOfStudentsMassivForVariant50[i].studentsOneYear[j] != NULL)
					{
						cout << "\n\t\t" << DataBaseOfStudentsMassivForVariant50[i].studentsOneYear[j]->surName << " " << DataBaseOfStudentsMassivForVariant50[i].studentsOneYear[j]->name << " " << DataBaseOfStudentsMassivForVariant50[i].studentsOneYear[j]->middleName << ", " << DataBaseOfStudentsMassivForVariant50[i].studentsOneYear[j]->group;
						printf_s("; �������: %.2f", DataBaseOfStudentsMassivForVariant50[i].studentsOneYear[j]->avrgMark);// << DataBaseOfStudentsMassivForVariant50[i].studentsOneYear[j]->avrgMark
						//cout << "\n        **********************************************************************************************************\n";
					}
				}
			}
		}
		for (int j = 0; j < 1111; j++)
		{
			if ((DataBaseOfStudentsMassivForVariant50[0].isFree) == 0)
			{
				if (DataBaseOfStudentsMassivForVariant50[0].studentsOneYear[j] != NULL)
				{
					if (j == 0)
					{
						cout << "\n\n\n\n������� ���������, ����������� � ���� ������ ����, �� ������������ (������������ �� �����������)\n";
						cout << "\n        **********************************************************************************************************\n";
					}
					cout << "\n\t\t" << DataBaseOfStudentsMassivForVariant50[0].studentsOneYear[j]->surName << " " << DataBaseOfStudentsMassivForVariant50[0].studentsOneYear[j]->name << " " << DataBaseOfStudentsMassivForVariant50[0].studentsOneYear[j]->middleName << ", " << DataBaseOfStudentsMassivForVariant50[0].studentsOneYear[j]->group;
					printf_s("; �������: %.2f", DataBaseOfStudentsMassivForVariant50[0].studentsOneYear[j]->avrgMark);
					cout << ", ��� �����������: " << DataBaseOfStudentsMassivForVariant50[0].studentsOneYear[j]->startYear;
					//DataBaseOfStudentsMassivForVariant50[0].studentsOneYear[j]
					//
				}
			}
		}
		cout << "\n\n";
		system("pause");
		delete DataBaseOfStudentsMassivForVariant50;

	}
	*/

	void SaveDataToFile(string _fileName)
	{
		ofstream outFile(_fileName);

		if (outFile.is_open())
		{
			for (int i=0;i<1111;i++)
			{
				if (this->DataBaseOfStudentsMassiv[i] != NULL)
				{
					outFile << endl << "�" << i + 1;
					outFile << endl << startRecordString <<endl;
					outFile << this->DataBaseOfStudentsMassiv[i]->surName << endl;
					outFile << this->DataBaseOfStudentsMassiv[i]->name << endl;
					outFile << this->DataBaseOfStudentsMassiv[i]->middleName << endl;
					outFile << this->DataBaseOfStudentsMassiv[i]->birthDateString << endl;
					outFile << this->DataBaseOfStudentsMassiv[i]->sex << endl;
					outFile << this->DataBaseOfStudentsMassiv[i]->startYear << endl;
					outFile << this->DataBaseOfStudentsMassiv[i]->group << endl;
					outFile << this->DataBaseOfStudentsMassiv[i]->numberZachetki << endl;
					outFile << this->DataBaseOfStudentsMassiv[i]->faculty << endl;
					outFile << this->DataBaseOfStudentsMassiv[i]->department << endl;
					//outFile << "zachetka:";
					for (int sesNub = 0; sesNub < 9; sesNub++)
					{
						for (int disciplina = 0; disciplina < 10; disciplina++)
						{
							outFile << " "<<"_" << sesNub <<"&"<<this->DataBaseOfStudentsMassiv[i]->uspevaemost[disciplina][sesNub].disciplina << "@" << this->DataBaseOfStudentsMassiv[i]->uspevaemost[disciplina][sesNub].mark;
						}
					}
					outFile << endl << endRecordString << endl;
				}
			}
			cout << "\n������� ��������� � ����: "<< _fileName <<"\n";
			system("pause");
		}
		else
		{
			cout << "\n��������!!! ������ ����������. ���������, ����������.\n";
			system ("pause");
		}
		outFile.close();  
	}
	int FindFreePositionInBase()
	{
		for (int i = 0; i < 1111; i++)
		{
			if (this->DataBaseOfStudentsMassiv[i] ==  NULL)
			{
				return i;
			}
		}
	}

	void ReadDataFromFile(string _fileName)
	{
		string strTemp="";
		string strCh = "";
		string disciplina = "";
		char tempCh=' ';
		int numSem=-1;
		StudentClass *pTempStud;
		ifstream inFile(_fileName); // �������� ���� ��� ������

		if (inFile.is_open())
		{
			while (getline(inFile, strTemp))
			{
				if (strTemp == "###Start_Record")
				{
					pTempStud = new StudentClass;
					getline(inFile, strTemp);
					pTempStud->surName = strTemp;

					getline(inFile, strTemp);
					pTempStud->name = strTemp;

					getline(inFile, strTemp);
					pTempStud->middleName = strTemp;

					getline(inFile, strTemp);
					pTempStud->birthDateString = strTemp;

					getline(inFile, strTemp);
					pTempStud->sex = strTemp[0];

					getline(inFile, strTemp);
					pTempStud->startYear = atoi(strTemp.c_str());

					getline(inFile, strTemp);
					pTempStud->group = strTemp;

					getline(inFile, strTemp);
					pTempStud->numberZachetki = strTemp;

					getline(inFile, strTemp);
					pTempStud->faculty = strTemp;

					getline(inFile, strTemp);
					pTempStud->department = strTemp;


					getline(inFile, strTemp);
					for (int i=0;i< strTemp.size();i++)
					{					
						numSem = -1;
						disciplina = "";

						if (strTemp[i] == '_')
						{
							i++;
							strCh[0] = strTemp[i];
							i++;
							numSem = atoi(strCh.c_str());
							if (strTemp[i] == '&')
							{
								i++;
								tempCh = ' ';
								strCh = "";
								while (strTemp[i] != '@')
								{									
									strCh = strCh + strTemp[i];
									i++;
								}
								disciplina = strCh;
								i++;
								strCh= strTemp[i];
								if ((disciplina!="")&&(atoi(strCh.c_str())!=0))
								{
									pTempStud->PutMarkToFirstEmptyPos(numSem, disciplina, atoi(strCh.c_str()));/////---------------
								}
							}
						}
						else
						{
							//break;
						}
					}
					this->DataBaseOfStudentsMassiv[this->FindFreePositionInBase()] = pTempStud;
					pTempStud = NULL;
				}
			}			
			inFile.close();

			cout << "\n������ �� ����� " << _fileName << " ������� ���������.\n";
			system("pause");
		}
		else
		{
			cout << "\n��������!!! ������ ������ ������. ���������, ����������.\n";
			system("pause");
		}	
	}

protected:


};