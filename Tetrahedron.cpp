#include "stdafx.h"
#include "Tetrahedron.h"
#include <iostream>
#include "math.h"
#include <fstream>
using namespace std;

void Tetrahedron::In(ifstream &f)
{
	f >> a;
}

void Tetrahedron::Out(ofstream &f)
{
	f << "It's tetrahedron: a = " << a; 
}

float Tetrahedron::Volume()
{
	return ((sqrt(2.0))*pow(a,3.0)/12);
}

int* Tetrahedron::GetP()
{
	int *param = new int[2];
	param[0] = 1;
	param[1] = a;
	return param;
}

void Tetrahedron::SetP(int* param)
{
	//param[0] = 1;
	a = param[1];
}