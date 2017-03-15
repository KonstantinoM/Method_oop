#include "stdafx.h"
#include "Container.h"
#include <iostream>
#include <fstream>
using namespace std;

cont::cont()
{
	sh = NULL;
	n = 0;
	next = this; 
	prev = this;
}

void cont::Incont(ifstream &f)
{
	f >> n; 
	sh=Shape::InShape(f);
	for (int i = 0; i < n-1; i++)
	{
		cont *temp = new cont;
		temp->sh=Shape::InShape(f);
		temp->n = n-1-i;
		temp->next = this;
		temp->prev = prev;
		prev->next = temp;
		prev = temp;
	}
}

void cont::Outcont(ofstream &f)
{
	int N = n;
	f << "Total number = " << N <<  endl;
	cont* l = this;
	for (int i = 0; i < N; i++)
	{
		l->sh->OutShape(f);
		l = l->next;
	}
}

void cont::OutSphere(ofstream &f)
{
	int N = n;
	f << "Only spheres:" <<  endl;
	cont* l = this;
	
	for (int i = 0; i < N; i++)
	{
		f << i+1 << ". ";
		l->sh->OutOnlySphere(f);
		l = l->next;
	}
}

void cont::Clear()
{
	cont* l = this->next;
	cont *temp;
	while (l != this) 
	{
		temp = l->next;
		delete l; 
		l = temp;
    }
}