#include "Level1Scene.h"
#include "Game.h"
#include "SpinButton.h"

Level1Scene::Level1Scene()
{
	start();
}

Level1Scene::~Level1Scene()
{
}

void Level1Scene::draw()
{
	m_pIncrease1->draw();
	m_pIncrease10->draw();
	m_pIncrease100->draw();
	m_pIncrease1000->draw();
	m_pDecrease1->draw();
	m_pDecrease10->draw();
	m_pDecrease100->draw();
	m_pDecrease1000->draw();
		slotMachine->draw();
		money->draw();
		reels[0]->draw();
		reels[1]->draw();
		reels[2]->draw();
		m_pSpinButton->draw();
		m_pMoney->draw();
		m_pBet->draw();
		m_pMessage->draw();
}

void Level1Scene::update()
{
	m_pIncrease1->setMousePosition(m_mousePosition);
	m_pIncrease10->setMousePosition(m_mousePosition);
	m_pIncrease100->setMousePosition(m_mousePosition);
	m_pIncrease1000->setMousePosition(m_mousePosition);
	m_pDecrease1->setMousePosition(m_mousePosition);
	m_pDecrease10->setMousePosition(m_mousePosition);
	m_pDecrease100->setMousePosition(m_mousePosition);
	m_pDecrease1000->setMousePosition(m_mousePosition);
	m_pSpinButton->setMousePosition(m_mousePosition);
	m_pIncrease1->ButtonClick();
	m_pIncrease10->ButtonClick();
	m_pIncrease100->ButtonClick();
	m_pIncrease1000->ButtonClick();
	m_pDecrease1->ButtonClick();
	m_pDecrease10->ButtonClick();
	m_pDecrease100->ButtonClick();
	m_pDecrease1000->ButtonClick();
	m_pSpinButton->ButtonClick();
}

void Level1Scene::clean()
{
}

void Level1Scene::handleEvents()
{
	int wheel = 0;

	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch(event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pIncrease1->setMouseButtonClicked(true);
				m_pIncrease10->setMouseButtonClicked(true);
				m_pIncrease100->setMouseButtonClicked(true);
				m_pIncrease1000->setMouseButtonClicked(true);
				m_pDecrease1->setMouseButtonClicked(true);
				m_pDecrease10->setMouseButtonClicked(true);
				m_pDecrease100->setMouseButtonClicked(true);
				m_pDecrease1000->setMouseButtonClicked(true);
				m_pSpinButton->setMouseButtonClicked(true);
				break;
			}
		
			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pIncrease1->setMouseButtonClicked(false);
				m_pIncrease10->setMouseButtonClicked(false);
				m_pIncrease100->setMouseButtonClicked(false);
				m_pIncrease1000->setMouseButtonClicked(false);
				m_pDecrease1->setMouseButtonClicked(false);
				m_pDecrease10->setMouseButtonClicked(false);
				m_pDecrease100->setMouseButtonClicked(false);
				m_pDecrease1000->setMouseButtonClicked(false);
				m_pSpinButton->setMouseButtonClicked(false);
				break;
			}
			break;
		case SDL_MOUSEWHEEL:
			wheel = event.wheel.y;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			}
			break;
		default:
			break;
		}
	}
}

void Level1Scene::start()
{
	m_pIncrease1 = new IncreaseButton(1, glm::vec2(250, 150));
	m_pIncrease10 = new IncreaseButton(10, glm::vec2(200, 150));
	m_pIncrease100 = new IncreaseButton(100, glm::vec2(150, 150));
	m_pIncrease1000 = new IncreaseButton(1000, glm::vec2(100, 150));
	m_pDecrease1 = new IncreaseButton(-1, glm::vec2(250, 200));
	m_pDecrease10 = new IncreaseButton(-10, glm::vec2(200, 200));
	m_pDecrease100 = new IncreaseButton(-100, glm::vec2(150, 200));
	m_pDecrease1000 = new IncreaseButton(-1000, glm::vec2(100, 200));
	addChild(m_pIncrease1);
	addChild(m_pIncrease10);
	addChild(m_pIncrease100);
	addChild(m_pIncrease1000);
	addChild(m_pDecrease1);
	addChild(m_pDecrease10);
	addChild(m_pDecrease100);
	addChild(m_pDecrease1000);

	m_pMoney = new Label("Money: 1000", "Consolas", 20, { (0),(0),(0),(255) }, glm::vec2(150, 250));
	m_pBet = new Label("0   0   0   0   0", "Consolas", 22.5, { (0),(0),(0),(255) }, glm::vec2(150, 100));
	m_pMessage = new Label("Message", "Consolas", 20, { (0),(0),(0),(255) }, glm::vec2(200, 400));
	slotMachine = new Image("../Assets/textures/Machine.png","slotMachine");
	slotMachine->setPosition(glm::vec2(450, 150));
	money = new Image("../Assets/textures/Money.png", "money");
	money->setPosition(glm::vec2(150, 100));
	reels[0] = new Image("../Assets/textures/blank.png", "blank");
	reels[0]->setPosition(glm::vec2(400, 150));
	reels[1] = new Image("../Assets/textures/blank.png", "blank");
	reels[1]->setPosition(glm::vec2(450, 150));
	reels[2] = new Image("../Assets/textures/blank.png", "blank");
	reels[2]->setPosition(glm::vec2(500, 150));
	addChild(m_pMoney);
	addChild(m_pBet);
	addChild(m_pMessage);
	addChild(slotMachine);
	addChild(money);
	addChild(reels[0]);
	addChild(reels[1]);
	addChild(reels[2]);

	m_pSpinButton = new SpinButton();
	m_pSpinButton->setPosition(glm::vec2(450, 200));
	addChild(m_pSpinButton);
}

