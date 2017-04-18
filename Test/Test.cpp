#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "gtest/gtest.h"
#include "TestFunctions.h"
using namespace std;

TEST(SphereTest, SphereInput)
{
	ifstream f("SphereInput.txt");
	Sphere *actual = new Sphere;
	actual->In(f);
	int *param;
	EXPECT_TRUE(actual->GetP()[1] == 5);
}

TEST(SphereTest, SphereOutput)
{
	ofstream f("SphereOutput.txt");
	Sphere* sphere = new Sphere;
	int *param = new int[2];
	param[0] = 1;
	param[1] = 4;
	sphere->SetP(param);
	sphere->Out(f);
	f.close();
	ifstream actual("SphereOutput.txt"), expected("SphereOutputPattern.txt");
	ASSERT_FALSE(!actual);
	EXPECT_TRUE(CompareFiles(actual, expected));
	actual.close();
	expected.close();
}

TEST(SphereTest, SphereVolume)
{
	Sphere *actual = new Sphere;
	int *param = new int[2];
	param[0] = 1;
	param[1] = 1;
	actual->SetP(param);
	float ActualVolume = actual->Volume();
	float ExpectedVolume = 4.18879;
	EXPECT_TRUE(abs(ActualVolume - ExpectedVolume) < 0.00001);
}

TEST(SphereTest, OnlySphereOutput)
{
	ofstream f("OnlySphereOutput.txt");
	Sphere* sphere = new Sphere;
	int *param = new int[2];
	param[0] = 1;
	param[1] = 4;
	sphere->SetP(param);
	sphere->OutOnlySphere(f);
	f.close();
	ifstream actual("OnlySphereOutput.txt"), expected("OnlySphereOutputPattern.txt");
	ASSERT_FALSE(!actual);
	EXPECT_TRUE(CompareFiles(actual, expected));
	actual.close();
	expected.close();
}


TEST(BoxTest, BoxInput)
{
	ifstream f("BoxInput.txt");
	Box *actual = new Box;
	actual->In(f);
	int *param;
	EXPECT_TRUE(actual->GetP()[1] == 2);
	EXPECT_TRUE(actual->GetP()[2] == 3);
	EXPECT_TRUE(actual->GetP()[3] == 4);
}


TEST(BoxTest, BoxOutput)
{
	ofstream f("BoxOutput.txt");
	Box* box = new Box;
	int *param = new int[4];
	param[0] = 3;
	param[1] = 3;
	param[2] = 5;
	param[3] = 9;
	box->SetP(param);
	box->Out(f);
	f.close();
	ifstream actual("BoxOutput.txt"), expected("BoxOutputPattern.txt");
	ASSERT_FALSE(!actual);
	EXPECT_TRUE(CompareFiles(actual, expected));
	actual.close();
	expected.close();
}

TEST(BoxTest, BoxVolume)
{
	Box *actual = new Box;
	int *param = new int[4];
	param[0] = 3;
	param[1] = 7;
	param[2] = 5;
	param[3] = 9;
	actual->SetP(param);
	float ActualVolume = actual->Volume();
	float ExpectedVolume = 315;
	EXPECT_EQ(ExpectedVolume, ActualVolume);
}

TEST(TetrahedronTest, TetrahedronInput)
{
	ifstream f("TetrahedronInput.txt");
	Tetrahedron *actual = new Tetrahedron;
	actual->In(f);
	int *param;
	EXPECT_TRUE(actual->GetP()[1] == 14);
}

TEST(TetrahedronTest, TetrahedronOutput)
{
	ofstream f("TetrahedronOutput.txt");
	Tetrahedron* tetrahedron = new Tetrahedron;
	int *param = new int[2];
	param[0] = 1;
	param[1] = 183;
	tetrahedron->SetP(param);
	tetrahedron->Out(f);
	f.close();
	ifstream actual("TetrahedronOutput.txt"), expected("TetrahedronOutputPattern.txt");
	ASSERT_FALSE(!actual);
	EXPECT_TRUE(CompareFiles(actual, expected));
	actual.close();
	expected.close();
}

