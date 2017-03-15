#include "stdafx.h"
#include "Box.h"
#include "Sphere.h"
#include "Tetrahedron.h"
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
		case 2: //Это тетраэдр
			{
				s = new Tetrahedron;
				break;
			}
		default:
			break;
	}
	s->In(f);
	f >> s->p;
	f >> s->t;
	return s;
}

void Shape::OutShape(ofstream &f)
{
	Out(f);
	f << ", p = " << p << ", t = " << t;
}

void Shape::OutOnlySphere(ofstream &f)
{
	f << endl; 
}
