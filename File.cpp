// File.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>

#define raz 256

using namespace std;
//master

void Files(char* name1, char* name2);

int main(int argc, char *argv[])
{
	

	char n1[raz], n2[raz];
	if (argc == 3)
	{
		strcpy_s(n1, argv[1]);
		strcpy_s(n2, argv[2]);
	}
	Files(n1, n2);
	Files(n2, n1);
	system("pause");
}

void Files(char* name1, char* name2)
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
			cout  << name1 << " " << i1 << " " << tmp << endl;
		}
	}
	file2.close();
	file.close();
}