TEST(TetrahedronTest, TetrahedronVolume)
{
	Tetrahedron *actual = new Tetrahedron;
	int *param = new int[2];
	param[0] = 1;
	param[1] = 9;
	actual->SetP(param);
	float ActualVolume = actual->Volume();
	float ExpectedVolume = 85.9135;
	EXPECT_TRUE(abs(ActualVolume - ExpectedVolume) < 0.0001);
}

TEST(InputShapeTest, InputSphereToShape)
{
	ifstream f("InputSphereToShape.txt");
	Shape *actual;
	actual = actual->InShape(f);
	Shape *expected = new Sphere;
	int *param = new int[2];
	param[0] = 1;
	param[1] = 2;
	expected->SetP(param);
	expected->p = 5;
	expected->t = 65;
	EXPECT_TRUE(CompareShapes(actual, expected));
}

TEST(InputShapeTest, InputBoxToShape)
{
	ifstream f("InputBoxToShape.txt");
	Shape *actual = actual->InShape(f);
	Shape *expected = new Box;
	int *param = new int[4];
	param[0] = 3;
	param[1] = 2;
	param[2] = 3;
	param[3] = 4;
	expected->SetP(param);
	expected->p = 67;
	expected->t = 987;
	EXPECT_TRUE(CompareShapes(actual, expected));
}

TEST(InputShapeTest, InputTetrahedronToShape)
{
	ifstream f("InputTetrahedronToShape.txt");
	Shape *actual = actual->InShape(f);
	Shape *expected = new Tetrahedron;
	int *param = new int[2];
	param[0] = 1;
	param[1] = 25;
	expected->SetP(param);
	expected->p = 75;
	expected->t = 698;
	EXPECT_TRUE(CompareShapes(actual, expected));
}

TEST(OutputShapeTest, ShapeSphereOutput)
{
	ofstream f("ShapeSphereOutput.txt");
	Shape *shape = new Sphere;
	int *param = new int[2];
	param[0] = 1;
	param[1] = 2;
	shape->SetP(param);
	shape->p = 5;
	shape->t = 65;
	shape->OutShape(f);
	f.close();
	ifstream actual("ShapeSphereOutput.txt"), expected("ShapeSphereOutputPattern.txt");
	ASSERT_FALSE(!actual);
	EXPECT_TRUE(CompareFiles(actual, expected));
	actual.close();
	expected.close();
}

TEST(OutputShapeTest, ShapeBoxOutput)
{
	ofstream f("ShapeBoxOutput.txt");
	Shape* shape = new Box;
	int *param = new int[4];
	param[0] = 3;
	param[1] = 2;
	param[2] = 3;
	param[3] = 4;
	shape->SetP(param);
	shape->p = 5;
	shape->t = 65;
	shape->OutShape(f);
	f.close();
	ifstream actual("ShapeBoxOutput.txt"), expected("ShapeBoxOutputPattern.txt");
	ASSERT_FALSE(!actual);
	EXPECT_TRUE(CompareFiles(actual, expected));
	actual.close();
	expected.close();
}

TEST(OutputShapeTest, ShapeTetrahedronOutput)
{
	ofstream f("ShapeTetrahedronOutput.txt");
	Shape *shape = new Tetrahedron;
	int *param = new int[2];
	param[0] = 1;
	param[1] = 25;
	shape->SetP(param);
	shape->p = 5;
	shape->t = 65;
	shape->OutShape(f);
	f.close();
	ifstream actual("ShapeTetrahedronOutput.txt"), expected("ShapeTetrahedronOutputPattern.txt");
	ASSERT_FALSE(!actual);
	EXPECT_TRUE(CompareFiles(actual, expected));
	actual.close();
	expected.close();
}

TEST(ShapeVolumeTest, ShapeSphereVolume)
{
	Shape *actual = new Sphere;
	int *param = new int[2];
	param[0] = 1;
	param[1] = 1;
	actual->SetP(param);
	float ActualVolume = actual->Volume();
	float ExpectedVolume = 4.18879;
	EXPECT_TRUE(abs(ActualVolume - ExpectedVolume) < 0.00001);
}

