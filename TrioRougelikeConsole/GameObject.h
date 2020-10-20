#pragma once
#include <iostream>
#include "GraphicalSymbol.h"

using namespace std;

class GameObject
{
protected:
	string name;
	GraphicalSymbol representation;
public:
	GameObject(string Name, GraphicalSymbol Symbol);
	GameObject();

	string getName() const;
	GraphicalSymbol getRepresentation() const;

	void setGraphicalRepresentation(GraphicalSymbol);
};
