#pragma once
#include "CreatureGameObject.h"

/// <summary>
/// Klasa przedstawiaj�ca gracza
/// </summary>
class PlayerGameObject final : public CreatureGameObject
{
private:
	/// <summary>
	/// Ekwipunek gracza.
	/// </summary>
	vector<vector<ItemGameObject*>*> inventory;
	/// <summary>
	/// Poziom gracza
	/// </summary>
	int level;
	/// <summary>
	/// Ilo�� punkt�w do�wiadczenia potrzebna do osi�gni�cia nast�pnego poziomu
	/// </summary>
	int experienceToNextLevel;
	/// <summary>
	/// Warto�� atrybutu si�y gracza.
	/// </summary>
	int strength;
	/// <summary>
	/// Warto�� atrybutu si�y magicznej gracza.
	/// </summary>
	int magicPower;
public:
	/// <summary>
	/// Konstruktor
	/// </summary>
	/// <param name="inventoryHeight">Wysoko�� przestrzeni ekwipunku.</param>
	/// <param name="inventoryWidth">Szeroko�� przestrzeni ekwipunku.</param>
	/// <param name="startHp">Pocz�tkowa warto�� punkt�w zdrowia bohatera</param>
	/// <param name="armor">Pocz�tkowa bazowa warto�� punkt�w pancerza</param>
	/// <param name="activeInventorySize">Ilo�� ekwipunku, kt�ry mo�e za�o�y� bohater</param>
	/// <param name="experienceToSecondLvl">Ilo�� punkt�w do�wiadczenia potrzebna do osi�gni�cia nast�pnego poziomu</param>
	/// <param name="startStrength">Pocz�tkowa warto�� punkt�w si�y</param>
	/// <param name="startArmor">Pocz�tkowa warto�� bazowej warto�ci pancerza bohatera</param>
	/// <param name="startMagicPow">Pocz�tkowa warto�� si�y magicznej bohatera</param>
	/// <param name="Name">Nazwa gracza</param>
	/// <param name="Symbol">Graficzna reprezentacja gracza</param>
	PlayerGameObject(int inventoryHeight, int inventoryWidth, int startHp, int activeInventorySize, int experienceToSecondLvl, int startStrength, int startArmor, 
		int startMagicPow, string Name, GraphicalSymbol Symbol);

	/// <summary>
	/// Metoda tworz�ca kopi� obiektu.
	/// </summary>
	/// <returns>Kopia obiektu</returns>
	virtual GameObject* clone() const override;
	
	
	int getLevel() const;

	/// <summary>
	/// Metoda tworz�ca kopi� obiektu.
	/// </summary>
	/// <returns>Kopia obiektu</returns>
	virtual GameObject* clone() const override;
	
	/// <summary>
	/// Destruktor
	/// </summary>
	~PlayerGameObject();

	void addExp(int exp);
};