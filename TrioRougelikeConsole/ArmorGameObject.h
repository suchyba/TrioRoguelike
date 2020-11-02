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
	/// <param name="Value">Wartoœæ zbroi</param>
	/// <param name="Effect">Efekt, który nak³ada zbroja w przypadku, gdy stworzenie j¹ nosz¹ce jest atakowane</param>
	/// <param name="Name">Nazwa</param>
	/// <param name="Symbol">Reprezentacja graficzna</param>
	/// <param name="Armor">Iloœæ punktów pancerza dodawanego nosz¹cemu</param>
	ArmorGameObject(int Value, const EffectGameObject* Effect, string Name, GraphicalSymbol Symbol, int Armor);
	/// <summary>
	/// Metoda tworz¹ca kopiê obiektu.
	/// </summary>
	/// <returns>Kopia obiektu</returns>
	virtual GameObject* clone() const override;
	/// <summary>
	/// Metoda uruchamiana, gdy nosiciel zbroi jest atakowany.
	/// </summary>
	/// <param name="damage">Obra¿enia, które maj¹ byæ zadane.</param>
	/// <param name="self">Obiekt stworzenia nosz¹cego.</param>
	/// <returns>Ostateczna iloœæ obra¿eñ otrzymywanych przez stworzenie.</returns>
	virtual int onDamege(int damage, CreatureGameObject& self) override;

	/// <summary>
	/// Wirtualny destruktor
	/// </summary>
	virtual ~ArmorGameObject();
};
