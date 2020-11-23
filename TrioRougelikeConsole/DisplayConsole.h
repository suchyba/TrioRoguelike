#pragma once
#include "Display.h"

class DisplayConsole : public Display
{
private:
	void drawStats(PlayerGameObject* player);
	void drawMap(Map* map);
public:
	// Odziedziczono za poœrednictwem elementu Display
	virtual int drawMenu() override;
	virtual void showAuthors() override;
	virtual void showInstructions() override;
	virtual void drawOver() override;
	virtual int drawInterface(Map* map, PlayerGameObject* player) override;
};