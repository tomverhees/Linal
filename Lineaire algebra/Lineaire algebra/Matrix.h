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
	Matrix<T> scale(float scalex, float scaley, float scalez)
	{
		Matrix<T> scale = Matrix(3, 3);
		scale(0,0) = scalex;
		scale(1, 1) = scaley;
		scale(2, 2) = scalez;
		return scale;
	}
	
	Matrix translate(float transx, float transy, Matrix<T>*m)
	{
		std::vector<T> arraypunten1;
		float myrow(5);
		Matrix scale = Matrix(3, 3, arraypunten1);
		for (int a = 0; a < scale.xlength() * scale.ylength(); a++)
		{
			scale.array.push_back(myrow);
		}
		scale.array(0, 0) = 1;
		scale.array(1, 1) = 1;
		scale.array(2, 2) = 1;
		scale.array(2, 0) = transx;
		scale.array(2, 1) = transy;

		for (int i = 0; i < m->xlength(); ++i) {
			m->array(i, 2).push_back(new Vector(1, 1));
		}
		float k = 0;
		for (int i = 0; i < scale.ylength(); i++)
		{
			for (int l = 0; l < m->xlength(); l++)
			{
				for (int n = 0; n < 3; n++)
				{
					k += m->array(l, n)->getlength() * scale.array(n, i);
				}
				m->array(l, i)->setLength(k);
				k = 0;
			}
		}
		for (int i = 0; i < m->xlength(); i++)
		{
			m->array(i, 2).pop_back();
		}
		return m;
	}
	int xlength();
	int ylength();
	std::vector<T> getMatrix();
};

