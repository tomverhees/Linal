#pragma once
#include "Vector.h"
#include <vector>

class Matrix
{
private :
	Vector*** array;
	int x; 
	int y; 
public:
	float** arraypunten;

	Matrix(int x1, int y2, float** hoi);
	~Matrix();
	Matrix * scale(float scalex, float scaley, Matrix *m);
	Matrix* translate(float scalex, float scaley, Matrix* m);
	int xlength();
	int ylength();
};

