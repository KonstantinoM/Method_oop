#include "stdafx.h"
#include <string>
#include "iostream"
#include <fstream>
#include "..\Met3o\Shape.h"
#include "..\Met3o\Container.h"
#include "..\Met3o\Sphere.h"
#include "..\Met3o\Box.h"
#include "..\Met3o\Tetrahedron.h"
using namespace std;

bool CompareFiles(ifstream &f1, ifstream &f2);
bool CompareShapes(Shape *s1, Shape *s2);
bool ComparePointerInContainer(cont *list1, cont *list2);
bool CompareContainer(cont *list1, cont *list2);
void OneSphereInContainerPattern(cont *&list);
void OneBoxInContainerPattern(cont *&list);
void OneTetrahedronInContainerPattern(cont *&list);
void ContainerPattern(cont *&list);
void SortContainerPattern(cont *&list);