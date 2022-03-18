#pragma once
#include<iostream>
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>

#include<fstream>
#include<sstream>
#include<string>
class Settings
{
public:
	//Variables 
	enum Difficulty
	{
		EASY = 0,
		NORMAL = 1,
		HARD = 2
	};
	unsigned int Difficulty_choice = 0;
	std::string title = "None";
	sf::VideoMode resolution;
	bool fullScreen = false;
	unsigned frameRateLimite;
	std::vector<sf::VideoMode> resolutions;
	float soundLevel;
public:
	Settings();

	void readFromFile(const std::string fileAdress);
	void writeOnFile(const std::string fileAdress);
};

