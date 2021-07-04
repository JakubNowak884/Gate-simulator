#ifndef FUNKCJE_H
#define FUNCKJE_H

#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>

#include "Struktury.h"

/** Funkcja neguje podan¹ wartoœæ. W przypadku podania 0 funkcja zwraca 1, w innym przypadku funkcja zwraca 0.
@param wartosc wartoœæ do zanegowania */
int zaneguj(int wartosc);

/** Funkcja sprawdza czy podane znaki w tabeli s¹ równe odpowieniemu kluczowi, tj. (du¿ymi lub ma³ymi literami) jeœli wiersz = 1 "IN:", jeœli wiersz = 2 "OUT:", jeœli wiersz > 2 "OR ", "AND ", "NOR ", "XOR ", "NEG ", "NAND ", "XNOR ". Funkcja zwraca 0 w przypadku niepowodzenia. W przypadku zgodnoœci znaków z kluczem zwraca 1 jeœli znaki by³y równe "IN:", 2 jeœli "OR ", 3 jeœli "OUT:", 4 jeœli "AND ", 5 jeœli "NOR ", 6 jeœli "NEG ", 7 jeœli "NAND ", 8 jeœli "XNOR ".
@param tabela tabela zawieraj¹ca 3, 4 lub 5 znaków
@param wiersz wiersz pliku wejœciowego */
int sprawdzPoprawnosc(char* tabela, int wiersz);

/** Funkcja dodaje nowy element do listy jednokierunkowej zawieraj¹cej bramki logiczne uk³adu. Funkcja zwraca 2 w przypadku powodzenia lub 1 jeœli nie uda siê przydzieliæ pamiêci.
@param glowa g³owa listy jednokierunkowej bramek logicznych uk³adu
@param typ typ dodawanej bramki
@param w1 numer pierwszego wêz³a wejœcia dodawanej bramki
@param w2 numer drugiego wêz³a wejœcia dodawanej bramki (nieistotne w przypadku bramki typu neg)
@param wy numer wêz³a wyjœciowego dodawanej bramki */
int dodajNaKoniecListy(struct lista** glowa, bramka typ, int w1, int w2, int wy);

/** Funkcja sprawdza czy podana bramka istnieje ju¿ w liœcie bramek logicznych. Funkcja zwraca 0 jeœli bramka znajduje siê ju¿ w liœcie lub 1 jeœli siê nie znajduje.
@param glowa g³owa listy jednokierunkowej bramek logicznych uk³adu
@param typ typ sprawdzanej bramki
@param w1 numer pierwszego wêz³a wejœcia sprawdzanej bramki
@param w2 numer drugiego wêz³a wejœcia sprawdzanej bramki (nieistotne w przypadku bramki typu neg)
@param wy numer wêz³a wyjœciowego sprawdzanej bramki */
int sprawdzCzyBramkaJuzJest(struct lista* glowa, bramka typ, int w1, int w2, int wy);

/** Funkcja dodaje nowy element do listy jednokierunkowej zawieraj¹cej informacje o stanach wejœæ uk³adu i taktach ich trwania. Funkcja zwraca 2 w przypadku powodzenia lub 1 jeœli nie uda siê przydzieliæ pamiêci.
@param glowa g³owa listy jednokierunkowej wymuszeñ
@param tab tabela z informacjami o stanach wejœæ uk³adu
@param takty iloœæ taktów dla poszczególnych stanów wejœæ uk³adu
@param wejscia iloœæ wejœæ uk³adu */
int dodajNaKoniecListyWymuszen(struct wymuszenia** glowa, int** tab, int takty, int wejscia);

/** Funkcja wczytuje z pliku informacje o wejœciach i wyjœciach uk³adu oraz bramkach logicznych. Funkcja zwraca 0 jeœli nie uda³o siê otworzyæ pliku, -1 jeœli nie uda³o siê przydzieliæ pamiêci, -2 jeœli któryœ z wêz³ów bramki jest mniejszy od 1, -3 jeœli plik jest pusty, liczbê wiêksz¹ od zera bêd¹c¹ wierszem w którym znajduje siê b³êdny zapis lub -4 w przypadku powodzenia.
@param nazwaPliku nazwa pliku wejœciowego
@param glowa g³owa listy jednokierunkowej bramek logicznych uk³adu
@param inTab tabela zawieraj¹ca informacje o numerach wêz³ów bêd¹cych wejœciami uk³adu
@param outTab tabela zawieraj¹ca informacje o numerach wêz³ów bêd¹cych wyjœciami uk³adu
@param wejscia iloœæ wejœæ uk³adu
@param wyjscia iloœæ wyjœæ uk³adu */
int wczytajZPliku1(char* nazwaPliku, struct lista** glowa, int** inTab, int** outTab, int* wejscia, int* wyjscia);

