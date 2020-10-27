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
	/// Ile klatek minê³o od uruchomienia efektu
	/// </summary>
	int frameFromStart = 0;
	/// <summary>
	/// Iloœæ zdrowia przywracanego w ka¿dym odœwie¿eniu
	/// </summary>
	int regeneratedHP;
public:
	/// <summary>
	/// Konstruktor
	/// </summary>
	/// <param name="Offset">Co ile klatek uruchamiany jest efekt</param>
	/// <param name="Duration">D³ugoœæ trwania efektu (w odœwierzeniach, niekoniecznie jest to iloœæ klatek)</param>
	/// <param name="RegeneredHP">Iloœæ zdrowia przywracanego w ka¿dym odœwie¿eniu</param>
	/// <param name="Name">Nazwa efektu</param>
	/// <param name="Symbol">Reprezentacja graficzna efektu</param>
	RegenerationEffectGameObject(int Offset, int Duration, int RegeneredHP, string Name, GraphicalSymbol Symbol);
	/// <summary>
	/// Metoda wywo³ywana podczas ka¿dego odœwie¿enia gry
	/// </summary>
	/// <param name="object">Obiekt na którym umieszczony jest efekt</param>
	/// <returns>Czy efekt wp³yn¹³ na obiekt</returns>
	virtual bool onRefresh(GameObject& object) override;
	/// <summary>
	/// Metoda tworz¹ca kopiê obiektu.
	/// </summary>
	/// <returns>Kopia obiektu</returns>
	virtual GameObject* clone() const override;
};