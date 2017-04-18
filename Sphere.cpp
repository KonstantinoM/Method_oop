#include "stdafx.h"
#include "Sphere.h"
#include <iostream>
#include <fstream>
#include "math.h"
using namespace std;

#define M_PI 3.1415926535897932384626433832795

void Sphere::In(ifstream &f)
{
	f >> r;
}

void Sphere::Out(ofstream &f)
{
	f << "It's sphere: r = " << r; 
}

float Sphere::Volume()
{
	return (float(4)/float(3)*M_PI*pow(r, 3.0));
}

void Sphere::OutOnlySphere(ofstream &f)
{
	Out(f);
	f << ", p = " << p << ", t = " << t << ", V = " << Volume() << endl;
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