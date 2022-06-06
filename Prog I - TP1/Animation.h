#ifndef ANIMATION_H
#define ANIMATION_H

#include <vector>
#include <initializer_list>
#include <iostream>

using namespace std;

/*

Afichmation utility class for remembering animations.

*/

class Animation
{
	friend class Afichmation;

private:

	//Animation name's variable.
	string name;

	//Integer list that contains a list of values to represent frames in integers.
	vector <int> frames;

	//Frames list iterator.
	vector <int>::iterator it;

	//Booleano for remembering if the animation should be in loop or not.
	bool loop;

	//Animation's number of frames per second.
	int fps;

	//Current frame index.
	int frame;

	//Actual frame 
	int indexFrame;

	//Indicator of the end of the animation.
	bool finish;

public:

	//Constrcutor method.
	Animation(string name, initializer_list <int> frames, int fps, bool loop)
	{
		//Animation name.
		this->name = name;

		//Intergers list that contains the frame numbers about the animation.
		this->loop = loop;

		//Number of frames per second. 
		this->fps = fps;

		//Sets the animation execution in loop.
		this->frame = 0;

		finish = 0;

		initializer_list<int>::iterator iter = frames.begin();

		while (iter != frames.end())
		{
			this->frames.push_back(*iter);

			iter++;

		}

		this->indexFrame = *this->frames.begin();

	}


	//Exchange of frames method.

	void NextFrame()
	{
		if (frame >= frames.size())
		{
			frame = 0;

			if (!loop)
			{
				finish = true;
			}

		}

		it = frames.begin() + frame;

		indexFrame = *it;

		frame++;
	}

};
#endif

