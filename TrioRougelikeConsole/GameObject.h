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
	GameObject(string, GraphicalSymbol);

	const string getName();
	const GraphicalSymbol getRepresentation();

	void setGraphicalRepresentation(GraphicalSymbol);
};
