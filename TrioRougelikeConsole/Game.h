#pragma once
#include <map>
#include "CreatureGameObject.h"
#include "ItemGameObject.h"
#include "PlayerGameObject.h"
#include "GameObject.h"
#include "EffectGameObject.h"


using namespace std;

class Game final
{
private:
	/// <summary>
	/// Prywatny konstruktor by uniemo¿liwiæ tworzenie instancji obiektu.
	/// </summary>
	Game();
	/// <summary>
	/// Prywatny konstruktor kopiuj¹cy.
	/// </summary>
	Game(const Game&);
	/// <summary>
	/// Prywatny operator przypisania.
	/// </summary>
	const Game& operator=(const Game&);
	/// <summary>
	/// Wzorcowe stworzenia, które póŸniej mo¿na umieszczaæ na mapie.
	/// </summary>
	static map<string, const CreatureGameObject*> templateCreatureList;
	/// <summary>
	/// Wzorcowe przedmioty, które póŸniej mo¿na umieszczaæ na mapie.
	/// </summary>
	static map<string, const ItemGameObject*> templateItemList;
	/// <summary>
	/// Wzorcowe obiekty sta³e, z których zbudowana jest mapa.
	/// </summary>
	static map<string, const GameObject*> templateOtherObjectsList;
	/// <summary>
	/// Wzorcowe efekty, które mo¿na za³o¿yæ na stworzenie lub przedmiot.
	/// </summary>
	static map<string, const EffectGameObject*> templateEffectObjectList;
	
	/// <summary>
	/// Lista obeitków dynamicznych na mapie (do przeniesienia).
	/// </summary>
	static vector<DynamicGameObject*> dynamicList;
	/// <summary>
	/// WskaŸnik na obiekt gracza (do przeniesienia).
	/// </summary>
	static PlayerGameObject* player;

	/// <summary>
	/// G³ówna pêtla gry.
	/// </summary>
	static void mainLoop();
	/// <summary>
	/// Metoda przygotowuj¹ca grê do startu.
	/// </summary>
	static void init();
	/// <summary>
	/// Metoda rejstruj¹ca obiekty wzorcowe.
	/// </summary>
	static void registerObjects();
	/// <summary>
	/// Metoda wyœwietlaj¹ca wiadomoœæ w konsoli.
	/// </summary>
	/// <param name="message">Wiadomoœæ do wyœwietlenia.</param>
	static void logMessage(string message);
	/// <summary>
	/// Metoda wyœwietlaj¹ca komunikat b³edu w konsoli.
	/// </summary>
	/// <param name="message">Treœæ b³edu.</param>
	static void logError(string message);
	/// <summary>
	/// Metoda koñcz¹ca dzia³anie gry.
	/// </summary>
	static void quit();
public:
	/// <summary>
	/// Metoda, uruchamiaj¹ca proces dzia³ania gry.
	/// </summary>
	static void start();
	/// <summary>
	/// Metoda, rysuj¹ca menu g³ówne.
	/// </summary>
	static void menuThread();


};