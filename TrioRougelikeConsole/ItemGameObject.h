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
private:
protected:
	/// <summary>
	/// Dodatkowe punkty pancerza, które zapewnia przedmiot.
	/// </summary>
	int bonusArmor;
	/// <summary>
	/// Minimalne obra¿enia, które zapewnia przedmiot.
	/// </summary>
	int minDamage;
	/// <summary>
	/// Maksymalne obra¿enia, które zapewnia przedmiot.
	/// </summary>
	int maxDamage;
	/// <summary>
	/// Wartoœæ przedmiotu.
	/// </summary>
	int value;
	/// <summary>
	/// Tablica efektów dodawanych przez przedmiot stworzeniu, które go nosi.
	/// </summary>
	EffectGameObject* effect;
public:
	/// <summary>
	/// Konstruktor dla elementu zbroi.
	/// </summary>
	/// <param name="Armor">Wartoœæ dodatkowego poncerza</param>
	/// <param name="Damage">Wartoœæ obra¿eñ zadawanych przez przedmiot</param>
	/// <param name="Value">Wartoœæ przedmiotu</param>
	/// <param name="Effect">Efekt, który nak³ada przedmiot</param>
	/// <param name="Name">Nazwa przedmiotu</param>
	/// <param name="Symbol">Graficzna reprezentacja przedmiotu</param>
	ItemGameObject(int Value, const EffectGameObject* Effect, string Name, GraphicalSymbol Symbol, int Armor = 0, int MinDamage = 0, int MaxDamage = 0);
	/// <summary>
	/// Metoda dostêpowa do pola bonusArmor.
	/// </summary>
	/// <returns>bonusArmor</returns>
	int getArmor() const;
	/// <summary>
	/// Metoda dostêpowa do pola minDamage.
	/// </summary>
	/// <returns>Minimalne obra¿enia</returns>
	int getMinDamage() const;
	/// <summary>
	/// Metoda dostêpowa do pola maxDamage.
	/// </summary>
	/// <returns>Maksymalne obra¿enia</returns>
	int getMaxDamage() const;
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
	/// <param name="self">Stworzenie, na które jest za³o¿ony przedmiot</param>
	/// <returns>Przetworzone obra¿enia, które s¹ otrzymywane przez stworzenie.</returns>
	virtual int onDamege(int damage, CreatureGameObject& self);
	/// <summary>
	/// Metoda wywo³ywana w momencie aktywowania przez stworzenie.
	/// </summary>
	virtual void onActivation();
	/// <summary>
	/// Metoda wywo³ywana w momencie zak³adania ekwipunku na stworzenie.
	/// </summary>
	/// <param name="creature">Obiekt stworzenia, które zak³ada przedmiot.</param>
	virtual void onEquipping(CreatureGameObject& creature);

	/// <summary>
	/// Metoda czysto abstrakcyjna tworz¹ca kopiê obiektu.
	/// </summary>
	/// <returns>Kopia obiektu</returns>
	virtual GameObject* clone() const override = 0;
};