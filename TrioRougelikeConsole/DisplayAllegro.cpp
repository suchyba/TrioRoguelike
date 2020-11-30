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
#include "Windows.h"

#define BACKGROUND_FILE     "images/preScroll.png"
#define FONT_FILE     "fonts/BreatheFire.ttf"
#define EMPTY_SCROLL "images/EmptyScroll.png"

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
	string fileName;
	for (int i = 0; i < 20; i++)
	{
		fileName = "images/animation/";
		fileName += to_string(i + 1) + ".png";
		animation[i] = al_load_bitmap(fileName.c_str());

		if (animation[i] == NULL)
		{
			cout << "Failed to load knightFire animation nr" << i << " !" << endl;
			return -1;
		}

	}

	titleFont = al_load_font(FONT_FILE, 72, NULL);
	if (!titleFont)
	{
		cout << "Failed to load title font !\n";
		return -1;
	}
	categoryFont = al_load_font(FONT_FILE, 48, NULL);
	if (!categoryFont)
	{
		cout << "Failed to load category font !\n";
		return -1;
	}
	scrollBitmap = al_load_bitmap(BACKGROUND_FILE);
	if (!scrollBitmap)
	{
		cout << "Failed to load scroll bitmap!\n";
		return -1;
	}


	int scrollX = al_get_bitmap_x(scrollBitmap);
	int scrollY = al_get_bitmap_y(scrollBitmap);
	int scrollWidth = al_get_bitmap_width(scrollBitmap);
	int scrollHeight = al_get_bitmap_height(scrollBitmap);

	int scrollIterator = 0;

	int animationIterator = 0;

	bool flag = false;
	int selectedCategory = 0;
	POINT mousePosition;

	int categorytextX = (scrollX + scrollWidth / 2) - 5;
	int categoryStartGameY = scrollY + scrollHeight / 3;
	int categoryGameInstructionY = scrollY + scrollHeight * 13 / 30;
	int categoryGameAutorsY = scrollY + scrollHeight * 16 / 30;
	int categoryExitGameY = scrollY + scrollHeight * 19 / 30;

	while (true)
	{
		al_clear_to_color(al_map_rgb(colors[0],colors[1],colors[2])); // poprzedni kolor 84, 89, 85
		flag = false;
		scrollIterator++;
		if (scrollIterator > 19)
		{
			scrollIterator = 0;
		}

		animationIterator++;

		if (GetCursorPos(&mousePosition))
		{
			if (mousePosition.x > categorytextX + 180 && mousePosition.x < categorytextX + 450)
			{
				if (mousePosition.y > categoryStartGameY + 170 && mousePosition.y < categoryStartGameY + 220)
				{
					selectedCategory = 0;
					if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
					{
						return 1;
					}
				}
				else if (mousePosition.y > categoryGameInstructionY + 170 && mousePosition.y < categoryGameInstructionY + 220)
				{
					selectedCategory = 1;
					if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
					{
						return 2;
					}
				}
				else if (mousePosition.y > categoryGameAutorsY + 170 && mousePosition.y < categoryGameAutorsY + 220)
				{
					selectedCategory = 2;
					if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
					{
						return 3;
					}
				}
				else if (mousePosition.y > categoryExitGameY + 170 && mousePosition.y < categoryExitGameY + 220)
				{
					selectedCategory = 3;
					if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
					{
						return 4;
					}
				}
			}
		}
		if (animationIterator < 15)
		{
			al_draw_scaled_bitmap(scrollBitmap, 0, 0, al_get_bitmap_width(scrollBitmap), al_get_bitmap_height(scrollBitmap), 0, (al_get_display_height(display) / 2) - animationIterator * 25, al_get_bitmap_width(scrollBitmap), animationIterator * 50, NULL);
		}
		else
		{
			al_draw_bitmap(scrollBitmap, 0, 0, 0);

			switch (selectedCategory)
			{
			case 0:
				al_draw_text(categoryFont, al_map_rgb(15, 80, 120), categorytextX, categoryStartGameY, ALLEGRO_ALIGN_CENTER, "Rozpocznij Gre");
				al_draw_text(categoryFont, al_map_rgb(32, 28, 69), categorytextX, categoryGameInstructionY, ALLEGRO_ALIGN_CENTER, "Instrukcja gry");
				al_draw_text(categoryFont, al_map_rgb(32, 28, 69), categorytextX, categoryGameAutorsY, ALLEGRO_ALIGN_CENTER, "Autorzy");
				al_draw_text(categoryFont, al_map_rgb(32, 28, 69), categorytextX, categoryExitGameY, ALLEGRO_ALIGN_CENTER, "Wyjdz");
				break;
			case 1:
				al_draw_text(categoryFont, al_map_rgb(15, 80, 120), categorytextX, categoryGameInstructionY, ALLEGRO_ALIGN_CENTER, "Instrukcja gry");
				al_draw_text(categoryFont, al_map_rgb(32, 28, 69), categorytextX, categoryStartGameY, ALLEGRO_ALIGN_CENTER, "Rozpocznij Gre");
				al_draw_text(categoryFont, al_map_rgb(32, 28, 69), categorytextX, categoryGameAutorsY, ALLEGRO_ALIGN_CENTER, "Autorzy");
				al_draw_text(categoryFont, al_map_rgb(32, 28, 69), categorytextX, categoryExitGameY, ALLEGRO_ALIGN_CENTER, "Wyjdz");
				break;
			case 2:
				al_draw_text(categoryFont, al_map_rgb(15, 80, 120), categorytextX, categoryGameAutorsY, ALLEGRO_ALIGN_CENTER, "Autorzy");
				al_draw_text(categoryFont, al_map_rgb(32, 28, 69), categorytextX, categoryGameInstructionY, ALLEGRO_ALIGN_CENTER, "Instrukcja gry");
				al_draw_text(categoryFont, al_map_rgb(32, 28, 69), categorytextX, categoryStartGameY, ALLEGRO_ALIGN_CENTER, "Rozpocznij Gre");
				al_draw_text(categoryFont, al_map_rgb(32, 28, 69), categorytextX, categoryExitGameY, ALLEGRO_ALIGN_CENTER, "Wyjdz");
				break;
			case 3:
				al_draw_text(categoryFont, al_map_rgb(15, 80, 120), categorytextX, categoryExitGameY, ALLEGRO_ALIGN_CENTER, "Wyjdz");
				al_draw_text(categoryFont, al_map_rgb(32, 28, 69), categorytextX, categoryStartGameY, ALLEGRO_ALIGN_CENTER, "Rozpocznij Gre");
				al_draw_text(categoryFont, al_map_rgb(32, 28, 69), categorytextX, categoryGameInstructionY, ALLEGRO_ALIGN_CENTER, "Instrukcja gry");
				al_draw_text(categoryFont, al_map_rgb(32, 28, 69), categorytextX, categoryGameAutorsY, ALLEGRO_ALIGN_CENTER, "Autorzy");
				break;
			default:
				break;
			}
		}
		al_draw_bitmap(animation[scrollIterator], 750, 100, 0);

		if (GetKeyState(0x57) & 0x8000)
		{
			selectedCategory--;
			if (selectedCategory < 0)
			{
				selectedCategory = 3;

			}
			flag = true;
			al_rest(0.15);
		}
		if (GetKeyState(0x53) & 0x8000)
		{
			selectedCategory++;
			if (selectedCategory > 3)
			{
				selectedCategory = 0;

			}
			flag = true;
			al_rest(0.15);
		}
		al_flip_display();

		if (GetKeyState(VK_RETURN) & 0x8000) //obs³uga klawiatury
		{
			switch (selectedCategory)
			{
			case 0:
				return 1;
				break;
			case 1:
				return 2;
				break;
			case 2:
				return 3;
				break;
			case 3:
				return 4;
				break;
			default:
				break;
			}
		}
		if (!flag)
		{
			al_rest(0.05);
		}
	}
}