TEST(ShapeVolumeTest, ShapeBoxVolume)
{
	Shape *actual = new Box;
	int *param = new int[4];
	param[0] = 3;
	param[1] = 7;
	param[2] = 5;
	param[3] = 9;
	actual->SetP(param);
	float ActualVolume = actual->Volume();
	float ExpectedVolume = 315;
	EXPECT_EQ(ExpectedVolume, ActualVolume);
}

TEST(ShapeVolumeTest, ShapeTetrahedronVolume)
{
	Shape *actual = new Tetrahedron;
	int *param = new int[2];
	param[0] = 1;
	param[1] = 9;
	actual->SetP(param);
	float ActualVolume = actual->Volume();
	float ExpectedVolume = 85.9135;
	EXPECT_TRUE(abs(ActualVolume - ExpectedVolume) < 0.0001);
}

TEST(ShapeCompareVolumeTest, CompareVolumeMore)
{	
	Shape *shape1 = new Tetrahedron;
	int *param1 = new int[2];
	param1[0] = 1;
	param1[1] = 9;
	shape1->SetP(param1);

	Shape *shape2 = new Box;
	int *param2 = new int[4];
	param2[0] = 3;
	param2[1] = 7;
	param2[2] = 6;
	param2[3] = 2;
	shape2->SetP(param2);
	EXPECT_TRUE(shape1->Compare(shape2));
}

TEST(ShapeCompareVolumeTest, CompareVolumeLess)
{	
	Shape *shape1 = new Tetrahedron;
	int *param1 = new int[2];
	param1[0] = 1;
	param1[1] = 9;
	shape1->SetP(param1);

	Shape *shape2 = new Box;
	int *param2 = new int[4];
	param2[0] = 3;
	param2[1] = 7;
	param2[2] = 6;
	param2[3] = 2;
	shape2->SetP(param2);
	EXPECT_TRUE(!shape2->Compare(shape1));
}

TEST(ShapeCompareVolumeTest, CompareVolumeEqual)
{	
	Shape *shape1 = new Tetrahedron;
	int *param1 = new int[2];
	param1[0] = 1;
	param1[1] = 9;
	shape1->SetP(param1);

	EXPECT_TRUE(!shape1->Compare(shape1));
}

TEST(InitContainerTest, InitContainer)
{
	cont list;
	EXPECT_TRUE(list.sh == NULL);
	EXPECT_EQ(list.n, 0);
	EXPECT_TRUE(list.next == &list);
	EXPECT_TRUE(list.prev == &list);
}

TEST(ClearContainerTest, ClearEmptyContainer)
{
	cont list;
	list.Clear();
	EXPECT_TRUE(list.sh == NULL);
	EXPECT_EQ(list.n, 0);
	EXPECT_TRUE(list.next == &list);
	EXPECT_TRUE(list.prev == &list);
}

TEST(ClearContainerTest, ClearNonEmptyContainer)
{
	cont *list = new cont;
	list->sh = new Sphere;
	list->n = 1;
	list->next = list; 
	list->prev = list;
	list->Clear();
	EXPECT_TRUE(list->sh == NULL);
	EXPECT_EQ(list->n, 0);
	EXPECT_TRUE(list->next == list);
	EXPECT_TRUE(list->prev == list);
}

