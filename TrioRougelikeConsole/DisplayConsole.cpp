#include "DisplayConsole.h"
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <cstdio>
#include "Bars.h"
#include "PlayerGameObject.h"
#include "Map.h"
#include "ItemGameObject.h"
#include "DisplayConsole.h"


int DisplayConsole::drawMenu()
{
	enum KEYCODES { UP = 72, DOWN = 80, ENTER = 13 };
	char c = 254;
	int chosenOption = 1;
	int keyy = -1;
	while (1)
	{
		system("cls");

		std::cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" <<std:: endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
std::cout<<"			    ______ _____ _____ _   _ _____    _     _____ _   __ _____ "<<std::endl;
std::cout<<"			    | ___ \\  _  |  __ \\ | | |  ___|  | |   |_   _| | / /|  ___|"<<std::endl;
std::cout<<"			    | |_/ / | | | |  \\/ | | | |__    | |     | | | |/ / | |__  "<<std::endl;
std::cout<<"			    |    /| | | | | __| | | |  __|   | |     | | |    \\ |  __| "<<std::endl;
std::cout<<"			    | |\\ \\\\ \\_/ / |_\\ \\ |_| | |___   | |_____| |_| |\\  \\| |___ "<<std::endl;
std::cout<<"			    \\_| \\_|\\___/ \\____/\\___/\\____/   \\_____/\\___/\\_| \\_/\\____/ "<<std::endl << std::endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		std::cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << std::endl;
		std::cout << "" << std::endl;

		switch (chosenOption)
		{
		case 1:
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			printf("			     [%c]		  Rozpocznij Gre \n ", chosenOption == 1 ? c : ' ');
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("			     [%c]		  Instrukcja gry \n ", chosenOption == 2 ? c : ' ');
			printf("			     [%c]		     Autorzy\n ", chosenOption == 3 ? c : ' ');
			printf("			     [%c]		      Wyjdz \n ", chosenOption == 4 ? c : ' ');
			break;

		}
		case 2:
		{
			printf("			     [%c]		  Rozpocznij Gre \n ", chosenOption == 1 ? c : ' ');
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			printf("			     [%c]		  Instrukcja gry \n ", chosenOption == 2 ? c : ' ');
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("			     [%c]		     Autorzy\n ", chosenOption == 3 ? c : ' ');
			printf("			     [%c]		      Wyjdz \n ", chosenOption == 4 ? c : ' ');
			break;
		}
		case 3:
		{
			printf("			     [%c]		  Rozpocznij Gre \n ", chosenOption == 1 ? c : ' ');
			printf("			     [%c]		  Instrukcja gry \n ", chosenOption == 2 ? c : ' ');
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			printf("			     [%c]		     Autorzy\n ", chosenOption == 3 ? c : ' ');
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			printf("			     [%c]		      Wyjdz \n ", chosenOption == 4 ? c : ' ');
			break;
		}
		case 4:
		{
			printf("			     [%c]		  Rozpocznij Gre \n ", chosenOption == 1 ? c : ' ');
			printf("			     [%c]		  Instrukcja gry \n ", chosenOption == 2 ? c : ' ');
			printf("			     [%c]		     Autorzy\n ", chosenOption == 3 ? c : ' ');
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
			printf("			     [%c]		      Wyjdz \n ", chosenOption == 4 ? c : ' ');
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			break;
		}
		}



		std::cout << std::endl << std::endl << "					    .                                         " << std::endl;
		std::cout << "		                         /   ))     |\\         )               ).           " << std::endl;
		std::cout << "		                   c--. (\\  ( `.    / )  (\\   ( `.     ).     ( (           " << std::endl;
		std::cout << "		                   | |   ))  ) )   ( (   `.`.  ) )    ( (      ) )          " << std::endl;
		std::cout << "		                   | |  ( ( / _..----.._  ) | ( ( _..----.._  ( (           " << std::endl;
		std::cout << "		     ,-.           | |---) V.'-------.. `-. )-/.-' ..------ `--) \\._        " << std::endl;
		std::cout << "		     | /===========| |  (   |      ) ( ``-.`\\/'.-''           (   ) ``-._   " << std::endl;
		std::cout << "		     | | / / / / / | |--------------------->  <-------------------------_>=-" << std::endl;
		std::cout << "		     | \\===========| |                 ..-'./\\.`-..                _,,-'    " << std::endl;
		std::cout << "		     `-'           | |-------._------''_.-'----`-._``------_.-----'         " << std::endl;
		std::cout << "		                   | |         ``----''            ``----''                 " << std::endl;
		std::cout << "		                   | |                                                      " << std::endl;
		std::cout << "		                   c--`                                                     " << std::endl;



		keyy = _getch();


		switch (keyy)
		{
		case DOWN:
		{
			if (chosenOption == 4)
				chosenOption = 1;
			else
				++chosenOption;

			break;
		}
		case UP:
		{
			if (chosenOption == 1)
				chosenOption = 4;
			else
				--chosenOption;

			break;
		}
		case ENTER:
		{
			return chosenOption;
		}
		}
	}
	return -1;

}

