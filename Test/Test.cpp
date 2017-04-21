#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include "gtest/gtest.h"
#include "TestFunctions.h"
using namespace std;

TEST(SphereTest, SphereInput)
{
	ifstream file("SphereInput.txt");
	Sphere *actual = new Sphere;
	actual->In(file);
	int *param;
	EXPECT_TRUE(actual->GetP()[1] == 5);
}

TEST(SphereTest, SphereOutput)
{
	ofstream file("SphereOutput.txt");
	Sphere* sphere = new Sphere;
	int *param = new int[2];
	param[0] = 1;
	param[1] = 4;
	sphere->SetP(param);
	sphere->Out(file);
	file.close();
	ifstream actualFile("SphereOutput.txt"), expectedFile("SphereOutputPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
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
	ofstream file("OnlySphereOutput.txt");
	Sphere* sphere = new Sphere;
	int *param = new int[2];
	param[0] = 1;
	param[1] = 4;
	sphere->SetP(param);
	sphere->OutOnlySphere(file);
	file.close();
	ifstream actualFile("OnlySphereOutput.txt"), expectedFile("OnlySphereOutputPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}


TEST(BoxTest, BoxInput)
{
	ifstream file("BoxInput.txt");
	Box *actual = new Box;
	actual->In(file);
	int *param;
	EXPECT_TRUE(actual->GetP()[1] == 2);
	EXPECT_TRUE(actual->GetP()[2] == 3);
	EXPECT_TRUE(actual->GetP()[3] == 4);
}


TEST(BoxTest, BoxOutput)
{
	ofstream file("BoxOutput.txt");
	Box* box = new Box;
	int *param = new int[4];
	param[0] = 3;
	param[1] = 3;
	param[2] = 5;
	param[3] = 9;
	box->SetP(param);
	box->Out(file);
	file.close();
	ifstream actualFile("BoxOutput.txt"), expectedFile("BoxOutputPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
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
	ifstream file("TetrahedronInput.txt");
	Tetrahedron *actual = new Tetrahedron;
	actual->In(file);
	int *param;
	EXPECT_TRUE(actual->GetP()[1] == 14);
}

TEST(TetrahedronTest, TetrahedronOutput)
{
	ofstream file("TetrahedronOutput.txt");
	Tetrahedron* tetrahedron = new Tetrahedron;
	int *param = new int[2];
	param[0] = 1;
	param[1] = 183;
	tetrahedron->SetP(param);
	tetrahedron->Out(file);
	file.close();
	ifstream actualFile("TetrahedronOutput.txt"), expectedFile("TetrahedronOutputPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
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
	ifstream file("InputSphereToShape.txt");
	Shape *actual;
	actual = actual->InShape(file);
	Shape *expected = new Sphere;
	int *param = new int[2];
	param[0] = 1;
	param[1] = 2;
	expected->SetP(param);
	expected->density = 5;
	expected->temperature = 65;
	EXPECT_TRUE(CompareShapes(actual, expected));
}

TEST(InputShapeTest, InputBoxToShape)
{
	ifstream file("InputBoxToShape.txt");
	Shape *actual = actual->InShape(file);
	Shape *expected = new Box;
	int *param = new int[4];
	param[0] = 3;
	param[1] = 2;
	param[2] = 3;
	param[3] = 4;
	expected->SetP(param);
	expected->density = 67;
	expected->temperature = 987;
	EXPECT_TRUE(CompareShapes(actual, expected));
}

TEST(InputShapeTest, InputTetrahedronToShape)
{
	ifstream file("InputTetrahedronToShape.txt");
	Shape *actual = actual->InShape(file);
	Shape *expected = new Tetrahedron;
	int *param = new int[2];
	param[0] = 1;
	param[1] = 25;
	expected->SetP(param);
	expected->density = 75;
	expected->temperature = 698;
	EXPECT_TRUE(CompareShapes(actual, expected));
}

TEST(OutputShapeTest, ShapeSphereOutput)
{
	ofstream file("ShapeSphereOutput.txt");
	Shape *shape = new Sphere;
	int *param = new int[2];
	param[0] = 1;
	param[1] = 2;
	shape->SetP(param);
	shape->density = 5;
	shape->temperature = 65;
	shape->OutShape(file);
	file.close();
	ifstream actualFile("ShapeSphereOutput.txt"), expectedFile("ShapeSphereOutputPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(OutputShapeTest, ShapeBoxOutput)
{
	ofstream file("ShapeBoxOutput.txt");
	Shape* shape = new Box;
	int *param = new int[4];
	param[0] = 3;
	param[1] = 2;
	param[2] = 3;
	param[3] = 4;
	shape->SetP(param);
	shape->density = 5;
	shape->temperature = 65;
	shape->OutShape(file);
	file.close();
	ifstream actualFile("ShapeBoxOutput.txt"), expectedFile("ShapeBoxOutputPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(OutputShapeTest, ShapeTetrahedronOutput)
{
	ofstream file("ShapeTetrahedronOutput.txt");
	Shape *shape = new Tetrahedron;
	int *param = new int[2];
	param[0] = 1;
	param[1] = 25;
	shape->SetP(param);
	shape->density = 5;
	shape->temperature = 65;
	shape->OutShape(file);
	file.close();
	ifstream actualFile("ShapeTetrahedronOutput.txt"), expectedFile("ShapeTetrahedronOutputPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
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
	Container list;
	EXPECT_TRUE(list.shape == NULL);
	EXPECT_EQ(list.n, 0);
	EXPECT_TRUE(list.next == &list);
	EXPECT_TRUE(list.prev == &list);
}

TEST(ClearContainerTest, ClearEmptyContainer)
{
	Container list;
	list.Clear();
	EXPECT_TRUE(list.shape == NULL);
	EXPECT_EQ(list.n, 0);
	EXPECT_TRUE(list.next == &list);
	EXPECT_TRUE(list.prev == &list);
}

TEST(ClearContainerTest, ClearNonEmptyContainer)
{
	Container *list = new Container;
	list->shape = new Sphere;
	list->n = 1;
	list->next = list; 
	list->prev = list;
	list->Clear();
	EXPECT_TRUE(list->shape == NULL);
	EXPECT_EQ(list->n, 0);
	EXPECT_TRUE(list->next == list);
	EXPECT_TRUE(list->prev == list);
}

TEST(InputContainerTest, OneSphereInContainer)
{
	ifstream file("OneSphereInContainer.txt");
	Container *actual = new Container;
	actual->InContainer(file);

	Container *expected = NULL;
	OneSphereInContainerPattern(expected);
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(InputContainerTest, OneBoxInContainer)
{
	ifstream file("OneBoxInContainer.txt");
	Container *actual = new Container;
	actual->InContainer(file);

	Container *expected = NULL;
	OneBoxInContainerPattern(expected);
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(InputContainerTest, OneTetrahedronInContainer)
{
	ifstream file("OneTetrahedronInContainer.txt");
	Container *actual = new Container;
	actual->InContainer(file);

	Container *expected = NULL;
	OneTetrahedronInContainerPattern(expected);
	EXPECT_TRUE(CompareContainer(actual, expected));
}

//There is no nesessity to run this test because of secure coding.
//TEST(InputContainerTest, NoElementsInContainer)
//{
//	ifstream file("NoElementsInContainer.txt");
//	Container *actual = new Container;
//	actual->InContainer(file);
//	Container *expected = new Container;
//	EXPECT_TRUE(CompareContainer(actual, expected));
//}

TEST(InputContainerTest, SeveralElementsInContainer)
{
	ifstream file("SeveralElementsInContainer.txt");
	Container *actual = new Container;
	actual->InContainer(file);

	Container *expected = NULL;
	ContainerPattern(expected);
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(OutputContainerTest, SeveralElementsOutContainer)
{
	ofstream file("SeveralElementOutContainer.txt");
	Container *list = NULL;
	ContainerPattern(list);
	list->OutContainer(file);
	file.close();

	ifstream actualFile("SeveralElementOutContainer.txt"), expectedFile("SeveralElementOutContainerPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(OutputContainerTest, OneSphereOutContainer)
{
	ofstream file("OneSphereOutContainer.txt");
	Container *list = NULL;
	OneSphereInContainerPattern(list);
	list->OutContainer(file);
	file.close();

	ifstream actualFile("OneSphereOutContainer.txt"), expectedFile("OneSphereOutContainerPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(OutputContainerTest, OneBoxOutContainer)
{
	ofstream file("OneBoxOutContainer.txt");
	Container *list = NULL;
	OneBoxInContainerPattern(list);
	list->OutContainer(file);
	file.close();

	ifstream actualFile("OneBoxOutContainer.txt"), expectedFile("OneBoxOutContainerPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(OutputContainerTest, OneTetrahedronOutContainer)
{
	ofstream file("OneTetrahedronOutContainer.txt");
	Container *list =  NULL;
	OneTetrahedronInContainerPattern(list);
	list->OutContainer(file);
	file.close();

	ifstream actualFile("OneTetrahedronOutContainer.txt"), expectedFile("OneTetrahedronOutContainerPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(OutputContainerTest, NoElementsOutContainer)
{
	ofstream file("NoElementsOutContainer.txt");
	Container list;
	list.OutContainer(file);
	file.close();

	ifstream actualFile("NoElementsOutContainer.txt"), expectedFile("NoElementsOutContainerPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(OutputContainerTest, OnlySeveralSpheresOutContainer)
{
	ofstream file("OnlySeveralSpheresOutContainer.txt");
	Container *list = NULL;
	ContainerPattern(list);
	list->OutSphere(file);
	file.close();

	ifstream actualFile("OnlySeveralSpheresOutContainer.txt"), expectedFile("OnlySeveralSpheresOutContainerPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(OutputContainerTest, OnlySingleSphereOutContainer)
{
	ofstream file("OnlySingleSpheresOutContainer.txt");
	Container *list = NULL;
	OneSphereInContainerPattern(list);
	list->OutSphere(file);
	file.close();

	ifstream actualFile("OnlySingleSpheresOutContainer.txt"), expectedFile("OnlySingleSpheresOutContainerPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(OutputContainerTest,NoSpheresOutContainer)
{
	ofstream file("NoSpheresOutContainer.txt");
	Container list;
	list.OutSphere(file);
	file.close();

	ifstream actualFile("NoSpheresOutContainer.txt"), expectedFile("NoSpheresOutContainerPattern.txt");
	ASSERT_FALSE(!actualFile);
	EXPECT_TRUE(CompareFiles(actualFile, expectedFile));
	actualFile.close();
	expectedFile.close();
}

TEST(SortContainerTest, JustSortContainer)
{
	Container *actual = NULL;
	ContainerPattern(actual);
	actual->Sort();

	Container *expected = NULL;
	SortContainerPattern(expected);
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(SortContainerTest, ReversedSortContainer)
{
	Container *actual = new Container;
	actual->n = 6;
	actual->shape = new Sphere;
	int *param = new int[2];
	param[0] = 1;
	param[1] = 67;
	actual->shape->SetP(param);
	actual->shape->density = 87;
	actual->shape->temperature = 343;
	actual->next = actual; 
	actual->prev = actual;
	delete param;

	Container *temp = new Container;
	temp->shape = new Sphere;
	param = new int[2];
	param[0] = 1;
	param[1] = 6;
	temp->shape->SetP(param);
	temp->shape->density = 985;
	temp->shape->temperature = 157;
	temp->n = 5;
	temp->next = actual; 
	temp->prev = actual->prev;
	actual->prev->next = temp;
	actual->prev = temp;
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
	temp->n = 4;
	temp->next = actual; 
	temp->prev = actual->prev;
	actual->prev->next = temp;
	actual->prev = temp;
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
	temp->next = actual; 
	temp->prev = actual->prev;
	actual->prev->next = temp;
	actual->prev = temp;
	delete param;

	temp = new Container;	
	temp->shape = new Tetrahedron;
	param = new int[2];
	param[0] = 1;
	param[1] = 9;
	temp->shape->SetP(param);
	temp->shape->density = 98;
	temp->shape->temperature = 354;
	temp->n = 2;
	temp->next = actual; 
	temp->prev = actual->prev;
	actual->prev->next = temp;
	actual->prev = temp;
	delete param;

	temp = new Container;
	temp->shape = new Tetrahedron;
	param = new int[2];
	param[0] = 1;
	param[1] = 3;
	temp->shape->SetP(param);
	temp->shape->density = 5;
	temp->shape->temperature = 34;
	temp->n = 1;
	temp->next = actual; 
	temp->prev = actual->prev;
	actual->prev->next = temp;
	actual->prev = temp;
	delete param;
	actual->Sort();

	Container *expected = NULL;
	SortContainerPattern(expected);
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(SortContainerTest, SortedSortContainer)
{
	Container *actual = NULL;
	SortContainerPattern(actual);
	actual->Sort();

	Container *expected = NULL;
	SortContainerPattern(expected);
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(SortContainerTest, OneSphereInContainer)
{
	Container *actual = NULL;
	OneSphereInContainerPattern(actual);
	actual->Sort();

	Container *expected = NULL;
	OneSphereInContainerPattern(expected);
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(SortContainerTest, OneBoxInContainer)
{
	Container *actual = NULL;
	OneBoxInContainerPattern(actual);
	actual->Sort();

	Container *expected = NULL;
	OneBoxInContainerPattern(expected);
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(SortContainerTest, OneTetrahedronInContainer)
{
	Container *actual = NULL;
	OneTetrahedronInContainerPattern(actual);
	actual->Sort();

	Container *expected = NULL;
	OneTetrahedronInContainerPattern(expected);
	EXPECT_TRUE(CompareContainer(actual, expected));
}

TEST(SortContainerTest, NothingInContainer)
{
	Container *actual = new Container;
	actual->Sort();

	Container *expected = new Container;
	EXPECT_TRUE(CompareContainer(actual, expected));
}

int main(int argc, char **argv) 
{ 
	::testing::InitGoogleTest(&argc, argv); 
	RUN_ALL_TESTS(); 
	system("pause"); 
	return 0; 
}