void DisplayAllegro::showAuthors()// Daniel- zrobione, tylko nie nie ma podswietlenia takiego jak w menu jesli chodzi o wybor	
									// zarowno mysz jak i klawiatura (Spacja i Enter wychodz¹ do porzedniego ekranu) dzia³aj¹
{
	al_rest(0.15);
	POINT mousePosition;
	trio = al_load_bitmap("images/trio.png");
	littleFont = al_load_font(FONT_FILE, 24, NULL);
	if (!littleFont)
	{
		cout << "Failed to load title font !\n";
		exit(0);
	}
	emptyScroll = al_load_bitmap(EMPTY_SCROLL);
	if (!emptyScroll)
	{
		cout << "Failed to load scroll bitmap!\n";
		exit(0);
	}


	while (true)
	{
		if (GetCursorPos(&mousePosition)) //obs³uga myszki
		{
			if (mousePosition.x > 550 && mousePosition.x < 800 && mousePosition.y > 550 && mousePosition.y < 700)
			{

				if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
				{
					al_rest(0.15);
					break;
				}


			}


		}
		if (GetKeyState(VK_RETURN) & 0x8000 || GetKeyState(VK_SPACE) & 0x8000) //obs³uga klawiatury
			break;

		al_clear_to_color(al_map_rgb(colors[0], colors[1], colors[2]));// poprzedni kolor 84, 89, 85
		al_draw_bitmap(emptyScroll, 0, 0, 0);
		
		al_draw_text(titleFont, al_map_rgb(15, 80, 120), 350, 100, ALLEGRO_ALIGN_CENTER, "Autorzy");
		al_draw_text(categoryFont, al_map_rgb(32, 28, 69), 350, 250, ALLEGRO_ALIGN_CENTER, "Sebastian Tomkiel");
		al_draw_text(categoryFont, al_map_rgb(32, 28, 69), 350, 300, ALLEGRO_ALIGN_CENTER, "Bartlomiej Suchecki");
		al_draw_text(categoryFont, al_map_rgb(32, 28, 69), 350, 350, ALLEGRO_ALIGN_CENTER, "Zywalewski Daniel");
		al_draw_text(categoryFont, al_map_rgb(15, 80, 120), 350, 450, ALLEGRO_ALIGN_CENTER, "Powrot do menu");

		al_draw_bitmap(trio, 750, 100, 0);




		al_flip_display();

	}


}

