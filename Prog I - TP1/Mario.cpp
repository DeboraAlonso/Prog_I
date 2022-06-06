#include "Mario.h"

Mario::Mario()
{
	//Drawing the sprithsheet.
	spr_grap();

}

void Mario::spr_grap()
{
	_Mario = Afichmation("assets/spritesheet.png", true, 104, 125);

	_Mario.Add("idle", { 0, 2, 1, 0, 2, 1, 2 }, 3.f, true);

	//Run animation.
	_Mario.Add("run", { 3, 4, 5, 6, 7, 8, }, 7, true);

	//Jump animation.
	_Mario.Add("jump", { 12, 13, 14 }, 9, true);

	_Mario.Add("hit", { 15 }, 9, true);

	//Executing an animation from a sprite. In this case from 'idle'
	_Mario.Play("idle");

	//Setting the scale using Sprite's methods.
	_Mario.setScale(Vector2f(0.6f, 0.6f));

	_Mario.setPosition(_Mario.getPosition().x, groundPos);

	/*Mario was in an inverted position because I erased the method without realizing it.*/
}

Afichmation Mario::getCharacter()
{
	return _Mario;
}


void Mario::update()
{
	//Afichmation update

	_Mario.Update();/*Hay que actualizar el propio Afichmation para que funcione la animación*/

	//Hay que controlar el salto en todo ciclo...
	jumpControl();

}

void Mario::jumpControl()//Jump method
{
	if (isJumping)
	{
		//Getting if the Mario's position in the Y component is the same that the floor.
		if (_Mario.getPosition().y <= groundPos - 430)
		{
			//Boolen jump = false;
			jump = false;
		}

		if (jump)
		{
			//Setting the Mario's position against gravity.
			_Mario.setPosition(_Mario.getPosition().x, _Mario.getPosition().y - gravity);

		}
		else
		{
			//Setting the Sprite been afected for the gravity force.
			_Mario.setPosition(_Mario.getPosition().x, _Mario.getPosition().y + gravity);

			//jump;

		}

		//Setting Mario's position at the same level to the floor.
		if (_Mario.getPosition().y >= groundPos)
		{
			//Boolean "jump in process?"
			//isJumping;

			_Mario.setPosition(_Mario.getPosition().x, groundPos);
			_Mario.Play("idle");
			ground = true;
		}

	}

}

void Mario::controller(Event e)
{
	if (e.type == Event::KeyPressed)
	{
		//Executing the sprite left movements.
		if (e.key.code == Keyboard::Left)
		{
			_Mario.Play("run");

			_Mario.FlipX(false);

			_Mario.move(-4, 0);
		}
		//Executing the sprite right movements.
		if (e.key.code == Keyboard::Right)
		{
			_Mario.Play("run");

			_Mario.FlipX(true);

			_Mario.setPosition(_Mario.getPosition().x + 4, _Mario.getPosition().y);
		}

		//Executing the sprite jump.
		if (e.key.code == Keyboard::Up)
		{
			if (ground && !jump)
			{
				_Mario.Play("jump");

				_Mario.FlipY(false);

				//jump;
				jump = true;

				isJumping = true;//en algún momento hay que activarlo

				//!ground;
				ground = false;

			}
			
			if (!jump && collision_)
			{

				//ground = true;

				_Mario.Play("hit");
				
			}
		}
	}
	else
	{
		_Mario.Play("idle");
	}
}
void Mario::set_coll(bool collis)
{
	collision_ = collis;
}

void Mario::collision(bool col)
{
	collision_ = col;
}

bool Mario::get_coll()
{
	return collision_;
}

bool Mario::collision_Control()
{
	return collision_;
}
