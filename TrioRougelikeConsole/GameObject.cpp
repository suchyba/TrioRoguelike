#include "GameObject.h"

GameObject::GameObject(string Name, GraphicalSymbol GSymbol) : name(Name), representation(GSymbol)
{

}

GameObject::GameObject() : name("<NONE>"), representation(new GraphicalSymbol(' '))
{

}

string GameObject::getName() const
{
    return name;
}

GraphicalSymbol GameObject::getRepresentation() const
{
    return representation;
}

void GameObject::setGraphicalRepresentation(GraphicalSymbol newRepresentation)
{
    representation = newRepresentation;
}
