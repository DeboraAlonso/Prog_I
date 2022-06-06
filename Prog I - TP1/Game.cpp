#include "Game.h"

Game::Game()
{

	gamescreen();

	fps();

	backg_grap();

	for (int j = 0; j < 10; j++)
	{
		_block[j].set_Position(PosX, PosY);

		_block[j].text_pos(PosX, PosY);
		
		PosX = PosX + 110;
	}

}

void Game::gamescreen()
{
	Wind.create(VideoMode(WIDTH, HEIGHT, 32), "Prog practice part 1");//bits per pixel refiere a la profundidad de color en bits a utilizar
	/*En videomode primero WIDTH y luego HEIGHT te intercambio los valores de las constantes*/
}

void Game::fps()
{
	Wind.setVerticalSyncEnabled(true);//la habilitación de sincronización vertical requiere un true o false

	Wind.setFramerateLimit(60);
}

void Game::backg_grap()
{
	//Setting background graphics.
	backg_tx.loadFromFile("Assets/Background.jpg");

	backg_sp.setTexture(backg_tx);

	backg_sp.setScale(Vector2f (1.28f, 1.3f));
}

void Game::draw()
{
	Wind.draw(backg_sp);

	Wind.draw(Character.getCharacter());

	for (int i = 0; i < 10; i++)
	{
		_block[i].get_Block(Wind);
	}
	
	Wind.display();

}

void Game::loop()// te dejé algunas correcciones de orden y de control de eventos
{
	Event e;
	while (Wind.isOpen())
	{
		while (Wind.pollEvent(e))
		{
			if (e.key.code == Event::Closed || e.key.code == Keyboard::Escape)
			{
				Wind.close();
			}
			//Processing Sprite jump.
			Character.jumpControl();

				check_collision();
		}
		//Processing events from Mario's class.
		Character.controller(e);

		//Processing animation update.
		Character.update();



		Wind.clear();

		draw();

	}
}

void Game::check_collision()
{

	FloatRect character_ = Character.getGlobalBounds();

	for (int i = 0; i < 10; i++)
	{
		FloatRect block_ = _block[i].is_collision();

		if (character_.intersects(block_))
		{
			if (Character.collision_Control())
			{
				Character.collision(true);

				Character.set_coll(true);

				Character.Play("hit");

			}
		}
	}
}