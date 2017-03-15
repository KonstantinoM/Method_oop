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
