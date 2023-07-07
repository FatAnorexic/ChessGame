#include "SDL_boiler.h"

void SDL_boiler::renderBackground() {
	bool white = true;
	int cell = 8;
	std::string filename="../resource/wood.png";

	SDL_Surface* image = IMG_Load(filename.c_str());

	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);

	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	//draw the checker board using a nested loop. 
	for (int x = 0; x < cell; x++) {
		for (int y = 0; y < cell; y++)
		{
			if (!white)
				SDL_SetRenderDrawColor(renderer, 68, 128, 14, 200);
			else
				SDL_SetRenderDrawColor(renderer, 220, 255, 224, 200);
			
			white = !white;
			SDL_Rect rectangle = { x * SCREEN_WIDTH / 8, y * SCREEN_HEIGHT / 8, SCREEN_WIDTH / 8, SCREEN_HEIGHT / 8 };

			SDL_RenderFillRect(renderer, &rectangle);
		}
		white = !white;
	}
}

void SDL_boiler::DrawRectangle(SDL_Rect source, SDL_Rect destination, SDL_Texture* texture) {
	if (texture != nullptr) {
		SDL_RenderCopy(renderer, texture, &source, &destination);
		SDL_RenderPresent(renderer);
		SDL_UpdateWindowSurface(window);
	}

	else
		printf("Draw Rectangle: Texture was null pointer.\n");
}