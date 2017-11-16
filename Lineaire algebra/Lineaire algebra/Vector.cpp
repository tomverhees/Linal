#include "Vector.h"

Vector::Vector(int length, int direction)
{
	this->length = length; 
	this->direction = direction; 
}

Vector::~Vector()
{
	delete v; 
}

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
	v = new Vector(lengte, richting);
}

Vector* Vector::scaleVector(int value)
{
	v->setdirection(direction * value); 
	v->setLength(length * value);
	return v;
}

Vector* Vector::combineVectors(Vector &v)
{
	Vector* m = new Vector(this->length + v.getlength(), this->direction + v.getdirection()); 
	return m; 
}

Vector* Vector::subtractVectors(Vector &v)
{
	Vector* m = new Vector(this->length - v.getlength(), this->direction - v.getdirection());
	return m;
}

void Vector::show()
{
}
