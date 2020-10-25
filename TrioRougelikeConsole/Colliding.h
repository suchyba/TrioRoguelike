#pragma once
#include "GameObject.h"

/// <summary>
/// Interfejs dodawany do obiekt�w, przez kt�re gracz i stwory nie mog� przechodzi�.
/// </summary>
class Colliding
{
private:

public:
	/// <summary>
	/// Metoda wywo�ywana w momencie zderzenia stworzenia z obiektem
	/// </summary>
	/// <param name="sender">Obiekt wywo�uj�cy metod� (stworzenie)</param>
	void virtual onCollide(GameObject& sender) = 0;
};