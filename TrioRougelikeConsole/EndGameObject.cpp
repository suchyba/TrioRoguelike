#include "EndGameObject.h"
#include "Game.h"

EndGameObject::EndGameObject(string Name, GraphicalSymbol Symbol) : InteractionableGameObject(Name, Symbol)
{
}

void EndGameObject::onInteraction()
{
    Game::nextMap();
}

GameObject* EndGameObject::clone() const
{
    return new EndGameObject(*this);
}
