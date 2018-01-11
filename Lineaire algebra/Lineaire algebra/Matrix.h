#pragma once
#include "Vector.h"
#include <vector>
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
template<typename T>
class Matrix
{
private:
	std::vector<T> array;
	int x;
	int y;
public:
	Matrix(int x1, int y2) : x(x1), y(y2), array(x1 * y2)
	{
	}
	~Matrix()
	{
		array.clear();
	}
	T& operator()(int x, int y) {
		return array[(this->y* x) + y];
	}
	Matrix Matrix::operator*(const Matrix& other)
	{
		bool which = true;
		Matrix extra = Matrix(this->xlength(), this->xlength());
		if (this->ylength() > other.ylength())
		{
			extra = Matrix(this->xlength(), this->ylength());
			for (int i = 0; i < other.xlength(); i++)
			{
				for (int j = 0; j < other.ylength(); j++)
				{
					extra(i, j) = other.array[(other.ylength()* i) + j];
				}
			}
			which = true;
		}
		else
		{
			extra = Matrix(other.xlength(), other.xlength());
			for (int i = 0; i < this->xlength(); i++)
			{
				for (int j = 0; j < this->ylength(); j++)
				{
					extra(i, j) = array[(this->y* i) + j];
				}
			}
			which = false;
		}

		float k = 0;
		if (this->ylength() != other.ylength()) {
			if ((extra.xlength() == 4) && (extra.ylength() == 4))
			{
				extra(0, 3) = 0;
				extra(1, 3) = 0;
				extra(2, 3) = 0;
				extra(3, 3) = 1;
				extra(3, 2) = 0;
				extra(3, 1) = 0;
				extra(3, 0) = 0;
			}
			else {
				extra(0, 2) = 1;
				extra(1, 2) = 1;
				extra(2, 2) = 1;
			}
		}
		else
		{

		}

		Matrix product = Matrix(extra.xlength(), extra.ylength());
		if (which == true) {
			for (int i = 0; i < this->ylength(); i++)
			{
				for (int l = 0; l < extra.xlength(); l++)
				{
					for (int n = 0; n < extra.ylength(); n++)
					{
						k += extra(l, n) * array[(this->y * n) + i];
					}
					product(l, i) = k;
					k = 0;
				}
			}
		}
		else {
			for (int i = 0; i < other.ylength(); i++)
			{
				for (int l = 0; l < extra.xlength(); l++)
				{
					for (int n = 0; n < extra.ylength(); n++)
					{
						k += extra(n, i) * other.array[(other.ylength() * l) + n];
					}
					product(l, i) = k;
					k = 0;
				}
			}
		}
		return product;
	}
	Matrix rotateMatrix(float degrees)
	{
		float radians = degrees * (M_PI / 180);
		Matrix scale = Matrix(2, 2);
		scale(0, 0) = cos(radians);
		scale(0, 1) = sin(radians);
		scale(1, 0) = -sin(radians);
		scale(1, 1) = cos(radians);
		return scale;
	}
	Matrix rotateMatrixwp(float degrees)
	{
		float radians = degrees * (M_PI / 180);
		Matrix scale = Matrix(3, 3);
		scale(0, 0) = cos(radians);
		scale(0, 1) = sin(radians);
		scale(1, 0) = -sin(radians);
		scale(1, 1) = cos(radians);
		scale(2, 0) = 0;
		scale(2, 1) = 0;
		scale(2, 2) = 1;
		scale(0, 2) = 0;
		scale(1, 2) = 0;
		return scale;
	}
	Matrix rotate(float degrees, float x, float y)
	{
		Matrix product = Matrix(3, 3);
		if (x == 0 && y == 0)
		{
			product = rotateMatrix(degrees) * (*this);
		}
		else
		{
			product = (translate2d(x, y) * (rotateMatrixwp(degrees) * translate2d(-x, -y)) * (*this));
		}
		return product;
	}

