#pragma once
#include "state.h"
#include "Settings.h"
#include"Board.h"
#include"GameHandler.h"

class GameState :
    public state
{
private:
    //variables
    sf::RectangleShape Background;
    std::map<std::string, sf::Texture*> iconTextures;
    std::map<std::string, sf::RectangleShape*> icons;
    sf::Texture Background_texture;
    sf::Font font;
    Settings settings;
    std::map<std::string, Button*> Buttons;
    Board *board;
    GameHandler* gameHandler;
    sf::Vector2i activePos;
    int currnetNumber;
    int enteredNumber = -1; 
    std::stack<std::pair<int, int>> undo_val;
    std::stack<std::pair<int, int>> undo_pos;
    std::stack<std::pair<int, int>> redo_val;
    std::stack<std::pair<int, int>> redo_pos;
    unsigned int hintCounter = 3;

    //Timer
    sf::RectangleShape timerBoard;
    sf::Clock clock;
    std::string Timer;
    sf::Text Time, TimerTitle;
    unsigned int mints = 0, sec = 0;

   
   

    //functions
        //Initialisation functions
        void initBackground(sf::RenderWindow &window);
        void initFont();
        void initButtons();
        void initIcons();
        void initTimer();


        //Update functions
        void updateButtons(const float& dt);
        void updateInput();
        void activate(int numb);
        void clear();
        void color(int numb);
        void colorTheSameColor(int numb);
        void EnterNumber();
        void undoManger();
        void undo();
        bool undoed = false;
        bool keyPressed = false;
        void erease();
        void hint();
        void redo();
        void redoManger();
        void updateGameTimer();

        //render functions
        void renderButtons(sf::RenderTarget* target);
        void renderIcons(sf::RenderTarget* target);

public:
    //variables


    //functions
        //constructor/distructor
        GameState(sf::RenderWindow* window, Settings& settings, std::map<std::string, int>* supportedKeys, std::stack<state*>* states);
        ~GameState();

        //Initialisation functions
        void initkeysBind();

        //Update functions
        void update(const float& dt, sf::Event event);
       
        //render functions
        void render(sf::RenderTarget* target);
       
};

