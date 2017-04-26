#include "stdafx.h"
#include "Sphere.h"
#include <iostream>
#include <fstream>
using namespace std;

void Sphere::In(ifstream &f)
{
	f >> r;
}

void Sphere::Out(ofstream &f)
{
	f << "It's sphere: r = " << r; 
}

void Sphere::MultiMethod(Shape *other, ofstream &f)
{
	other->MultiMethodCaseSphere(f);
}

void Sphere::MultiMethodCaseSphere(ofstream &f)
{
	f << "Sphere and Sphere" << endl;
}
void Sphere::MultiMethodCaseBox(ofstream &f)
{
	f << "Box and Sphere" << endl;
}