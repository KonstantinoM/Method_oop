#include "stdafx.h"
#include "Sphere.h"
#include "SecureCoding.h"
#include <iostream>
#include <fstream>
#include "math.h"
using namespace std;

#define PI 3.1415926535897932384626433832795

void Sphere::In(ifstream &file)
{
	CheckInputFile(file);
	file >> r;
	CheckInputValue(file);
	CheckNonnegativeness(r);
}

void Sphere::Out(ofstream &file)
{
	CheckOutputFile(file);
	file << "It's sphere: r = " << r; 
}

float Sphere::Volume()
{
	return (float(4)/float(3)*PI*pow(r, 3.0));
}

void Sphere::OutOnlySphere(ofstream &file)
{
	CheckOutputFile(file);
	Out(file);
	file << ", p = " << density << ", t = " << temperature << ", V = " << Volume() << endl;
}

int* Sphere::GetP()
{
	int *param = new int[2];
	param[0] = 1;
	param[1] = r;
	return param;
}

void Sphere::SetP(int* param)
{
	//param[0] = 1;
	r = param[1];
}