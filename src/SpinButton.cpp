#include "SpinButton.h"
#include "Game.h"

SpinButton::SpinButton()
	:Button(
		"../Assets/textures/SpinButton.png",
		"spinButton",
		START_BUTTON, glm::vec2(600.0f, 300.0f)), m_isClicked(false)

{
}

SpinButton::~SpinButton()
{
}

bool SpinButton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked && Game::Instance()->getScene()->canSpin()) //&& bet isn't 0
		{
			Game::Instance()->getScene()->Spin();
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
