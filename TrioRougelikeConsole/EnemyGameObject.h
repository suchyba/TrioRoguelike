#pragma once
#include "CreatureGameObject.h"

/// <summary>
/// Klasa dla obiekt�w reprezentuj�cych przeciwnik�w.
/// </summary>
class EnemyGameObject : public CreatureGameObject
{
protected:

public:
	EnemyGameObject(int hp, int armor, int exp, int activeItemsCount, string Name, GraphicalSymbol Symbol);
	EnemyGameObject(int hp, int armor, int exp, int activeItemsCount, string Name, GraphicalSymbol Symbol, const vector<ItemGameObject*>& itemList);
	virtual void onRefresh() override;
	virtual GameObject* clone() const override;
};