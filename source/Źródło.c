/** @file */

#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>

#include "Funkcje.h"
#include "Struktury.h"

int main(int argc, char* argv[]) {
	printf("\n");
	//sprawdzenie czy podane sa 3 przelaczniki i 3 nazwy plikow
	if (argc == 7) {

		int wejscia = 0; //zmienna przechowujaca liczbe wejsc ukladu
		int wyjscia = 0; //zmienna przechowujaca liczbe wyjsc ukladu
		int wezel = 0; //zmienna podawana do funkcji zapiszDoPliku oznaczajaca bledny wezel ukladu

		struct lista* glowa; //lista przechowujaca bramki
		glowa = NULL;

		struct wymuszenia* glowaW; //lista przechowujaca stany wejsc i takty ich trwania
		glowaW = NULL;

		int* inTab; //tabela przechowujaca numery wezlow wejscia ukladu
		inTab = malloc(1 * sizeof(int));

		int* outTab; //tabela przechowujaca numery wezlow wyjscia ukladu
		outTab = malloc(1 * sizeof(int));

		if (!inTab) { printf("Blad! Nie udalo sie przydzielic pamieci\n"); wyczyscPamiec(&glowa, &glowaW, &inTab, &outTab); return 0; }

		if (!inTab) { printf("Blad! Nie udalo sie przydzielic pamieci\n"); wyczyscPamiec(&glowa, &glowaW, &inTab, &outTab); return 0; }

		int wybor = 0;

		int i = 1; //zmienna zwiekszajaca sie o 2 przez pierwsze 3 obiegi petli, oznaczajaca miejsca w tabeli, w ktorych znajduja sie przelaczniki -u -i -o

		int p1 = 0; //zmienne oznaczajace miejsca w tabeli argv, w ktorych znajduja sie nazwy plikow wejsciowych i wyjsciowych

		int p2 = 0;

		int p3 = 0;

		while (1) {
			//sprawdzenie czy, i w ktorych miejscach tabeli argv znajduja sie przelaczniki i nazwy plikow wejsciowych i wyjsciowych
			if (i < 7) {
				if (argv[i][0] == 45 && argv[i][1] == 117) {

					p1 = i + 1;

					i += 2; continue;
				}

				if (argv[i][0] == 45 && argv[i][1] == 105) {

					p2 = i + 1;

					i += 2; continue;
				}

				if (argv[i][0] == 45 && argv[i][1] == 111) {

					p3 = i + 1;

					i += 2; continue;
				}
			}
			//jesli wszystkie przelaczniki zostaly wczytane poprawnie wykonanie glownej czesci programu
			if (p1 != 0 && p2 != 0 && p3 != 0) {

				wybor = wczytajZPliku1(argv[p1], &glowa, &inTab, &outTab, &wejscia, &wyjscia);

				if (wybor == 0) { printf("Blad! Nie udalo sie otworzyc pliku wejsciowego z ukladem o podanej nazwie\n"); break; }
				if (wybor == -1) { printf("Blad! Nie udalo sie przydzielic pamieci\n"); break; }
				if (wybor == -2) { printf("Blad! Numer wezla nie moze byc mniejszy od 1\n"); break; }
				if (wybor == -3) { printf("Blad! Plik wejsciowy z ukladem nie moze byc pusty\n"); break; }
				if (wybor > 0) { printf("Blad! Niepoprawny zapis w pliku wejsciowym z ukladem w %d wierszu\n", wybor); break; }

				wybor = wczytajZPliku2(argv[p2], wejscia, inTab, &glowaW);

				if (wybor == 0) { printf("Blad! Nie udalo sie otworzyc pliku wymuszen o podanej nazwie\n"); break; }
				if (wybor == -1) { printf("Blad! Nie udalo sie przydzielic pamieci\n"); break; }
				if (wybor == -2) { printf("Blad! Plik wejsciowy wymuszen nie moze byc pusty\n"); break; }
				if (wybor > 0) { printf("Blad! Niepoprawny zapis w pliku wejsciowym wymuszen w %d wierszu\n", wybor); break; }

				wybor = zapiszDoPliku(argv[p3], &glowa, glowaW, inTab, outTab, wejscia, wyjscia, &wezel);

				if (wybor == 0) { printf("Blad! Nie udalo sie utworzyc pliku o podanej nazwie\n"); break; }
				if (wybor == 1) { printf("Blad! Nie udalo sie przydzielic pamieci\n"); break; }
				if (wybor == 2) { printf("Blad! W ukladzie wystepuja dwa wezly wejsciowe o numerze %d\n", wezel); break; }
				if (wybor == 3) { printf("Blad! W ukladzie wystepuja dwa wezly wyjsciowe o numerze %d\n", wezel); break; }
				if (wybor == 4) { printf("Blad! W ukladzie brakuje wezla o numerze %d\n", wezel); break; }
				if (wybor == 5) { printf("Blad! W ukladzie wystepuje dwa wezly wyjsciowe bramek o numerze %d\n", wezel); break; }
				if (wybor == 6) { printf("Blad! W ukladzie wezly wyjsciowe nie pokrywaja sie z wezlami wyjsciowymi bramek\n"); break; }
				if (wybor == 7) { printf("Blad! Wezel wejsciowy nie moze byc wyjsciem bramki\n"); break; }
			}
			//jesli wszystkie przelaczniki zostaly wczytane poprawnie zakonczenie petli
			if (i == 7) break;
			//jesli przelaczniki zostaly blednie podane wyswietlenie komunikatu o bledzie i zakonczenie petli
			printf("Blad! Nalezy podac przelaczniki -u plik wejsciowy z ukladem -i plik wejsciowy z stanami wejsc -o plik wyjsciowy ze stanami wyjsc\n");
			break;

		}

		wyczyscPamiec(&glowa, &glowaW, &inTab, &outTab); //czyszczenie pamieci po programie
	}
	else printf("Blad! Nalezy podac przelaczniki -u plik wejsciowy z ukladem -i plik wejsciowy z stanami wejsc -o plik wyjsciowy ze stanami wyjsc\n");

	return 0;
}
