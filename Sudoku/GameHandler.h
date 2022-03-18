#pragma once
#include<fstream>
#include<random>
#include<string>
#include<cstdlib>
#include<time.h>
#include"Board.h"
class GameHandler
{
private:
	//Variables
	int randomSelector= -1;
	char garbage=' ';
	std::fstream f_stream;
	Board* board;
	
	//functions
	void chooseLevel(unsigned int difficulty_choice);
	void initSolvedBoard();
	

	//Solve functions
		int find_empty(int* x, int* y);
		bool valid_number(int num, int* x, int* y);
		bool solve();
	
public:
	//Variables

	//functions
		//constructor/destructor
		GameHandler(unsigned int difficulty_choice,Board *board);

		//initialisation functions
		void initLevel(unsigned int difficulty_choice);
		

};

