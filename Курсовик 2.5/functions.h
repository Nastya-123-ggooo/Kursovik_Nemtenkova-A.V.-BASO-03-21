#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <time.h>
#include <fstream>
using namespace std;


int foolproof(string _str, int _min, int _max)
{
	bool vibor = 1;
	int znach;
	while (vibor == 1)
	{
		cout << _str;
		cin >> znach;
		if ((znach >= _min) && (znach <= _max))
		{
			vibor = 0;
			return znach;
		}
		else
		{
			vibor = 1;
			cout << "\nНекорректный ввод данных. Повторите, пожалуйста.\n";
		}
	}
}


bool confirmationSelection(int nomerPunkta0, string p0)
{
	bool tekVibor;
	cout << "\nВнимание!!! Выбран пункт меню --->> " << nomerPunkta0 << "). \"" << p0 << "\"\n\n";
	cout << "\nВы подтверждаете (Да - 1, Нет - 0) выбор пункт " << nomerPunkta0 << "). \"" << p0 << "\" ? ";
	cin >> tekVibor;
	return tekVibor;
}
void negotovPunkt()
{
	cout << "\nК сожалению, данный пункт пока не готов. Наберитесь, пожалуйста, терпения.\n";
	system("pause");
}


void Crypt()
{	
	srand(time(NULL));
	char* pass = new char[64];
	for (int i = 0; i < 64; ++i) 
	{
		switch (rand() % 3) //http://cppstudio.com/post/339/
		{
		case 0:
			pass[i] = rand() % 10 + 'S';
			break;
		case 1:
			pass[i] = rand() % 26 + 'A';
			break;
		case 2:
			pass[i] = rand() % 26 + 'a';
		}
	}	
	string command = "openssl\\bin\\openssl.exe enc -aes-256-cbc -salt -in dataBaseOfStudents.txt -out dataBaseOfStudents.txt.enc -pass pass:";
	for (int i = 0; i < 64; i++)
	{
		command += pass[i];
	}	
	cout << pass; system("pause");
	system(command.c_str());
	if (remove("dataBaseOfStudents.txt") != 0) 
	{
		cout << "[ERROR] - deleting file" << endl;
	}
	ofstream file;
	file.open("key.txt", ios::binary);
	file.write(pass, 64);//65
	file.close();
	command = "openssl\\bin\\openssl.exe rsautl -encrypt -inkey rsa.public -pubin -in key.txt -out key.txt.enc";
	system(command.c_str());
	delete pass;
	if (remove("key.txt") != 0) 
	{
		cout << "[ERROR] - deleting file" << endl;
	}
}
/*
void Crypt()
{
	fileNameSet = " ";
	srand(time(NULL));
	char* pass = new char[64];
	for (int i = 0; i < 64; ++i)
	{
		switch (rand() % 3) //http://cppstudio.com/post/339/
		{
		case 0:
			pass[i] = rand() % 10 + 'S';
			cout << "\nВыбор пароля " << pass[i];
			break;
		case 1:
			pass[i] = rand() % 26 + 'A';
			cout << "\nВыбор пароля " << pass[i];
			break;
		case 2:
			pass[i] = rand() % 26 + 'a';
		}
	}

	string command = "openssl\\bin\\openssl.exe enc -aes-256-cbc -salt -in ";
	command= command+fileNameSet+" - out dataBaseOfStudents.txt.enc - pass pass : ";
	for (int i = 0; i < 64; i++)
	{
		command += pass[i];
	}
	//cout << command<<"\n";
	cout << pass; system("pause");
	system(command.c_str());
	
	if (remove(*fileNameSet) != 0)
	{
		cout << "[ERROR] - deleting file" << endl;
	}
	ofstream file;
	file.open("key.txt", ios::binary);
	file.write(pass, 64);//65
	file.close();
	command = "openssl\\bin\\openssl.exe rsautl -encrypt -inkey rsa.public -pubin -in key.txt -out key.txt.enc";
	system(command.c_str());
	delete pass;
	if (remove("key.txt") != 0)
	{
		cout << "[ERROR] - deleting file" << endl;
	}
}
*/
void Decrypt()
{
	string command = "openssl\\bin\\openssl.exe rsautl -decrypt -inkey rsa.private -in key.txt.enc -out key.txt";
	system(command.c_str());
	if (remove("key.txt.enc") != 0) 
	{
		cout << "[ERROR] - deleting file" << endl;
	}
	char* pass = new char[64];

	ifstream file;
	file.open("key.txt", ios::binary);
	file.read(pass, 64);//65
	file.close();
	if (remove("key.txt") != 0) 
	{
		cout << "[ERROR] - deleting file" << endl;
	}
	command = "openssl\\bin\\openssl.exe enc -aes-256-cbc -d -in dataBaseOfStudents.txt.enc -out dataBaseOfStudents.txt -pass pass:";
	for (int i = 0; i < 64; i++)
	{
		command += pass[i];
	}
	delete pass;
	system(command.c_str());
	if (remove("dataBaseOfStudents.txt.enc") != 0) 
	{
		cout << "[ERROR] - deleting file" << endl;
	}
}