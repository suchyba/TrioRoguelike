#include "DisplayAllegro.h"
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro.h>
#include <conio.h>

DisplayAllegro::DisplayAllegro()
{
    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init();
    display = al_create_display(1280, 750); // tekstury 25x25
    _getch();
}

int DisplayAllegro::drawMenu() // Sebastian
{
    return 4;
}

void DisplayAllegro::showAuthors() // Daniel
{

}

void DisplayAllegro::showInstructions() // Daniel
{

}

void DisplayAllegro::drawOver() // Daniel
{

}

DisplayAllegro::~DisplayAllegro()
{
    al_destroy_display(display);
}

int DisplayAllegro::drawInterface(Map* map, PlayerGameObject* player) // Bartek
{
    return 0;
}
