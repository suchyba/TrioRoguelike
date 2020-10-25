#pragma once
#include "DynamicGameObject.h"

/// <summary>
/// Klasa dla obiektów reprezentuj¹cych efekt na³o¿ony na inny obiekt gry.
/// </summary>
class EffectGameObject : public DynamicGameObject
{
private:
	/// <summary>
	/// Prywatna implementacja metody onInteraction by uniemo¿liwiæ jej wywo³anie.
	/// </summary>
	virtual void onInteraction() override;
protected:

public:
	EffectGameObject(string Name, GraphicalSymbol Symbol);
	/// <summary>
	/// Nieobowi¹zkowa metoda wywo³ywana w ka¿dym odœwierzeniu gry.
	/// </summary>
	virtual void onRefresh() override;
};