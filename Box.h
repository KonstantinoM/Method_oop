#include <iostream>
#include <fstream>
#include "Shape.h"
using namespace std;

class Box:public Shape
{
private:
	int a, b, c;
public:
	void In(ifstream &f);
	void Out(ofstream &f);
	float Volume();
	Box() {}
};

