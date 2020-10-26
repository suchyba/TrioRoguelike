#pragma once
#include "DynamicGameObject.h"
#include "Colliding.h"
#include "EffectGameObject.h"
#include <vector>

using namespace std;

class ItemGameObject;

/// <summary>
/// Klasa dla obiekt�w reprezentuj�cych stworzenia.
/// </summary>
class CreatureGameObject : public DynamicGameObject, public Colliding
{
protected:
	/// <summary>
	/// Obecna liczba punkt�w zdrowia.
	/// </summary>
	int healthPoints;
	/// <summary>
	/// Ca�kowita liczba punkt�w zdrowia.
	/// </summary>
	int baseHealthPoints;
	/// <summary>
	/// Bazowa warto�� pancerza.
	/// </summary>
	int baseArmor;
	/// <summary>
	/// Za�o�ony na stworzenie ekwipunek.
	/// </summary>
	vector<ItemGameObject*> activeInventory;
	/// <summary>
	/// Oznaczenie czy stworzenie �yje.
	/// </summary>
	bool alive = true;
	/// <summary>
	/// Ilo�� punkt�w do�wiadczenia stworzenia.
	/// </summary>
	int experience;
	/// <summary>
	/// Aktywne efekty na�o�one na stworzenie.
	/// </summary>
	vector<EffectGameObject*> activeEffects;
public:
	/// <summary>
	/// Podstawowy konstruktor
	/// </summary>
	/// <param name="hp">Bazowa ilo�� punkt�w zdrowia</param>
	/// <param name="armor">Bazowa ilo�� pancerza</param>
	/// <param name="exp">Ilo�� punkt�w do�wiadczenia</param>
	/// <param name="activeItemsCount">Wielko�� aktywnego ekwipunku</param>
	/// <param name="Name">Nazwa stworzenia</param>
	/// <param name="Symbol">Graficzna reprezentacja stworzenia</param>
	CreatureGameObject(int hp, int armor, int exp, int activeItemsCount, string Name, GraphicalSymbol Symbol);
	/// <summary>
	/// Konstruktor pozwalaj�cy na automatyczne za�o�enie ekwipunku
	/// </summary>
	/// <param name="hp">Bazowa ilo�� punkt�w zdrowia</param>
	/// <param name="armor">Bazowa ilo�� pancerza</param>
	/// <param name="exp">Ilo�� punkt�w do�wiadczenia</param> 
	/// <param name="activeItemsCount">Wielko�� aktywnego ekwipunku</param>
	/// <param name="Name">Nazwa stworzenia</param>
	/// <param name="Symbol">Graficzna reprezentacja stworzenia</param>
	CreatureGameObject(int hp, int armor, int exp, int activeItemsCount, string Name, GraphicalSymbol Symbol, const vector<ItemGameObject*>& itemList);
	/// <summary>
	/// Metoda wywo�ywana podczas ataku.
	/// </summary>
	/// <param name="dmg">Ilo�� obra�e� zadana stworzeniu.</param>
	virtual void onHit(int dmg);
	/// <summary>
	/// Metoda wywo�ywana po �mierci stworzenia
	/// </summary>
	virtual void onDeath();
	/// <summary>
	/// Metoda wywo�ywana bezpo�rednio przed atakiem na inne stworzenie.
	/// </summary>
	/// <param name="opponent">Stworzenie, kt�re atakujemy.</param>
	virtual void onAttack(CreatureGameObject& opponent);
	/// <summary>
	/// Metoda wywo�ywana wa ka�dej klatce gry.
	/// </summary>
	virtual void onRefresh() override;
	/// <summary>
	/// Metoda wywo�ywana, gdy inny obiekt wchodzi w interakcj� z obecnym.
	/// </summary>
	virtual void onInteraction() override;
	/// <summary>
	/// Metoda wywo�ywana podczas kolizji z innym obiektem.
	/// </summary>
	/// <param name="sender">Obiekt, kt�ry wszed� w kolizj�.</param>
	virtual void onCollide(GameObject& sender) override;

	/// <summary>
	/// Metoda dost�powa do pola healthPoints
	/// </summary>
	/// <returns>healthPoints</returns>
	int getHealthPoints() const;
	/// <summary>
	/// Metoda dost�powa do pola baseHealthPoints
	/// </summary>
	/// <returns>baseHealthPoints</returns>
	int getBaseHealthPoints() const;
	/// <summary>
	/// Metoda dost�powa do pola baseArmor
	/// </summary>
	/// <returns>baseArmor</returns>
	int getBaseArmor() const;
	/// <summary>
	/// Metoda zwracaj�ca przedmiot znajduj�cy si� w danym slocie ekwipunku.
	/// </summary>
	/// <param name="slot">Identyfikator pola w ekwipunku, kt�re chcemy sprawdzi�.</param>
	/// <returns>Wska�nik na obiekt przedmiotu znajduj�cego si� w odpowiednim slocie ekwipunku.</returns>
	ItemGameObject* getItemFromSlot(int slot) const;
	/// <summary>
	/// Metoda dost�powa do pola alive.
	/// </summary>
	/// <returns>alive</returns>
	bool isAlive() const;
	/// <summary>
	/// Metoda dost�powa do pola experience.
	/// </summary>
	/// <returns>experience</returns>
	int getExperience() const;

	/// <summary>
	/// Metoda pozwalaj�ca na na�ozenie na stworzenie efektu.
	/// </summary>
	/// <param name="effect">Efekt, kt�ry chcemy za�o�y�</param>
	void addEffect(const EffectGameObject& effect);
	/// <summary>
	/// Metoda pozwalaj�ca na usuni�cie efektu na�o�onego na stworzenie.
	/// </summary>
	/// <param name="Name">Nazwa efektu, kt�ry ma by� usuni�ty</param>
	void removeEffect(string Name);
	/// <summary>
	/// Metoda pr�bujaca za�o�y� ekwipunek do odpowiedniego slotu.
	/// </summary>
	/// <param name="item">Przedmiot, kt�ry ma by� za�o�ony.</param>
	/// <param name="slot">Miejsce w ekwipunku, w kt�re ma zosta� za�o�ony obiekt.</param>
	/// <returns>true - je�li operacja si� powiod�a, w przeciwnym wypadku false</returns>
	bool equipItem(ItemGameObject* item, int slot);
	/// <summary>
	/// Metoda pozwalaj�ca na zadawanie obra�e� stworzeniu z omini�ciem pancerza
	/// </summary>
	/// <param name="dmg">Obra�enia, kt�re maj� zosta� zadane</param>
	void directDmg(int dmg);

	virtual GameObject* clone() const override = 0;

	~CreatureGameObject();
};