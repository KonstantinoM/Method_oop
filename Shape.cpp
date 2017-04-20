#include "stdafx.h"
#include "Box.h"
#include "Sphere.h"
#include "Tetrahedron.h"
#include <iostream>
#include <fstream>
using namespace std;

Shape* Shape::InShape(ifstream &file)
{
	CheckInputFile(file);
	if(file.eof())
	{
		cout << "Error. Too many shapes is specified." << endl;
		system("pause");
		exit(1);
	}
	Shape *shape;
	int key = 0;
	file >> key;
	CheckInputValue(file);
	CheckNonnegativeness(key);
	if (key > 2)
	{
		cout << "Error. Incorrect values. The key can take the values 0, 1, 2." << endl;
		system("pause");
		exit(1);
	}
	switch(key)
	{
		case 0: //Это сфера
			{
				shape = new Sphere;
				break;
			}
		case 1: //Это параллелепипед
			{
				shape = new Box;
				break;
			}
		case 2: //Это тетраэдр
			{
				shape = new Tetrahedron;
				break;
			}
		default:
			break;
	}
	shape->In(file);
	file >> shape->density;
	CheckInputValue(file);
	CheckNonnegativeness(shape->density);
	file >> shape->temperature;
	CheckInputValue(file);
	CheckNonnegativeness(shape->temperature);
	return shape;
}

void Shape::OutShape(ofstream &file)
{
	CheckOutputFile(file);
	Out(file);
	file << ", p = " << density << ", t = " << temperature;
}

void Shape::OutOnlySphere(ofstream &file)
{
	CheckOutputFile(file);
	file << endl; 
}
