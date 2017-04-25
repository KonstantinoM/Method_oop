#include <iostream>
#include <fstream>
#include "Shape.h"
using namespace std;

class Box:public Shape
{
private:
	int a, b, c;
public:
	void In(ifstream &file);
	void Out(ofstream &file);
	float Volume();
	int* GetP();
	void SetP(int *param);
	void MultiMethod(Shape *other, ofstream &file);
	void MultiMethodCaseSphere(ofstream &file);
	void MultiMethodCaseBox(ofstream &file);
	void MultiMethodCaseTetrahedron(ofstream &file);
	Box() {}
};

