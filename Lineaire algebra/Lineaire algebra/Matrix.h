#pragma once
#include "Vector.h"
#include <vector>

class Matrix
{
private :
	std::vector<std::vector<Vector*>> array;
	int x; 
	int y; 
public:

	std::vector<std::vector<float>> arraypunten;
	Matrix(int x1, int y2, std::vector<std::vector<float>> arraypunten1);
	Matrix(int x, int y, std::vector<std::vector<Vector*>> arraypunten1);
	~Matrix();

	Matrix * scale(float scalex, float scaley, Matrix *m);
	Matrix* translate(float scalex, float scaley, Matrix* m);
	int xlength();
	int ylength();
	std::vector<std::vector<Vector*>> getMatrix();
};

