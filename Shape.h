#include <iostream>
#include <fstream>
using namespace std;

#ifndef __Shape__
#define __Shape__

class Shape
{
public:
	float p;
	static Shape* InShape(ifstream &f);
	virtual void In(ifstream &f) = 0; 
    virtual void Out(ofstream &f) = 0;
	virtual void OutOnlySphere(ofstream &f);
	void OutShape(ofstream &f);
};

#endif
