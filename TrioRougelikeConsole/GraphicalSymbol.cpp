#include "GraphicalSymbol.h"

GraphicalSymbol::GraphicalSymbol(char symbol) : charSymbol(symbol)
{
}

const char GraphicalSymbol::getCharSymbol()
{
    return charSymbol;
}
