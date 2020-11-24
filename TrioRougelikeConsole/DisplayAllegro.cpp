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

	transparentBitmap = al_load_bitmap("images/transparent.png");
	_getch();
}

int DisplayAllegro::drawMenu() // Sebastian
{
	return 1;
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
	int x_size = map->getMapDesignObject()->size();
	int y_size = map->getMapDesignObject()[0].size();

	for (int i = 0; i < x_size; i++)
	{
		for (int j = 0; j < y_size; j++)
		{
			for (int k = 0; k <= 2; ++k)
			{
				GameObject* g = map->getObjectInMap(i, j, k);
				if (g && g->getRepresentation().getSprite())
				{
					al_draw_bitmap(g->getRepresentation().getSprite(), j * 25, i * 25, NULL);
				}
				else
					al_draw_bitmap(transparentBitmap, j * 25, i * 25, NULL);
			}
		}
	}
	al_flip_display();
	return _getch();
}
