#pragma once
#include "CreatureGameObject.h"

/// <summary>
/// Klasa dla obiekt�w reprezentuj�cych przeciwnik�w.
/// </summary>
class EnemyGameObject : public CreatureGameObject
{
protected:

public:
	/// <summary>
	/// Konstruktor dla przeciwnik�w bez startowego ekwipunku.
	/// </summary>
	/// <param name="hp">Ilo�� startowych punkt�w zdrowia</param>
	/// <param name="armor">Ilo�� bazowego pancerza</param>
	/// <param name="exp">Ilo�� punkt�w do�wiadczenia, jakie otrzymuje gracz gdy zabije przediwnika</param>
	/// <param name="activeItemsCount">Wielko�� aktywnego ekwipunku</param>
	/// <param name="Name">Nazwa stworzenia</param>
	/// <param name="Symbol">Reprezentacja graficzna stworzenia</param>
	EnemyGameObject(int hp, int armor, int exp, int activeItemsCount, string Name, GraphicalSymbol Symbol);
	/// <summary>
	/// Konstruktor dla przeciwnik�w bez startowego ekwipunku.
	/// </summary>
	/// <param name="hp">Ilo�� startowych punkt�w zdrowia</param>
	/// <param name="armor">Ilo�� bazowego pancerza</param>
	/// <param name="exp">Ilo�� punkt�w do�wiadczenia, jakie otrzymuje gracz gdy zabije przediwnika</param>
	/// <param name="activeItemsCount">Wielko�� aktywnego ekwipunku</param>
	/// <param name="Name">Nazwa stworzenia</param>
	/// <param name="Symbol">Reprezentacja graficzna stworzenia</param>
	/// <param name="itemList">Lista przedmiot�w startowych przeciwnika</param>
	EnemyGameObject(int hp, int armor, int exp, int activeItemsCount, string Name, GraphicalSymbol Symbol, const vector<ItemGameObject*>& itemList);
	/// <summary>
	/// Metoda wywo�ywana w ka�dym od�wierzeniu gry.
	/// </summary>
	virtual void onRefresh() override;
	/// <summary>
	/// Metoda czysto abstrakcyjna tworz�ca kopi� obiektu.
	/// </summary>
	/// <returns>Kopia obiektu</returns>
	virtual GameObject* clone() const override;

	/// <summary>
	/// Wirtualny destruktor
	/// </summary>
	virtual ~EnemyGameObject();
};