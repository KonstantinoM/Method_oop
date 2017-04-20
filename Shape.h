#include <iostream>
#include <fstream>
#include "SecureCoding.h"
using namespace std;

#ifndef __Shape__
#define __Shape__

class Shape
{
public:
	float density;
	int temperature;
	static Shape* InShape(ifstream &file);
	virtual void In(ifstream &file) = 0; 
	virtual void Out(ofstream &file) = 0; 
	virtual float Volume() = 0;
	virtual void OutOnlySphere(ofstream &file);
	void OutShape(ofstream &file);
	bool Compare(Shape *shape);
	virtual int* GetP() = 0;
	virtual void SetP(int *param) = 0;
};

#endif
