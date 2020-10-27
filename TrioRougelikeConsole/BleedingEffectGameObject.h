#pragma once
#include "EffectGameObject.h"

class BleedingEffectGameObject : public EffectGameObject
{
protected:
	/// <summary>
	/// Co ile klatek ma zostaæ uruchomiony efekt
	/// </summary>
	int offset;
	/// <summary>
	/// Iloœæ klatek od rozpoczêcia dzia³ania efektu
	/// </summary>
	int frameFromStart = 0;
	/// <summary>
	/// Minimalna iloœæ obra¿eñ zadawanych przez efekt
	/// </summary>
	int minDamage;
	/// <summary>
	/// Maksymalna iloœæ obra¿eñ zadawanych przez efekt
	/// </summary>
	int maxDamage;
public:
	/// <summary>
	/// Konstruktor
	/// </summary>
	/// <param name="Offset">Co ile klatek ma zostaæ uruchamiany efekt</param>
	/// <param name="Duration">Ile odœwierzeñ (niekoniecznie klatek) ma trwaæ efekt</param>
	/// <param name="MinDamage">Minimalna iloœæ obra¿eñ zadawanych przez efekt</param>
	/// <param name="MaxDamage">Maksymalna iloœæ obra¿eñ zadawana przez efekt</param>
	/// <param name="Name">Nazwa efektu</param>
	/// <param name="Symbol">Reprezentacja graficzna efektu</param>
	BleedingEffectGameObject(int Offset, int Duration, int MinDamage, int MaxDamage, string Name, GraphicalSymbol Symbol);
	/// <summary>
	/// Metoda wywo³ywana podczas ka¿dego odœwierzenia gry
	/// </summary>
	/// <param name="object">Obiekt, na którym za³o¿ony jest efekt</param>
	/// <returns>Czy metoda zmieni³a stan obiektu</returns>
	virtual bool onRefresh(GameObject& object) override;
	/// <summary>
	/// Metoda tworz¹ca kopiê obiektu.
	/// </summary>
	/// <returns>Kopia obiektu</returns>
	virtual GameObject* clone() const override;
};
