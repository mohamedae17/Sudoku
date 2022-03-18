#include "GameState.h"
//Constructor/Destructor
GameState::GameState(sf::RenderWindow* window, Settings& settings, std::map<std::string, int>* supportedKeys, std::stack<state*>* states) :
	state(window, supportedKeys, states)
{
	this->settings.readFromFile("C:/Users/PC/source/repos/Sudoku/Config/window_config.txt");
	this->initkeysBind();
	this->initBackground(*this->window);
	this->board = new Board(window, this->gridSizef);
	this->gameHandler = new GameHandler(this->settings.Difficulty_choice, this->board);
	this->board->initNumbers();
	this->initFont();
	this->initButtons();
	this->initIcons();
	this->initTimer();

}
GameState::~GameState()
{
	auto it = this->iconTextures.begin();
	for (it; it != this->iconTextures.end(); ++it)
	{
		delete it->second;
	}

	auto it2 = this->icons.begin();
	for (it2; it2 != this->icons.end(); ++it2)
	{
		delete it2->second;
	}

	auto it3 = this->Buttons.begin();
	for (it3; it3 != this->Buttons.end(); ++it3)
	{
		delete it3->second;
	}

	delete this->board;
	delete this->gameHandler;
}

//Initialisation functions
	void GameState::initkeysBind()
{
	std::fstream supported_Keys_read("C:/Users/PC/source/repos/Sudoku/Config/supported_Key_GameState.txt");
	if (supported_Keys_read.is_open())
	{
		std::string key = "";
		std::string key2 = "";
		while (supported_Keys_read >> key >> key2)
		{
			this->keyBind[key] = this->supportedKeys->at(key2);
		}
	}
	supported_Keys_read.close();
}
	void GameState::initBackground(sf::RenderWindow &window)
	{
		this->Background_texture.loadFromFile("C:/Users/PC/source/repos/Sudoku/Textures/HG_sudoku_header.png");
		this->Background.setTexture(&this->Background_texture);
		this->Background.setSize(sf::Vector2f(float(window.getSize().x), float(window.getSize().y)));
		//this->Background.setFillColor(sf::Color::Black);
	}
	void GameState::initFont()
	{
		this->font.loadFromFile("C:/Users/PC/source/repos/Sudoku/Fonts/Sudoku.ttf");
	}
	void GameState::initButtons()
	{	
		this->Buttons["UNDO"] = new Button(this->settings.soundLevel,
			4.f * this->gridSizef, 6.7f * this->gridSizef, 5.f * this->gridSizef, 5.f * this->gridSizef,
			"", this->font, this->gridSizef,
			sf::Color::White, sf::Color::Yellow, sf::Color::Blue,
			sf::Color::Transparent, sf::Color::Transparent, sf::Color::Transparent,
			sf::Color::White, sf::Color::Yellow, sf::Color::Blue);
		this->Buttons["UNDO"]->setOutline(this->gridSizef);

		this->Buttons["EREASE"] = new Button(this->settings.soundLevel,
			10.5f * this->gridSizef, 6.7f * this->gridSizef, 5.f * this->gridSizef, 5.f * this->gridSizef,
			"", this->font, this->gridSizef,
			sf::Color::White, sf::Color::Yellow, sf::Color::Blue,
			sf::Color::Transparent, sf::Color::Transparent, sf::Color::Transparent,
			sf::Color::White, sf::Color::Yellow, sf::Color::Blue);
		this->Buttons["EREASE"]->setOutline(this->gridSizef);

		this->Buttons["HINT"] = new Button(this->settings.soundLevel,
			17.f * this->gridSizef, 6.7f * this->gridSizef, 5.f * this->gridSizef, 5.f * this->gridSizef,
			"", this->font, this->gridSizef,
			sf::Color::White, sf::Color::Yellow, sf::Color::Blue,
			sf::Color::Transparent, sf::Color::Transparent, sf::Color::Transparent,
			sf::Color::White, sf::Color::Yellow, sf::Color::Blue);
		this->Buttons["HINT"]->setOutline(this->gridSizef);

		this->Buttons["REDO"] = new Button(this->settings.soundLevel,
			23.5f * this->gridSizef, 6.7f * this->gridSizef, 5.f * this->gridSizef, 5.f * this->gridSizef,
			"", this->font, this->gridSizef,
			sf::Color::Transparent, sf::Color::Transparent, sf::Color::Transparent,
			sf::Color::Transparent, sf::Color::Transparent, sf::Color::Transparent,
			sf::Color::White, sf::Color::Yellow, sf::Color::Blue);
		this->Buttons["REDO"]->setOutline(this->gridSizef);

		this->Buttons["RESET"] = new Button(this->settings.soundLevel,
			4.f * this->gridSizef, 15.f * this->gridSizef, 19.f * this->gridSizef, 5.f * this->gridSizef,
			"New game", this->font, this->gridSizef,
			sf::Color::Black, sf::Color::Yellow, sf::Color::Blue,
			sf::Color::Transparent, sf::Color::Transparent, sf::Color::Transparent,
			sf::Color::Transparent, sf::Color::Transparent, sf::Color::Transparent);
		this->Buttons["RESET"]->setOutline(this->gridSizef);

		this->Buttons["BACK"] = new Button(this->settings.soundLevel, 5.6f * this->gridSizef, 61.f * this->gridSizef, 16.f * this->gridSizef, 6.5f * this->gridSizef,
			"Back", this->font, this->gridSizef,
			sf::Color::Black, sf::Color::Yellow, sf::Color::Blue,
			sf::Color::Transparent, sf::Color::Transparent, sf::Color::Transparent,
			sf::Color::Transparent, sf::Color::Transparent, sf::Color::Transparent);

		this->Buttons["BACK"]->setOutline(this->gridSizef);
	}
	void GameState::initIcons()
	{
		this->iconTextures["HINT"] = new sf::Texture;
		this->iconTextures["UNDO"] = new sf::Texture;
		this->iconTextures["EREASE"] = new sf::Texture;
		this->iconTextures["REDO"] = new sf::Texture;

		this->iconTextures["HINT"]->loadFromFile("C:/Users/PC/source/repos/Sudoku/Textures/hint.png");
		this->iconTextures["UNDO"]->loadFromFile("C:/Users/PC/source/repos/Sudoku/Textures/undo.png");
		this->iconTextures["EREASE"]->loadFromFile("C:/Users/PC/source/repos/Sudoku/Textures/eraser.png");
		this->iconTextures["REDO"]->loadFromFile("C:/Users/PC/source/repos/Sudoku/Textures/redo.png");

		this->icons["HINT"] = new sf::RectangleShape;
		this->icons["UNDO"] = new sf::RectangleShape;
		this->icons["EREASE"] = new sf::RectangleShape;
		this->icons["REDO"] = new sf::RectangleShape;

		this->icons["HINT"]->setTexture(this->iconTextures["HINT"]);
		this->icons["UNDO"]->setTexture(this->iconTextures["UNDO"]);
		this->icons["EREASE"]->setTexture(this->iconTextures["EREASE"]);
		this->icons["REDO"]->setTexture(this->iconTextures["REDO"]);

		for (auto& i : icons)
		{
			i.second->setSize(sf::Vector2f(5.f * this->gridSizef, 5.f * this->gridSizef));
		}

		this->icons["UNDO"]->setPosition(sf::Vector2f(4.f * this->gridSizef, 6.7f * this->gridSizef));
		this->icons["EREASE"]->setPosition(sf::Vector2f(10.5f * this->gridSizef, 6.7f * this->gridSizef));
		this->icons["HINT"]->setPosition(sf::Vector2f(17.f * this->gridSizef, 6.7f * this->gridSizef));
		this->icons["REDO"]->setPosition(sf::Vector2f(23.5f * this->gridSizef, 6.7f * this->gridSizef));
		

	}
	void GameState::initTimer()
	{
		this->TimerTitle.setFont(this->font);
		this->TimerTitle.setFillColor(sf::Color::Blue);
		this->TimerTitle.setPosition(77.0f, 50.0f);
		this->TimerTitle.setStyle(sf::Text::Bold);
		this->TimerTitle.setString("Time");

		this->timerBoard.setPosition(50, 50);
		this->timerBoard.setSize(sf::Vector2f(120, 70));
	}

