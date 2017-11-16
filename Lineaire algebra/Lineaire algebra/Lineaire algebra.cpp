// Lineaire algebra.cpp : Defines the entry point for the console application.
//


#include <array>
#include "Matrix.h"
#include <iostream>

int main()
{
	float** array = new float*[3]; 
	for(int i = 0; i < 3; i++)
	{
		array[i] = new float[2];
	}
	for(int i = 0; i< 3; i++)
	{
		for(int j =0; j < 2; j++)
		{
			array[i][j] = 2; 
		}
	}
	
	Matrix m = Matrix(3,2, array); 
	auto a = m.scale(2,2, &m); 
	for(int i =0; i < a->xlength(); i++)
	{
		for(int j = 0; j < a->ylength(); j++)
		{
			std::cout << a->arraypunten[i][j] << std::endl;
		}
	}
    return 0;
}
