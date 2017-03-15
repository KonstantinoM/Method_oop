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
	f << ", p = " << p << ", t = " << t << endl;
}