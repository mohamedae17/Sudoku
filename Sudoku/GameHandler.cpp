#include "GameHandler.h"
#include<iostream>
GameHandler::GameHandler(unsigned int difficulty_choice,Board *board)
{
    this->board = board;
    this->initLevel(difficulty_choice);
    this->initSolvedBoard();
    this->solve();
}
void GameHandler::initLevel(unsigned int difficulty_choice)
{
    srand((unsigned)time(NULL));
    this->randomSelector = rand() % 10 + 1;
    this->randomSelector--;
    this->chooseLevel(difficulty_choice);
    while (this->randomSelector)
    {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                this->f_stream >> this->garbage;

        this->randomSelector--;
    }
    for (int i = 0; this->f_stream.is_open(); i++)
    {
        if (i == 9)
        {
            this->f_stream.close();
            break;
        }

        for (int j = 0; this->f_stream.is_open(); j++)
        {
            if (j == 9)
                break;
            this->f_stream >> this->board->Numbers[i][j];
            if (this->board->Numbers[i][j] != 0)
                this->board->baseCells[i][j] = true;

        }
    }
   
}
void GameHandler::chooseLevel(unsigned int difficulty_choice)
{
    switch (difficulty_choice)
    {
    case 0:
        f_stream.open("C:/Users/PC/source/repos/Sudoku/Texts/easy_puzzles.txt");
        break;
    case 1:
        f_stream.open("C:/Users/PC/source/repos/Sudoku/Texts/normal_puzzles.txt");
        break;
    case 2:
        f_stream.open("C:/Users/PC/source/repos/Sudoku/Texts/hard_puzzles.txt");
        break;
    default:

        break;
    }
}
void GameHandler::initSolvedBoard()
{
    for(int i =0;i < 9;i++)
        for (int j = 0; j < 9; j++)
        {
            this->board->solvedBoard[i][j] = this->board->Numbers[i][j];
        }
}

//Solve functions
int GameHandler::find_empty(int* x, int* y)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (this->board->solvedBoard[i][j] == 0)
            {
                *x = i;
                *y = j;
                return 1;
            }

        }
    }
    return -1;
}
bool GameHandler::valid_number(int num, int* x, int* y)
{
    for (int i = 0; i < 9; i++)
    {
        if (this->board->solvedBoard[*x][i] == num)
            return false;
    }
    for (int i = 0; i < 9; i++)
    {
        if (this->board->solvedBoard[i][*y] == num)
            return false;
    }
    int boxX = *x / 3;
    int boxY = *y / 3;
    for (int i = boxX * 3; i < boxX * 3 + 3; i++)
    {
        for (int j = boxY * 3; j < boxY * 3 + 3; j++)
        {
            if (this->board->solvedBoard[i][j] == num)
                return false;
        }
    }
    return true;
}
bool GameHandler::solve()
{
    
    int* cellX = new int, * cellY = new int;
    int find = find_empty(cellX, cellY);
    if (find == -1)
        return true;
    for (int i = 1; i < 10; i++)
    {
        if (valid_number(i, cellX, cellY))
        {
           this->board->solvedBoard[*cellX][*cellY] = i;
            if (solve()) {
                return true;
            }
           this->board->solvedBoard[*cellX][*cellY] = 0;
        }
    }
    return false;
}
