#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <sstream>


using namespace sf;
using namespace std;

class Block
{
public:

	Block();

	void print_block(int num);

	void set_Position(int x, int y);

	void get_Block(RenderWindow& Wind);

	void set_Text();

	void text_pos(int x, int y);

	void set_color();

	bool get_color();

	void check_collision();

	string GenerateValueString();

	int get_random();



	FloatRect is_collision();

private:

	int num;

	int rand_N;

	Texture block_tx;

	Sprite block_sp;

	Font font;

	Text block_text;

	string string_randN;

	bool txt_color = false;


};

