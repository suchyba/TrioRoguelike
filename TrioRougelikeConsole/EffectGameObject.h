#pragma once
#include "DynamicGameObject.h"

/// <summary>
/// Klasa dla obiektów reprezentuj¹cych efekt na³o¿ony na inny obiekt gry.
/// </summary>
class EffectGameObject : public DynamicGameObject
{
private:
	/// <summary>
	/// Prywatna implementacja metody onInteraction by uniemo¿liwiæ jej wywo³anie.
	/// </summary>
	virtual void onInteraction() override;
	/// <summary>
	/// Ukrycie bezparametrowej metody onRefresh().
	/// </summary>
	virtual void onRefresh() override;
protected:
	/// <summary>
	/// D³ugoœæ trwania efektu (w iloœci odœwierzeñ)
	/// </summary>
	int duration;
public:
	EffectGameObject(int Duration, string Name, GraphicalSymbol Symbol);
	/// <summary>
	/// Metoda wywo³ywana w ka¿dej klatce gry (efekt wp³ywa na obiekt)
	/// </summary>
	/// <param name="object">Obiekt, na który wp³ywa efekt</param>
	/// <returns>True - jeœli efekt wp³yn¹³ na obiekt, False - jeœli nie (domyœlnie)</returns>
	virtual bool onRefresh(GameObject& object) override;
	/// <summary>
	/// Metoda tworz¹ca kopiê obiektu.
	/// </summary>
	/// <returns>Kopia obiektu</returns>
	virtual GameObject* clone() const override;
	/// <summary>
	/// Metoda dostêpowa do pola duration
	/// </summary>
	/// <returns>Wartoœæ pola duration</returns>
	int getDuration() const;

	/// <summary>
	/// Wirtualny destruktor
	/// </summary>
	virtual ~EffectGameObject();
};