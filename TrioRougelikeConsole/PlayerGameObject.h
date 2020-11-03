#pragma once
#include "CreatureGameObject.h"

/// <summary>
/// Klasa przedstawiaj¹ca gracza
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
	/// Iloœæ punktów doœwiadczenia potrzebna do osi¹gniêcia nastêpnego poziomu
	/// </summary>
	int experienceToNextLevel;
	/// <summary>
	/// Wartoœæ atrybutu si³y gracza.
	/// </summary>
	int strength;
	/// <summary>
	/// Wartoœæ atrybutu si³y magicznej gracza.
	/// </summary>
	int magicPower;
public:
	/// <summary>
	/// Konstruktor
	/// </summary>
	/// <param name="inventoryHeight">Wysokoœæ przestrzeni ekwipunku.</param>
	/// <param name="inventoryWidth">Szerokoœæ przestrzeni ekwipunku.</param>
	/// <param name="startHp">Pocz¹tkowa wartoœæ punktów zdrowia bohatera</param>
	/// <param name="armor">Pocz¹tkowa bazowa wartoœæ punktów pancerza</param>
	/// <param name="activeInventorySize">Iloœæ ekwipunku, który mo¿e za³o¿yæ bohater</param>
	/// <param name="experienceToSecondLvl">Iloœæ punktów doœwiadczenia potrzebna do osi¹gniêcia nastêpnego poziomu</param>
	/// <param name="startStrength">Pocz¹tkowa wartoœæ punktów si³y</param>
	/// <param name="startArmor">Pocz¹tkowa wartoœæ bazowej wartoœci pancerza bohatera</param>
	/// <param name="startMagicPow">Pocz¹tkowa wartoœæ si³y magicznej bohatera</param>
	/// <param name="Name">Nazwa gracza</param>
	/// <param name="Symbol">Graficzna reprezentacja gracza</param>
	PlayerGameObject(int inventoryHeight, int inventoryWidth, int startHp, int activeInventorySize, int experienceToSecondLvl, int startStrength, int startArmor, 
		int startMagicPow, string Name, GraphicalSymbol Symbol);

	/// <summary>
	/// Metoda tworz¹ca kopiê obiektu.
	/// </summary>
	/// <returns>Kopia obiektu</returns>
	virtual GameObject* clone() const override;
	
	
	int getLevel() const;

	/// <summary>
	/// Metoda tworz¹ca kopiê obiektu.
	/// </summary>
	/// <returns>Kopia obiektu</returns>
	virtual GameObject* clone() const override;
	
	/// <summary>
	/// Destruktor
	/// </summary>
	~PlayerGameObject();

	void addExp(int exp);
};