/** Funkcja wczytuje z pliku wymuszeñ informacje o stanach wejœæ uk³adu oraz taktach ich trwania. Funkcja zwraca 0 jeœli nie uda³o siê otworzyæ pliku, -1 jeœli nie uda³o siê przydzieliæ pamiêci, -2 jeœli plik jest pusty, liczbê wiêksz¹ od zera bêd¹c¹ wierszem w którym znajduje siê b³êdny zapis lub -3 w przypadku powodzenia.
@param nazwaPliku nazwa pliku wejœciowego wymuszeñ
@param wejscia iloœæ wejœæ uk³adu
@param inTab tabela zawieraj¹ca informacje o numerach wêz³ów bêd¹cych wejœciami uk³adu
@param glowaW g³owa listy jednokierunkowej wymuszeñ */
int wczytajZPliku2(char* nazwaPliku, int wejscia, int* inTab, struct wymuszenia** glowaW);

/** Funkcja przypisuje iteracyjnie poprzednim stanom bramek ich aktualn¹ wartoœæ.
@param glowa g³owa listy jednokierunkowej bramek logicznych uk³adu */
void wyrownajStanyBramek(struct lista* glowa);

/** Funkcja zwraca poprzedni stan bramki o podanym wêŸle wyjœæiowym jeœli wybór = 1, w innym wypadku zwraca aktualny stan bramki o podanym wêŸle wyjœciowym lub 2 jeœli bramka o danym wêŸle wyjœciowym nie istnieje.
@param glowa g³owa listy jednokierunkowej bramek logicznych uk³adu
@param glowaW g³owa listy jednokierunkowej wymuszeñ
@param inTab tabela zawieraj¹ca informacje o numerach wêz³ów bêd¹cych wejœciami uk³adu
@param wejscia iloœæ wejœæ uk³adu
@param wezel wêze³ wyjœciowy szukanej bramki logicznej
@param wybor zmienna decyduj¹ca czy zwrócony zostanie poprzedni czy aktualny stan bramki */
int znajdzStanBramki(struct lista* glowa, struct wymuszenia* glowaW, int* inTab, int wejscia, int wezel, int wybor);

/** Funkcja wykonuje rekurencyjnie operacje na bramkach logicznych.
@param glowa g³owa listy jednokierunkowej bramek logicznych uk³adu
@param glowa2 g³owa listy jednokierunkowej bramek logicznych uk³adu
@param glowaW g³owa listy jednokierunkowej wymuszeñ
@param inTab tabela zawieraj¹ca informacje o numerach wêz³ów bêd¹cych wejœciami uk³adu
@param wejscia iloœæ wejœæ uk³adu */
void wykonajOperacjeNaBramkach(struct lista** glowa, struct lista* glowa2, struct wymuszenia* glowaW, int* inTab, int wejscia);

/** Funkcja zwraca numer wêz³a wejœciowego który siê powtarza lub 0 w przypadku braku takiego wêz³a.
@param inTab tabela zawieraj¹ca informacje o numerach wêz³ów bêd¹cych wejœciami uk³adu
@param wejscia iloœæ wejœæ uk³adu */
int znajdzNiepoprawnyWezelWejsciowy(int* inTab, int wejscia);

/** Funkcja zwraca numer wêz³a wyjœciowego który siê powtarza lub 0 w przypadku braku takiego wêz³a.
@param outTab tabela zawieraj¹ca informacje o numerach wêz³ów bêd¹cych wyjœciami uk³adu
@param wyjscia iloœæ wyjœæ uk³adu */
int znajdzNiepoprawnyWezelWyjsciowy(int* outTab, int wyjscia);

/** Funkcja zwraca iloœæ wêz³ów wejœciowych, wyjœciowych i wszystkich bramek.
@param wejscia iloœæ wejœæ uk³adu
@param wyjscia iloœæ wyjœæ uk³adu
@param glowa g³owa listy jednokierunkowej bramek logicznych uk³adu */
int policzWezly(int wejscia, int wyjscia, struct lista* glowa);

/** Funkcja sprawdza czy w uk³adzie nie brakuje któregoœ z numerów wêz³ów. Funkcja zwraca numer brakuj¹cego wêz³a, 0 w przypadku niepowodzenia przydzialania pamiêci lub -1 w przypadku braku takiego wêz³a.
@param glowa g³owa listy jednokierunkowej bramek logicznych uk³adu
@param inTab tabela zawieraj¹ca informacje o numerach wêz³ów bêd¹cych wejœciami uk³adu
@param outTab tabela zawieraj¹ca informacje o numerach wêz³ów bêd¹cych wyjœciami uk³adu
@param wejscia iloœæ wejœæ uk³adu
@param wyjscia iloœæ wyjœæ uk³adu */
int sprawdzPoprawnoscWezlow(struct lista* glowa, int* inTab, int* outTab, int wejscia, int wyjscia);

