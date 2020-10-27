#include "GameObject.h"
#include <iostream>
#include <Windows.h>

using namespace std;

GameObject::GameObject(string Name, GraphicalSymbol GSymbol) : name(Name), representation(GSymbol)
{
    //  DEBUG
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << getTag() << "Created GameObject (" << name << ", ";
    SetConsoleTextAttribute(hConsole, representation.getColor());
    cout << representation.getCharSymbol();
    SetConsoleTextAttribute(hConsole, 7);
    cout << ")" << endl;
    // END DEBUG
}

string GameObject::getName() const
{
    return name;
}

GraphicalSymbol GameObject::getRepresentation() const
{
    return representation;
}

void GameObject::setGraphicalRepresentation(const GraphicalSymbol& newRepresentation)
{
    representation = newRepresentation;
}

string GameObject::getTag() const
{
    return "[" + name + "] ";
}

GameObject* GameObject::clone() const
{
    return new GameObject(*this);
}
