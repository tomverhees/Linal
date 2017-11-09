#include "Vector.h"

void Vector::setdirection(int value)
{
	direction = value; 
}

void Vector::setLength(int value)
{
	length = value; 
}

int Vector::getlength()
{
	return length; 
}

int Vector::getdirection()
{
	return direction;
}

void Vector::addVectors(int richting, int lengte)
{
	Vector v; 
	v.setLength(lengte);
	v.setdirection(richting);
}

Vector Vector::scaleVector(int value)
{
	Vector v; 
	v.setdirection(direction * value); 
	v.setLength(length * value);
	return v;
}

Vector Vector::combineVectors(Vector v)
{
	Vector m; 
	m.setLength(length + v.getlength()); 
	m.setdirection(direction + v.getdirection()); 
	return m; 
}

Vector Vector::subtractVectors(Vector v)
{
	Vector m;
	m.setLength(length - v.getlength());
	m.setdirection(direction - v.getdirection());
	return m;
}

void Vector::show()
{
}
