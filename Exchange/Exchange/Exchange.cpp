#include "pch.h"

// OpenGL headers
#include <GL/glew.h>


// SDL headers
#include <SDL_main.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_ttf.h>

#include <iostream>
#include <string>
#include "GLRendererColor.h"
#include "SquareMeshVbo.h"
#include "Game.h"



using namespace std;

bool quit;
const GLint WIDTH = 1280, HEIGHT = 720;
float deltaTime = 0.0f, lastFrame = 0.0f;

SDL_Window* window;
SDL_GLContext glContext;
SDL_Event sdlEvent;

Game * game = nullptr;

int main(int argc, char *argv[])
{

	quit = false;

	//Use OpenGL 3.1 core
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	// Initialize video subsystem
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		// Display error message
		cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
		return false;
	}
	else
	{
		// Create window
		window = SDL_CreateWindow("My Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			// Display error message
			cout << "Window could not be created! SDL_Error" << SDL_GetError() << endl;
			return false;
		}
		else
		{
			TTF_Init();
			// Create OpenGL context
			glContext = SDL_GL_CreateContext(window);

			if (glContext == NULL)
			{
				// Display error message
				cout << "OpenGL context could not be created! SDL Error: " << SDL_GetError() << endl;
				return false;
			}
			else
			{
				// Initialize glew
				GLenum glewError = glewInit();
				if (glewError != GLEW_OK)
				{
					cout << "Error initializing GLEW! " << glewGetErrorString(glewError) << endl;
					return false;
				}
				if (SDL_GL_SetSwapInterval(1) < 0)
				{
					cout << "Warning: Unable to set VSync! SDL Error: " << SDL_GetError() << endl;
				}

				game = Game::getInstance();
				game->init(WIDTH, HEIGHT);

			}
		}
	}
	float fps = 1000.0f / 60.0f;
	// Game loop
	while (!quit)
	{
		float currentFrame = SDL_GetTicks();
		if (currentFrame < lastFrame + fps)
		{
			continue;
		}
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		while (SDL_PollEvent(&sdlEvent) != 0)
		{
			// Esc button is pressed
			if (sdlEvent.type == SDL_QUIT)
			{
				quit = true;
			}
			else if (sdlEvent.type == SDL_KEYDOWN) {

				switch (sdlEvent.key.keysym.sym)
				{
				case SDLK_LEFT: game->handleKey('l'); break;
				case SDLK_RIGHT:game->handleKey('r'); break;
				case SDLK_UP: game->handleKey('u');   break;
				case SDLK_DOWN:game->handleKey('d');  break;

				}
			}
			else if (sdlEvent.type == SDL_MOUSEBUTTONDOWN) {
				if (sdlEvent.button.button = SDL_BUTTON_LEFT) {
					game->handleMouse(sdlEvent.button.x, sdlEvent.button.y);
				}
			}
		}
		game->update(deltaTime);
		game->render();

		SDL_GL_SwapWindow(window);
	}

	//Destroy window
	SDL_DestroyWindow(window);
	window = NULL;

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}

