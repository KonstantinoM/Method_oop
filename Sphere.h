#include <iostream>
#include <fstream>
#include "Shape.h"
using namespace std;

#ifndef __Sphere__ 
#define __Sphere__

class Sphere:public Shape
{
private:
	int r;
public:
	void In(ifstream &file);
	void Out(ofstream &file);
	float Volume();
	void OutOnlySphere(ofstream &file);
	int* GetP();
	void SetP(int *param);
	void MultiMethod(Shape *other, ofstream &file);
	void MultiMethodCaseSphere(ofstream &file);
	void MultiMethodCaseBox(ofstream &file);
	void MultiMethodCaseTetrahedron(ofstream &file);
	Sphere() {}
};

#endif