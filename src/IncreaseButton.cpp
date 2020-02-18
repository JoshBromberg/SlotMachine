#include "IncreaseButton.h"
#include "Game.h"

IncreaseButton::IncreaseButton(int i, glm::vec2 transform) :Button(
	i > 0 ? "../Assets/textures/IncreaseButton.png" : "../Assets/textures/DecreaseButton.png",
	i > 0 ? "increaseButton" : "decreaseButton",
	INCREASE_BUTTON,
	transform
), m_isClicked(false), increaseValue(i)
{
}

IncreaseButton::~IncreaseButton()
{
}

bool IncreaseButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			Game::Instance()->getScene()->incrementBet(increaseValue);
			m_isClicked = true;
		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}
	return false;
}
