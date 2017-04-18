#include "stdafx.h"
#include <string>
#include "iostream"
#include <fstream>
#include "TestFunctions.h"
using namespace std;

bool CompareFiles(ifstream &f1, ifstream &f2)
{
	string s1;
	string s2;
	int i = 0;
	while ((!f1.eof())||(!f2.eof())) 
	{ 
		getline(f1, s1); 
		getline(f2, s2); 
		if (s1 != s2)
		{
			cout << "String " << i+1 << "\n" << s1 << "\n" << s2 << "\n";
			return false;
		}
		i += 1;
	}
	return true;
}

bool CompareShapes(Shape *s1, Shape *s2)
{
	int *param1 = s1->GetP();
	int *param2 = s2->GetP();
	for (int i = 0; i <= param1[0]; i++)
		if (param1[i] != param2[i])
			return false;
	if (s1->p != s2->p)
		return false;
	if (s1->t != s2->t)
		return false;
	return true;
}

bool ComparePointerInContainer(cont *list1, cont *list2)
{
	if ((list1 == NULL)^(list2 == NULL))
		return false;
	if (!CompareShapes(list1->sh, list2->sh))
		return false;
	return true;
}

bool CompareContainer(cont *list1, cont *list2)
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

void OneSphereInContainerPattern(cont *&list)
{
	list = new cont;
	list->n = 1;
	list->sh = new Sphere;
	int *param = new int[2];
	param[0] = 1;
	param[1] = 9;
	list->sh->SetP(param);
	list->sh->p = 98;
	list->sh->t = 354;
	list->next = list; 
	list->prev = list;
}

void OneBoxInContainerPattern(cont *&list)
{
	list = new cont;
	list->n = 1;
	list->sh = new Box;
	int *param = new int[4];
	param[0] = 3;
	param[1] = 9;
	param[2] = 13;
	param[3] = 34;
	list->sh->SetP(param);
	list->sh->p = 58;
	list->sh->t = 134;
	list->next = list; 
	list->prev = list;
}

void OneTetrahedronInContainerPattern(cont *&list)
{
	list = new cont;
	list->n = 1;
	list->sh = new Tetrahedron;
	int *param = new int[2];
	param[0] = 1;
	param[1] = 9;
	list->sh->SetP(param);
	list->sh->p = 58;
	list->sh->t = 134;
	list->next = list; 
	list->prev = list;
}

void ContainerPattern(cont *&list)
{
	list = new cont;
	list->n = 6;
	list->sh = new Tetrahedron;
	int *param = new int[2];
	param[0] = 1;
	param[1] = 9;
	list->sh->SetP(param);
	list->sh->p = 98;
	list->sh->t = 354;
	list->next = list; 
	list->prev = list;
	delete param;

	cont *temp = new cont;
	temp->sh = new Sphere;
	param = new int[2];
	param[0] = 1;
	param[1] = 67;
	temp->sh->SetP(param);
	temp->sh->p = 87;
	temp->sh->t = 343;
	temp->n = 5;
	temp->next = list; 
	temp->prev = list->prev;
	list->prev->next = temp;
	list->prev = temp;
	delete param;

	temp = new cont;
	temp->sh = new Tetrahedron;
	param = new int[2];
	param[0] = 1;
	param[1] = 3;
	temp->sh->SetP(param);
	temp->sh->p = 5;
	temp->sh->t = 34;
	temp->n = 4;
	temp->next = list; 
	temp->prev = list->prev;
	list->prev->next = temp;
	list->prev = temp;
	delete param;

	temp = new cont;
	temp->sh = new Box;
	param = new int[4];
	param[0] = 3;
	param[1] = 10;
	param[2] = 8;
	param[3] = 6;
	temp->sh->SetP(param);
	temp->sh->p = 87;
	temp->sh->t = 343;
	temp->n = 3;
	temp->next = list; 
	temp->prev = list->prev;
	list->prev->next = temp;
	list->prev = temp;
	delete param;

	temp = new cont;
	temp->sh = new Box;
	param = new int[4];
	param[0] = 3;
	param[1] = 4;
	param[2] = 12;
	param[3] = 11;
	temp->sh->SetP(param);
	temp->sh->p = 123;
	temp->sh->t = 167;
	temp->n = 2;
	temp->next = list; 
	temp->prev = list->prev;
	list->prev->next = temp;
	list->prev = temp;
	delete param;

	temp = new cont;
	temp->sh = new Sphere;
	param = new int[2];
	param[0] = 1;
	param[1] = 6;
	temp->sh->SetP(param);
	temp->sh->p = 985;
	temp->sh->t = 157;
	temp->n = 1;
	temp->next = list; 
	temp->prev = list->prev;
	list->prev->next = temp;
	list->prev = temp;
	delete param;
}

void SortContainerPattern(cont *&list)
{
	list = new cont;
	list->n = 6;
	list->sh = new Tetrahedron;
	int *param = new int[2];
	param[0] = 1;
	param[1] = 3;
	list->sh->SetP(param);
	list->sh->p = 5;
	list->sh->t = 34;
	list->next = list; 
	list->prev = list;
	delete param;

	cont *temp = new cont;	
	temp->sh = new Tetrahedron;
	param = new int[2];
	param[0] = 1;
	param[1] = 9;
	temp->sh->SetP(param);
	temp->sh->p = 98;
	temp->sh->t = 354;
	temp->n = 5;
	temp->next = list; 
	temp->prev = list->prev;
	list->prev->next = temp;
	list->prev = temp;
	delete param;

	temp = new cont;
	temp->sh = new Box;
	param = new int[4];
	param[0] = 3;
	param[1] = 10;
	param[2] = 8;
	param[3] = 6;
	temp->sh->SetP(param);
	temp->sh->p = 87;
	temp->sh->t = 343;
	temp->n = 4;
	temp->next = list; 
	temp->prev = list->prev;
	list->prev->next = temp;
	list->prev = temp;
	delete param;

	temp = new cont;
	temp->sh = new Box;
	param = new int[4];
	param[0] = 3;
	param[1] = 4;
	param[2] = 12;
	param[3] = 11;
	temp->sh->SetP(param);
	temp->sh->p = 123;
	temp->sh->t = 167;
	temp->n = 3;
	temp->next = list; 
	temp->prev = list->prev;
	list->prev->next = temp;
	list->prev = temp;
	delete param;

	temp = new cont;
	temp->sh = new Sphere;
	param = new int[2];
	param[0] = 1;
	param[1] = 6;
	temp->sh->SetP(param);
	temp->sh->p = 985;
	temp->sh->t = 157;
	temp->n = 2;
	temp->next = list; 
	temp->prev = list->prev;
	list->prev->next = temp;
	list->prev = temp;
	delete param;

	temp = new cont;
	temp->sh = new Sphere;
	param = new int[2];
	param[0] = 1;
	param[1] = 67;
	temp->sh->SetP(param);
	temp->sh->p = 87;
	temp->sh->t = 343;
	temp->n = 1;
	temp->next = list; 
	temp->prev = list->prev;
	list->prev->next = temp;
	list->prev = temp;
	delete param;
}