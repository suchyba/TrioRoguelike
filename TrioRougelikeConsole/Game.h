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
	/// Prywatny konstruktor by uniemo�liwi� tworzenie instancji obiektu.
	/// </summary>
	Game();
	/// <summary>
	/// Prywatny konstruktor kopiuj�cy.
	/// </summary>
	Game(const Game&);
	/// <summary>
	/// Prywatny operator przypisania.
	/// </summary>
	const Game& operator=(const Game&);
	/// <summary>
	/// Wzorcowe stworzenia, kt�re p�niej mo�na umieszcza� na mapie.
	/// </summary>
	static map<string, const CreatureGameObject*> templateCreatureList;
	/// <summary>
	/// Wzorcowe przedmioty, kt�re p�niej mo�na umieszcza� na mapie.
	/// </summary>
	static map<string, const ItemGameObject*> templateItemList;
	/// <summary>
	/// Wzorcowe obiekty sta�e, z kt�rych zbudowana jest mapa.
	/// </summary>
	static map<string, const GameObject*> templateOtherObjectsList;
	/// <summary>
	/// Wzorcowe efekty, kt�re mo�na za�o�y� na stworzenie lub przedmiot.
	/// </summary>
	static map<string, const EffectGameObject*> templateEffectObjectList;
	
	/// <summary>
	/// Lista obeitk�w dynamicznych na mapie (do przeniesienia).
	/// </summary>
	static vector<DynamicGameObject*> dynamicList;
	/// <summary>
	/// Wska�nik na obiekt gracza (do przeniesienia).
	/// </summary>
	static PlayerGameObject* player;

	/// <summary>
	/// G��wna p�tla gry.
	/// </summary>
	static void mainLoop();
	/// <summary>
	/// Metoda przygotowuj�ca gr� do startu.
	/// </summary>
	static void init();
	/// <summary>
	/// Metoda rejstruj�ca obiekty wzorcowe.
	/// </summary>
	static void registerObjects();
	/// <summary>
	/// Metoda wy�wietlaj�ca wiadomo�� w konsoli.
	/// </summary>
	/// <param name="message">Wiadomo�� do wy�wietlenia.</param>
	static void logMessage(string message);
	/// <summary>
	/// Metoda wy�wietlaj�ca komunikat b�edu w konsoli.
	/// </summary>
	/// <param name="message">Tre�� b�edu.</param>
	static void logError(string message);
	/// <summary>
	/// Metoda ko�cz�ca dzia�anie gry.
	/// </summary>
	static void quit();
public:
	/// <summary>
	/// Metoda, uruchamiaj�ca proces dzia�ania gry.
	/// </summary>
	static void start();
	/// <summary>
	/// Metoda, rysuj�ca menu g��wne.
	/// </summary>
	static void menuThread();


};