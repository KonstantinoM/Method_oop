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

void cont::MultiMethod(ofstream &f)
{
	f << endl << "Multimethod:" << endl;
	cont *temp1 = this;
	cont *temp2 = this;
	while(temp1->next != this)
	{
		temp2 = temp1->next;
		while (temp2 != this) 
		{
			temp1->sh->MultiMethod(temp2->sh, f);
			temp1->sh->OutShape(f);
			temp2->sh->OutShape(f);
			f << endl;
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}