#include "GraphicalSymbol.h"
#include <iostream>
#include <Windows.h>

using namespace std;

GraphicalSymbol::GraphicalSymbol(char symbol, int foreground, int background) : charSymbol(symbol), foregroundColor(foreground), backgroundColor(background), sprite(NULL)
{
}

GraphicalSymbol::GraphicalSymbol(ALLEGRO_BITMAP* image) : charSymbol((char)0), foregroundColor(-1), backgroundColor(-1), sprite(image)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 4);
    if (!image)
        cout << "[Graphical Symbol] Could not found bitmap!" << endl;
    SetConsoleTextAttribute(hConsole, 7);
}

char GraphicalSymbol::getCharSymbol() const
{
    return charSymbol;
}

int GraphicalSymbol::getColor() const
{
    return foregroundColor + backgroundColor * 16;
}

void GraphicalSymbol::setColors(int foreground, int background)
{
    foregroundColor = foreground;
    backgroundColor = background;
}

ALLEGRO_BITMAP* GraphicalSymbol::getSprite() const
{
    return sprite;
}
