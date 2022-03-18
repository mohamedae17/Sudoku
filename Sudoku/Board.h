#pragma once
#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/System.hpp>
#include<string>
#include<stack>
class Board
{
private:
    //variables
        //Board things
        sf::RectangleShape seperationLines[4];
        sf::Texture IdleTextures[10];
     
        sf::Texture redTextures[10];
        bool OutBoardPress = false, BoardPressed = false, keyused = false;


        //Undo things
        std::stack<std::pair<int, int>> undo_values;
        std::stack<std::pair<int, int>> undo_positions;

    //functions
        //Initialisation functions
        void initBoard(sf::RenderWindow& window, float gridSize);
        void initSeperationLines(sf::RenderWindow& window, float gridSize);
        void initChoices(sf::RenderWindow& window, float gridSize);
        void initTextures();
        

        //Update functions

        //render functions
        void renderBoard(sf::RenderTarget *target);
        void renderSeperationLines(sf::RenderTarget *target);
        void renderChoices(sf::RenderTarget * target);

public:
    //variables
    sf::RectangleShape cells[9][9];
    sf::RectangleShape choices[10];
    int solvedBoard[9][9] = { 0 };
    bool baseCells[9][9];
    int Numbers[9][9];
    sf::Texture blueTextures[10];

    //functions
        //constructor/distructor
        Board(sf::RenderWindow* window, float gridSize);

        //Initialisation functions
        void initNumbers();
    

        //Update functions
       
        //render functions
        void render(sf::RenderTarget* target);

        //Getters
        sf::Texture getBlueTexture(int index);
};

