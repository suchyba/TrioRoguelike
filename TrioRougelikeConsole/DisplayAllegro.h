#pragma once
#include "Display.h"

class DisplayAllegro : public Display
{
private:
    ALLEGRO_DISPLAY* display;
public:
    DisplayAllegro();
    // Odziedziczono za poœrednictwem elementu Display
    virtual int drawMenu() override;
    virtual void showAuthors() override;
    virtual void showInstructions() override;
    virtual void drawOver() override;
    virtual int drawInterface(Map* map, PlayerGameObject* player) override;
    virtual ~DisplayAllegro();
};

