#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "windows.h"
using namespace std;

#ifndef __SecureCoding__
#define __SecureCoding__

void CheckInputFile(ifstream &file);
void CheckInputValue(ifstream &file);
void CheckNonnegativeness(float value);
void CheckOutputFile(ofstream &file);


#endif