// met1oop.cpp: ���������� ����� ����� ��� ����������� ����������.
// ������������� �����, ��13-01

#include "stdafx.h"
#include <iostream>
#include <fstream>
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

	cont list;
	list.Incont (f1);

	ofstream f2(argv[2]);
	list.Outcont(f2);
	f2 << '\n';
	list.OutSphere(f2);
	list.Clear();
	return 0;
}

