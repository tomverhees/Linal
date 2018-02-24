#include "stdafx.h"
#include "Testvector.h"

#include <vector>
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>

Testvector::Testvector(float deltax, float deltay, float deltaz, float extra, float x, float y, float z)
	: x_(x)
	, y_(y)
	, z_(z)
	, extra_(extra)
	, deltax_(deltax)
	, deltay_(deltay)
	, deltaz_(deltaz)
{

}

void Testvector::scaleVector(float valuex, float valuey, float valuez)
{
	deltax_ *= valuex;
	deltay_ *= valuey;
	deltaz_ *= valuez;
}

float Testvector::getLength() const
{
	return sqrt(pow(deltax_, 2) + pow(deltay_, 2) + pow(deltaz_, 2));
}

void Testvector::normalize()
{
	const float length = getLength();
	deltax_ /= length;
	deltay_ /= length;
	deltaz_ /= length;
}

float Testvector::getDeltaX() const
{
	return deltax_;
}
float Testvector::getDeltaY() const
{
	return deltay_;
}

float Testvector::getDeltaZ() const
{
	return deltaz_;
}

Testvector Testvector::crossProduct(const Testvector& vector) const
{
	float deltax = deltay_ * vector.getDeltaZ() - deltaz_ * vector.getDeltaY();
	float deltay = deltaz_ * vector.getDeltaX() - deltax_ * vector.getDeltaZ();
	float deltaz = deltax_ * vector.getDeltaY() - deltay_ * vector.getDeltaX();

	return Testvector(deltax, deltay, deltaz);
}

float Testvector::inProduct(const Testvector& vector) const
{
	return deltax_ * vector.getDeltaX() + deltay_ * vector.getDeltaY() + deltaz_ * vector.getDeltaZ();
}

float Testvector::calculateAngle(const Testvector& vector) const
{
	float cos = inProduct(vector) / (getLength() * vector.getLength());
	cos = acos(cos);
	return cos * 180.0 / M_PI;
}

Testvector Testvector::operator+(const Testvector& vector) const
{
	return Testvector(deltax_ + vector.getDeltaX(), deltay_ + vector.getDeltaY(), deltaz_ + vector.getDeltaZ(), extra_ + vector.extra_, x_, y_, z_);
}

Testvector Testvector::operator-(const Testvector& vector) const
{
	return Testvector(deltax_ - vector.getDeltaX(), deltay_ - vector.getDeltaY(), deltaz_ - vector.getDeltaZ(), extra_ - vector.extra_, x_, y_, z_);
}

Testvector Testvector::operator*(const Testvector& vector) const
{
	return Testvector(deltax_ * vector.getDeltaX(), deltay_ * vector.getDeltaY(), deltaz_ * vector.getDeltaZ(), extra_ * vector.extra_, x_, y_, z_);
}

Testvector Testvector::operator*(float scale) const
{
	return Testvector(deltax_ * scale, deltay_ * scale, deltaz_ * scale, extra_*scale, x_, y_, z_);
}
