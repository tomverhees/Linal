// Lineaire algebra.cpp : Defines the entry point for the console application.
//

#include "Matrix.h"
#include <iostream>
#include "FWApplication.h"
#include <SDL.h>
#undef main
#include "Config.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	FWApplication application;
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
