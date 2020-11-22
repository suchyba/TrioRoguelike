#pragma once
#include "Display.h"
class DisplayAllegro :
    public Display
{
private:

public:
    // Odziedziczono za poœrednictwem elementu Display
    virtual int drawMenu() override;
    virtual void showAuthors() override;
    virtual void showInstructions() override;
    virtual void drawStats(PlayerGameObject* player) override;
    virtual void drawMap(Map* map) override;
    virtual void drawOver() override;
};

