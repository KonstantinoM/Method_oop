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
	Sphere() {}
};

#endif