void DisplayAllegro::showInstructions() // Daniel- zrobione, tylko nie nie ma podswietlenia takiego jak w menu jesli chodzi o wybor	
										// zarowno mysz jak i klawiatura (Spacja i enter wychodz¹ do porzedniego ekranu) dzia³aj¹
{
	al_rest(0.15);
	POINT mousePosition;
	bigSword = al_load_bitmap("images/bloddySword.png");
	littleFont = al_load_font(FONT_FILE, 24, NULL);
	if (!littleFont)
	{
		cout << "Failed to load title font !\n";
		exit(0);
	}
	emptyScroll = al_load_bitmap(EMPTY_SCROLL);
	if (!emptyScroll)
	{
		cout << "Failed to load scroll bitmap!\n";
		exit(0);
	}

	while (true)
	{
		if (GetCursorPos(&mousePosition)) //myszka
		{
			if (mousePosition.x > 550 && mousePosition.x < 800 && mousePosition.y > 550 && mousePosition.y < 700)
			{
				if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
				{
					al_rest(0.15);
					break;
				}


			}

		}
		if (GetKeyState(VK_RETURN) & 0x8000 || GetKeyState(VK_SPACE) & 0x8000) // klawiatura
			break;

		al_clear_to_color(al_map_rgb(colors[0],colors[1],colors[2])); 
		al_draw_bitmap(emptyScroll, 0, 0, 0);
		al_draw_text(titleFont, al_map_rgb(15, 80, 120), 350, 100, ALLEGRO_ALIGN_CENTER, "Instrukcja");
		al_draw_text(littleFont, al_map_rgb(32, 28, 69), 350, 200, ALLEGRO_ALIGN_CENTER, "Jestes na mapie zlotym ludzikiem");
		al_draw_text(littleFont, al_map_rgb(32, 28, 69), 350, 225, ALLEGRO_ALIGN_CENTER, "Poruszasz sie klawiszami WASD");
		al_draw_text(littleFont, al_map_rgb(32, 28, 69), 350, 250, ALLEGRO_ALIGN_CENTER, "Zbieraj przedmioty, pokonuj wrogow, zdobywaj nowe poziomy");
		al_draw_text(littleFont, al_map_rgb(32, 28, 69), 350, 275, ALLEGRO_ALIGN_CENTER, "Schodami przechodzisz na nowy poziom");
		al_draw_text(littleFont, al_map_rgb(32, 28, 69), 350, 300, ALLEGRO_ALIGN_CENTER, "Nie trac HP bo zginiesz");

		al_draw_bitmap(bigSword, 750, 100, 0);

		al_draw_text(categoryFont, al_map_rgb(15, 80, 120), 350, 450, ALLEGRO_ALIGN_CENTER, "Powrot do menu");

		al_flip_display();
	}

}

