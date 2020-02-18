#pragma once
#ifndef __INCREASE__
#define __INCREASE__
#include "Button.h"
class IncreaseButton : public Button
{
public:
	IncreaseButton(int i, glm::vec2 transform/*std::string imagePath = "../Assets/textures/IncreaseButton.png",
		std::string buttonName = "startButton", 
		GameObjectType type = INCREASE_BUTTON,
		glm::vec2 position = glm::vec2(0.0f, 0.0f), bool isCentered = true*/);
	~IncreaseButton();

	bool ButtonClick() override;
private:
	bool m_isClicked;
	int increaseValue;
};
#endif