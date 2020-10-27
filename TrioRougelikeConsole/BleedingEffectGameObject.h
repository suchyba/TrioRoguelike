#pragma once
#include "EffectGameObject.h"

class BleedingEffectGameObject : public EffectGameObject
{
protected:
	/// <summary>
	/// Co ile klatek ma zosta� uruchomiony efekt
	/// </summary>
	int offset;
	/// <summary>
	/// Ilo�� klatek od rozpocz�cia dzia�ania efektu
	/// </summary>
	int frameFromStart = 0;
	/// <summary>
	/// Minimalna ilo�� obra�e� zadawanych przez efekt
	/// </summary>
	int minDamage;
	/// <summary>
	/// Maksymalna ilo�� obra�e� zadawanych przez efekt
	/// </summary>
	int maxDamage;
public:
	/// <summary>
	/// Konstruktor
	/// </summary>
	/// <param name="Offset">Co ile klatek ma zosta� uruchamiany efekt</param>
	/// <param name="Duration">Ile od�wierze� (niekoniecznie klatek) ma trwa� efekt</param>
	/// <param name="MinDamage">Minimalna ilo�� obra�e� zadawanych przez efekt</param>
	/// <param name="MaxDamage">Maksymalna ilo�� obra�e� zadawana przez efekt</param>
	/// <param name="Name">Nazwa efektu</param>
	/// <param name="Symbol">Reprezentacja graficzna efektu</param>
	BleedingEffectGameObject(int Offset, int Duration, int MinDamage, int MaxDamage, string Name, GraphicalSymbol Symbol);
	/// <summary>
	/// Metoda wywo�ywana podczas ka�dego od�wierzenia gry
	/// </summary>
	/// <param name="object">Obiekt, na kt�rym za�o�ony jest efekt</param>
	/// <returns>Czy metoda zmieni�a stan obiektu</returns>
	virtual bool onRefresh(GameObject& object) override;
	/// <summary>
	/// Metoda tworz�ca kopi� obiektu.
	/// </summary>
	/// <returns>Kopia obiektu</returns>
	virtual GameObject* clone() const override;
};
