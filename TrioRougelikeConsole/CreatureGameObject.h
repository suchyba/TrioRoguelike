#pragma once
#include "DynamicGameObject.h"
#include "Colliding.h"
#include "EffectGameObject.h"
#include <vector>

using namespace std;

class ItemGameObject;

/// <summary>
/// Klasa dla obiektów reprezentuj¹cych stworzenia.
/// </summary>
class CreatureGameObject : public DynamicGameObject, public Colliding
{
protected:
	/// <summary>
	/// Obecna liczba punktów zdrowia.
	/// </summary>
	int healthPoints;
	/// <summary>
	/// Ca³kowita liczba punktów zdrowia.
	/// </summary>
	int baseHealthPoints;
	/// <summary>
	/// Bazowa wartoœæ pancerza.
	/// </summary>
	int baseArmor;
	/// <summary>
	/// Za³o¿ony na stworzenie ekwipunek.
	/// </summary>
	vector<ItemGameObject*> activeInventory;
	/// <summary>
	/// Oznaczenie czy stworzenie ¿yje.
	/// </summary>
	bool alive = true;
	/// <summary>
	/// Iloœæ punktów doœwiadczenia stworzenia.
	/// </summary>
	int experience;
	/// <summary>
	/// Aktywne efekty na³o¿one na stworzenie.
	/// </summary>
	vector<EffectGameObject*> activeEffects;
public:
	/// <summary>
	/// Podstawowy konstruktor
	/// </summary>
	/// <param name="hp">Bazowa iloœæ punktów zdrowia</param>
	/// <param name="armor">Bazowa iloœæ pancerza</param>
	/// <param name="exp">Iloœæ punktów doœwiadczenia</param>
	/// <param name="activeItemsCount">Wielkoœæ aktywnego ekwipunku</param>
	/// <param name="Name">Nazwa stworzenia</param>
	/// <param name="Symbol">Graficzna reprezentacja stworzenia</param>
	CreatureGameObject(int hp, int armor, int exp, int activeItemsCount, string Name, GraphicalSymbol Symbol);
	/// <summary>
	/// Konstruktor pozwalaj¹cy na automatyczne za³o¿enie ekwipunku
	/// </summary>
	/// <param name="hp">Bazowa iloœæ punktów zdrowia</param>
	/// <param name="armor">Bazowa iloœæ pancerza</param>
	/// <param name="exp">Iloœæ punktów doœwiadczenia</param> 
	/// <param name="activeItemsCount">Wielkoœæ aktywnego ekwipunku</param>
	/// <param name="Name">Nazwa stworzenia</param>
	/// <param name="Symbol">Graficzna reprezentacja stworzenia</param>
	CreatureGameObject(int hp, int armor, int exp, int activeItemsCount, string Name, GraphicalSymbol Symbol, const vector<ItemGameObject*>& itemList);
	/// <summary>
	/// Metoda wywo³ywana podczas ataku.
	/// </summary>
	/// <param name="dmg">Iloœæ obra¿eñ zadana stworzeniu.</param>
	virtual void onHit(int dmg);
	/// <summary>
	/// Metoda wywo³ywana po œmierci stworzenia
	/// </summary>
	virtual void onDeath();
	/// <summary>
	/// Metoda wywo³ywana bezpoœrednio przed atakiem na inne stworzenie.
	/// </summary>
	/// <param name="opponent">Stworzenie, które atakujemy.</param>
	virtual void onAttack(CreatureGameObject& opponent);
	/// <summary>
	/// Metoda wywo³ywana wa ka¿dej klatce gry.
	/// </summary>
	virtual void onRefresh() override;
	/// <summary>
	/// Metoda wywo³ywana, gdy inny obiekt wchodzi w interakcjê z obecnym.
	/// </summary>
	virtual void onInteraction() override;
	/// <summary>
	/// Metoda wywo³ywana podczas kolizji z innym obiektem.
	/// </summary>
	/// <param name="sender">Obiekt, który wszed³ w kolizjê.</param>
	virtual void onCollide(GameObject& sender) override;

	/// <summary>
	/// Metoda dostêpowa do pola healthPoints
	/// </summary>
	/// <returns>healthPoints</returns>
	int getHealthPoints() const;
	/// <summary>
	/// Metoda dostêpowa do pola baseHealthPoints
	/// </summary>
	/// <returns>baseHealthPoints</returns>
	int getBaseHealthPoints() const;
	/// <summary>
	/// Metoda dostêpowa do pola baseArmor
	/// </summary>
	/// <returns>baseArmor</returns>
	int getBaseArmor() const;
	/// <summary>
	/// Metoda zwracaj¹ca przedmiot znajduj¹cy siê w danym slocie ekwipunku.
	/// </summary>
	/// <param name="slot">Identyfikator pola w ekwipunku, które chcemy sprawdziæ.</param>
	/// <returns>Wska¿nik na obiekt przedmiotu znajduj¹cego siê w odpowiednim slocie ekwipunku.</returns>
	ItemGameObject* getItemFromSlot(int slot) const;
	/// <summary>
	/// Metoda dostêpowa do pola alive.
	/// </summary>
	/// <returns>alive</returns>
	bool isAlive() const;
	/// <summary>
	/// Metoda dostêpowa do pola experience.
	/// </summary>
	/// <returns>experience</returns>
	int getExperience() const;

	/// <summary>
	/// Metoda pozwalaj¹ca na na³ozenie na stworzenie efektu.
	/// </summary>
	/// <param name="effect">Efekt, który chcemy za³o¿yæ</param>
	void addEffect(const EffectGameObject& effect);
	/// <summary>
	/// Metoda pozwalaj¹ca na usuniêcie efektu na³o¿onego na stworzenie.
	/// </summary>
	/// <param name="Name">Nazwa efektu, który ma byæ usuniêty</param>
	void removeEffect(string Name);
	/// <summary>
	/// Metoda próbujaca za³o¿yæ ekwipunek do odpowiedniego slotu.
	/// </summary>
	/// <param name="item">Przedmiot, który ma byæ za³o¿ony.</param>
	/// <param name="slot">Miejsce w ekwipunku, w które ma zostaæ za³o¿ony obiekt.</param>
	/// <returns>true - jeœli operacja siê powiod³a, w przeciwnym wypadku false</returns>
	bool equipItem(ItemGameObject* item, int slot);
	/// <summary>
	/// Metoda pozwalaj¹ca na zadawanie obra¿eñ stworzeniu z ominiêciem pancerza
	/// </summary>
	/// <param name="dmg">Obra¿enia, które maj¹ zostaæ zadane</param>
	void directDmg(int dmg);

	virtual GameObject* clone() const override = 0;

	~CreatureGameObject();
};