	Matrix rotate3dO(float degrees, float x, float y, float z)
	{
		Matrix product = Matrix(3, 3);
		float t1 = atan2(z, x);
		auto t2 = atan2(y, sqrt((x*x) + (z*z)));
		product = (InverseRotateY(t1) * (InverseRotateZ(t2) * (rotateX(degrees) *(rotateZ(t2) * rotateY(t1)))) * (*this));
		return product;
	}
	Matrix rotate3dall(float degrees, float x, float y, float z)
	{
		Matrix product = Matrix(4, 4);
		float t1 = atan2(z, x);
		auto t2 = atan2(y, sqrt((x*x) + (z*z)));
		product = (translate3d(x, y, z) * (InverseRotateY(t1) * (InverseRotateZ(t2) * (rotateX(degrees) *(rotateZ(t2) * (rotateY(t1) * translate3d(-x, -y, -z)))))) * (*this) );
		return product;
	}
	Matrix rotateX(float degrees)
	{
		float radians = degrees * M_PI / 180;
		Matrix scale = Matrix(3, 3);
		scale(0, 0) = 1;
		scale(0, 1) = 0;
		scale(0, 2) = 0;
		scale(1, 0) = 0;
		scale(2, 0) = 0;
		scale(1, 1) = cos(radians);
		scale(1, 2) = sin(radians);
		scale(2, 1) = -sin(radians);
		scale(2, 2) = cos(radians);
		return scale;
	}
	Matrix rotateY(float radians)
	{
		//float radians = degrees * M_PI / 180;
		Matrix scale = Matrix(3, 3);
		scale(0, 0) = cos(radians);
		scale(0, 1) = 0;
		scale(0, 2) = sin(radians);
		scale(1, 0) = 0;
		scale(2, 0) = -sin(radians);
		scale(1, 1) = 1;
		scale(1, 2) = 0;
		scale(2, 1) = 0;
		scale(2, 2) = cos(radians);
		return scale;
	}
	Matrix InverseRotateY(float radians)
	{
		//float radians = degrees * M_PI / 180;
		Matrix scale = Matrix(3, 3);
		scale(0, 0) = cos(radians);
		scale(0, 1) = 0;
		scale(0, 2) = -sin(radians);
		scale(1, 0) = 0;
		scale(2, 0) = sin(radians);
		scale(1, 1) = 1;
		scale(1, 2) = 0;
		scale(2, 1) = 0;
		scale(2, 2) = cos(radians);
		return scale;
	}
	Matrix rotateZ(float radians)
	{
		//float radians = degrees * M_PI / 180;
		Matrix scale = Matrix(3, 3);
		scale(0, 0) = cos(radians);
		scale(0, 1) = sin(radians);
		scale(0, 2) = 0;
		scale(1, 0) = -sin(radians);
		scale(2, 0) = 0;
		scale(1, 1) = cos(radians);
		scale(1, 2) = 0;
		scale(2, 1) = 0;
		scale(2, 2) = 1;
		return scale;
	}
	Matrix InverseRotateZ(float radians)
	{
		//float radians = degrees * M_PI / 180;
		Matrix scale = Matrix(3, 3);
		scale(0, 0) = cos(radians);
		scale(0, 1) = -sin(radians);
		scale(0, 2) = 0;
		scale(1, 0) = sin(radians);
		scale(2, 0) = 0;
		scale(1, 1) = cos(radians);
		scale(1, 2) = 0;
		scale(2, 1) = 0;
		scale(2, 2) = 1;
		return scale;
	}
	Matrix scale2d(float scalex, float scaley)
	{
		Matrix scale = Matrix(2, 2);
		scale(0, 0) = scalex;
		scale(1, 1) = scaley;
		return scale;
	}
	Matrix scale3d(float scalex, float scaley, float scalez)
	{
		Matrix scale = Matrix(3, 3);
		scale(0, 0) = scalex;
		scale(1, 1) = scaley;
		scale(2, 2) = scalez;
		return scale;
	}
	Matrix translate2d(float transx, float transy)
	{
		Matrix scale = Matrix(3, 3);
		scale(0, 0) = 1;
		scale(1, 1) = 1;
		scale(2, 2) = 1;
		scale(2, 0) = transx;
		scale(2, 1) = transy;
		return scale;
	}
	Matrix translate3d(float transx, float transy, float transz)
	{
		Matrix scale = Matrix(4, 4);
		scale(0, 0) = 1;
		scale(1, 1) = 1;
		scale(2, 2) = 1;
		scale(3, 3) = 1;
		scale(3, 0) = transx;
		scale(3, 1) = transy;
		scale(3, 2) = transz;
		return scale;
	}
	int xlength() const
	{
		return x;
	}
	int ylength() const
	{
		return y;
	}
	std::vector<T> getMatrix()
	{
		return array;
	}
};

