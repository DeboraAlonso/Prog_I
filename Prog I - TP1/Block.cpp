#include "Block.h"

Block::Block()
{
	print_block( num);

	set_Text();

}

void Block::print_block(int num)
{
	block_tx.loadFromFile("Assets/block.png");
	block_sp.setTexture(block_tx);
	block_sp.setScale(Vector2f(1.6f, 1.f));
}

void Block::set_Position(int x, int y)
{
	block_sp.setPosition(x, y);
	
}

void Block::get_Block(RenderWindow& Wind)
{
	Wind.draw(block_sp);

	Wind.draw(block_text);
}

void Block::set_Text()
{

	font.loadFromFile("Assets/SuperMario.ttf");
	block_text.setFont(font);
	block_text.setString(GenerateValueString());
	block_text.setCharacterSize(20);
	block_text.setFillColor(Color::White);
	block_text.setOutlineColor(Color::Black);
	block_text.setOutlineThickness(2.5f);
	block_text.Bold;
	block_text.setLetterSpacing(1.5f);

}

void Block::text_pos(int x, int y)
{
	block_text.setPosition(x + 4, y + 12);
}


void Block::set_color()
{
	txt_color = true;
}

bool Block::get_color()
{
	return txt_color;
}

string Block::GenerateValueString()
{
	stringstream randNumber;

	rand_N = rand() % 999;

	randNumber << rand_N;

	return randNumber.str();
}

int Block::get_random()
{
	return rand_N;
}

FloatRect Block::is_collision()
{
	return block_sp.getGlobalBounds();
}

