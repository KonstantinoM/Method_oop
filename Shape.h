#include <iostream>
#include <fstream>
using namespace std;

#ifndef __Shape__
#define __Shape__

class Shape
{
public:
	float p;
	int t;
	static Shape* InShape(ifstream &f);
	virtual void In(ifstream &f) = 0; 
	virtual void Out(ofstream &f) = 0; 
	virtual float Volume() = 0;
	virtual void OutOnlySphere(ofstream &f);
	void OutShape(ofstream &f);
	bool Compare(Shape *other);
	virtual int* GetP() = 0;
	virtual void SetP(int *param) = 0;
};

#endif
