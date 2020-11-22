#pragma once
#include "Display.h"

class DisplayConsole : public Display
{
	// Odziedziczono za pośrednictwem elementu Display
	virtual int drawMenu() override;
	virtual void showAuthors() override;
	virtual void showInstructions() override;
	virtual void drawStats(PlayerGameObject* player) override;
	virtual void drawMap(Map* map) override;
	virtual void drawOver() override;
};