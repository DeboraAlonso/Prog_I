#pragma once
#include <SFML/Graphics.hpp>

#include "Mario.h"
#include "Block.h"

#define HEIGHT 780
#define WIDTH 1024
#define PosY 450

using namespace sf;

class Game
{
public:

	Game();

	void gamescreen();

	void backg_grap();

	void fps();

	void draw();

	void loop();

	void check_collision();

private:

	RenderWindow Wind;

	Texture backg_tx;

	Sprite backg_sp;

	Event evt;

	Mario Character;

	Block _block[10];

	int PosX = 40;

	int ordered_num[10];

	int disordered_num[10];



};

