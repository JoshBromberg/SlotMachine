#pragma once
#ifndef __LEVEL_1_SCENE__
#define __LEVEL_1_SCENE__

#include "Scene.h"
#include "IncreaseButton.h"
#include "Image.h"
#include "Label.h"

class Level1Scene : public Scene
{
	friend class SpinButton;
public:
	Level1Scene();
	~Level1Scene();
	
	void draw() override;
	void update() override;
	void clean() override;
	void handleEvents() override;
	void start() override;

	// getters
	glm::vec2 getMousePosition();

	void resetFruitTally();
	void resetAll();
	void checkJackPot();
	void showWinMessage();
	void showLossMessage();
	bool checkRange(int value, int lowerBounds, int upperBounds);
	std::string* Reels();
	void determineWinnings();
	void incrementBet(int i);
	bool canSpin();
	void Spin();

private:
	// game objects
	Button* m_pSpin;
	IncreaseButton* m_pIncrease1;
	IncreaseButton* m_pIncrease10;
	IncreaseButton* m_pIncrease100;
	IncreaseButton* m_pIncrease1000;
	IncreaseButton* m_pDecrease1;
	IncreaseButton* m_pDecrease10;
	IncreaseButton* m_pDecrease100;
	IncreaseButton* m_pDecrease1000;
	SpinButton* m_pSpinButton;
	Label* m_pMoney;
	Label* m_pBet;
	Label* m_pMessage;
	Image* slotMachine;
	Image* money;
	Image* reels[3];


	// private data member
	glm::vec2 m_mousePosition;
	
	//Slot Machine Stuff
	int playerMoney = 1000, winnings = 0, jackpot = 5000, turn = 0, playerBet = 0,
		winNumber = 0, lossNumber = 0, winRatio = 0, grapes = 0, bananas = 0, oranges = 0, cherries = 0, bars = 0, bells = 0, sevens = 0, blanks = 0;
	std::string fruits = "";
	//something spinResult
};

#endif /* defined (__LEVEL_1_SCENE__) */
