#pragma once
#include "Button.h"
#include "Settings.h"
#include<Windows.h>
#include<WinUser.h>

class List
{
private:
	Settings settings;
	std::string string;
	sf::Font font;
	Button* selectedOption;
	std::vector<Button*>Options;
	bool click = false;
	int noOfLists = -1;
	unsigned int currentList = 0;
	int delta = 0;

	float clicktimer = 0.f;
	float maxclicktimer = 1.f;
public:
	bool change = false;

public:
	//constructor / Destructor
	List(float x_pos, float y_pos, float width, float height, std::string options[], unsigned noOFoptions, float gridSizef,std::string firstOption, unsigned activeButton = 0);
	~List();

	//Getters
	const bool changed()const;
	const unsigned short& getSelecteditemID()const;
	const bool Clicked() const;
	const bool getclicktime();

	//Update fuctions
	void updateClicktimer(const float& dt);
	void update(sf::Vector2f& mousePos, const float& dt, sf::RenderWindow& window, sf::Event event);

	//Render Functions
	void render(sf::RenderTarget* target);
};

