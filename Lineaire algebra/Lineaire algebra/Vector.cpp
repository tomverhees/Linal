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

Vector Vector::crossProduct(const Vector& vector) const
{
	float deltax = deltay_ * vector.getDeltaZ() - deltaz_ * vector.getDeltaY();
	float deltay = deltaz_ * vector.getDeltaX() - deltax_ * vector.getDeltaZ();
	float deltaz = deltax_ * vector.getDeltaY() - deltay_ * vector.getDeltaX();

	return Vector(deltax, deltay, deltaz);
}

float Vector::inProduct(const Vector& vector) const
{
	return deltax_ * vector.getDeltaX() + deltay_ * vector.getDeltaY() + deltaz_ * vector.getDeltaZ();
}

float Vector::calculateAngle(const Vector& vector) const
{
	float cos = inProduct(vector) / (getLength() * vector.getLength());
	cos = acos(cos);
	return cos * 180.0 / M_PI;
}

Vector Vector::operator+(const Vector& vector)
{
	return Vector(deltax_ + vector.getDeltaX(), deltay_ + vector.getDeltaY(), deltaz_ + vector.getDeltaZ(), x_, y_, z_);
}

Vector Vector::operator-(const Vector& vector) const
{
	return Vector(deltax_ - vector.getDeltaX(), deltay_ - vector.getDeltaY(), deltaz_ - vector.getDeltaZ(), x_, y_, z_);
}

Vector Vector::operator*(const Vector& vector) const
{
	return Vector(deltax_ * vector.getDeltaX(), deltay_ * vector.getDeltaY(), deltaz_ * vector.getDeltaZ(), x_, y_, z_);
}

Vector Vector::operator*(float scale) const
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
