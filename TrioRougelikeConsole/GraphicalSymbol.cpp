#include "GraphicalSymbol.h"

GraphicalSymbol::GraphicalSymbol() {}

GraphicalSymbol::GraphicalSymbol(char symbol, int foreground, int background) : charSymbol(symbol), foregroundColor(foreground), backgroundColor(background)
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
