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
	sh = Shape::InShape(f);
	for (int i = 0; i < n-1; i++)
	{
		cont *temp = new cont;
		temp->sh = Shape::InShape(f);
		temp->n = n-1-i;
		temp->next = this;
		temp->prev = prev;
		prev->next = temp;
		prev = temp;
	}
	/*
	Insignificant changes for optimization:
	
	cont* temp;
	for (int i = 0; i < n-1; i++)
	{
		temp = new cont;
		temp->sh = Shape::InShape(f);
		temp->n = n-1-i;
		temp->prev = prev;
		prev->next = temp;
		prev = temp;
	}
	temp->next = this;
	*/
}

void cont::Outcont(ofstream &f)
{
	int N = n;
	f << "Total number = " << N <<  endl;
	cont* l = this;
	l->Sort();
	for (int i = 0; i < N; i++)
	{
		f << i+1 << ": ";
		l->sh->OutShape(f);
		f << ", V = " << l->sh->Volume() << endl;
		l = l->next;
	}
}

void cont::OutSphere(ofstream &f)
{
	int N = n;
	f << "Only spheres:" <<  endl;
	cont* l = this;
	l->Sort();	
	for (int i = 0; i < N; i++)
	{
		f << i+1 << ": ";
		l->sh->OutOnlySphere(f);
		l = l->next;
	}
	/*
	Add counter parameter to the OutOnlySphere function that is incremented only for the class Sphere
	int counter = 0;
	for (int i = 0; i < N; i++)
	{
		l->sh->OutOnlySphere(f);
		l = l->next;
	}
	
	Function Sphere::OutOnlySphere:
	void Sphere::OutOnlySphere(int &counter, ofstream &f)
	{
		f << counter++ << ": ";
		Out(f);
		f << ", p = " << p << ", t = " << t << ", V = " << Volume() << endl;
	}
	*/
}

void cont::Clear()
{
	cont* l = this->next;
	cont *temp;
	while (l != this) 
	{
		temp = l->next;
		/*
		Clear the memory allocated for shape
		delete l->sh;
		*/
		delete l; 
		l = temp;
    }
	l->n = 0;
	l->sh = NULL;
}

void cont::Sort() 
{
	int N = n;
	cont* l = this;
	for (int i = 0; i < N-1; i++)
	{
		for (int j = i+1; j < N; j++)
		{
			if(l->sh->Compare(l->next->sh))
			{
				//cout << ", V = " << l->sh->Volume() << endl;
				//cout << ", V = " << l->next->sh->Volume() << endl;
				//cout << "Changed\n";

				cont *temp = new cont;
				temp->sh = l->sh;
				l->sh = l->next->sh;
				l->next->sh = temp->sh;
			}
				l = l->next;
		}
		l = this;
	}

	/*
	//Possible solution:
	cont* l = this;
	for (int i = 0; i < N-1; i++)
	{
		for (int j = i+1; j < N; j++)
		{
			if(l->sh->Compare(l->next->sh))
			{
				//cout << ", V = " << l->sh->Volume() << endl;
				//cout << ", V = " << l->next->sh->Volume() << endl;
				//cout << "Changed\n";

				swap(l->sh,l->next->sh);
			}
				l = l->next;
		}
		l = this;
	}
	*/
	//for (int i = 0; i < N-1; i++)
	//{
	//	for (int j = i+1; j < N; j++)
	//	{
	//		if(l->sh->Compare(l->next->sh))
	//		{
	//			//cout << ", V = " << l->sh->Volume() << endl;
	//			//cout << ", V = " << l->next->sh->Volume() << endl;
	//			//cout << "Changed\n";
	//			cont *temp = l->next->next;
	//			cont *prev = l->prev;
	//			cont *next = l->next;
	//			l->prev->next = next;
	//			l->next->prev = prev;
	//			l->next->next->prev = l;
	//			l->next->next = l;
	//			l->prev = next;
	//			l->next = temp;
	//		}
	//		else
	//			l = l->next;
	//	}
	//	for (int j = 0; j <= i; j++)
	//		l = l->next;
	//}
}
