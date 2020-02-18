#pragma once
#ifndef __SPIN__
#define __SPIN__
#include "Button.h"
class SpinButton : public Button {
public:
	SpinButton();
	~SpinButton();
	bool ButtonClick() override;
private:
	bool m_isClicked;
};
#endif // !__SPIN__
