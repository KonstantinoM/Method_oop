#include "stdafx.h"
#include "Box.h"
#include "SecureCoding.h"
#include <iostream>
#include <fstream>
using namespace std;

void Box::In(ifstream &file)
{
	CheckInputFile(file);
	file >> a;
	CheckInputValue(file);
	CheckNonnegativeness(a);
	file >> b;
	CheckInputValue(file);
	CheckNonnegativeness(b);
	file >> c;
	CheckInputValue(file);
	CheckNonnegativeness(c);
}

void Box::Out(ofstream &file)
{
	CheckOutputFile(file);
	file << "It's box: a = " << a << ", b = " << b << ", c = " << c; 
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

void Box::MultiMethod(Shape *other, ofstream &file)
{
	other->MultiMethodCaseBox(file);
}

void Box::MultiMethodCaseSphere(ofstream &file)
{
	file << "Sphere and Box" << endl;
}

void Box::MultiMethodCaseBox(ofstream &file)
{
	file << "Box and Box" << endl;
}

void Box::MultiMethodCaseTetrahedron(ofstream &file)
{
	file << "Tetrahedron and Box" << endl;
}