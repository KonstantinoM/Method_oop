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