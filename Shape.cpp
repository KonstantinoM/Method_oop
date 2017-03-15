#include "stdafx.h"
#include "Box.h"
#include "Sphere.h"
#include <iostream>
#include <fstream>
using namespace std;

Shape* Shape::InShape(ifstream &f)
{
	Shape *s;
	int key = 0;
	f >> key;
	switch(key)
	{
		case 0: //Это сфера
			{
				s = new Sphere;
				break;
			}
		case 1: //Это параллелепипед
			{
				s = new Box;
				break;
			}
		default:
			break;
	}
	s->In(f);
	f >> s->p;
	return s;
}

void Shape::OutShape(ofstream &f)
{
	Out(f);
	f << ", p = " << p <<  endl;
}

void Shape::OutOnlySphere(ofstream &f)
{
	f << endl; 
}
