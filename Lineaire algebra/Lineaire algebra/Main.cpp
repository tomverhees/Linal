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

	//Matrix<float> matrix3 = matrix5.scale2d(5, 5) * matrix5;
	//Matrix<float> matrix4 = matrix3.rotate(90, 5,5);
	prisma prisma;
	application.AddRenderable(&prisma);
	//prisma.rotate(50);
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

	std::vector<Bullet> bullets; 
	
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
				case SDLK_UP:
					prisma.move(0, -1);
					break;
				case SDLK_DOWN:
					prisma.move(0, 1);
					break;
				case SDLK_RIGHT:
					prisma.move(-1, 0);
					break;
				case SDLK_LEFT:
					prisma.move(1, 0);
					break;
				case SDLK_KP_8:
					prisma.rotate(10);
					break;
				case SDLK_KP_2:
					prisma.rotate(-10);
					break;
				case SDLK_KP_6:
					prisma.rotateVertical(10);
					break;
				case SDLK_KP_4:
					prisma.rotateVertical(-10);
					break;
				case SDLK_w:
					//camera.translate(0, 1, 0);
					prisma.rotateRoll(10); 
					break;
				case SDLK_s:
					prisma.rotateRoll(-10);
					//camera.translate(0, -1, 0);
					break;
				case SDLK_SPACE:
					bullets.push_back(prisma.shoot());
					//camera.translate(1, 0, 0);
					break;
					// Camera LEFT
				case SDLK_a:
					//camera.translate(-1, 0, 0);
					break;
					// Camera ZOOM IN
				case SDLK_PAGEUP:
					//camera.translate(0, 0, 1);
					break;
					// Camera ZOOM OUT
				case SDLK_PAGEDOWN:
					//camera.translate(0, 0, -1);
					break;
				default:
					break;
				}
			default:
				break;
			}
		}

		// For the background
		application.SetColor(Color(255, 255, 255, 255));

		for (auto &element : bullets)
		{
			element.Update(0);
			element.Draw(); 
		}
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

	
	//auto f = m * k;

	return EXIT_SUCCESS;
}
