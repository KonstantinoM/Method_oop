#include <iostream>
#include <fstream>
using namespace std;

#ifndef __Shape__
#define __Shape__

class Shape
{
private:
	float p;
public:
	static Shape* InShape(ifstream &f);
	virtual void In(ifstream &f) = 0; 
    virtual void Out(ofstream &f) = 0; 
	virtual float Volume() = 0;
	void OutShape(ofstream &f);
};

#endif
