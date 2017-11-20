#pragma once
#include "Vector.h"
#include <vector>
template<typename T>
class Matrix
{
private :
	std::vector<T> array;
	int x; 
	int y; 
public:
	Matrix(int x1, int y2) : x(x1),y(y2),array(x1 * y2)
	{
	}
	~Matrix()
	{
		array.clear();
	}
	T& operator()(int x, int y) {
		return array[(this->y* x) + y];
	}
	Matrix& Matrix::operator*(Matrix& other)
	{
		Matrix product = Matrix(3, 3); 
		if (this->xlength() == other.ylength()) {
			float k = 0;
			for (int i = 0; i < this->ylength(); i++)
			{
				for (int l = 0; l < other.xlength(); l++)
				{
					for (int n = 0; n < other.ylength(); n++)
					{
						k += other(l, n) * array[(this->y * n) + i];
					}
					product(l, i) = k;
					k = 0;
				}
			}
		}
		return product; 
	}
	Matrix scale(float scalex, float scaley, float scalez)
	{
		Matrix scale = Matrix(3, 3);
		scale(0,0) = scalex;
		scale(1, 1) = scaley;
		scale(2, 2) = scalez;
		return scale;
	}
	
	Matrix translate(float transx, float transy)
	{
		Matrix scale = Matrix(3, 3);
		scale(0, 0) = 1;
		scale(1, 1) = 1;
		scale(2, 2) = 1;
		scale(2, 0) = transx;
		scale(2, 1) = transy;
		return scale; 
	}
	int xlength()
	{
		return x; 
	}
	int ylength()
	{
		return y; 
	}
	std::vector<T> getMatrix()
	{
		return array;
	}
};

