// Lineaire algebra.cpp : Defines the entry point for the console application.
//

#include "Matrix.h"
#include <iostream>
#include "FWApplication.h"
#include <SDL.h>
#undef main
#include "Config.h"
#include "Prisma.h"
#include "Piramide.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	FWApplication application;

	Prisma prisma;
	application.AddRenderable(&prisma);

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
					prisma.rotateRoll(10);
					break;
				case SDLK_s:
					prisma.rotateRoll(-10);
					break;
				case SDLK_SPACE:
					bullets.push_back(prisma.shoot());
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

	return EXIT_SUCCESS;
}
