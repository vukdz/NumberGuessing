// include/Game.cpp
#pragma once
#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <random>
#include <string>
#include <limits>
#include "Config.hpp"

class Game
{
public:
	Game();
	void run();

private:
	void reset();
	void checkInput(int& guess);
	int genRndNr();
	void playAgain(std::string& input);

	int m_num;
	int m_guess;
	int m_cnt;
	std::string m_playAgainInput;

	std::random_device m_rd;
	std::mt19937 m_rndGen;
	std::uniform_int_distribution<int> m_dist;
};

#endif // GAME_HPP