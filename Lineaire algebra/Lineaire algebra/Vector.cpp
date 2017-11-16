#include "Vector.h"

Vector::Vector(float length, float direction)
{
	this->length = length; 
	this->direction = direction; 
}

Vector::~Vector()
{
	delete v; 
}

void Vector::setdirection(float value)
{
	direction = value; 
}

void Vector::setLength(float value)
{
	length = value; 
}

float Vector::getlength()
{
	return length; 
}

float Vector::getdirection()
{
	return direction;
}

void Vector::addVectors(float richting, float lengte)
{
	v = new Vector(lengte, richting);
}

Vector* Vector::scaleVector(float value)
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
