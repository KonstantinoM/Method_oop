#include "stdafx.h"
#include "Box.h"
#include "Sphere.h"

bool Shape::Compare(Shape *shape)
{
	return (Volume() > shape->Volume());
}
