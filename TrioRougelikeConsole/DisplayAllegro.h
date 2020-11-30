#pragma once
#include "Display.h"
#include <allegro5/allegro_font.h>

class DisplayAllegro : public Display
{
private:
    ALLEGRO_DISPLAY* display;
    ALLEGRO_BITMAP* transparentBitmap;
    ALLEGRO_BITMAP* none_bitmap;
    ALLEGRO_FONT* font_normal_20;
    ALLEGRO_FONT* font_normal_15;
    ALLEGRO_EVENT_QUEUE* eventQueue;
    ALLEGRO_BITMAP* scrollBitmap = NULL;
    ALLEGRO_BITMAP* emptyScroll = NULL;
    ALLEGRO_BITMAP* animation[20];
    ALLEGRO_FONT* titleFont = NULL;
    ALLEGRO_FONT* categoryFont = NULL;
    ALLEGRO_FONT* gameOverFont = NULL;
    ALLEGRO_FONT* littleFont = NULL;
    ALLEGRO_BITMAP* trio = NULL;
    ALLEGRO_BITMAP* bigSword = NULL;
    ALLEGRO_BITMAP* skull = NULL;

    int colors[3] = { 12,12,12 }; // poprzedni kolor 84, 89, 85
    int offset;
    int baseHeight;
    int baseWidth;
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

