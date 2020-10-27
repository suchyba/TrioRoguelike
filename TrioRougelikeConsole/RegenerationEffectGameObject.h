#pragma once
#include "EffectGameObject.h"

class RegenerationEffectGameObject : public EffectGameObject
{
protected:
	/// <summary>
	/// Co ile klatek uruchamiany jest efekt
	/// </summary>
	int offset;
	/// <summary>
	/// Ile klatek min�o od uruchomienia efektu
	/// </summary>
	int frameFromStart = 0;
	/// <summary>
	/// Ilo�� zdrowia przywracanego w ka�dym od�wie�eniu
	/// </summary>
	int regeneratedHP;
public:
	/// <summary>
	/// Konstruktor
	/// </summary>
	/// <param name="Offset">Co ile klatek uruchamiany jest efekt</param>
	/// <param name="Duration">D�ugo�� trwania efektu (w od�wierzeniach, niekoniecznie jest to ilo�� klatek)</param>
	/// <param name="RegeneredHP">Ilo�� zdrowia przywracanego w ka�dym od�wie�eniu</param>
	/// <param name="Name">Nazwa efektu</param>
	/// <param name="Symbol">Reprezentacja graficzna efektu</param>
	RegenerationEffectGameObject(int Offset, int Duration, int RegeneredHP, string Name, GraphicalSymbol Symbol);
	/// <summary>
	/// Metoda wywo�ywana podczas ka�dego od�wie�enia gry
	/// </summary>
	/// <param name="object">Obiekt na kt�rym umieszczony jest efekt</param>
	/// <returns>Czy efekt wp�yn�� na obiekt</returns>
	virtual bool onRefresh(GameObject& object) override;
	/// <summary>
	/// Metoda tworz�ca kopi� obiektu.
	/// </summary>
	/// <returns>Kopia obiektu</returns>
	virtual GameObject* clone() const override;
};