//update functions
	void GameState::updateButtons(const float& dt)
{
		for (auto& button : this->Buttons)
		{
			button.second->update(this->mousePosView, *this->window, dt);
		}
		if (this->Buttons["UNDO"]->isPressed() && this->getClickable())
		{
			this->undo();
		}
		if (this->Buttons["EREASE"]->isPressed() && this->getClickable())
		{
			this->erease();
		}
		if (this->Buttons["HINT"]->isPressed() && this->getClickable())
		{
			this->hint();
		}
		if (this->Buttons["RESET"]->isPressed() && this->getClickable())
		{
			this->endState();
			this->states->push(new GameState(this->window, this->settings, this->supportedKeys, this->states));
		}
		if (this->Buttons["BACK"]->isPressed() && this->getClickable())
		{
			this->endState();
		}
		if (this->Buttons["REDO"]->isPressed() && this->getClickable())
		{
			this->redo();
		}
}
	void GameState::updateInput()
	{
		for(int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
			{
				if (this->board->cells[i][j].getGlobalBounds().contains(this->mousePosView))
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->getClickable())
					{
							this->clear();
							this->activePos = sf::Vector2i(i, j);
							this->currnetNumber = this->board->Numbers[j][i];
							this->activate(this->currnetNumber);
					}
				}
			}

		
			for (int i = 1; i < 10; i++)
			{
				if (this->board->choices[i].getGlobalBounds().contains(this->mousePosView))
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->getClickable())
					{
						keyPressed = true;
						this->enteredNumber = i;						
					}
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad1) && this->getClickable())
			{
				keyPressed = true;
				this->enteredNumber = 1;
			
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad2) && this->getClickable()) {
				this->enteredNumber = 2;
				keyPressed = true;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad3) && this->getClickable()) {
				this->enteredNumber = 3;
				keyPressed = true;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad4) && this->getClickable()) {
				this->enteredNumber = 4;
				keyPressed = true;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad5) && this->getClickable()) {
				this->enteredNumber = 5;
				keyPressed = true;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad6) && this->getClickable()) {
				this->enteredNumber = 6;
				keyPressed = true;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad7) && this->getClickable()) {
				this->enteredNumber = 7;
				keyPressed = true;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad8) && this->getClickable()) {
				this->enteredNumber = 8;
				keyPressed = true;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Numpad9) && this->getClickable()) {
				this->enteredNumber = 9;
				keyPressed = true;
			}

			if (keyPressed)
			{
				this->EnterNumber();
				keyPressed = false;
			}
	}
	void GameState::activate(int numb)
	{
		this->colorTheSameColor(this->currnetNumber);
		bool Reded = false;
		for (int i = 0; i < 9; i++)
		{
			if (i == this->activePos.y)
				continue;

			if (this->board->Numbers[i][(int)this->activePos.x] == numb && numb != 0)
			{
				this->board->cells[(int)this->activePos.x][i].setFillColor(sf::Color::Red);
				Reded = true;
			}
			else if (this->board->cells[(int)this->activePos.x][i].getFillColor() != sf::Color::Red)
				this->board->cells[(int)this->activePos.x][i].setFillColor(sf::Color(159, 169, 180));

		}

		//col correct
		for (int i = 0; i < 9; i++)
		{
			if ((int)this->activePos.x == i)
				continue;

			if (this->board->Numbers[(int)this->activePos.y][i] == numb && numb != 0)
			{
				this->board->cells[i][(int)this->activePos.y].setFillColor(sf::Color::Red);
				Reded = true;
			}
			else if (this->board->cells[i][(int)this->activePos.y].getFillColor() != sf::Color::Red)
				this->board->cells[i][(int)this->activePos.y].setFillColor(sf::Color(159, 169, 180));
		}
		int boxX = (int)this->activePos.x / 3;
		int boxY = (int)this->activePos.y / 3;
		for (int i = boxX * 3; i < boxX * 3 + 3; i++)
		{
			for (int j = boxY * 3; j < boxY * 3 + 3; j++)
			{
				if ((int)this->activePos.x == i && (int)this->activePos.y == j)
					continue;

				if (this->board->Numbers[j][i] == numb && numb != 0)
				{
					this->board->cells[i][j].setFillColor(sf::Color::Red);
					Reded = true;
				}
				else if (this->board->cells[i][j].getFillColor() != sf::Color::Red)
					this->board->cells[i][j].setFillColor(sf::Color(159, 169, 180));
			}

		}
		if (Reded)
			this->board->cells[(int)this->activePos.x][(int)this->activePos.y].setFillColor(sf::Color::Red);
		else
			this->board->cells[(int)this->activePos.x][(int)this->activePos.y].setFillColor(sf::Color(187, 222, 251));


		
	}
	void GameState::clear()
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (this->board->cells[i][j].getFillColor() != sf::Color::Red)
					this->board->cells[i][j].setFillColor(sf::Color::White);
			}
		}
	}
	void GameState::EnterNumber()
	{
		if (this->board->baseCells[this->activePos.y][this->activePos.x] == true)
		{
			this->enteredNumber = -1;
			return;
		}
		else if (this->enteredNumber != -1)
		{
			if (this->board->cells[this->activePos.x][this->activePos.y].getFillColor() == sf::Color::Red)
			{
				int Redd = this->board->Numbers[this->activePos.y][this->activePos.x];
				if (this->enteredNumber != -1)
				{
					for (int i = 0; i < 9; i++)
					{
						for (int j = 0; j < 9; j++)
						{
							if (this->board->cells[i][j].getFillColor() == sf::Color::Red && this->board->Numbers[j][i] == Redd)
							{
								this->board->cells[i][j].setFillColor(sf::Color::White);
							}
						}
					}
				}

			}
			if (!undoed)
			{	
				
				this->undoManger();				
			}
			else
			{
				undoed = false;
			}
				
			this->board->Numbers[(int)this->activePos.y][(int)this->activePos.x] = this->enteredNumber;
			this->board->cells[this->activePos.x][this->activePos.y].setTexture(&this->board->blueTextures[this->enteredNumber]);
			this->currnetNumber = this->enteredNumber;
			this->color(currnetNumber);
			this->colorTheSameColor(this->currnetNumber);
			this->activate(this->currnetNumber);
			this->enteredNumber = -1;
		}
	}
	void GameState::undoManger()
	{
		if (this->enteredNumber == this->board->Numbers[this->activePos.y][this->activePos.x])
		{
			return;
		}
		else
		{
			std::pair<int, int> values;
			std::pair<int, int> position;
			values.first = this->board->Numbers[this->activePos.y][this->activePos.x];
			values.second = this->enteredNumber;
			this->undo_val.push(values);
			position.first = this->activePos.x;
			position.second = this->activePos.y;
			this->undo_pos.push(position);
		}
	}
	void GameState::undo()
	{
		if (this->undo_pos.empty())
		{
			return;
		}
		else
		{
			this->enteredNumber = this->undo_val.top().first;
			this->activePos.x = this->undo_pos.top().first;
			this->activePos.y = this->undo_pos.top().second;
			
			this->clear();
			this->undoed = true;
			this->color(this->undo_val.top().first);
			this->EnterNumber();
			
			this->redoManger(); //Put the values and position into the redo stack

			this->undo_pos.pop();
			this->undo_val.pop();
			this->enteredNumber = -1;

		}
	}
	void GameState::color(int numb)
	{
		for (int i = 0; i < 9; i++)
		{
			if (this->board->Numbers[i][(int)this->activePos.x] == numb && numb != 0)
			{
				
				this->board->cells[(int)this->activePos.x][i].setFillColor(sf::Color::Red);
			}
		}

		//col correct
		for (int i = 0; i < 9; i++)
		{
			

			if (this->board->Numbers[(int)this->activePos.y][i] == numb && numb != 0)
			{
				this->board->cells[i][(int)this->activePos.y].setFillColor(sf::Color::Red);
			}
		}

		int boxX = (int)this->activePos.x / 3;
		int boxY = (int)this->activePos.y / 3;
		for (int i = boxX * 3; i < boxX * 3 + 3; i++)
		{
			for (int j = boxY * 3; j < boxY * 3 + 3; j++)
			{
			

				if (this->board->Numbers[j][i] == numb && numb != 0)
				{
					this->board->cells[i][j].setFillColor(sf::Color::Red);
					
				}
			}

		}
	}
	void GameState::colorTheSameColor(int numb)
	{
		if (numb == 0)
			return;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (this->board->cells[i][j].getFillColor() != sf::Color::Red)
				{
					if (this->board->Numbers[j][i] == numb)
						this->board->cells[i][j].setFillColor(sf::Color::Green);
					else
						this->board->cells[i][j].setFillColor(sf::Color::White);

				}
			}

		}
	}
	void GameState::update(const float& dt, sf::Event event)
	{
		this->updateMousepos();
		this->updateTimer(dt);
		this->updateButtons(dt);
		this->updateInput();
		this->updateGameTimer();
	}
	void GameState::erease()
	{
		if (this->board->baseCells[this->activePos.y][this->activePos.x] || this->currnetNumber == 0)
		{
			return;
		}
		else
		{
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					if (this->board->cells[i][j].getFillColor() == sf::Color::Red && this->board->Numbers[j][i] == undo_val.top().second)
					{
						this->board->cells[i][j].setFillColor(sf::Color::White);
					}

				}
				
			}
			this->undo_val.push(std::make_pair(this->board->Numbers[this->activePos.y][this->activePos.x], 0));
			this->undo_pos.push(std::make_pair(this->activePos.x,this->activePos.y));

			this->board->Numbers[this->activePos.y][this->activePos.x] = 0;
			this->board->cells[this->activePos.x][this->activePos.y].setTexture(NULL);
			this->clear();
			this->activate(this->board->Numbers[this->activePos.y][this->activePos.x]);
		}
	}
	void GameState::hint()
	{

		if (this->board->baseCells[this->activePos.y][this->activePos.x] || !this->hintCounter)
		{
			return;
		}
		else
		{
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					if (this->board->cells[i][j].getFillColor() == sf::Color::Red && this->board->Numbers[j][i] == undo_val.top().second)
					{

						this->board->cells[i][j].setFillColor(sf::Color::White);
					}

				}

			}
			this->board->Numbers[this->activePos.y][this->activePos.x] = this->board->solvedBoard[this->activePos.y][this->activePos.x];
			this->board->baseCells[this->activePos.y][this->activePos.x] = true;
			this->board->initNumbers();
			this->colorTheSameColor(this->board->Numbers[this->activePos.y][this->activePos.x]);
			hintCounter--;
		}
	}
	void GameState::redo()
	{
		if (!this->redo_pos.empty())
		{
			
			this->enteredNumber = this->redo_val.top().first;
			this->activePos.x = this->redo_pos.top().first;
			this->activePos.y = this->redo_pos.top().second;

			this->clear();

			this->color(this->redo_val.top().first);

			this->EnterNumber();	

			this->redo_pos.pop();
			this->redo_val.pop();
			
			this->enteredNumber = -1;

		}
		return;
	}
	void GameState::redoManger()
	{
		if (!this->undo_pos.empty())
		{
			std::pair<int, int> values;
			std::pair<int, int> position;
			values.first = this->undo_val.top().second;
			values.second = this->undo_val.top().first;
			this->redo_val.push(values);
			position.first = this->undo_pos.top().first;
			position.second = this->undo_pos.top().second;
			this->redo_pos.push(position);
		}
	}
	void GameState::updateGameTimer()
	{
		sf::Time elapsed = clock.getElapsedTime();
		sec = elapsed.asSeconds() - 60 * mints;
		if (sec < 10)
			Timer = std::to_string(mints) + ":" + "0" + std::to_string(sec);
		else
			Timer = std::to_string(mints) + ":" + std::to_string(sec);
		if (sec == 60)
			mints++;

		this->Time.setString(this->Timer);
	}

	//render functions
	void GameState::renderButtons(sf::RenderTarget* target)
{
	
		for (auto& button : this->Buttons)
		{
			button.second->render(target);
			button.second->renderAnimation(target);
		}
	}
	void GameState::renderIcons(sf::RenderTarget* target)
	{
		for (auto& i : this->icons)
		{
			target->draw(*i.second);

		}
	}
	void GameState::render(sf::RenderTarget* target)
	{
		if (!target)
			target = window;

		target->draw(this->Background);
		target->draw(this->Time);
		target->draw(this->timerBoard);
		target->draw(this->TimerTitle);
		this->renderButtons(target);
		this->renderIcons(target);
		this->board->render(target);

	}