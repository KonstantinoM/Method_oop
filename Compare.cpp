#include "stdafx.h"
#include "Box.h"
#include "Sphere.h"

bool Shape::Compare(Shape *other)
{
	return Volume() > other->Volume();
}
