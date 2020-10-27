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
	/// Minimalne obra�enia, kt�re zapewnia przedmiot.
	/// </summary>
	int minDamage;
	/// <summary>
	/// Maksymalne obra�enia, kt�re zapewnia przedmiot.
	/// </summary>
	int maxDamage;
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
	ItemGameObject(int Value, const EffectGameObject* Effect, string Name, GraphicalSymbol Symbol, int Armor = 0, int MinDamage = 0, int MaxDamage = 0);
	/// <summary>
	/// Metoda dost�powa do pola bonusArmor.
	/// </summary>
	/// <returns>bonusArmor</returns>
	int getArmor() const;
	/// <summary>
	/// Metoda dost�powa do pola minDamage.
	/// </summary>
	/// <returns>Minimalne obra�enia</returns>
	int getMinDamage() const;
	/// <summary>
	/// Metoda dost�powa do pola maxDamage.
	/// </summary>
	/// <returns>Maksymalne obra�enia</returns>
	int getMaxDamage() const;
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
	/// <param name="self">Stworzenie, na kt�re jest za�o�ony przedmiot</param>
	/// <returns>Przetworzone obra�enia, kt�re s� otrzymywane przez stworzenie.</returns>
	virtual int onDamege(int damage, CreatureGameObject& self);
	/// <summary>
	/// Metoda wywo�ywana w momencie aktywowania przez stworzenie.
	/// </summary>
	virtual void onActivation();
	/// <summary>
	/// Metoda wywo�ywana w momencie zak�adania ekwipunku na stworzenie.
	/// </summary>
	/// <param name="creature">Obiekt stworzenia, kt�re zak�ada przedmiot.</param>
	virtual void onEquipping(CreatureGameObject& creature);

	/// <summary>
	/// Metoda czysto abstrakcyjna tworz�ca kopi� obiektu.
	/// </summary>
	/// <returns>Kopia obiektu</returns>
	virtual GameObject* clone() const override = 0;
};