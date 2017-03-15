#include <iostream>
#include <fstream>
#include "Shape.h"
using namespace std;

class Tetrahedron:public Shape
{
private:
	int a;
public:
	void In(ifstream &f);
	void Out(ofstream &f);
	float Volume();
	Tetrahedron() {}
};

