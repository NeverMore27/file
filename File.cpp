// File.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>

#define raz 256

using namespace std;

void Files(char* name1, char* name2, ofstream &file3);

void main()
{
	

	char n1[256], n2[raz], n3[raz];
	cin.getline(n1, raz);
	cin.getline(n2, raz);
	cin.getline(n3, raz);
	ofstream file3(n3);
	Files(n1, n2, file3);
	Files(n2, n1, file3);
	file3.close();
	system("pause");
}

void Files(char* name1, char* name2, ofstream &file3)
{
	ifstream file(name1);
	ifstream file2(name2);

	char *tmp, *tmp2;;
	tmp = new char[raz];
	tmp2 = new char[raz];

	int str = 0;
	while (!file.eof())
	{
		int i1, i = 0, k = 0;

		file.getline(tmp, raz);
		str++;
		while (!file2.eof())
		{

			file2.getline(tmp2, raz);
			if (strcmp(tmp2, tmp))
			{
				i1 = str;
				i++;
			}
			k++;
		}
		file2.seekg(0, ios::beg);
		if (i == k)
		{
			file3  << name1 << " " << i1 << " " << tmp << endl;
		}
	}
	file2.close();
	file.close();
}
