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
	/// <param name="Value">Wartoœæ broni</param>
	/// <param name="Effect">Efekt nak³adany na przeciwnika, kiedy siê go atakuje</param>
	/// <param name="Name">Nazwa broni</param>
	/// <param name="Symbol">Reprezentacja graficzna broni</param>
	/// <param name="MinDamage">Minimalna iloœæ obra¿eñ</param>
	/// <param name="MaxDamage">Maksymalna iloœæ obra¿eñ</param>
	WeaponGameObject(int Value, const EffectGameObject* Effect, string Name, GraphicalSymbol Symbol, int MinDamage, int MaxDamage);
	/// <summary>
	/// Metoda tworz¹ca kopiê obiektu.
	/// </summary>
	/// <returns>Kopia obiektu</returns>
	virtual GameObject* clone() const override;
	/// <summary>
	/// Metoda wywo³ywana, kiedy zaatakuje siê stworzenie
	/// </summary>
	/// <param name="opponent">Stworzenie, które atakujemy</param>
	virtual void onAttack(CreatureGameObject& opponent) override;
};