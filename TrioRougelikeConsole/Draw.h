#pragma once
#include "PlayerGameObject.h"
/// <summary>
/// Funkcja odpowiedzialna za rysowanie menu
/// </summary>
int drawMenu();
/// <summary>
/// Funkcja odpowiedzialna za Wypisanie autorów
/// </summary>
void showAuthors();
/// <summary>
/// Funkcja odpowiedzialna za Instrukcji Gry
/// </summary>
void showInstructions();
/// <summary>
/// Funkcja odpowiedzialna za statystyki gracza
/// </summary>
void drawStats(PlayerGameObject* player);
