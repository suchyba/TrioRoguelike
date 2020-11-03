#pragma once
#include <map>
#include "CreatureGameObject.h"
#include "ItemGameObject.h"
#include "PlayerGameObject.h"
#include "GameObject.h"
#include "EffectGameObject.h"
#include "Map.h"


using namespace std;

class Game final
{
private:
	/// <summary>
	/// Wskaźnik na obecną mapę
	/// </summary>
	static Map* gameMap;

	static bool nextLevel;

	static bool gameOver;

	/// <summary>
	/// Prywatny konstruktor by uniemożliwić tworzenie instancji obiektu.
	/// </summary>
	Game();
	/// <summary>
	/// Prywatny konstruktor kopiujący.
	/// </summary>
	Game(const Game&);
	/// <summary>
	/// Prywatny operator przypisania.
	/// </summary>
	const Game& operator=(const Game&);
	/// <summary>
	/// Wzorcowe stworzenia, które później można umieszczać na mapie.
	/// </summary>
	static map<string, const CreatureGameObject*> templateCreatureList;
	/// <summary>
	/// Wzorcowe przedmioty, które później można umieszczać na mapie.
	/// </summary>
	static map<string, const ItemGameObject*> templateItemList;
	/// <summary>
	/// Wzorcowe obiekty stałe, z których zbudowana jest mapa.
	/// </summary>
	static map<string, const GameObject*> templateOtherObjectsList;
	/// <summary>
	/// Wzorcowe efekty, które można założyć na stworzenie lub przedmiot.
	/// </summary>
	static map<string, const EffectGameObject*> templateEffectObjectList;
	/// <summary>
	/// Lista obeitków dynamicznych na mapie (do przeniesienia).
	/// </summary>
	static vector<DynamicGameObject*> dynamicList;
	/// <summary>
	/// Wskaźnik na obiekt gracza.
	/// </summary>
	static PlayerGameObject* player;*/

	/// <summary>
	/// Główna pętla gry.
	/// </summary>
	static void mainLoop();
	/// <summary>
	/// Metoda przygotowująca grę do startu.
	/// </summary>
	static void init();
	static void mainMenu();
	/// <summary>
	/// Metoda rejstrująca obiekty wzorcowe.
	/// </summary>
	static void registerObjects();
	/// <summary>
	/// Metoda wyświetlająca wiadomość w konsoli.
	/// </summary>
	/// <param name="message">Wiadomość do wyświetlenia.</param>
	static void logMessage(string message);
	/// <summary>
	/// Metoda wyświetlająca komunikat błedu w konsoli.
	/// </summary>
	/// <param name="message">Treść błedu.</param>
	static void logError(string message);
	/// <summary>
	/// Metoda kończąca działanie gry.
	/// </summary>
	static void quit();
public:
	/// <summary>
	/// Metoda, uruchamiająca proces działania gry.
	/// </summary>
	static void start();
	static Map* getMap();
	static void nextMap();
	static void GameOver();
	/// <summary>
	/// Metoda, rysująca menu główne.
	/// </summary>
	static void menuThread();
};