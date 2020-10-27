#pragma once
#include "DynamicGameObject.h"

/// <summary>
/// Klasa dla obiekt�w reprezentuj�cych efekt na�o�ony na inny obiekt gry.
/// </summary>
class EffectGameObject : public DynamicGameObject
{
private:
	/// <summary>
	/// Prywatna implementacja metody onInteraction by uniemo�liwi� jej wywo�anie.
	/// </summary>
	virtual void onInteraction() override;
	/// <summary>
	/// Ukrycie bezparametrowej metody onRefresh().
	/// </summary>
	virtual void onRefresh() override;
protected:
	/// <summary>
	/// D�ugo�� trwania efektu (w ilo�ci od�wierze�)
	/// </summary>
	int duration;
public:
	EffectGameObject(int Duration, string Name, GraphicalSymbol Symbol);
	/// <summary>
	/// Metoda wywo�ywana w ka�dej klatce gry (efekt wp�ywa na obiekt)
	/// </summary>
	/// <param name="object">Obiekt, na kt�ry wp�ywa efekt</param>
	/// <returns>True - je�li efekt wp�yn�� na obiekt, False - je�li nie (domy�lnie)</returns>
	virtual bool onRefresh(GameObject& object) override;
	/// <summary>
	/// Metoda tworz�ca kopi� obiektu.
	/// </summary>
	/// <returns>Kopia obiektu</returns>
	virtual GameObject* clone() const override;
	/// <summary>
	/// Metoda dost�powa do pola duration
	/// </summary>
	/// <returns>Warto�� pola duration</returns>
	int getDuration() const;

	/// <summary>
	/// Wirtualny destruktor
	/// </summary>
	virtual ~EffectGameObject();
};