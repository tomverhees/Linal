// Lineaire algebra.cpp : Defines the entry point for the console application.
//

#include "Matrix.h"
#include <iostream>
#include "FWApplication.h"
#include <SDL.h>
#undef main
#include "Config.h"
#include "Vector.h"
#include "prisma.h"
#include "Piramide.h"

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

	Matrix<float> testright = Matrix<float>(4, 3);
	testright(0, 0) = 15;
	testright(0, 1) = 0;
	testright(0, 2) = 5;
	testright(1, 0) = -15;
	testright(1, 1) = -10;
	testright(1, 2) = 5;
	testright(2, 0) = -15;
	testright(2, 1) = -10;
	testright(2, 2) = -5;
	testright(3, 0) = 15;
	testright(3, 1) = 0;
	testright(3, 2) = -5;


	Matrix<float> testtop = Matrix<float>(3, 3);
	testtop(0, 0) = 15;
	testtop(0, 1) = 0;
	testtop(0, 2) = 5;
	testtop(1, 0) = -15;
	testtop(1, 1) = 10;
	testtop(1, 2) = 5;
	testtop(2, 0) = -15;
	testtop(2, 1) = -10;
	testtop(2, 2) = 5;

	Matrix<float> testbot = Matrix<float>(3, 3);
	testbot(0, 0) = 15;
	testbot(0, 1) = 0;
	testbot(0, 2) = -5;
	testbot(1, 0) = -15;
	testbot(1, 1) = 10;
	testbot(1, 2) = -5;
	testbot(2, 0) = -15;
	testbot(2, 1) = -10;
	testbot(2, 2) = 5;

	Matrix<float> testleft = Matrix<float>(4, 3);
	testleft(0, 0) = 15;
	testleft(0, 1) = 0;
	testleft(0, 2) = 5;
	testleft(1, 0) = -15;
	testleft(1, 1) = 10;
	testleft(1, 2) = 5;
	testleft(2, 0) = -15;
	testleft(2, 1) = 10;
	testleft(2, 2) = -5;
	testleft(3, 0) = 15;
	testleft(3, 1) = 0;
	testleft(3, 2) = -5;

	Matrix<float> testback = Matrix<float>(4, 3);
	testback(0, 0) = -15;
	testback(0, 1) = 10;
	testback(0, 2) = 5;
	testback(1, 0) = -15;
	testback(1, 1) = -10;
	testback(1, 2) = 5;
	testback(2, 0) = -15;
	testback(2, 1) = -10;
	testback(2, 2) = -5;
	testback(3, 0) = -15;
	testback(3, 1) = 10;
	testback(3, 2) = -5;


	//Matrix<float> matrix3 = matrix5.scale2d(5, 5) * matrix5;
	//Matrix<float> matrix4 = matrix3.rotate(90, 5,5);
	prisma prisma;
	application.AddRenderable(&prisma);
	prisma.rotate(50);
	for (int i = 0; i < prisma.getSides().size(); i++)
	{
		application.AddRenderable(&prisma.getSides()[i]);

	}

	Piramide piramide;
	
	for (int i = 0; i < piramide.getSides().size(); i++)
	{
		application.AddRenderable(&piramide.getSides()[i]);
	}
	application.AddRenderable(&piramide);

	

	//application.AddRenderable(&matrix2);
	//application.AddRenderable(&matrix3);
	//application.AddRenderable(&matrix4);


	// Camera positie
	// near minimale afstand die je ziet
	// far tot waar je kan kijken
	// testen met 100,100,100 cubus 
	// lookat oorsprong
	// scherm vierkant (bijv 600,600)


	//application.AddRenderable(&displayVector);
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

	Matrix<float> m = Matrix<float>(4, 4);
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
	//auto f = m * k;

	return EXIT_SUCCESS;
}
