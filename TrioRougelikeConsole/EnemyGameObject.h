#pragma once
#include "CreatureGameObject.h"

/// <summary>
/// Klasa dla obiektów reprezentuj¹cych przeciwników.
/// </summary>
class EnemyGameObject : public CreatureGameObject
{
protected:

public:
	/// <summary>
	/// Konstruktor dla przeciwników bez startowego ekwipunku.
	/// </summary>
	/// <param name="hp">Iloœæ startowych punktów zdrowia</param>
	/// <param name="armor">Iloœæ bazowego pancerza</param>
	/// <param name="exp">Iloœæ punktów doœwiadczenia, jakie otrzymuje gracz gdy zabije przediwnika</param>
	/// <param name="activeItemsCount">Wielkoœæ aktywnego ekwipunku</param>
	/// <param name="Name">Nazwa stworzenia</param>
	/// <param name="Symbol">Reprezentacja graficzna stworzenia</param>
	EnemyGameObject(int hp, int armor, int exp, int activeItemsCount, string Name, GraphicalSymbol Symbol);
	/// <summary>
	/// Konstruktor dla przeciwników bez startowego ekwipunku.
	/// </summary>
	/// <param name="hp">Iloœæ startowych punktów zdrowia</param>
	/// <param name="armor">Iloœæ bazowego pancerza</param>
	/// <param name="exp">Iloœæ punktów doœwiadczenia, jakie otrzymuje gracz gdy zabije przediwnika</param>
	/// <param name="activeItemsCount">Wielkoœæ aktywnego ekwipunku</param>
	/// <param name="Name">Nazwa stworzenia</param>
	/// <param name="Symbol">Reprezentacja graficzna stworzenia</param>
	/// <param name="itemList">Lista przedmiotów startowych przeciwnika</param>
	EnemyGameObject(int hp, int armor, int exp, int activeItemsCount, string Name, GraphicalSymbol Symbol, const vector<ItemGameObject*>& itemList);
	/// <summary>
	/// Metoda wywo³ywana w ka¿dym odœwierzeniu gry.
	/// </summary>
	virtual void onRefresh() override;
	/// <summary>
	/// Metoda czysto abstrakcyjna tworz¹ca kopiê obiektu.
	/// </summary>
	/// <returns>Kopia obiektu</returns>
	virtual GameObject* clone() const override;

	/// <summary>
	/// Wirtualny destruktor
	/// </summary>
	virtual ~EnemyGameObject();
};