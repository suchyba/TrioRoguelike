#pragma once
#include "GameObject.h"
#include "EffectGameObject.h"
using namespace std;

class CreatureGameObject;

/// <summary>
/// Klasa dla obiektów reprezentuj¹cych przedmioty
/// </summary>
class ItemGameObject : public GameObject
{
protected:
	/// <summary>
	/// Dodatkowe punkty pancerza, które zapewnia przedmiot.
	/// </summary>
	int bonusArmor;
	/// <summary>
	/// Obra¿enia, które zapewnia przedmiot.
	/// </summary>
	int damage;
	/// <summary>
	/// Wartoœæ przedmiotu.
	/// </summary>
	int value;
	/// <summary>
	/// Tablica efektów dodawanych przez przedmiot stworzeniu, które go nosi.
	/// </summary>
	EffectGameObject* effect = NULL;
public:
	/// <summary>
	/// Metoda dostêpowa do pola bonusArmor.
	/// </summary>
	/// <returns>bonusArmor</returns>
	int getArmor() const;
	/// <summary>
	/// Metoda dostêpowa do pola damage.
	/// </summary>
	/// <returns>damage</returns>
	int getDamage() const;
	/// <summary>
	/// Metoda dostêpowa do pola value.
	/// </summary>
	/// <returns>value</returns>
	int getValue() const;

	/// <summary>
	/// Metoda wywo³ywana bezpoœrednio przed atakiem na przeciwnika.
	/// </summary>
	/// <param name="opponent">Stworzenie, które jest atakowane</param>
	virtual void onAttack(CreatureGameObject& opponent);
	/// <summary>
	/// Metoda wywo³ywana bezpoœrednio przed otrzymaniem obra¿eñ.
	/// </summary>
	/// <param name="damage">Obra¿enia, które s¹ otrzymywane.</param>
	/// <returns>Przetworzone obra¿enia, które s¹ otrzymywane przez stworzenie.</returns>
	virtual int onDamege(int damage);
	/// <summary>
	/// Metoda wywo³ywana w momencie aktywowania przez stworzenie.
	/// </summary>
	virtual void onActivation();
	/// <summary>
	/// Metoda wywo³ywana w momencie zak³adania ekwipunku na stworzenie.
	/// </summary>
	/// <param name="creature">Obiekt stworzenia, które zak³ada przedmiot.</param>
	virtual void onEquipping(CreatureGameObject& creature);
};