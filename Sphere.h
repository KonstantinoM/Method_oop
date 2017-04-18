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
	void In(ifstream &f);
	void Out(ofstream &f);
	float Volume();
	void OutOnlySphere(ofstream &f);
	int* GetP();
	void SetP(int *param);
	Sphere() {}
};

#endif