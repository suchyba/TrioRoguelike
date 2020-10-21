#pragma once

class GraphicalSymbol
{
private:
	char charSymbol;
	int foregroundColor;
	int backgroundColor;
public:
	GraphicalSymbol(char charSymbol, int foreground, int background);
	char getCharSymbol() const;
	int getColor() const;
	void setColors(int foreground, int background);
};