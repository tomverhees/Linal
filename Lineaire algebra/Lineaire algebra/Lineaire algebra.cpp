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
	
	Matrix<float> m = Matrix<float>(3,3); 
	for (int i = 0; i < m.xlength(); i++) {
		m(i, 0) = 5;
	}
	for (int i = 0; i < m.ylength(); i++) {
		m(i, 1) = 3;
	}
	for (int i = 0; i < m.ylength(); i++) {
		m(i, 2) = 1;
	}
	Matrix<float> n = Matrix<float>(3, 3);
	auto a = n.translate(1.8, 1.5);
	auto b = a * m; 
    return 0;
}
