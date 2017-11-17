// Lineaire algebra.cpp : Defines the entry point for the console application.
//


#include <array>
#include "Matrix.h"
#include <iostream>

int main()
{
	std::vector<std::vector<Vector*>> array; 
	 //
	for(int i = 0; i< 3; i++)
	{
		array.push_back(std::vector<Vector*>(1, new Vector(3, 1)));
		array[i].push_back(new Vector(2, 1));
	}
	for (int i = 0; i< 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << array[j][i]->getlength() << " ";
		}
		std::cout << std::endl;
	}
	Matrix m = Matrix(3,2, array); 
	auto a = m.scale(2,2, &m);
	auto b = m.translate(1.8, 1.5, &m);
    return 0;
}
