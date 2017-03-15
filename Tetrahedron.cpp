#include "stdafx.h"
#include "Tetrahedron.h"
#include <iostream>
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

