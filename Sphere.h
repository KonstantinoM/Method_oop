//#include "Enu.h"
#include <iostream>
#include <fstream>
#include "Shape.h"
using namespace std;

class Sphere:public Shape
{
private:
	int r;
public:
	void In(ifstream &f);
	void Out(ofstream &f);
	void MultiMethod(Shape *other, ofstream &f);
	void MultiMethodCaseSphere(ofstream &f);
	void MultiMethodCaseBox(ofstream &f);
	Sphere() {}
};

