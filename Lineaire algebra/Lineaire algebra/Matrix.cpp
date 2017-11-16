#include "Matrix.h"
#include <algorithm>
#include <memory>
#include <vector>
#include <iostream>

Matrix::Matrix(int x, int y, float** hoi)
{
	this->x = x;
	this->y = y;
	arraypunten = new float*[x];
	for (int i = 0; i < x; ++i){
		arraypunten[i] = new float[y]; 
	}
	memcpy(arraypunten, hoi, 9);
}

Matrix::~Matrix()
{
}

Matrix* Matrix::scale(float scalex, float scaley, Matrix *m)
{
	float** array = new float*[2];
	for(int i =0 ; i< 2;i++)
	{
		array[i] = new float[2];
	}
	Matrix scale = Matrix(2,2, array);
	for(int a =0; a < scale.xlength(); a++)
	{
		for(int b = 0; b < scale.ylength(); b++)
		{
			scale.arraypunten[a][b] = 0; 
		}
	}
	scale.arraypunten[0][0] = scalex;
	scale.arraypunten[1][1] = scaley;
	int k = 0; 
	if (scale.xlength() == m->ylength()) {
		for (int i = 0; i < scale.ylength(); i++)
		{
			for (int l = 0; l < m->xlength(); l++)
			{
				for (int n = 0; n < m->ylength(); n++)
				{
					k += m->arraypunten[l][n] * scale.arraypunten[n][i];
				}
				m->arraypunten[l][i] = k;
				k = 0;
			}
		}
	}
	return m;
}

//Matrix * Matrix::translate(float transx, float transy, Matrix *m)
//{
//	Matrix scale = Matrix(3, 3);
//	for (int a = 0; a < scale.xlength(); a++)
//	{
//		for (int b = 0; b < scale.ylength(); b++)
//		{
//			scale.arraypunten[a][b] = 0;
//		}
//	}
//	scale.arraypunten[0][0] = 1;
//	scale.arraypunten[1][1] = 1;
//	scale.arraypunten[2][2] = 1;
//	scale.arraypunten[2][0] = transx;
//	scale.arraypunten[2][1] = transy;
//	float** fl = new float*[m->xlength()];
//	for (int i = 0; i < m->xlength(); ++i) {
//		fl[i] = new float[3]; 
//	}
//	memcpy(fl, m->arraypunten, sizeof(m->arraypunten)); 
//	for (int i = 0; i < m->xlength(); ++i) {
//		m->arraypunten[i] = new float[3];
//		memcpy(m->arraypunten, fl, sizeof(fl));
//		m->arraypunten[i][3] = 1; 
//	}
//	for (int k = 0; k < m->xlength(); k++)
//	{
//		delete[] fl[k]; 
//	}
//	delete[] fl;
//	int k = 0;
//	for (int i = 0; i < scale.ylength(); i++)
//	{
//		for (int l = 0; l < m->xlength(); l++)
//		{
//			for (int n = 0; n < m->ylength(); n++)
//			{
//				k += m->arraypunten[n][i] * scale.arraypunten[l][n];
//			}
//			m->arraypunten[l][i] = k;
//			k = 0;
//		}
//	}
//}


int Matrix::xlength()
{
	return x;
}

int Matrix::ylength()
{
	return y;
}

