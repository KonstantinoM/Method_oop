#include "stdafx.h"
#include "Container.h"
#include "SecureCoding.h"
#include <iostream>
#include <fstream>
using namespace std;

Container::Container()
{
	shape = NULL;
	n = 0;
	next = this; 
	prev = this;
}

void Container::InContainer(ifstream &file)
{
	CheckInputFile(file);
	file >> n; 
	CheckInputValue(file);
	CheckNonnegativeness(n);
	shape = Shape::InShape(file);
	for (int i = 0; i < n-1; i++)
	{
		Container *temp = new Container;
		temp->shape = Shape::InShape(file);
		temp->n = n-1-i;
		temp->next = this;
		temp->prev = prev;
		prev->next = temp;
		prev = temp;
	}
	if(!file.eof())
	{
		cout << "Error. There's some odd data" << endl;
		system("pause");
		exit(1);
	}
}

void Container::OutContainer(ofstream &file)
{
	CheckOutputFile(file);
	int N = n;
	file << "Total number = " << N <<  endl;
	Container* container = this;
	container->Sort();
	for (int i = 0; i < N; i++)
	{
		file << i+1 << ": ";
		container->shape->OutShape(file);
		file << ", V = " << container->shape->Volume() << endl;
		container = container->next;
	}
}

void Container::OutSphere(ofstream &file)
{
	CheckOutputFile(file);
	int N = n;
	file << "Only spheres:" <<  endl;
	Container* container = this;
	container->Sort();	
	for (int i = 0; i < N; i++)
	{
		file << i+1 << ": ";
		container->shape->OutOnlySphere(file);
		container = container->next;
	}
}

void Container::Clear()
{
	Container* container = this->next;
	Container *temp;
	while (container != this) 
	{
		temp = container->next;
		delete container; 
		container = temp;
    }
	container->n = 0;
	container->shape = NULL;
}

void Container::Sort() 
{
	int N = n;
	Container* container = this;
	for (int i = 0; i < N-1; i++)
	{
		for (int j = i+1; j < N; j++)
		{
			if(container->shape->Compare(container->next->shape))
			{
				//cout << ", V = " << l->sh->Volume() << endl;
				//cout << ", V = " << l->next->sh->Volume() << endl;
				//cout << "Changed\n";

				Container *temp = new Container;
				temp->shape = container->shape;
				container->shape = container->next->shape;
				container->next->shape = temp->shape;
			}
				container = container->next;
		}
		container = this;
	}

	//for (int i = 0; i < N-1; i++)
	//{
	//	for (int j = i+1; j < N; j++)
	//	{
	//		if(l->sh->Compare(l->next->sh))
	//		{
	//			//cout << ", V = " << l->sh->Volume() << endl;
	//			//cout << ", V = " << l->next->sh->Volume() << endl;
	//			//cout << "Changed\n";
	//			Container *temp = l->next->next;
	//			Container *prev = l->prev;
	//			Container *next = l->next;
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

void Container::MultiMethod(ofstream &file)
{
	file << "Multimethod:" << endl;
	Container *temp1 = this;
	Container *temp2 = this;
	while(temp1->next != this)
	{
		temp2 = temp1->next;
		while (temp2 != this) 
		{
			temp1->shape->MultiMethod(temp2->shape, file);
			temp1->shape->OutShape(file);
			file << ", V = " << temp1->shape->Volume() << endl;
			temp2->shape->OutShape(file);
			file << ", V = " << temp2->shape->Volume() << endl << endl;
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}