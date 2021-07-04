#ifndef FUNKCJE_H
#define FUNCKJE_H

#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>

#include "Struktury.h"

/** Funkcja neguje podan� warto��. W przypadku podania 0 funkcja zwraca 1, w innym przypadku funkcja zwraca 0.
@param wartosc warto�� do zanegowania */
int zaneguj(int wartosc);

/** Funkcja sprawdza czy podane znaki w tabeli s� r�wne odpowieniemu kluczowi, tj. (du�ymi lub ma�ymi literami) je�li wiersz = 1 "IN:", je�li wiersz = 2 "OUT:", je�li wiersz > 2 "OR ", "AND ", "NOR ", "XOR ", "NEG ", "NAND ", "XNOR ". Funkcja zwraca 0 w przypadku niepowodzenia. W przypadku zgodno�ci znak�w z kluczem zwraca 1 je�li znaki by�y r�wne "IN:", 2 je�li "OR ", 3 je�li "OUT:", 4 je�li "AND ", 5 je�li "NOR ", 6 je�li "NEG ", 7 je�li "NAND ", 8 je�li "XNOR ".
@param tabela tabela zawieraj�ca 3, 4 lub 5 znak�w
@param wiersz wiersz pliku wej�ciowego */
int sprawdzPoprawnosc(char* tabela, int wiersz);

/** Funkcja dodaje nowy element do listy jednokierunkowej zawieraj�cej bramki logiczne uk�adu. Funkcja zwraca 2 w przypadku powodzenia lub 1 je�li nie uda si� przydzieli� pami�ci.
@param glowa g�owa listy jednokierunkowej bramek logicznych uk�adu
@param typ typ dodawanej bramki
@param w1 numer pierwszego w�z�a wej�cia dodawanej bramki
@param w2 numer drugiego w�z�a wej�cia dodawanej bramki (nieistotne w przypadku bramki typu neg)
@param wy numer w�z�a wyj�ciowego dodawanej bramki */
int dodajNaKoniecListy(struct lista** glowa, bramka typ, int w1, int w2, int wy);

/** Funkcja sprawdza czy podana bramka istnieje ju� w li�cie bramek logicznych. Funkcja zwraca 0 je�li bramka znajduje si� ju� w li�cie lub 1 je�li si� nie znajduje.
@param glowa g�owa listy jednokierunkowej bramek logicznych uk�adu
@param typ typ sprawdzanej bramki
@param w1 numer pierwszego w�z�a wej�cia sprawdzanej bramki
@param w2 numer drugiego w�z�a wej�cia sprawdzanej bramki (nieistotne w przypadku bramki typu neg)
@param wy numer w�z�a wyj�ciowego sprawdzanej bramki */
int sprawdzCzyBramkaJuzJest(struct lista* glowa, bramka typ, int w1, int w2, int wy);

/** Funkcja dodaje nowy element do listy jednokierunkowej zawieraj�cej informacje o stanach wej�� uk�adu i taktach ich trwania. Funkcja zwraca 2 w przypadku powodzenia lub 1 je�li nie uda si� przydzieli� pami�ci.
@param glowa g�owa listy jednokierunkowej wymusze�
@param tab tabela z informacjami o stanach wej�� uk�adu
@param takty ilo�� takt�w dla poszczeg�lnych stan�w wej�� uk�adu
@param wejscia ilo�� wej�� uk�adu */
int dodajNaKoniecListyWymuszen(struct wymuszenia** glowa, int** tab, int takty, int wejscia);

/** Funkcja wczytuje z pliku informacje o wej�ciach i wyj�ciach uk�adu oraz bramkach logicznych. Funkcja zwraca 0 je�li nie uda�o si� otworzy� pliku, -1 je�li nie uda�o si� przydzieli� pami�ci, -2 je�li kt�ry� z w�z��w bramki jest mniejszy od 1, -3 je�li plik jest pusty, liczb� wi�ksz� od zera b�d�c� wierszem w kt�rym znajduje si� b��dny zapis lub -4 w przypadku powodzenia.
@param nazwaPliku nazwa pliku wej�ciowego
@param glowa g�owa listy jednokierunkowej bramek logicznych uk�adu
@param inTab tabela zawieraj�ca informacje o numerach w�z��w b�d�cych wej�ciami uk�adu
@param outTab tabela zawieraj�ca informacje o numerach w�z��w b�d�cych wyj�ciami uk�adu
@param wejscia ilo�� wej�� uk�adu
@param wyjscia ilo�� wyj�� uk�adu */
int wczytajZPliku1(char* nazwaPliku, struct lista** glowa, int** inTab, int** outTab, int* wejscia, int* wyjscia);

