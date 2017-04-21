#include "stdafx.h"
#include <string>
#include "iostream"
#include <fstream>
#include "TestFunctions.h"
using namespace std;

bool CompareFiles(ifstream &file1, ifstream &file2)
{
	string s1;
	string s2;
	int i = 0;
	while ((!file1.eof())||(!file2.eof())) 
	{ 
		getline(file1, s1); 
		getline(file2, s2); 
		if (s1 != s2)
		{
			cout << "String " << i+1 << "\n" << s1 << "\n" << s2 << "\n";
			return false;
		}
		i += 1;
	}
	return true;
}

bool CompareShapes(Shape *shape1, Shape *shape2)
{
	int *param1 = shape1->GetP();
	int *param2 = shape2->GetP();
	for (int i = 0; i <= param1[0]; i++)
		if (param1[i] != param2[i])
			return false;
	if (shape1->density != shape2->density)
		return false;
	if (shape1->temperature != shape2->temperature)
		return false;
	return true;
}

bool ComparePointerInContainer(Container *list1, Container *list2)
{
	if ((list1 == NULL)^(list2 == NULL))
		return false;
	if (!CompareShapes(list1->shape, list2->shape))
		return false;
	return true;
}

bool CompareContainer(Container *list1, Container *list2)
{
	if (list1->n != list2->n)
		return false;
	else
	{
		int n = list1->n;
		for (int i = 0; i < n; i++)
		{
			if (!ComparePointerInContainer(list1, list2))
				return false;
			list1 = list1->next;
			list2 = list2->next;
		}
	}
	return true;
}

void OneSphereInContainerPattern(Container *&list)
{
	list = new Container;
	list->n = 1;
	list->shape = new Sphere;
	int *param = new int[2];
	param[0] = 1;
	param[1] = 9;
	list->shape->SetP(param);
	list->shape->density = 98;
	list->shape->temperature = 354;
	list->next = list; 
	list->prev = list;
}

void OneBoxInContainerPattern(Container *&list)
{
	list = new Container;
	list->n = 1;
	list->shape = new Box;
	int *param = new int[4];
	param[0] = 3;
	param[1] = 9;
	param[2] = 13;
	param[3] = 34;
	list->shape->SetP(param);
	list->shape->density = 58;
	list->shape->temperature = 134;
	list->next = list; 
	list->prev = list;
}

void OneTetrahedronInContainerPattern(Container *&list)
{
	list = new Container;
	list->n = 1;
	list->shape = new Tetrahedron;
	int *param = new int[2];
	param[0] = 1;
	param[1] = 9;
	list->shape->SetP(param);
	list->shape->density = 58;
	list->shape->temperature = 134;
	list->next = list; 
	list->prev = list;
}

void ContainerPattern(Container *&list)
{
	list = new Container;
	list->n = 6;
	list->shape = new Tetrahedron;
	int *param = new int[2];
	param[0] = 1;
	param[1] = 9;
	list->shape->SetP(param);
	list->shape->density = 98;
	list->shape->temperature = 354;
	list->next = list; 
	list->prev = list;
	delete param;

	Container *temp = new Container;
	temp->shape = new Sphere;
	param = new int[2];
	param[0] = 1;
	param[1] = 67;
	temp->shape->SetP(param);
	temp->shape->density = 87;
	temp->shape->temperature = 343;
	temp->n = 5;
	temp->next = list; 
	temp->prev = list->prev;
	list->prev->next = temp;
	list->prev = temp;
	delete param;

	temp = new Container;
	temp->shape = new Tetrahedron;
	param = new int[2];
	param[0] = 1;
	param[1] = 3;
	temp->shape->SetP(param);
	temp->shape->density = 5;
	temp->shape->temperature = 34;
	temp->n = 4;
	temp->next = list; 
	temp->prev = list->prev;
	list->prev->next = temp;
	list->prev = temp;
	delete param;

	temp = new Container;
	temp->shape = new Box;
	param = new int[4];
	param[0] = 3;
	param[1] = 10;
	param[2] = 8;
	param[3] = 6;
	temp->shape->SetP(param);
	temp->shape->density = 87;
	temp->shape->temperature = 343;
	temp->n = 3;
	temp->next = list; 
	temp->prev = list->prev;
	list->prev->next = temp;
	list->prev = temp;
	delete param;

	temp = new Container;
	temp->shape = new Box;
	param = new int[4];
	param[0] = 3;
	param[1] = 4;
	param[2] = 12;
	param[3] = 11;
	temp->shape->SetP(param);
	temp->shape->density = 123;
	temp->shape->temperature = 167;
	temp->n = 2;
	temp->next = list; 
	temp->prev = list->prev;
	list->prev->next = temp;
	list->prev = temp;
	delete param;

	temp = new Container;
	temp->shape = new Sphere;
	param = new int[2];
	param[0] = 1;
	param[1] = 6;
	temp->shape->SetP(param);
	temp->shape->density = 985;
	temp->shape->temperature = 157;
	temp->n = 1;
	temp->next = list; 
	temp->prev = list->prev;
	list->prev->next = temp;
	list->prev = temp;
	delete param;
}

void SortContainerPattern(Container *&list)
{
	list = new Container;
	list->n = 6;
	list->shape = new Tetrahedron;
	int *param = new int[2];
	param[0] = 1;
	param[1] = 3;
	list->shape->SetP(param);
	list->shape->density = 5;
	list->shape->temperature = 34;
	list->next = list; 
	list->prev = list;
	delete param;

	Container *temp = new Container;	
	temp->shape = new Tetrahedron;
	param = new int[2];
	param[0] = 1;
	param[1] = 9;
	temp->shape->SetP(param);
	temp->shape->density = 98;
	temp->shape->temperature = 354;
	temp->n = 5;
	temp->next = list; 
	temp->prev = list->prev;
	list->prev->next = temp;
	list->prev = temp;
	delete param;

	temp = new Container;
	temp->shape = new Box;
	param = new int[4];
	param[0] = 3;
	param[1] = 10;
	param[2] = 8;
	param[3] = 6;
	temp->shape->SetP(param);
	temp->shape->density = 87;
	temp->shape->temperature = 343;
	temp->n = 4;
	temp->next = list; 
	temp->prev = list->prev;
	list->prev->next = temp;
	list->prev = temp;
	delete param;

	temp = new Container;
	temp->shape = new Box;
	param = new int[4];
	param[0] = 3;
	param[1] = 4;
	param[2] = 12;
	param[3] = 11;
	temp->shape->SetP(param);
	temp->shape->density = 123;
	temp->shape->temperature = 167;
	temp->n = 3;
	temp->next = list; 
	temp->prev = list->prev;
	list->prev->next = temp;
	list->prev = temp;
	delete param;

	temp = new Container;
	temp->shape = new Sphere;
	param = new int[2];
	param[0] = 1;
	param[1] = 6;
	temp->shape->SetP(param);
	temp->shape->density = 985;
	temp->shape->temperature = 157;
	temp->n = 2;
	temp->next = list; 
	temp->prev = list->prev;
	list->prev->next = temp;
	list->prev = temp;
	delete param;

	temp = new Container;
	temp->shape = new Sphere;
	param = new int[2];
	param[0] = 1;
	param[1] = 67;
	temp->shape->SetP(param);
	temp->shape->density = 87;
	temp->shape->temperature = 343;
	temp->n = 1;
	temp->next = list; 
	temp->prev = list->prev;
	list->prev->next = temp;
	list->prev = temp;
	delete param;
}