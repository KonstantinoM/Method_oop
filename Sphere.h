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
	float Volume();
	Sphere() {}
};