/** Funkcja wczytuje z pliku wymusze� informacje o stanach wej�� uk�adu oraz taktach ich trwania. Funkcja zwraca 0 je�li nie uda�o si� otworzy� pliku, -1 je�li nie uda�o si� przydzieli� pami�ci, -2 je�li plik jest pusty, liczb� wi�ksz� od zera b�d�c� wierszem w kt�rym znajduje si� b��dny zapis lub -3 w przypadku powodzenia.
@param nazwaPliku nazwa pliku wej�ciowego wymusze�
@param wejscia ilo�� wej�� uk�adu
@param inTab tabela zawieraj�ca informacje o numerach w�z��w b�d�cych wej�ciami uk�adu
@param glowaW g�owa listy jednokierunkowej wymusze� */
int wczytajZPliku2(char* nazwaPliku, int wejscia, int* inTab, struct wymuszenia** glowaW);

/** Funkcja przypisuje iteracyjnie poprzednim stanom bramek ich aktualn� warto��.
@param glowa g�owa listy jednokierunkowej bramek logicznych uk�adu */
void wyrownajStanyBramek(struct lista* glowa);

/** Funkcja zwraca poprzedni stan bramki o podanym w�le wyj��iowym je�li wyb�r = 1, w innym wypadku zwraca aktualny stan bramki o podanym w�le wyj�ciowym lub 2 je�li bramka o danym w�le wyj�ciowym nie istnieje.
@param glowa g�owa listy jednokierunkowej bramek logicznych uk�adu
@param glowaW g�owa listy jednokierunkowej wymusze�
@param inTab tabela zawieraj�ca informacje o numerach w�z��w b�d�cych wej�ciami uk�adu
@param wejscia ilo�� wej�� uk�adu
@param wezel w�ze� wyj�ciowy szukanej bramki logicznej
@param wybor zmienna decyduj�ca czy zwr�cony zostanie poprzedni czy aktualny stan bramki */
int znajdzStanBramki(struct lista* glowa, struct wymuszenia* glowaW, int* inTab, int wejscia, int wezel, int wybor);

/** Funkcja wykonuje rekurencyjnie operacje na bramkach logicznych.
@param glowa g�owa listy jednokierunkowej bramek logicznych uk�adu
@param glowa2 g�owa listy jednokierunkowej bramek logicznych uk�adu
@param glowaW g�owa listy jednokierunkowej wymusze�
@param inTab tabela zawieraj�ca informacje o numerach w�z��w b�d�cych wej�ciami uk�adu
@param wejscia ilo�� wej�� uk�adu */
void wykonajOperacjeNaBramkach(struct lista** glowa, struct lista* glowa2, struct wymuszenia* glowaW, int* inTab, int wejscia);

/** Funkcja zwraca numer w�z�a wej�ciowego kt�ry si� powtarza lub 0 w przypadku braku takiego w�z�a.
@param inTab tabela zawieraj�ca informacje o numerach w�z��w b�d�cych wej�ciami uk�adu
@param wejscia ilo�� wej�� uk�adu */
int znajdzNiepoprawnyWezelWejsciowy(int* inTab, int wejscia);

/** Funkcja zwraca numer w�z�a wyj�ciowego kt�ry si� powtarza lub 0 w przypadku braku takiego w�z�a.
@param outTab tabela zawieraj�ca informacje o numerach w�z��w b�d�cych wyj�ciami uk�adu
@param wyjscia ilo�� wyj�� uk�adu */
int znajdzNiepoprawnyWezelWyjsciowy(int* outTab, int wyjscia);

/** Funkcja zwraca ilo�� w�z��w wej�ciowych, wyj�ciowych i wszystkich bramek.
@param wejscia ilo�� wej�� uk�adu
@param wyjscia ilo�� wyj�� uk�adu
@param glowa g�owa listy jednokierunkowej bramek logicznych uk�adu */
int policzWezly(int wejscia, int wyjscia, struct lista* glowa);

/** Funkcja sprawdza czy w uk�adzie nie brakuje kt�rego� z numer�w w�z��w. Funkcja zwraca numer brakuj�cego w�z�a, 0 w przypadku niepowodzenia przydzialania pami�ci lub -1 w przypadku braku takiego w�z�a.
@param glowa g�owa listy jednokierunkowej bramek logicznych uk�adu
@param inTab tabela zawieraj�ca informacje o numerach w�z��w b�d�cych wej�ciami uk�adu
@param outTab tabela zawieraj�ca informacje o numerach w�z��w b�d�cych wyj�ciami uk�adu
@param wejscia ilo�� wej�� uk�adu
@param wyjscia ilo�� wyj�� uk�adu */
int sprawdzPoprawnoscWezlow(struct lista* glowa, int* inTab, int* outTab, int wejscia, int wyjscia);

