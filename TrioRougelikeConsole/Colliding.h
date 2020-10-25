#pragma once
#include "GameObject.h"

/// <summary>
/// Interfejs dodawany do obiektów, przez które gracz i stwory nie mog¹ przechodziæ.
/// </summary>
class Colliding
{
private:

public:
	/// <summary>
	/// Metoda wywo³ywana w momencie zderzenia stworzenia z obiektem
	/// </summary>
	/// <param name="sender">Obiekt wywo³uj¹cy metodê (stworzenie)</param>
	void virtual onCollide(GameObject& sender) = 0;
};