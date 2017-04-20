#include "Shape.h"
#include <iostream>
#include <fstream>
using namespace std;

class Container
{
public:
	int n;
	Shape* shape;
	Container *next;
	Container *prev;
	void InContainer(ifstream &file);
	void OutContainer(ofstream &file);
	void OutSphere(ofstream &file);
	void Clear();
	void Sort();
	Container();    
    ~Container() { delete shape; }
};
