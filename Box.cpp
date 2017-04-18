#include "stdafx.h"
#include "Box.h"
#include <iostream>
#include <fstream>
using namespace std;

void Box::In(ifstream &f)
{
	f >> a;
	f >> b;
	f >> c;
}

void Box::Out(ofstream &f)
{
	f << "It's box: a = " << a << ", b = " << b << ", c = " << c; 
}

float Box::Volume()
{
	return (a*b*c);
}

int* Box::GetP()
{
	int *param = new int[4];
	param[0] = 3;
	param[1] = a;
	param[2] = b;
	param[3] = c;
	return param;
}

void Box::SetP(int* param)
{
	//param[0] = 3;
	a = param[1];
	b = param[2];
	c = param[3];	
}