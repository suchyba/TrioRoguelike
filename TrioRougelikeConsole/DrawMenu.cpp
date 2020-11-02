#include "DrawMenu.h"
#include <iostream>
#include <conio.h>
#include <cstdio>


int  drawMenu()
{
	enum KEYCODES { UP = 72, DOWN = 80, ENTER = 13 };
	char c = 254;
	int chosenOption = 1;
	int keyy = -1;
	while (1)
	{
		system("cls");
		std::cout << "//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" <<std:: endl;
		std::cout << "                             ______ _____ _   _ _____  _____   _     _____ _   __ _____ " << std::endl;
		std::cout << "                             | ___ \\  _  | | | |  __ \\|  ___| | |   |_   _| | / /|  ___|" << std::endl;
		std::cout << "                             | |_/ / | | | | | | |  \\/| |__   | |     | | | |/ / | |__  " << std::endl;
		std::cout << "                             |    /| | | | | | | | __ |  __|  | |     | | |    \\ |  __| " << std::endl;
		std::cout << "                             | |\\ \\\\ \\_/ / |_| | |_\\ \\| |___  | |_____| |_| |\\  \\| |___ " << std::endl;
		std::cout << "                             \\_| \\_|\\___/ \\___/ \\____/\\____/  \\_____/\\___/\\_| \\_/\\____/" << std::endl << std::endl;
		std::cout << "//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////" << std::endl;
		std::cout << "" << std::endl;


		printf("			     [%c]		  Rozpocznij Gre \n ", chosenOption == 1 ? c : ' ');
		printf("			     [%c]		  Instrukcja gry \n ", chosenOption == 2 ? c : ' ');
		printf("			     [%c]		     Autorzy\n ", chosenOption == 3 ? c : ' ');
		printf("			     [%c]		      Wyjdz \n ", chosenOption == 4 ? c : ' ');


		std::cout << std::endl << std::endl << "					    .                                         " << std::endl;
		std::cout << "		                         /   ))     |\\         )               ).           " << std::endl;
		std::cout << "		                   c--. (\\  ( `.    / )  (\\   ( `.     ).     ( (           " << std::endl;
		std::cout << "		                   | |   ))  ) )   ( (   `.`.  ) )    ( (      ) )          " << std::endl;
		std::cout << "		                   | |  ( ( / _..----.._  ) | ( ( _..----.._  ( (           " << std::endl;
		std::cout << "		     ,-.           | |---) V.'-------.. `-. )-/.-' ..------ `--) \\._        " << std::endl;
		std::cout << "		     | /===========| |  (   |      ) ( ``-.`\\/'.-''           (   ) ``-._   " << std::endl;
		std::cout << "		     | | / / / / / | |--------------------->  <-------------------------_>=-" << std::endl;
		std::cout << "		     | \===========| |                 ..-'./\\.`-..                _,,-'    " << std::endl;
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

