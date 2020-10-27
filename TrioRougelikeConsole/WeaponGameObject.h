#pragma once
#include "ItemGameObject.h"

class WeaponGameObject : public ItemGameObject
{
private:
	/// <summary>
	/// Dodatkowy pancerz
	/// </summary>
	int bonusArmor;
public:
	/// <summary>
	/// Konstruktor
	/// </summary>
	/// <param name="Value">Warto�� broni</param>
	/// <param name="Effect">Efekt nak�adany na przeciwnika, kiedy si� go atakuje</param>
	/// <param name="Name">Nazwa broni</param>
	/// <param name="Symbol">Reprezentacja graficzna broni</param>
	/// <param name="MinDamage">Minimalna ilo�� obra�e�</param>
	/// <param name="MaxDamage">Maksymalna ilo�� obra�e�</param>
	WeaponGameObject(int Value, const EffectGameObject* Effect, string Name, GraphicalSymbol Symbol, int MinDamage, int MaxDamage);
	/// <summary>
	/// Metoda tworz�ca kopi� obiektu.
	/// </summary>
	/// <returns>Kopia obiektu</returns>
	virtual GameObject* clone() const override;
	/// <summary>
	/// Metoda wywo�ywana, kiedy zaatakuje si� stworzenie
	/// </summary>
	/// <param name="opponent">Stworzenie, kt�re atakujemy</param>
	virtual void onAttack(CreatureGameObject& opponent) override;
};