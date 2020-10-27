#pragma once
#include "ItemGameObject.h"

class ArmorGameObject : public ItemGameObject
{
private:
	/// <summary>
	/// Ukrycie pola damage.
	/// </summary>
	int damage;
public:
	/// <summary>
	/// Konstruktor obitktu zbroi
	/// </summary>
	/// <param name="Value">Warto�� zbroi</param>
	/// <param name="Effect">Efekt, kt�ry nak�ada zbroja w przypadku, gdy stworzenie j� nosz�ce jest atakowane</param>
	/// <param name="Name">Nazwa</param>
	/// <param name="Symbol">Reprezentacja graficzna</param>
	/// <param name="Armor">Ilo�� punkt�w pancerza dodawanego nosz�cemu</param>
	ArmorGameObject(int Value, const EffectGameObject* Effect, string Name, GraphicalSymbol Symbol, int Armor);
	/// <summary>
	/// Metoda tworz�ca kopi� obiektu.
	/// </summary>
	/// <returns>Kopia obiektu</returns>
	virtual GameObject* clone() const override;
	/// <summary>
	/// Metoda uruchamiana, gdy nosiciel zbroi jest atakowany.
	/// </summary>
	/// <param name="damage">Obra�enia, kt�re maj� by� zadane.</param>
	/// <param name="self">Obiekt stworzenia nosz�cego.</param>
	/// <returns>Ostateczna ilo�� obra�e� otrzymywanych przez stworzenie.</returns>
	virtual int onDamege(int damage, CreatureGameObject& self) override;

	/// <summary>
	/// Wirtualny destruktor
	/// </summary>
	virtual ~ArmorGameObject();
};