TEST(InputContainerTest, OneSphereInContainer)
{
	ifstream f("OneSphereInContainer.txt");
	cont *actual = new cont;
	actual->Incont(f);

	cont *expected = NULL;
	OneSphereInContainerPattern(expected);
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(InputContainerTest, OneBoxInContainer)
{
	ifstream f("OneBoxInContainer.txt");
	cont *actual = new cont;
	actual->Incont(f);

	cont *expected = NULL;
	OneBoxInContainerPattern(expected);
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(InputContainerTest, OneTetrahedronInContainer)
{
	ifstream f("OneTetrahedronInContainer.txt");
	cont *actual = new cont;
	actual->Incont(f);

	cont *expected = NULL;
	OneTetrahedronInContainerPattern(expected);
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(InputContainerTest, NoElementsInContainer)
{
	ifstream f("NoElementsInContainer.txt");
	cont *actual = new cont;
	actual->Incont(f);
	cont *expected = new cont;
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(InputContainerTest, SeveralElementsInContainer)
{
	ifstream f("SeveralElementsInContainer.txt");
	cont *actual = new cont;
	actual->Incont(f);

	cont *expected = NULL;
	ContainerPattern(expected);
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(OutputContainerTest, SeveralElementsOutContainer)
{
	ofstream f("SeveralElementOutContainer.txt");
	cont *list = NULL;
	ContainerPattern(list);
	list->Outcont(f);
	f.close();

	ifstream actual("SeveralElementOutContainer.txt"), expected("SeveralElementOutContainerPattern.txt");
	ASSERT_FALSE(!actual);
	EXPECT_TRUE(CompareFiles(actual, expected));
	actual.close();
	expected.close();
}

TEST(OutputContainerTest, OneSphereOutContainer)
{
	ofstream f("OneSphereOutContainer.txt");
	cont *list = NULL;
	OneSphereInContainerPattern(list);
	list->Outcont(f);
	f.close();

	ifstream actual("OneSphereOutContainer.txt"), expected("OneSphereOutContainerPattern.txt");
	ASSERT_FALSE(!actual);
	EXPECT_TRUE(CompareFiles(actual, expected));
	actual.close();
	expected.close();
}

TEST(OutputContainerTest, OneBoxOutContainer)
{
	ofstream f("OneBoxOutContainer.txt");
	cont *list = NULL;
	OneBoxInContainerPattern(list);
	list->Outcont(f);
	f.close();

	ifstream actual("OneBoxOutContainer.txt"), expected("OneBoxOutContainerPattern.txt");
	ASSERT_FALSE(!actual);
	EXPECT_TRUE(CompareFiles(actual, expected));
	actual.close();
	expected.close();
}

TEST(OutputContainerTest, OneTetrahedronOutContainer)
{
	ofstream f("OneTetrahedronOutContainer.txt");
	cont *list =  NULL;
	OneTetrahedronInContainerPattern(list);
	list->Outcont(f);
	f.close();

	ifstream actual("OneTetrahedronOutContainer.txt"), expected("OneTetrahedronOutContainerPattern.txt");
	ASSERT_FALSE(!actual);
	EXPECT_TRUE(CompareFiles(actual, expected));
	actual.close();
	expected.close();
}

TEST(OutputContainerTest, NoElementsOutContainer)
{
	ofstream f("NoElementsOutContainer.txt");
	cont list;
	list.Outcont(f);
	f.close();

	ifstream actual("NoElementsOutContainer.txt"), expected("NoElementsOutContainerPattern.txt");
	ASSERT_FALSE(!actual);
	EXPECT_TRUE(CompareFiles(actual, expected));
	actual.close();
	expected.close();
}

TEST(OutputContainerTest, OnlySeveralSpheresOutContainer)
{
	ofstream f("OnlySeveralSpheresOutContainer.txt");
	cont *list = NULL;
	ContainerPattern(list);
	list->OutSphere(f);
	f.close();

	ifstream actual("OnlySeveralSpheresOutContainer.txt"), expected("OnlySeveralSpheresOutContainerPattern.txt");
	ASSERT_FALSE(!actual);
	EXPECT_TRUE(CompareFiles(actual, expected));
	actual.close();
	expected.close();
}

TEST(OutputContainerTest, OnlySingleSphereOutContainer)
{
	ofstream f("OnlySingleSpheresOutContainer.txt");
	cont *list = NULL;
	OneSphereInContainerPattern(list);
	list->OutSphere(f);
	f.close();

	ifstream actual("OnlySingleSpheresOutContainer.txt"), expected("OnlySingleSpheresOutContainerPattern.txt");
	ASSERT_FALSE(!actual);
	EXPECT_TRUE(CompareFiles(actual, expected));
	actual.close();
	expected.close();
}

TEST(OutputContainerTest,NoSpheresOutContainer)
{
	ofstream f("NoSpheresOutContainer.txt");
	cont list;
	list.OutSphere(f);
	f.close();

	ifstream actual("NoSpheresOutContainer.txt"), expected("NoSpheresOutContainerPattern.txt");
	ASSERT_FALSE(!actual);
	EXPECT_TRUE(CompareFiles(actual, expected));
	actual.close();
	expected.close();
}

TEST(SortContainerTest, JustSortContainer)
{
	cont *actual = NULL;
	ContainerPattern(actual);
	actual->Sort();

	cont *expected = NULL;
	SortContainerPattern(expected);
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(SortContainerTest, ReversedSortContainer)
{
	cont *actual = new cont;
	actual->n = 6;
	actual->sh = new Sphere;
	int *param = new int[2];
	param[0] = 1;
	param[1] = 67;
	actual->sh->SetP(param);
	actual->sh->p = 87;
	actual->sh->t = 343;
	actual->next = actual; 
	actual->prev = actual;
	delete param;

	cont *temp = new cont;
	temp->sh = new Sphere;
	param = new int[2];
	param[0] = 1;
	param[1] = 6;
	temp->sh->SetP(param);
	temp->sh->p = 985;
	temp->sh->t = 157;
	temp->n = 5;
	temp->next = actual; 
	temp->prev = actual->prev;
	actual->prev->next = temp;
	actual->prev = temp;
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
	temp->n = 4;
	temp->next = actual; 
	temp->prev = actual->prev;
	actual->prev->next = temp;
	actual->prev = temp;
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
	temp->next = actual; 
	temp->prev = actual->prev;
	actual->prev->next = temp;
	actual->prev = temp;
	delete param;

	temp = new cont;	
	temp->sh = new Tetrahedron;
	param = new int[2];
	param[0] = 1;
	param[1] = 9;
	temp->sh->SetP(param);
	temp->sh->p = 98;
	temp->sh->t = 354;
	temp->n = 2;
	temp->next = actual; 
	temp->prev = actual->prev;
	actual->prev->next = temp;
	actual->prev = temp;
	delete param;

	temp = new cont;
	temp->sh = new Tetrahedron;
	param = new int[2];
	param[0] = 1;
	param[1] = 3;
	temp->sh->SetP(param);
	temp->sh->p = 5;
	temp->sh->t = 34;
	temp->n = 1;
	temp->next = actual; 
	temp->prev = actual->prev;
	actual->prev->next = temp;
	actual->prev = temp;
	delete param;
	actual->Sort();

	cont *expected = NULL;
	SortContainerPattern(expected);
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(SortContainerTest, SortedSortContainer)
{
	cont *actual = NULL;
	SortContainerPattern(actual);
	actual->Sort();

	cont *expected = NULL;
	SortContainerPattern(expected);
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(SortContainerTest, OneSphereInContainer)
{
	cont *actual = NULL;
	OneSphereInContainerPattern(actual);
	actual->Sort();

	cont *expected = NULL;
	OneSphereInContainerPattern(expected);
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(SortContainerTest, OneBoxInContainer)
{
	cont *actual = NULL;
	OneBoxInContainerPattern(actual);
	actual->Sort();

	cont *expected = NULL;
	OneBoxInContainerPattern(expected);
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(SortContainerTest, OneTetrahedronInContainer)
{
	cont *actual = NULL;
	OneTetrahedronInContainerPattern(actual);
	actual->Sort();

	cont *expected = NULL;
	OneTetrahedronInContainerPattern(expected);
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(SortContainerTest, NothingInContainer)
{
	cont *actual = new cont;
	actual->Sort();

	cont *expected = new cont;
	EXPECT_TRUE(CompareContainer(actual, expected));
}

int main(int argc, char **argv) 
{ 
	::testing::InitGoogleTest(&argc, argv); 
	RUN_ALL_TESTS(); 
	system("pause"); 
	return 0; 
}