void DisplayAllegro::drawOver() // Daniel - zrobione, zastanawiama siê tylko nad inn¹ kolorystyk¹ game over

{
	al_rest(0.15);
	POINT mousePosition;
	skull = al_load_bitmap("images/skull.png");
	gameOverFont = al_load_font(FONT_FILE, 150, NULL);
	while (true)
	{

		if (GetCursorPos(&mousePosition)) //myszka
		{
			if (mousePosition.x > 800 && mousePosition.x < 1150 && mousePosition.y > 700 && mousePosition.y < 800)
			{
				if ((GetKeyState(VK_LBUTTON) & 0x100) != 0)
				{
					al_rest(0.15);
					break;
				}


			}

		}
		if (GetKeyState(VK_RETURN) & 0x8000 || GetKeyState(VK_SPACE) & 0x8000) //klawiatura
			break;


		al_clear_to_color(al_map_rgb(colors[0], colors[1], colors[2])); // poprzedni kolor 84, 89, 85
		al_draw_text(gameOverFont, al_map_rgb(210, 0, 0), baseWidth / 2, 50, ALLEGRO_ALIGN_CENTER, "Koniec Gry");
		al_draw_bitmap(skull, baseWidth/2 - 150, baseHeight/2 -150, 0);
		al_draw_text(categoryFont, al_map_rgb(220, 220, 220), baseWidth / 2, baseHeight / 4 * 3, ALLEGRO_ALIGN_CENTER, "Powrot do menu");
		al_flip_display();
	}
}

DisplayAllegro::~DisplayAllegro()
{
	al_destroy_display(display);

	al_destroy_bitmap(scrollBitmap);
	for (int i = 0; i < 20; i++)
	{
		al_destroy_bitmap(animation[i]);
	}
	al_destroy_font(titleFont);
	al_destroy_font(categoryFont);
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

	al_draw_filled_rectangle(baseXCord + hpBarXOffset + margin,
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

	al_draw_rectangle(baseXCord + eqBoxXOffset,
		eqBoxYOffset,
		baseXCord + remainingSpace - 10,
		eqBoxYOffset + slotSize * inventorySize + 2 * margin + 2 * 2,
		al_map_rgb(0, 0, 0), 2);

	for (int i = 0; i < inventorySize; ++i)
	{
		ItemGameObject* item = player->getItemFromSlot(i);
		if (item && item->getRepresentation().getSprite())
			al_draw_bitmap(item->getRepresentation().getSprite(), baseXCord + eqBoxXOffset + margin + 2,
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
		if (effect)
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
