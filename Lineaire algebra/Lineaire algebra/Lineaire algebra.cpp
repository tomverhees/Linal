// Lineaire algebra.cpp : Defines the entry point for the console application.
//


#include <array>
#include "Matrix.h"
#include <iostream>

int main()
{
	std::vector<float> array; 
	 //
	for(int i = 0; i< 9; i++)
	{
		array.push_back(3);
	}
	for (int j = 0; j < 9; j++)
	{
		std::cout << array[j] << " ";
	}
	std::cout << std::endl;
	
	Matrix<float> m = Matrix<float>(3,2); 
	auto a = m.scale(2,2, 2);
	//auto b = m.translate(1.8, 1.5, &m);
    return 0;
}