/** Funkcja zwraca iloœæ wêz³ów wyjœciowych uk³adu i wszystkich bramek.
@param glowa g³owa listy jednokierunkowej bramek logicznych uk³adu
@param wyjscia iloœæ wyjœæ uk³adu */
int policzWezlyWyjsciowe(struct lista* glowa, int wejscia);

/** Funkcja zwraca numer powtarzaj¹cego siê wêz³a wyjœciowego bramek, 0 w przypadku niepowodzenia przydzialania pamiêci lub -1 w przypadku braku takiego wêz³a.
@param glowa g³owa listy jednokierunkowej bramek logicznych uk³adu
@param wyjscia iloœæ wyjœæ uk³adu */
int znajdzNiepoprawnyWezelWyjsciowyBramek(struct lista* glowa, int wyjscia);

/** Funkcja sprawdza czy wêz³y wejœciowe uk³adu nie s¹ wyjœciami bramek logicznych. Funkcja zwraca 1 jeœli s¹ lub 2 jeœli nie s¹
@param glowa g³owa listy jednokierunkowej bramek logicznych uk³adu
@param inTab tabela zawieraj¹ca informacje o numerach wêz³ów bêd¹cych wejœciami uk³adu
@param wejscia iloœæ wejœæ uk³adu */
int sprawdzPoprawnoscWezlowWe(struct lista* glowa, int* inTab, int wejscia);

/** Funkcja sprawdza czy wêz³y wyjœciowe uk³adu pokrywaj¹ siê z wyjœciami bramek logicznych. Funkcja zwraca 1 w przypadku nie pokrywania siê wyjœæ lub 2 w przypadku pokrywania siê wyjœæ
@param glowa g³owa listy jednokierunkowej bramek logicznych uk³adu
@param outTab tabela zawieraj¹ca informacje o numerach wêz³ów bêd¹cych wyjœciami uk³adu
@param wyjscia iloœæ wyjœæ uk³adu */
int sprawdzPoprawnoscWezlowWy(struct lista* glowa, int* outTab, int wyjscia);

/** Funkcja zapisuje do pliku wyjœciowego  wartoœci wyjœæ w kolejnych taktach. Funkcja zwraca 0 jeœli nie uda³o siê utworzyæ pliku o podanej nazwie, 1 jeœli nie uda³o siê przydzieliæ pamiêci, 2 jeœli w ukladzie wystepuja dwa wezly wejsciowe o tym samym numerze, 3 jeœli w ukladzie wystepuja dwa wezly wyjsciowe o tym samym numerze, 4 jeœli w uk³adzie brakuje wêz³a o jakimœ numerze, 5 jeœli w ukladzie wystepuje dwa wezly wyjsciowe bramek o tym samym numerze, 6 jeœli w ukladzie wezly wyjsciowe nie pokrywaja sie z wezlami wyjsciowymi bramek, 7 jeœli wêze³ wejœciowy jest wyjœciem bramki lub 8 w przypadku powodzenia
@param nazwaPliku nazwa pliku wyjœciowego
@param glowa g³owa listy jednokierunkowej bramek logicznych uk³adu
@param glowaW g³owa listy jednokierunkowej wymuszeñ
@param inTab tabela zawieraj¹ca informacje o numerach wêz³ów bêd¹cych wejœciami uk³adu
@param outTab tabela zawieraj¹ca informacje o numerach wêz³ów bêd¹cych wyjœciami uk³adu
@param wejscia iloœæ wejœæ uk³adu
@param wyjscia iloœæ wyjœæ uk³adu
@param wezel zmienna oznaczaj¹ca brakuj¹cy lub powtarzaj¹cy siê numer wêz³a */
int zapiszDoPliku(char* nazwaPliku, struct lista** glowa, struct wymuszenia* glowaW, int* inTab, int* outTab, int wejscia, int wyjscia, int* wezel);

/** Funkcja czyœci pamiêc po programie.
@param glowa g³owa listy jednokierunkowej bramek logicznych uk³adu
@param glowaW g³owa listy jednokierunkowej wymuszeñ
@param inTab tabela zawieraj¹ca informacje o numerach wêz³ów bêd¹cych wejœciami uk³adu
@param outTab tabela zawieraj¹ca informacje o numerach wêz³ów bêd¹cych wyjœciami uk³adu */
void wyczyscPamiec(struct lista** glowa, struct wymuszenia** glowaW, int** inTab, int** outTab);

#endif
