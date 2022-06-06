#ifndef AFICHMATION_H
#define AFICHMATION_H

#include <iostream>

#include <list>
#include <initializer_list>
#include <string>
#include <SFML/Graphics.hpp>
#include "Animation.h"

using namespace sf;
using namespace std;

/*Sprite's child class that executes the animations.*/

class Afichmation : public Sprite
{
private:

	//Spritesheet texture.
	Texture* texture;

	//Spritesheet's update control (fps control).
	Clock clock;

	//List of setted animation by Add method.
	list <Animation> animations;

	//Animation in use variable.
	Animation* animation;

	//Boolean to know if the animation is looping.
	bool isLooping;

	//Boolean to know if the animation should be turned horizontally.
	bool flippedX;

	//Boolean to know if the animation should be turned vertically.
	bool flippedY;

	//Boolean to know if the animation is playing.
	bool playing;

	//Frames width and height.
	int width, height;

	//Contains the current frame.
	IntRect frame;

	//Method to set the current frame.
	void SetCurrentFrame();

	//Sprite's scale update method.
	void UpdateScale();

public:
	//Default constructor - no implemented.
	Afichmation() {}

	//Constructor
	/*
	path   -> Spritesheet file.
	loop   -> animation loop.
	width  -> frame width.
	height -> frame height.
	*/
	Afichmation(string path, bool loop, int width, int height);

	//Overload constructor
	/*
	tex    -> sprite texture.
	loop   -> animation loop.
	width  -> frame width.
	height -> frame height.
	*/
	Afichmation(Texture& tex, bool loop, int width, int height);

	//Class destructor - no implemented.
	~Afichmation() {}

	//Method (yes/no) to turn the character horizontally.
	void FlipX(bool isFlipped);

	//Method (yes/no) to turn the character vertically.
	void FlipY(bool isFlipped);

	//Method to add an animation to the list.
	/*

	name   -> animation's name.
	frames -> animation's frames -> for ex: {0,1,2,3}.
	fps    -> frames per second of the animation.
	loop   -> animation playback loop.

	*/
	void Add(string name, initializer_list <int> frames, int fps, bool loop);

	//Animation execution method.
	//name -> animation name
	void Play(string name);

	//Method to know the animations in execution.
	//name -> Animation's name we want to find.
	bool IsPlaying(string name);

	//Class status update method.
	void Update();

	/* Overwritten Sprite methods */

	//x -> float for component X.
	//y -> float for component Y.
	void setPosition(float x, float y);

	//position -> read-only position in Vector2f format.
	void setPosition(const Vector2f& posiiton);

	//factorx -> float for component X.
	//factory -> float for component Y.
	void setScale(float factorx, float factory);

	//factors -> read-only scale in Vector2f format.
	void setScale(const Vector2f& factors);

	//Returns the sprite's scale in Vector2f format.
	const Vector2f& getScale();

};
#endif


