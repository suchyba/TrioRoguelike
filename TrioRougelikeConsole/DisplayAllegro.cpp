#include "DisplayAllegro.h"
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <conio.h>
#include "ItemGameObject.h"
#include "ArmorGameObject.h"
#include "WeaponGameObject.h"

DisplayAllegro::DisplayAllegro() : baseHeight(750), baseWidth(1280)
{
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();
	al_init();
	al_install_keyboard();
	al_install_mouse();

	font_normal_20 = al_load_ttf_font("fonts/normal.ttf", 20, NULL);
	font_normal_15 = al_load_ttf_font("fonts/normal.ttf", 15, NULL);

	display = al_create_display(baseWidth, baseHeight); // tekstury 25x25

	eventQueue = al_create_event_queue();
	al_register_event_source(eventQueue, al_get_keyboard_event_source());

	transparentBitmap = al_load_bitmap("images/transparent.png");
	none_bitmap = al_load_bitmap("images/sprite.png");
	offset = (baseWidth - 3 * 10 * 25) / 2 - 100;
	cout << "[Allegro] Offset is: " << offset << endl;
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

	al_clear_to_color(al_map_rgb(60, 60, 60));

	for (int i = 0; i < x_size; i++)
	{
		for (int j = 0; j < y_size; j++)
		{
			for (int k = 0; k <= 2; ++k)
			{
				GameObject* g = map->getObjectInMap(i, j, k);
				if (g && g->getRepresentation().getSprite())
				{
					al_draw_bitmap(g->getRepresentation().getSprite(), j * 25 + offset, i * 25, NULL);
				}
				else if (g)
					al_draw_bitmap(none_bitmap, j * 25 + offset, i * 25, NULL);
				else
					al_draw_bitmap(transparentBitmap, j * 25 + offset, i * 25, NULL);
			}
		}
	}

	int baseXCord = offset + x_size * 25 + 1;
	int remainingSpace = baseWidth - baseXCord;


	// HP
	int hpBarXOffset = 10;
	int hpBarYOffset = 10;

	al_draw_text(font_normal_20, al_map_rgb(255, 255, 255), baseXCord + hpBarXOffset, hpBarYOffset, NULL, "Health points:");
	hpBarYOffset += 30;

	int playerBaseHP = player->getBaseHealthPoints();
	int playerHP = player->getHealthPoints();

	string hp = to_string(playerHP) + " / " + to_string(playerBaseHP);

	int margin = 3;
	int playerHPBarLength = (remainingSpace - 2 * (margin + hpBarXOffset)) * ((float)playerHP / playerBaseHP);

	al_draw_rectangle(baseXCord + hpBarXOffset, hpBarYOffset, baseXCord + remainingSpace - 10, hpBarYOffset + 40, al_map_rgb(0, 0, 0), 2);

	int hpTextOffset = (remainingSpace - 2 * (margin + hpBarXOffset) - hp.length() * 8) / 2;

	int colorFactor = 255 - 500 * ((float)playerHP / playerBaseHP);

	al_draw_filled_rectangle(	baseXCord + hpBarXOffset + margin, 
								hpBarYOffset + margin, 
								baseXCord + playerHPBarLength + margin + hpBarXOffset, 
								hpBarYOffset + 40 - margin, 
								al_map_rgb(colorFactor < 0 ? 255 + colorFactor : 255, colorFactor < 0 ? 255 : 255 - colorFactor, 0));
	al_draw_text(font_normal_15, al_map_rgb(0, 0, 0), baseXCord + hpBarXOffset + hpTextOffset, hpBarYOffset + margin + 10, NULL, hp.c_str());

	// XP
	int xpBarXOffset = 10;
	int xpBarYOffset = 100;
	
	al_draw_text(font_normal_20, al_map_rgb(255, 255, 255), baseXCord + xpBarXOffset, xpBarYOffset, NULL, ("Level: " + to_string(player->getLevel())).c_str());
	xpBarYOffset += 30;

	al_draw_text(font_normal_20, al_map_rgb(255, 255, 255), baseXCord + xpBarXOffset, xpBarYOffset, NULL, "Experience:");
	xpBarYOffset += 30;

	int playerBaseXP = player->getMaxXP();
	int playerXP = player->getExperience();
	string xp = to_string(playerXP) + " / " + to_string(playerBaseXP);
	int xpTextOffset = (remainingSpace - 2 * (margin + xpBarXOffset) - xp.length() * 8) / 2;
	int playerXPBarLength = (remainingSpace - 2 * (margin + xpBarXOffset)) * ((float)playerXP / playerBaseXP);

	al_draw_rectangle(baseXCord + xpBarXOffset, xpBarYOffset, baseXCord + remainingSpace - 10, xpBarYOffset + 40, al_map_rgb(0, 0, 0), 2);

	al_draw_filled_rectangle(baseXCord + xpBarXOffset + margin, xpBarYOffset + margin, baseXCord + playerXPBarLength + margin + xpBarXOffset, xpBarYOffset + 40 - margin, al_map_rgb(255, 255, 0));
	al_draw_text(font_normal_15, al_map_rgb(0, 0, 0), baseXCord + xpBarXOffset + xpTextOffset, xpBarYOffset + margin + 10, NULL, xp.c_str());

	// Eq
	int eqBoxXOffset = 10;
	int eqBoxYOffset = 480;

	al_draw_text(font_normal_20, al_map_rgb(255, 255, 255), baseXCord + eqBoxXOffset, eqBoxYOffset, NULL, "Inventory:");
	eqBoxYOffset += 30;

	int inventorySize = player->getActiveInventorySize();
	int slotSize = 55;

	al_draw_rectangle(	baseXCord + eqBoxXOffset, 
						eqBoxYOffset, 
						baseXCord + remainingSpace - 10, 
						eqBoxYOffset + slotSize * inventorySize + 2 * margin + 2 * 2, 
						al_map_rgb(0, 0, 0), 2);

	for (int i = 0; i < inventorySize; ++i)
	{
		ItemGameObject* item = player->getItemFromSlot(i);
		if (item && item->getRepresentation().getSprite())
			al_draw_bitmap(item->getRepresentation().getSprite(),	baseXCord + eqBoxXOffset + margin + 2, 
																	eqBoxYOffset + (i + 1) * margin + 2 + i * slotSize, 
																	NULL);
		else if (item)
			al_draw_bitmap(none_bitmap, baseXCord + eqBoxXOffset + margin + 2, 
										eqBoxYOffset + (i + 1) * margin + 2 + i * slotSize, 
										NULL);
		else
			continue;

		al_draw_text(font_normal_20, al_map_rgb(255, 255, 255), baseXCord + eqBoxXOffset + margin + 2 + margin + 25, 
																eqBoxYOffset + (i + 1) * margin + 2 + i * slotSize, 
																NULL, item->getName().c_str());
		EffectGameObject* effect = item->getEffect();
		if(effect)
			al_draw_bitmap(effect->getRepresentation().getSprite(), baseWidth - margin - 2 - 10 - 25,
																	eqBoxYOffset + (i + 1) * margin + 2 + i * slotSize, NULL);

		ArmorGameObject* item_armor = dynamic_cast<ArmorGameObject*> (item);
		if (item_armor)
		{
			al_draw_text(font_normal_15, al_map_rgb(255, 255, 255), baseXCord + eqBoxXOffset + margin + 2 + margin + 25, 
																	eqBoxYOffset + (i + 1) * margin + 2 + i * slotSize + 25, 
																	NULL, ("Armor: " + to_string(item_armor->getArmor())).c_str());
		}
		WeaponGameObject* item_weapon = dynamic_cast<WeaponGameObject*> (item);
		if (item_weapon)
		{
			al_draw_text(font_normal_15, al_map_rgb(255, 255, 255), baseXCord + eqBoxXOffset + margin + 2 + margin + 25, 
																	eqBoxYOffset + (i + 1) * margin + 2 + i * slotSize + 25, 
																	NULL, ("Damage: " + to_string(item_weapon->getMinDamage()) + " - " + to_string(item_weapon->getMaxDamage())).c_str());
		}
	}


	// Effects
	int effBoxXOffset = 10;
	int effBoxYOffset = 210;

	int effectSize = player->getActiveEffectsSize();
	if (effectSize > 0)
	{
		al_draw_text(font_normal_20, al_map_rgb(255, 255, 255), baseXCord + effBoxXOffset, effBoxYOffset, NULL, "Effects:");
		effBoxYOffset += 30;

		int effectSlotSize = 25;

		al_draw_rectangle(baseXCord + eqBoxXOffset,
			effBoxYOffset,
			baseXCord + remainingSpace - 10,
			effBoxYOffset + effectSlotSize * effectSize + 2 * margin + 2 * 2,
			al_map_rgb(0, 0, 0), 2);

		for (int i = 0; i < effectSize; ++i)
		{
			const EffectGameObject* effect = player->getEffectFromSlot(i);
			if (effect && effect->getRepresentation().getSprite())
				al_draw_bitmap(effect->getRepresentation().getSprite(), baseXCord + effBoxXOffset + margin + 2,
					effBoxYOffset + (i + 1) * margin + 2 + i * effectSlotSize,
					NULL);
			else if (effect)
				al_draw_bitmap(none_bitmap, baseXCord + effBoxXOffset + margin + 2,
					effBoxYOffset + (i + 1) * margin + 2 + i * effectSlotSize,
					NULL);
			else
				continue;

			al_draw_text(font_normal_20, al_map_rgb(255, 255, 255), baseXCord + effBoxXOffset + margin + 2 + margin + 25,
				effBoxYOffset + (i + 1) * margin + 2 + i * effectSlotSize,
				NULL, effect->getName().c_str());

			al_draw_text(font_normal_20, al_map_rgb(255, 255, 255), baseWidth - margin - 2 - 10 - 40,
				effBoxYOffset + (i + 1) * margin + 2 + i * effectSlotSize,
				NULL, to_string(effect->getDuration()).c_str());
		}

	}

	al_flip_display();

	ALLEGRO_EVENT events;
	al_wait_for_event(eventQueue, &events);
	int key = -1;

	if (events.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		switch (events.keyboard.keycode)
		{
		case ALLEGRO_KEY_S:
		{
			key = 's';
			break;
		}
		case ALLEGRO_KEY_W:
		{
			key = 'w';
			break;
		}
		case ALLEGRO_KEY_D:
		{
			key = 'd';
			break;
		}
		case ALLEGRO_KEY_A:
		{
			key = 'a';
			break;
		}
		case ALLEGRO_KEY_ESCAPE:
		{
			key = 27;
			break;
		}
		}
	}

	return key;
}
