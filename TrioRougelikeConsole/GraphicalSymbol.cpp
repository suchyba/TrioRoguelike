#include "GraphicalSymbol.h"

GraphicalSymbol::GraphicalSymbol(char symbol, int foreground, int background) : charSymbol(symbol), foregroundColor(foreground), backgroundColor(background), sprite(NULL)
{
}

GraphicalSymbol::GraphicalSymbol(ALLEGRO_BITMAP* image) : charSymbol((char)0), foregroundColor(-1), backgroundColor(-1), sprite(image)
{

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
