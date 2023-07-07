#include "Start.h"

void Start::run() {
	SDL_boiler instance;
	
	instance.init();

	instance.renderBackground();
}