#pragma once
#include "DynamicGameObject.h"

/// <summary>
/// Klasa dla obiekt�w reprezentuj�cych efekt na�o�ony na inny obiekt gry.
/// </summary>
class EffectGameObject : public DynamicGameObject
{
private:
	/// <summary>
	/// Prywatna implementacja metody onInteraction by uniemo�liwi� jej wywo�anie.
	/// </summary>
	virtual void onInteraction() override;
protected:

public:
	EffectGameObject(string Name, GraphicalSymbol Symbol);
	/// <summary>
	/// Nieobowi�zkowa metoda wywo�ywana w ka�dym od�wierzeniu gry.
	/// </summary>
	virtual void onRefresh() override;
};