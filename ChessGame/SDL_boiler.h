#pragma once

#include <SDL.h>
#include <stdio.h>
#include <SDL_image.h>
#include <iostream>
#include <string>
#undef main

//boiler plate class to initialize our window and render the background
class SDL_boiler
{
public:
	//for now we can keep it constant, but this will need to become adjustable in future iterations
	const int SCREEN_WIDTH = 800, SCREEN_HEIGHT = SCREEN_WIDTH;	//screen size
	
	//our board will consist of a series of 64 cells:each cell will occupy 100 pixels
	//this will change when transitioning to an adjustable resolution
	const int CELL = SCREEN_WIDTH / 8;

	//Create the window render, surface, renderer and event type all referenced to SDL
	SDL_Window* window;
	SDL_Surface* surface;
	SDL_Renderer* renderer;
	//event type->>mouse click
	SDL_Event* event;

	//bool condition for initilization
	bool init() {
		window = NULL;
		surface = NULL;

		if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			printf("SDL could not initialize!SDL error : % s\n", SDL_GetError());
			cleanUp();
			return false;
		}

		else {
			window = SDL_CreateWindow(
				"Simple Chess", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
				SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN
			);

			if (window == NULL)
				printf("Window could not be create. SDL error: %s\n", SDL_GetError());
			else
				renderer = SDL_CreateRenderer(window, -1, 0);

		}
		return true;
	}

	//cleaning function|
	void cleanUp() {
		SDL_FreeSurface(surface);
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
	}
	//constructor and destructor for SDL

	SDL_boiler() {
		bool init();
	}
	~SDL_boiler() {
		void cleanup();
	}

	//render the background
	void renderBackground();
	//Draw the rectangle spaces for each cell
	void DrawRectangle(SDL_Rect origin, SDL_Rect destination, SDL_Texture* texture);

	SDL_Texture* loadImage(std::string filename) {
		SDL_Surface* loadedImage = NULL;

		loadedImage = IMG_Load(filename.c_str());

		if (loadedImage == NULL) std::cout << "Could not draw " << filename << "\n";

		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, loadedImage);

		return texture;
	}


};