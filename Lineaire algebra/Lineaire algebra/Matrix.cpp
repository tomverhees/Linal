
#include "Matrix.h"
#include <algorithm>
#include <memory>
#include <vector>
#include <iostream>

Matrix::Matrix(int x, int y, std::vector<std::vector<float>> arraypunten1)
{
	this->x = x;
	this->y = y;
	
	arraypunten = arraypunten1;
}
Matrix::Matrix(int x, int y, std::vector<std::vector<Vector*>> arraypunten1)
{
	this->x = x;
	this->y = y;

	array = arraypunten1;
}

Matrix::~Matrix()
{
}

Matrix* Matrix::scale(float scalex, float scaley, Matrix *m)
{
	std::vector<std::vector<float>> arraypunten1; 
	std::vector<float> myrow(1, scalex);
	Matrix scale = Matrix(2,2, arraypunten1);
	for(int a =0; a < scale.xlength(); a++)
	{
		scale.arraypunten.push_back(myrow);
		scale.arraypunten[a].push_back(0);
	}
	scale.arraypunten[0][0] = scalex; 
	scale.arraypunten[1][1] = scaley;
	scale.arraypunten[1][0] = 0;
	float k = 0; 
	if (scale.xlength() == m->ylength()) {
		for (int i = 0; i < scale.ylength(); i++)
		{
			for (int l = 0; l < m->xlength(); l++)
			{
				for (int n = 0; n < m->ylength(); n++)
				{
					k += m->array[l][n]->getlength() * scale.arraypunten[n][i];
				}
				m->array[l][i]->setLength(k);
				k = 0;
			}
		}
	}
	std::cout << "m:" << std::endl;
	for (int i = 0; i< 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << m->array[j][i]->getlength() << "  ";
		}
		std::cout << std::endl;
	}
	return m;
}

Matrix * Matrix::translate(float transx, float transy, Matrix *m)
{
	std::vector<std::vector<float>> arraypunten1;
	std::vector<float> myrow(3, 0);
	Matrix scale = Matrix(3, 3, arraypunten1);
	for (int a = 0; a < scale.xlength(); a++)
	{
		scale.arraypunten.push_back(myrow); 
	}
	scale.arraypunten[0][0] = 1;
	scale.arraypunten[1][1] = 1;
	scale.arraypunten[2][2] = 1;
	scale.arraypunten[2][0] = transx;
	scale.arraypunten[2][1] = transy;
 
	for (int i = 0; i < m->xlength(); ++i) {
		m->array[i].push_back(new Vector(1, 1)); 
	}
	float k = 0;
	for (int i = 0; i < scale.ylength(); i++)
	{
		for (int l = 0; l < m->xlength(); l++)
		{
			for (int n = 0; n < 3; n++)
			{
				k += m->array[l][n]->getlength() * scale.arraypunten[n][i];
			}
			m->array[l][i]->setLength(k);
			k = 0;
		}
	}
	for(int i = 0; i < m->xlength(); i++)
	{
		m->array[i].pop_back();
	}
	std::cout << "Scale:" << std::endl;
	for (int i = 0; i< 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << scale.arraypunten[j][i] << "  ";
		}
		std::cout << std::endl;
	}
	std::cout << "m:" << std::endl;
	for (int i = 0; i< 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << m->array[j][i]->getlength() << "  ";
		}
		std::cout << std::endl;
	}
	return m;
}


int Matrix::xlength()
{
	return x;
}

int Matrix::ylength()
{
	return y;
}

std::vector<std::vector<Vector*>> Matrix::getMatrix()
{
	return array; 
}

