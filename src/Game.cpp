// src/Game.cpp
#include "Game.hpp"

void clearScreen()
{
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

Game::Game() :
	m_rndGen(m_rd()),
	m_dist(RND_MIN, RND_MAX),
	m_num(0),   
	m_guess(0), 
	m_cnt(0)
{
	reset();
}

void Game::run()
{
	std::cout << "Welcome to the Number Guessing Game!\n";
	std::cout << "Try to guess the number between " << RND_MIN << " and " << RND_MAX << ".\n";

	while (true)
	{
		if (m_cnt < MAX_GUESS)
		{
			std::cout << "Enter a number between " << RND_MIN << " and " << RND_MAX << ": ";
			checkInput(m_guess);

			m_cnt++;

			if (m_guess > m_num)
			{
				std::cout << "Too high!\n";
			}
			else if (m_guess < m_num)
			{
				std::cout << "Too low!\n";
			}
			else
			{
				std::cout << "Correct! It took " << m_cnt << " attempts.\n";
				break;
			}
		}
		else
		{
			std::cout << "Game over!\n";
			break;
		}
		std::cout << std::endl;
	}

	playAgain(m_playAgainInput);
}

void Game::reset()
{
	clearScreen();
	m_num = genRndNr();
	m_cnt = 0;
	m_guess = 0;
}

void Game::checkInput(int& guess)
{
	while (!(std::cin >> guess))
	{
		std::cout << "Invalid input. Please enter and integer: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

void Game::playAgain(std::string& input)
{
	std::cout << "Do you want to play again? (yes/no): ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, input);
	std::transform(input.begin(), input.end(), input.begin(),
		[](unsigned char c) { return static_cast<char>(std::tolower(c)); });

	if (input == "yes")
	{
		reset();
		run();
	}
	else
	{
		std::cout << "Thanks for playing!\n";
	}
}

int Game::genRndNr()
{
	return m_dist(m_rndGen);
}