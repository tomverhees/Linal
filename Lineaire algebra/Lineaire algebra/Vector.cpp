#include "Vector.h"
#include <vector>
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>

Vector::Vector(float deltax, float deltay,float deltaz, float x, float y, float z) : x_(x), y_(y), z_(z),deltax_(deltax), deltay_(deltay),deltaz_(deltaz)
{
	
}


void Vector::scaleVector(float valuex, float valuey, float valuez)
{
	deltax_ *= valuex;
	deltay_ *= valuey; 
	deltaz_ *= valuez;
}

float Vector::getLength() const
{
	return sqrt(pow(deltax_, 2) + pow(deltay_, 2) + pow(deltaz_, 2));
}

void Vector::normalize()
{
	float length = getLength(); 
	deltax_ /= length; 
	deltay_ /= length; 
	deltaz_ /= length; 
}

float Vector::getDeltaX() const
{
	return deltax_; 
}
float Vector::getDeltaY() const
{
	return deltay_;
}
float Vector::getDeltaZ() const
{
	return deltaz_;
}

Vector Vector::crossProduct(Vector v, Vector v1)
{
	float deltax = v.getDeltaY() * v1.getDeltaZ() - v.getDeltaZ() * v1.getDeltaY(); 
	float deltay = v.getDeltaZ() * v1.getDeltaX() - v.getDeltaX() * v1.getDeltaZ(); 
	float deltaz = v.getDeltaX() * v1.getDeltaY() - v.getDeltaY() * v1.getDeltaX();

	return Vector(deltax, deltay, deltaz);
}

float Vector::inProduct(Vector v, Vector v1)
{
	return v.getDeltaX() * v1.getDeltaX() + v.getDeltaY() * v1.getDeltaY() + v.getDeltaZ() * v1.getDeltaZ();
}

float Vector::calculateAngle(Vector v, Vector v1)
{
	float cos = inProduct(v, v1) / (v.getLength() * v1.getLength()); 
	cos = acos(cos); 
	return cos * 180.0 / M_PI; 
}

Vector& Vector::operator+=(const Vector& vector)
{
	deltax_ += vector.getDeltaX(); 
	deltay_ += vector.getDeltaY();
	deltaz_ += vector.getDeltaZ();

	return *this; 
}

Vector& Vector::operator-=(const Vector& vector)
{
	deltax_ -= vector.getDeltaX();
	deltay_ -= vector.getDeltaY();
	deltaz_ -= vector.getDeltaZ();

	return *this;
}

Vector& Vector::operator*=(const Vector& vector)
{
	deltax_ * vector.getDeltaX();
	deltay_ *= vector.getDeltaY();
	deltaz_ *= vector.getDeltaZ();

	return *this;
}

Vector& Vector::operator*=(float scale)
{
	deltax_ *= scale;
	deltay_ *= scale;
	deltaz_ *= scale;

	return *this;
}

void Vector::show()
{

}
