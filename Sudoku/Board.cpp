#include "Board.h"
#include<iostream>

void Board::initBoard(sf::RenderWindow &window,float gridSize)
{
	
	
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cells[i][j].setFillColor(sf::Color::White);
			cells[i][j].setSize(sf::Vector2f(5.f * gridSize, 5.f * gridSize));
			cells[i][j].setPosition(((88.f* gridSize / 17.f) * i) + 600, ((88.f * gridSize / 17.f) * j) + 50);
			cells[i][j].setOutlineColor(sf::Color::Blue);

		}
	}
}

void Board::initSeperationLines(sf::RenderWindow &window,float gridSize)
{
	for (int i = 0; i < 4; i++)
	{
		seperationLines[i].setSize(sf::Vector2f(87.8f * gridSize / 17.f * 9, .5f * gridSize));
		seperationLines[i].setFillColor(sf::Color::Black);
	}
	seperationLines[0].setPosition(600, (93.f * gridSize / 17.f * 3 - 5) + 38);
	seperationLines[1].setPosition(600, (90.f * gridSize / 17.f * 6 - 5) + 40);
	seperationLines[2].setPosition((89.f * gridSize / 17.f * 3) + 600, 50);
	seperationLines[2].rotate(90);
	seperationLines[3].setPosition((88.f * gridSize / 17.f * 6) + 600, 50);
	seperationLines[3].rotate(90);
}

void Board::initChoices(sf::RenderWindow& window, float gridSize)
{
	for (int i = 1; i <= 9; i++)
	{
		this->choices[i].setFillColor(sf::Color(220, 227, 237));
		this->choices[i].setSize(sf::Vector2f(5.f * gridSize, 5.f * gridSize));
		this->choices[i].setPosition(((88.f * gridSize / 17.f) * i) + 530, ((90.f * gridSize / 17.f) * 10) + 50);
		this->choices[i].setTexture(&this->IdleTextures[i]);
	}
}

void Board::initTextures()
{
	for (int i = 1; i <= 9; i++)
	{
		if (i == 1)
		{
			this->IdleTextures[i].loadFromFile("C:/Users/PC/source/repos/Ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh/T/1.png");
			this->blueTextures[i].loadFromFile("C:/Users/PC/source/repos/Ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh/T/1b.png");
			this->redTextures[i].loadFromFile("C:/Users/PC/source/repos/Ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh/T/1r.png");
		}
		else if (i == 2)
		{
			this->IdleTextures[i].loadFromFile("C:/Users/PC/source/repos/Ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh/T/2.png");
			this->blueTextures[i].loadFromFile("C:/Users/PC/source/repos/Ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh/T/2b.png");
			this->redTextures[i].loadFromFile("C:/Users/PC/source/repos/Ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh/T/2r.png");
		}
		else if (i == 3)
		{
			this->IdleTextures[i].loadFromFile("C:/Users/PC/source/repos/Ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh/T/3.png");
			this->blueTextures[i].loadFromFile("C:/Users/PC/source/repos/Ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh/T/3b.png");
			this->redTextures[i].loadFromFile("C:/Users/PC/source/repos/Ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh/T/3r.png");
		}
		else if (i == 4)
		{
			this->IdleTextures[i].loadFromFile("C:/Users/PC/source/repos/Ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh/T/4.png");
			this->blueTextures[i].loadFromFile("C:/Users/PC/source/repos/Ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh/T/4b.png");
			this->redTextures[i].loadFromFile("C:/Users/PC/source/repos/Ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh/T/4r.png");

		}
		else if (i == 5)
		{
			this->IdleTextures[i].loadFromFile("C:/Users/PC/source/repos/Ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh/T/5.png");
			this->blueTextures[i].loadFromFile("C:/Users/PC/source/repos/Ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh/T/5b.png");
			this->redTextures[i].loadFromFile("C:/Users/PC/source/repos/Ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh/T/5r.png");
		}
		else if (i == 6)
		{
			this->IdleTextures[i].loadFromFile("C:/Users/PC/source/repos/Ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh/T/6.png");
			this->blueTextures[i].loadFromFile("C:/Users/PC/source/repos/Ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh/T/6b.png");
			this->redTextures[i].loadFromFile("C:/Users/PC/source/repos/Ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh/T/6r.png");
		}
		else if (i == 7)
		{
			this->IdleTextures[i].loadFromFile("C:/Users/PC/source/repos/Ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh/T/7.png");
			this->blueTextures[i].loadFromFile("C:/Users/PC/source/repos/Ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh/T/7b.png");
			this->redTextures[i].loadFromFile("C:/Users/PC/source/repos/Ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh/T/7r.png");
		}
		else if (i == 8)
		{
			this->IdleTextures[i].loadFromFile("C:/Users/PC/source/repos/Ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh/T/8.png");
			this->blueTextures[i].loadFromFile("C:/Users/PC/source/repos/Ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh/T/8b.png");
			this->redTextures[i].loadFromFile("C:/Users/PC/source/repos/Ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh/T/8r.png");
		}
		else if (i == 9)
		{
			this->IdleTextures[i].loadFromFile("C:/Users/PC/source/repos/Ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh/T/9.png");
			this->blueTextures[i].loadFromFile("C:/Users/PC/source/repos/Ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh/T/9b.png");
			this->redTextures[i].loadFromFile("C:/Users/PC/source/repos/Ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh/T/9r.png");
		}
	}
}

void Board::initNumbers()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (this->Numbers[j][i] != 0) {
				if (this->baseCells[j][i])
					this->cells[i][j].setTexture(&this->IdleTextures[this->Numbers[j][i]]);

			}

		}
	}
}


void Board::renderBoard(sf::RenderTarget* target)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			target->draw(this->cells[i][j]);
		}
	}
}

void Board::renderSeperationLines(sf::RenderTarget* target)
{
	for (auto& i : this->seperationLines)
	{
		target->draw(i);
	}
}

void Board::renderChoices(sf::RenderTarget* target)
{
	for (auto& i : this->choices)
	{
		target->draw(i);
	}
}

Board::Board(sf::RenderWindow* window,float gridSize)
{
	this->initTextures();
	this->initBoard(*window, gridSize);
	this->initSeperationLines(*window, gridSize);
	this->initChoices(*window, gridSize);
}

void Board::render(sf::RenderTarget* target)
{
	this->renderBoard(target);
	this->renderSeperationLines(target);
	this->renderChoices(target);
}

sf::Texture Board::getBlueTexture(int index)
{
	return this->blueTextures[index];
}
