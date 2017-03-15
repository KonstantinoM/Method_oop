// met1oop.cpp: определяет точку входа для консольного приложения.
// Константинова Мария, КИ13-01

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "windows.h"
#include "Container.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	if(argc !=3) 
	{
		cout << "incorrect command line! "
				"Waited: command in_file out_file" 
				 << endl;
		return 0;
	}
	ifstream f1(argv[1]);

	cont l;
	l.Incont (f1);

	ofstream f2(argv[2]);
	l.Outcont(f2);
	l.Clear();
	//Outcont(l, f2);
	return 0;
}