glm::vec2 Level1Scene::getMousePosition()
{
	return m_mousePosition;
}

void Level1Scene::resetFruitTally()
{
	grapes = 0;
	bananas = 0;
	oranges = 0;
	cherries = 0;
	bars = 0;
	bells = 0;
	sevens = 0;
	blanks = 0;
}

void Level1Scene::resetAll()
{
	playerMoney = 1000;
	winnings = 0;
	jackpot = 5000;
	turn = 0;
	playerBet = 0;
	winNumber = 0;
	lossNumber = 0;
	winRatio = 0;
}

void Level1Scene::checkJackPot()
{
	int jackPotTry = floor(rand() * 51 + 1);
	int jackPotWin = floor(rand() * 51 + 1);
	if (jackPotTry == jackPotWin) {
		m_pMessage->setText("You won the jackpot!");
		playerMoney += jackpot;
		jackpot = 1000;
	}
}

void Level1Scene::showWinMessage()
{
	playerMoney += winnings;
	m_pMessage->setText("You won some money!");
	resetFruitTally();
	checkJackPot();
}

void Level1Scene::showLossMessage()
{
	playerMoney -= playerBet;
	m_pMessage->setText("You lost some money!");
	resetFruitTally();
}

bool Level1Scene::checkRange(int value, int lowerBounds, int upperBounds)
{
	return value >= lowerBounds && value <= upperBounds;
}

std::string* Level1Scene::Reels()
{
	std::string betLine[3] = { " ", " ", " " };
	int outCome[3] = { 0,0,0 };
	for (int spin = 0; spin < 3; ++spin) {
		outCome[spin] = floor((rand() % 65) + 1);
		if (checkRange(outCome[spin], 1, 27))
		{  // 41.5% probability
			betLine[spin] = "blank";
			blanks++;
		}
		else if (checkRange(outCome[spin], 28, 37))
		{ // 15.4% probability
			betLine[spin] = "Grapes";
			grapes++;
		}
		else if (checkRange(outCome[spin], 38, 46))
		{ // 13.8% probability
			betLine[spin] = "Banana";
			bananas++;
		}
		else if (checkRange(outCome[spin], 47, 54))
		{ // 12.3% probability
			betLine[spin] = "Orange";
			oranges++;
		}
		else if (checkRange(outCome[spin], 55, 59))
		{ //  7.7% probability
			betLine[spin] = "Cherry";
			cherries++;
		}
		else if (checkRange(outCome[spin], 60, 62))
		{ //  4.6% probability
			betLine[spin] = "Bar";
			bars++;
		}
		else if (checkRange(outCome[spin], 63, 64))
		{ //  3.1% probability
			betLine[spin] = "Bell";
			bells++;
		}
		else if (checkRange(outCome[spin], 65, 65))
		{ //  1.5% probability
			betLine[spin] = "Seven";
		}
		reels[spin] = new Image("../Assets/textures/" + betLine[spin] + ".png", betLine[spin]);
		reels[spin] ->setPosition(glm::vec2(400 + (50*spin), 150));
	}
	return betLine;
}

void Level1Scene::determineWinnings()
{
	if (blanks == 0)
	{
		if (grapes == 3) {
			winnings = playerBet * 10;
		}
		else if (bananas == 3) {
			winnings = playerBet * 20;
		}
		else if (oranges == 3) {
			winnings = playerBet * 30;
		}
		else if (cherries == 3) {
			winnings = playerBet * 40;
		}
		else if (bars == 3) {
			winnings = playerBet * 50;
		}
		else if (bells == 3) {
			winnings = playerBet * 75;
		}
		else if (sevens == 3) {
			winnings = playerBet * 100;
		}
		else if (grapes == 2) {
			winnings = playerBet * 2;
		}
		else if (bananas == 2) {
			winnings = playerBet * 2;
		}
		else if (oranges == 2) {
			winnings = playerBet * 3;
		}
		else if (cherries == 2) {
			winnings = playerBet * 4;
		}
		else if (bars == 2) {
			winnings = playerBet * 5;
		}
		else if (bells == 2) {
			winnings = playerBet * 10;
		}
		else if (sevens == 2) {
			winnings = playerBet * 20;
		}
		else if (sevens == 1) {
			winnings = playerBet * 5;
		}
		else {
			winnings = playerBet * 1;
		}
		winNumber++;
		showWinMessage();
	}
	else
	{
		lossNumber++;
		showLossMessage();
	}
	playerBet = 0;
	m_pMoney->setText(std::to_string(playerMoney));
}

void Level1Scene::incrementBet(int i)
{
	playerBet += i;
	if (playerBet < 0) {
		playerBet = 0;
	}
	else if (playerBet > playerMoney) {
		playerBet = playerMoney;
	}
	std::string temp = std::to_string(playerBet), tempOutput;
	for (int a = 5; a > 0; --a) {
		if (a > temp.length()) {
			tempOutput += "0   ";
		}
		else if (a!=1) {
			tempOutput += temp.substr(temp.length()-a, 1) + "   ";
		}
		else {
			tempOutput += temp.substr(temp.length() - a, 1);
		}
	}
	m_pBet->setText(tempOutput);
}

bool Level1Scene::canSpin()
{
	return playerBet > 0 && playerBet <= playerMoney;
}

void Level1Scene::Spin()
{
	m_pBet->setText("0   0   0   0   0");
	Reels();
	determineWinnings();
	turn++;
}

