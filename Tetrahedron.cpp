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
