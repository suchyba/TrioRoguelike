#pragma once
#include "GameObject.h"
#include "EffectGameObject.h"
using namespace std;

class CreatureGameObject;

/// <summary>
/// Klasa dla obiekt�w reprezentuj�cych przedmioty
/// </summary>
class ItemGameObject : public GameObject
{
protected:
	/// <summary>
	/// Dodatkowe punkty pancerza, kt�re zapewnia przedmiot.
	/// </summary>
	int bonusArmor;
	/// <summary>
	/// Obra�enia, kt�re zapewnia przedmiot.
	/// </summary>
	int damage;
	/// <summary>
	/// Warto�� przedmiotu.
	/// </summary>
	int value;
	/// <summary>
	/// Tablica efekt�w dodawanych przez przedmiot stworzeniu, kt�re go nosi.
	/// </summary>
	EffectGameObject* effect = NULL;
public:
	/// <summary>
	/// Metoda dost�powa do pola bonusArmor.
	/// </summary>
	/// <returns>bonusArmor</returns>
	int getArmor() const;
	/// <summary>
	/// Metoda dost�powa do pola damage.
	/// </summary>
	/// <returns>damage</returns>
	int getDamage() const;
	/// <summary>
	/// Metoda dost�powa do pola value.
	/// </summary>
	/// <returns>value</returns>
	int getValue() const;

	/// <summary>
	/// Metoda wywo�ywana bezpo�rednio przed atakiem na przeciwnika.
	/// </summary>
	/// <param name="opponent">Stworzenie, kt�re jest atakowane</param>
	virtual void onAttack(CreatureGameObject& opponent);
	/// <summary>
	/// Metoda wywo�ywana bezpo�rednio przed otrzymaniem obra�e�.
	/// </summary>
	/// <param name="damage">Obra�enia, kt�re s� otrzymywane.</param>
	/// <returns>Przetworzone obra�enia, kt�re s� otrzymywane przez stworzenie.</returns>
	virtual int onDamege(int damage);
	/// <summary>
	/// Metoda wywo�ywana w momencie aktywowania przez stworzenie.
	/// </summary>
	virtual void onActivation();
	/// <summary>
	/// Metoda wywo�ywana w momencie zak�adania ekwipunku na stworzenie.
	/// </summary>
	/// <param name="creature">Obiekt stworzenia, kt�re zak�ada przedmiot.</param>
	virtual void onEquipping(CreatureGameObject& creature);
};