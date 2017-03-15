#include "Shape.h"
#include <iostream>
#include <fstream>
using namespace std;

class cont
{
	int n;
	Shape* sh;
	cont *next;
	cont *prev;
public:
	void Incont(ifstream &f);
	void Outcont(ofstream &f);
	void OutSphere(ofstream &f);
	void Clear();
	void Sort();
	cont();    
    ~cont() { delete sh; }
};
