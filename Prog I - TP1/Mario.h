#pragma once

#include <SFML/Graphics.hpp>
#include "Afichmation.h"

using namespace sf;

class Mario : public Afichmation
{
public:

	Mario();

	

	void update();

	void controller(Event e); //separo la actualización del control de eventos

	void set_coll(bool collis);

	void collision(bool col);

	bool get_coll();

	bool collision_Control();

	void jumpControl();

	void spr_grap();


	Afichmation getCharacter();

private:

	Texture Mario_tx;

	Sprite Mario_sp;

	Afichmation _Mario;

	Event m_evt;

	int gravity = 9.8f;

	int groundPos = 650;

	bool jump = false;

	bool ground = true;

	bool isJumping = false;

	bool collision_ = true;

};