/** Funkcja zwraca ilo�� w�z��w wyj�ciowych uk�adu i wszystkich bramek.
@param glowa g�owa listy jednokierunkowej bramek logicznych uk�adu
@param wyjscia ilo�� wyj�� uk�adu */
int policzWezlyWyjsciowe(struct lista* glowa, int wejscia);

/** Funkcja zwraca numer powtarzaj�cego si� w�z�a wyj�ciowego bramek, 0 w przypadku niepowodzenia przydzialania pami�ci lub -1 w przypadku braku takiego w�z�a.
@param glowa g�owa listy jednokierunkowej bramek logicznych uk�adu
@param wyjscia ilo�� wyj�� uk�adu */
int znajdzNiepoprawnyWezelWyjsciowyBramek(struct lista* glowa, int wyjscia);

/** Funkcja sprawdza czy w�z�y wej�ciowe uk�adu nie s� wyj�ciami bramek logicznych. Funkcja zwraca 1 je�li s� lub 2 je�li nie s�
@param glowa g�owa listy jednokierunkowej bramek logicznych uk�adu
@param inTab tabela zawieraj�ca informacje o numerach w�z��w b�d�cych wej�ciami uk�adu
@param wejscia ilo�� wej�� uk�adu */
int sprawdzPoprawnoscWezlowWe(struct lista* glowa, int* inTab, int wejscia);

/** Funkcja sprawdza czy w�z�y wyj�ciowe uk�adu pokrywaj� si� z wyj�ciami bramek logicznych. Funkcja zwraca 1 w przypadku nie pokrywania si� wyj�� lub 2 w przypadku pokrywania si� wyj��
@param glowa g�owa listy jednokierunkowej bramek logicznych uk�adu
@param outTab tabela zawieraj�ca informacje o numerach w�z��w b�d�cych wyj�ciami uk�adu
@param wyjscia ilo�� wyj�� uk�adu */
int sprawdzPoprawnoscWezlowWy(struct lista* glowa, int* outTab, int wyjscia);

/** Funkcja zapisuje do pliku wyj�ciowego  warto�ci wyj�� w kolejnych taktach. Funkcja zwraca 0 je�li nie uda�o si� utworzy� pliku o podanej nazwie, 1 je�li nie uda�o si� przydzieli� pami�ci, 2 je�li w ukladzie wystepuja dwa wezly wejsciowe o tym samym numerze, 3 je�li w ukladzie wystepuja dwa wezly wyjsciowe o tym samym numerze, 4 je�li w uk�adzie brakuje w�z�a o jakim� numerze, 5 je�li w ukladzie wystepuje dwa wezly wyjsciowe bramek o tym samym numerze, 6 je�li w ukladzie wezly wyjsciowe nie pokrywaja sie z wezlami wyjsciowymi bramek, 7 je�li w�ze� wej�ciowy jest wyj�ciem bramki lub 8 w przypadku powodzenia
@param nazwaPliku nazwa pliku wyj�ciowego
@param glowa g�owa listy jednokierunkowej bramek logicznych uk�adu
@param glowaW g�owa listy jednokierunkowej wymusze�
@param inTab tabela zawieraj�ca informacje o numerach w�z��w b�d�cych wej�ciami uk�adu
@param outTab tabela zawieraj�ca informacje o numerach w�z��w b�d�cych wyj�ciami uk�adu
@param wejscia ilo�� wej�� uk�adu
@param wyjscia ilo�� wyj�� uk�adu
@param wezel zmienna oznaczaj�ca brakuj�cy lub powtarzaj�cy si� numer w�z�a */
int zapiszDoPliku(char* nazwaPliku, struct lista** glowa, struct wymuszenia* glowaW, int* inTab, int* outTab, int wejscia, int wyjscia, int* wezel);

/** Funkcja czy�ci pami�c po programie.
@param glowa g�owa listy jednokierunkowej bramek logicznych uk�adu
@param glowaW g�owa listy jednokierunkowej wymusze�
@param inTab tabela zawieraj�ca informacje o numerach w�z��w b�d�cych wej�ciami uk�adu
@param outTab tabela zawieraj�ca informacje o numerach w�z��w b�d�cych wyj�ciami uk�adu */
void wyczyscPamiec(struct lista** glowa, struct wymuszenia** glowaW, int** inTab, int** outTab);

#endif
