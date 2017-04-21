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

bool CompareFiles(ifstream &file1, ifstream &file2);
bool CompareShapes(Shape *shape1, Shape *shape);
bool ComparePointerInContainer(Container *list1, Container *list2);
bool CompareContainer(Container *list1, Container *list2);
void OneSphereInContainerPattern(Container *&list);
void OneBoxInContainerPattern(Container *&list);
void OneTetrahedronInContainerPattern(Container *&list);
void ContainerPattern(Container *&list);
void SortContainerPattern(Container *&list);