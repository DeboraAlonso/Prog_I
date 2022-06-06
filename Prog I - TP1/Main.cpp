#include <stdlib.h>
#include <time.h>
#include <ctime>

#include "Game.h"

using namespace sf;

int main()
{
	srand(time(NULL));

	Game Mario;

	Mario.loop();

}