void DisplayConsole::showAuthors()
{
	system("cls");
	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl <<  std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	std::cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	std::cout << "				    	  >	    Autorzy Gry:	<" << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	std::cout << "				    	  >	Suchecki Bartlomiej	<" << std::endl;
	std::cout << "				    	  >	 Tomkiel Sebastian	<" << std:: endl;
	std::cout << "				    	  >	 Zywalewski Daniel	<" <<  std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	std::cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << endl;
	cout << "				       Wcisnij dowolny klawisz by kontynuowac";
	int g = _getch();
}

void DisplayConsole::showInstructions()
{
	system("cls");
	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

	std::cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);

	std::cout << "			>	                   Instrukcja Gry:				<" << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	std::cout << "			>	               Jestes oznaczony symbolem @			< " << std::endl;
	std::cout << "			>	          Poruszasz sie za pomoca klawiszy WASD			<" << std::endl;
	std::cout << "			>	 Zbieraj przedmioty, pokonuj wrogow, zdobywaj nowe poziomy	< " <<  std::endl;
	std::cout << "			>	           Znak % to przejscie na inny poziom			< " << std::endl;
	std::cout << "			>	             Pamietaj o wylaczeniu CapsLock			< " << std::endl;
	std::cout << "			>	                Nie trac HP bo zginiesz!			<" << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

	std::cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << endl;
	cout << "				       Wcisnij dowolny klawisz by kontynuowac";
	int g = _getch();
}
void DisplayConsole::drawStats(PlayerGameObject* player)
{
	std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "Imie: " << player->getName() << std::endl;
	std::cout << "Pancerz: " << player->getBaseArmor() << std::endl;
	std::cout << "Poziom Gracza: " << player->getLevel() << std::endl;
	std::cout << "HP: [" << player->getHealthPoints() << "/" << player->getBaseHealthPoints() << "]";
	showHealthBar(player->getHealthPoints(), player->getBaseHealthPoints());
	std::cout << std::endl << "XP: [" << player->getExperience() << "/" << player->getMaxXP() << "]";
	showHealthBar(player->getExperience(), player->getMaxXP());
	cout << "Effects: ";
	for (int i = 0; i < player->getActiveEffectsSize(); ++i)
	{
		const EffectGameObject* e = player->getEffectFromSlot(i);
		if (e)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), e->getRepresentation().getColor());
			cout << e->getRepresentation().getCharSymbol() << " ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
	}
	cout << endl;
	cout << "Equiped: ";
	for (int i = 0; i < player->getActiveInventorySize(); ++i)
	{
		const ItemGameObject* item = player->getItemFromSlot(i);
		if (item)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), player->getItemFromSlot(i)->getRepresentation().getColor());
			cout << player->getItemFromSlot(i)->getRepresentation().getCharSymbol() << " ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		}
	}
	cout << endl;
	std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;

}

void DisplayConsole::drawMap(Map* map1)
{
	system("cls");
	//cout << map1->getMapDesignObject()->size() << endl;
	int x_size = map1->getMapDesignObject()->size();
	int y_size = map1->getMapDesignObject()[0].size();

	cout << (char)201;
	for (int i = 0; i < y_size; ++i)
		cout << (char)205;
	cout << (char)187 << endl;

	for (int i = 0; i < x_size; i++)
	{
		cout << (char)186;
		for (int j = 0; j < y_size; j++)
		{
			for (int k = 2; k >= 0; --k)
			{
				GameObject* g = map1->getObjectInMap(i, j, k);
				if (g)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), g->getRepresentation().getColor());
					cout << g->getRepresentation().getCharSymbol();
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					break;
				}
				else if (k == 0)
					cout << " ";
			}
		}
		cout << (char)186 << endl;
	}

	cout << (char)200;
	for (int i = 0; i < y_size; ++i)
		cout << (char)205;
	cout << (char)188 << endl;
}

void DisplayConsole::drawOver()
{
	int i = 0;
	system("cls");
	std::cout << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl << std::endl;
	std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "				 _____   ___  ___  ___ _____   _____  _   _ ___________ " << std::endl;
	std::cout << "				|  __ \\ / _ \\ |  \\/  ||  ___| |  _  || | | |  ___| ___ \\" << std::endl;
	std::cout << "				| |  \\// /_\\ \\| .  . || |__   | | | || | | | |__ | |_/ /" << std::endl;
	std::cout << "				| | __ |  _  || |\\/| ||  __|  | | | || | | |  __||    / " << std::endl;
	std::cout << "				| |_\\ \\| | | || |  | || |___  \\ \\_/ /\\ \\_/ / |___| |\\ \\ " << std::endl;
	std::cout << "				 \\____/\\_| |_/\\_|  |_/\\____/   \\___/  \\___/\\____/\\_| \\_|" << std::endl << std::endl;


	std::cout << "------------------------------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "                                               Press any key to continue                                                    " << std::endl;
	i = _getch();
	system("cls");
}