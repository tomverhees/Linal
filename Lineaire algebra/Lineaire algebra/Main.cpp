// Lineaire algebra.cpp : Defines the entry point for the console application.
//

#include "Matrix.h"
#include <iostream>
#include "FWApplication.h"
#include <SDL.h>
#undef main
#include "Config.h"
#include "Vector.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	FWApplication application;

	/*Vector v1 = Vector(2, 4, 0);
	Vector v2 = Vector(2, -3, 0, 4, 5);
	Vector v3 = v1 *= v2;
	application.AddRenderable(&v1);
	application.AddRenderable(&v2);
	application.AddRenderable(&v3);*/

	Matrix<float> matrix1 = Matrix<float>(3, 3);
	matrix1(0, 0) = 0;
	matrix1(0, 1) = 0;
	matrix1(1, 0) = 1;
	matrix1(1, 1) = 1;
	matrix1(2, 0) = 0;
	matrix1(2, 1) = 2;
	matrix1(2, 2) = 1; 

	Matrix<float> matrix5 = Matrix<float>(3, 2);
	matrix5(0, 0) = 0;
	matrix5(0, 1) = 0;
	matrix5(1, 0) = 1;
	matrix5(1, 1) = 1;
	matrix5(2, 0) = 0;
	matrix5(2, 1) = 2;
	Matrix<float> matrix2 = matrix1.translate2d(5, 5) * matrix1;

	Matrix<float> matrix3 = matrix5.scale2d(5, 5) * matrix5;
	Matrix<float> matrix4 = matrix3.rotate(90, 5,5);
	application.AddRenderable(&matrix5);
	//application.AddRenderable(&matrix2);
	application.AddRenderable(&matrix3);
	application.AddRenderable(&matrix4);

	/*Matrix<float> matrixCube = Matrix<float>(8, 4);
	matrixCube(0, 0) = 2;
	matrixCube(0, 1) = 4;
	matrixCube(0, 2) = 5;
	matrixCube(1, 0) = 5;
	matrixCube(1, 1) = 4;
	matrixCube(1, 2) = 5;
	matrixCube(2, 0) = 5;
	matrixCube(2, 1) = 8;
	matrixCube(2, 2) = 5;
	matrixCube(3, 0) = 2;
	matrixCube(3, 1) = 8;
	matrixCube(3, 2) = 5;

	matrixCube(4, 0) = 2;
	matrixCube(4, 1) = 4;
	matrixCube(4, 2) = 10;
	matrixCube(5, 0) = 5;
	matrixCube(5, 1) = 4;
	matrixCube(5, 2) = 10;
	matrixCube(6, 0) = 5;
	matrixCube(6, 1) = 8;
	matrixCube(6, 2) = 10;
	matrixCube(7, 0) = 2;
	matrixCube(7, 1) = 8;
	matrixCube(7, 2) = 10;*/

	// Camera positie
	// near minimale afstand die je ziet
	// far tot waar je kan kijken
	// testen met 100,100,100 cubus 
	// lookat oorsprong
	// scherm vierkant (bijv 600,600)
	//Vector eye = Vector(400, 300, 0);
	//Vector lookAt = Vector(2, 4, 5);
	//Vector up = Vector(0, 1, 0);
	//Matrix<float> cameraMatrix = Matrix<float>(4, 4);
	//cameraMatrix = cameraMatrix.generateCameraMatrix(eye, lookAt, up);
	//Matrix<float> perspectionMatrix = Matrix<float>(4, 4);
	//perspectionMatrix = perspectionMatrix.generatePerspectionMatrix(5, 10, 90);
	//Matrix<float> displayVector = perspectionMatrix * cameraMatrix * matrixCube;
	//displayVector.afterCalculation(400);
/*
	application.AddRenderable(&displayVector);*/
	if (!application.GetWindow())
	{
		LOG("Couldn't create window...");
		return EXIT_FAILURE;
	}

	application.SetTargetFPS(30);

	while (application.IsRunning())
	{
		application.StartTick();

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				application.Quit();
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym) {

				default:
					break;
				}
			default:
				break;
			}
		}

		// For the background
		application.SetColor(Color(255, 255, 255, 255));

		application.UpdateGameObjects();
		application.RenderGameObjects();
		application.EndTick();
	}

	std::vector<float> array;
	//
	for (int i = 0; i < 9; i++)
	{
		array.push_back(3);
	}
	for (int j = 0; j < 9; j++)
	{
		std::cout << array[j] << " ";
	}
	std::cout << std::endl;

	Matrix<float> m = Matrix<float>(3, 2);
	/*for (int i = 0; i < m.xlength(); i++) {
		m(i, 0) = 5;
	}
	for (int i = 0; i < m.xlength(); i++) {
		m(i, 1) = 3;
	}*/

	m(0, 0) = 2;
	m(0, 1) = 2;
	m(1, 0) = 2;
	m(1, 1) = 2;
	m(2, 0) = 2;
	m(2, 1) = 2;
	Matrix<float> n = Matrix<float>(3, 3);
	auto k = n.translate2d(0.1, 0.1);
	auto l = m.rotate3dall(10, 5, 2, 3);
	auto f = m * k;

	return EXIT_SUCCESS;
}
