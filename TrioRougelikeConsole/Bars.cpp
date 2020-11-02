#include "Bars.h"
#include <iostream>
#include <Windows.h>

void showHealthBar(int healthPoints,int baseHealthPoints){

	float  ratio = 0;
	ratio = ((float)healthPoints / (float)baseHealthPoints) * 10;

	int pusto = 10 - (int)ratio;
	char HP = 178;
	if (ratio <= 2.5)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	}
	std::cout << "HP : |";


	for (int i = 0; i < (int)ratio; i++)
	{
		std::cout << " " << HP;
	}
	for (int i = 0; i < pusto; i++)
	{
		std::cout << "  ";
	}
	std::cout << " |" << std::endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

}