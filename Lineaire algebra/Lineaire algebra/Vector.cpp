#include "Vector.h"
#include <vector>
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
#include "FWApplication.h"

Vector::Vector(float deltax, float deltay, float deltaz, float x, float y, float z)
	: x_(x)
	, y_(y)
	, z_(z)
	, deltax_(deltax)
	, deltay_(deltay)
	, deltaz_(deltaz)
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
	const float length = getLength();
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

Vector Vector::crossProduct(Vector v, Vector v1) const
{
	float deltax = v.getDeltaY() * v1.getDeltaZ() - v.getDeltaZ() * v1.getDeltaY();
	float deltay = v.getDeltaZ() * v1.getDeltaX() - v.getDeltaX() * v1.getDeltaZ();
	float deltaz = v.getDeltaX() * v1.getDeltaY() - v.getDeltaY() * v1.getDeltaX();

	return Vector(deltax, deltay, deltaz);
}

float Vector::inProduct(Vector v, Vector v1) const
{
	return v.getDeltaX() * v1.getDeltaX() + v.getDeltaY() * v1.getDeltaY() + v.getDeltaZ() * v1.getDeltaZ();
}

float Vector::calculateAngle(Vector v, Vector v1) const
{
	float cos = inProduct(v, v1) / (v.getLength() * v1.getLength());
	cos = acos(cos);
	return cos * 180.0 / M_PI;
}

Vector Vector::operator+=(const Vector& vector)
{
	return Vector(deltax_ + vector.getDeltaX(), deltay_ + vector.getDeltaY(), deltaz_ + vector.getDeltaZ(), x_, y_, z_);
}

Vector Vector::operator-=(const Vector& vector) const
{
	return Vector(deltax_ - vector.getDeltaX(), deltay_ - vector.getDeltaY(), deltaz_ - vector.getDeltaZ(), x_, y_, z_);
}

Vector Vector::operator*=(const Vector& vector)
{
	return Vector(deltax_ * vector.getDeltaX(), deltay_ * vector.getDeltaY(), deltaz_ * vector.getDeltaZ(), x_, y_, z_);
}

Vector Vector::operator*=(float scale)
{
	return Vector(deltax_ * scale, deltay_ * scale, deltaz_ * scale, x_, y_, z_);
}

void Vector::Update(float deltaTime)
{

}

void Vector::Draw()
{
	mApplication->SetColor(Color(0, 0, 0, 0));
	mApplication->DrawLine(x_ * 10, y_ * 10, x_ * 10 + deltax_ * 10, y_ * 10 + deltay_ * 10);
	mApplication->SetColor(Color(255, 255, 255, 255));
}
