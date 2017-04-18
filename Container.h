#include "Shape.h"
#include <iostream>
#include <fstream>
using namespace std;

class cont
{
public:
	int n;
	Shape* sh;
	cont *next;
	cont *prev;
	void Incont(ifstream &f);
	void Outcont(ofstream &f);
	void OutSphere(ofstream &f);
	void Clear();
	void Sort();
	cont();    
    ~cont() { delete sh; }
};
