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

void Box::MultiMethod(Shape *other, ofstream &f)
{
	other->MultiMethodCaseBox(f);
}

void Box::MultiMethodCaseSphere(ofstream &f)
{
	f << "Sphere and Box" << endl;
}
void Box::MultiMethodCaseBox(ofstream &f)
{
	f << "Box and Box" << endl;
}