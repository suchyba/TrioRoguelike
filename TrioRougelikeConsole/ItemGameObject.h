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
private:
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
	EffectGameObject* effect;
public:
	/// <summary>
	/// Konstruktor dla elementu zbroi.
	/// </summary>
	/// <param name="Armor">Warto�� dodatkowego poncerza</param>
	/// <param name="Damage">Warto�� obra�e� zadawanych przez przedmiot</param>
	/// <param name="Value">Warto�� przedmiotu</param>
	/// <param name="Effect">Efekt, kt�ry nak�ada przedmiot</param>
	/// <param name="Name">Nazwa przedmiotu</param>
	/// <param name="Symbol">Graficzna reprezentacja przedmiotu</param>
	ItemGameObject(int Value, const EffectGameObject* Effect, string Name, GraphicalSymbol Symbol, int Armor = 0, int Damage = 0);
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

	virtual GameObject* clone() const override = 0;
};