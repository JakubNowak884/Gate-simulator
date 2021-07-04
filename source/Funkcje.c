#pragma warning(disable: 4996)

#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>

#include "Funkcje.h"
#include "Struktury.h"

int zaneguj(int wartosc) {
	if (wartosc == 0) return 1;
	else return 0; //uzytkownik nie podaje tutaj wartosci, wiec nie ma mozliwosci, ze podana wartosc bedzie inna niz 0 lub 1
}

int sprawdzPoprawnosc(char* tabela, int wiersz) {
	if (tabela[0] == 'i' && tabela[1] == 'n' && tabela[2] == ':' && wiersz == 1) return 1;
	if (tabela[0] == 'o' && tabela[1] == 'r' && tabela[2] == ' ' && wiersz > 2) return 2;
	if (tabela[0] == 'o' && tabela[1] == 'u' && tabela[2] == 't' && tabela[3] == ':' && wiersz == 2) return 3;
	if (tabela[0] == 'a' && tabela[1] == 'n' && tabela[2] == 'd' && tabela[3] == ' ' && wiersz > 2) return 4;
	if (tabela[0] == 'n' && tabela[1] == 'o' && tabela[2] == 'r' && tabela[3] == ' ' && wiersz > 2) return 5;
	if (tabela[0] == 'x' && tabela[1] == 'o' && tabela[2] == 'r' && tabela[3] == ' ' && wiersz > 2) return 6;
	if (tabela[0] == 'n' && tabela[1] == 'e' && tabela[2] == 'g' && tabela[3] == ' ' && wiersz > 2) return 7;
	if (tabela[0] == 'n' && tabela[1] == 'a' && tabela[2] == 'n' && tabela[3] == 'd' && tabela[4] == ' ' && wiersz > 2) return 8;
	if (tabela[0] == 'x' && tabela[1] == 'n' && tabela[2] == 'o' && tabela[3] == 'r' && tabela[4] == ' ' && wiersz > 2) return 9;
	if (tabela[0] == 'I' && tabela[1] == 'N' && tabela[2] == ':' && wiersz == 1) return 1;
	if (tabela[0] == 'O' && tabela[1] == 'R' && tabela[2] == ' ' && wiersz > 2) return 2;
	if (tabela[0] == 'O' && tabela[1] == 'U' && tabela[2] == 'T' && tabela[3] == ':' && wiersz == 2) return 3;
	if (tabela[0] == 'A' && tabela[1] == 'N' && tabela[2] == 'D' && tabela[3] == ' ' && wiersz > 2) return 4;
	if (tabela[0] == 'N' && tabela[1] == 'O' && tabela[2] == 'R' && tabela[3] == ' ' && wiersz > 2) return 5;
	if (tabela[0] == 'X' && tabela[1] == 'O' && tabela[2] == 'R' && tabela[3] == ' ' && wiersz > 2) return 6;
	if (tabela[0] == 'N' && tabela[1] == 'E' && tabela[2] == 'G' && tabela[3] == ' ' && wiersz > 2) return 7;
	if (tabela[0] == 'N' && tabela[1] == 'A' && tabela[2] == 'N' && tabela[3] == 'D' && tabela[4] == ' ' && wiersz > 2) return 8;
	if (tabela[0] == 'X' && tabela[1] == 'N' && tabela[2] == 'O' && tabela[3] == 'R' && tabela[4] == ' ' && wiersz > 2) return 9;
	return 0;
}

int dodajNaKoniecListy(struct lista** glowa, bramka typ, int w1, int w2, int wy)
{
	if ((*glowa) == NULL)
	{
		(*glowa) = (struct lista*)malloc(sizeof(struct lista));
		if (!(*glowa)) return 1;
		(*glowa)->typ = typ;
		(*glowa)->w1 = w1;
		(*glowa)->w2 = w2;
		(*glowa)->wy = wy;
		(*glowa)->stan = X;
		(*glowa)->nast = NULL;
	}
	else
	{
		struct lista* temp = (*glowa);

		while (temp->nast != NULL) {
			temp = temp->nast;
		}

		temp->nast = (struct lista*)malloc(sizeof(struct lista));
		if (!temp->nast) return 1;
		temp->nast->typ = typ;
		temp->nast->w1 = w1;
		temp->nast->w2 = w2;
		temp->nast->wy = wy;
		temp->nast->stan = X;
		temp->nast->nast = NULL;
	}
	return 2;
}

int sprawdzCzyBramkaJuzJest(struct lista* glowa, bramka typ, int w1, int w2, int wy) {
	while (1) {
		if (glowa == NULL) break;
		if (typ == neg) { if (typ == glowa->typ && w1 == glowa->w1 && wy == glowa->wy) return 0; }
		if (typ != neg) { if (typ == glowa->typ && w1 == glowa->w1 && w2 == glowa->w2 && wy == glowa->wy) return 0; }
		if (typ != neg) { if (typ == glowa->typ && w1 == glowa->w2 && w2 == glowa->w1 && wy == glowa->wy) return 0; }
		glowa = glowa->nast;
	}
	return 1;
}

int dodajNaKoniecListyWymuszen(struct wymuszenia** glowa, int** tab, int takty, int wejscia)
{
	if ((*glowa) == NULL)
	{
		(*glowa) = (struct wymuszenia*)malloc(sizeof(struct wymuszenia));
		if (!(*glowa)) return 1;
		(*glowa)->tab = malloc(wejscia * sizeof(int));
		if (!(*glowa)->tab) return 1;
		for (int i = 0; i < wejscia; i++) {
			(*glowa)->tab[i] = (*tab)[i];
		}
		(*glowa)->takty = takty;
		(*glowa)->nast = NULL;
	}
	else
	{
		struct wymuszenia* temp = (*glowa);

		while (temp->nast != NULL) {
			temp = temp->nast;
		}

		temp->nast = (struct wymuszenia*)malloc(sizeof(struct wymuszenia));
		if (!temp->nast) return 1;
		temp->nast->tab = malloc(wejscia * sizeof(int));
		if (!temp->nast->tab) return 1;
		for (int i = 0; i < wejscia; i++) {
			temp->nast->tab[i] = (*tab)[i];
		}
		temp->nast->takty = takty;
		temp->nast->nast = NULL;
	}
	return 2;
}

int wczytajZPliku1(char* nazwaPliku, struct lista** glowa, int** inTab, int** outTab, int* wejscia, int* wyjscia) {
	FILE* plik = fopen(nazwaPliku, "rt");
	if (!plik) return 0;
	int brakDwukropka = 0;
	int p;
	int bufor = 0;
	int bufor2 = 0;
	bramka typ;
	int w1 = 0;
	int w2 = 0;
	int wy = 0;
	char znak;
	int wezel;
	char tabela[5];
	int wiersz = 1;
	int koniec = 0;
	int sprawdzKoniec = 0;
	int* temp;
	while (1) {
		for (int i = 0; i < 5; i++) { //wpisywanie w petli pierwszych znakow w danym wierszu by sprawdzic czy odpowiada on kluczowi
			if (fscanf(plik, "%c", &znak) == EOF) {
				koniec = 1; break;
			}
			tabela[i] = znak;
			if (sprawdzKoniec == 1 && znak == '\n' || sprawdzKoniec == 1 && znak == ' ' || sprawdzKoniec == 1 && znak == '	') i = -1; else if (sprawdzKoniec == 1) { fclose(plik); return wiersz; }
			if (znak == '\n') { i = -1; sprawdzKoniec = 1; continue; }
			if (znak == ' ' && i <= 2 || znak == '	' && i <= 2) { i = -1; sprawdzKoniec = 1; continue; }
			if (znak == ':') break;
			if (znak == ' ' && i > 2) { brakDwukropka = 1; break; }
		}
		if (koniec == 1) break;
		if (sprawdzPoprawnosc(tabela, wiersz) == 0) { fclose(plik); return wiersz; } //porownywanie tabeli znakow z kluczem
		if (sprawdzPoprawnosc(tabela, wiersz) == 1) typ = in;
		if (sprawdzPoprawnosc(tabela, wiersz) == 2) typ = or;
		if (sprawdzPoprawnosc(tabela, wiersz) == 3) typ = out;
		if (sprawdzPoprawnosc(tabela, wiersz) == 4) typ = and;
		if (sprawdzPoprawnosc(tabela, wiersz) == 5) typ = nor;
		if (sprawdzPoprawnosc(tabela, wiersz) == 6) typ = xor;
		if (sprawdzPoprawnosc(tabela, wiersz) == 7) typ = neg;
		if (sprawdzPoprawnosc(tabela, wiersz) == 8) typ = nand;
		if (sprawdzPoprawnosc(tabela, wiersz) == 9) typ = xnor;
		if (brakDwukropka == 1)  p = 1; else p = 0;
		while (1) {
			if (p % 2 == 0) {
				if (fscanf(plik, "%c", &znak) == EOF) {
					if (p < 4 && typ == neg) { fclose(plik); return wiersz; } if (p < 6 && typ != neg && typ != in && typ != out) { fclose(plik); return wiersz; } if (p < 2 && typ == in || p < 2 && typ == out) { fclose(plik); return wiersz; }
					else { koniec = 1; break; }
				}
				if (znak == '\n') break;
				if (p > 3 && znak == ' ' || p > 3 && znak == '	') { if (typ == neg) { p += 2; continue; } if (p > 5 && typ != neg && typ != in && typ != out) { p += 2; continue; } }
				if (znak != ' ') { fclose(plik); return wiersz; }
			}
			if (p % 2 == 1) {
				if (!fscanf(plik, "%d", &wezel)) { fclose(plik); return wiersz; }
				if (wezel < 1) { fclose(plik); return -2; }
				if (p == 1) w1 = wezel;
				if (p == 3 && typ != neg) w2 = wezel;
				if (p == 3 && typ == neg) wy = wezel;
				if (p == 5) wy = wezel;
				if (p == 5 && typ == neg) { fclose(plik); return wiersz; }
				if (typ == in) {
					if (bufor > 0) {
						temp = realloc((*inTab), (bufor + 1) * sizeof(int*));
						if (temp != NULL)
						{
							(*inTab) = temp;
						}
						else {
							fclose(plik); return -1;
						}
					}
					(*inTab)[bufor] = wezel;
					(*wejscia)++;
					bufor++;
				}
				if (typ == out) {
					if (bufor2 > 0) {
						temp = realloc((*outTab), (bufor + 1) * sizeof(int*));
						if (temp != NULL)
						{
							(*outTab) = temp;
						}
						else {
							fclose(plik); return -1;
						}
					}
					(*outTab)[bufor2] = wezel;
					(*wyjscia)++;
					bufor2++;
				}
			}
			p++;
		}
		if (typ != in && typ != out) if (sprawdzCzyBramkaJuzJest((*glowa), typ, w1, w2, wy) == 1) if (dodajNaKoniecListy(&(*glowa), typ, w1, w2, wy) == 1) { fclose(plik); return -1; }
		wiersz++;
		if (koniec == 1) break;
	}

	fclose(plik);
	if ((*glowa) == NULL) return -3;

	return -4;
}

int wczytajZPliku2(char* nazwaPliku, int wejscia, int* inTab, struct wymuszenia** glowaW) {
	FILE* plik = fopen(nazwaPliku, "rt");
	if (!plik) return 0;
	int* tab;
	tab = malloc(wejscia * sizeof(int));
	if (!tab) { free(tab); fclose(plik); return -1; }
	int p = 1;
	int z = 0;
	int wartosc;
	char znak;
	int koniecP = 0;
	int koniec = 0;
	int wiersz = 1;
	while (1) {
		while (1) {
			if (p % 2 == 1) {
				if (!fscanf(plik, "%d", &wartosc)) {
					while (1) {
						if (fscanf(plik, "%c", &znak) == EOF) { koniec = 1; break; }
						if (znak == ' ' || znak == '	' || znak == '\n'); else { free(tab); fclose(plik); return wiersz; }
					}
					if (koniec == 1) break;
				}
				if (z == wejscia) {
					if (dodajNaKoniecListyWymuszen(&(*glowaW), &tab, wartosc, wejscia) == 1) { free(tab); fclose(plik); return -1; }
					while (1) {
						if (fscanf(plik, "%c", &znak) == EOF) { koniecP = 1; koniec = 1; break; }
						if (znak == '\n') { koniecP = 1; break; }
						if (znak != ' ' && znak != '	') { free(tab); fclose(plik); return wiersz; }
					}
					wiersz++;
					if (koniecP == 1) break;
				}
				if (p % 4 == 1) {
					if (wartosc != inTab[z]) { if (fscanf(plik, "%c", &znak) == EOF) { koniec = 1; break; } else { free(tab); fclose(plik); return wiersz; } }
				}
				else {
					if (wartosc != 0 && wartosc != 1) { free(tab); fclose(plik); return wiersz; }
					tab[z] = wartosc;
				}
			}

			if (p % 2 == 0) {
				fscanf(plik, "%c", &znak);

				if (p % 4 == 0) {
					if (znak != ' ') { free(tab); fclose(plik); return wiersz; }
					z++;
				}

				else {
					if (znak != ':') { free(tab); fclose(plik); return wiersz; }
				}
			}
			p++;
		}

		if (koniec == 1) break; else { koniecP = 0; p = 1; z = 0; }
	}

	free(tab);
	fclose(plik);
	if ((*glowaW) == NULL) return -2;

	return -3;
}

void wyrownajStanyBramek(struct lista* glowa) {
	while (1) {
		if (glowa == NULL) break;
		glowa->stanP = glowa->stan;

		glowa = glowa->nast;
	}
}

int znajdzStanBramki(struct lista* glowa, struct wymuszenia* glowaW, int* inTab, int wejscia, int wezel, int wybor) {

	for (int i = 0; i < wejscia; i++) {
		if (inTab[i] == wezel) return glowaW->tab[i];
	}
	while (1) {
		if (glowa == NULL) break;
		if (glowa->wy == wezel) if (wybor == 1) return glowa->stanP; else return glowa->stan;

		glowa = glowa->nast;
	}
	return X;
}

void wykonajOperacjeNaBramkach(struct lista** glowa, struct lista* glowa2, struct wymuszenia* glowaW, int* inTab, int wejscia) {

	if ((*glowa) == NULL) return;

	int w1 = znajdzStanBramki(glowa2, glowaW, inTab, wejscia, (*glowa)->w1, 1); //zmienna oznaczajaca stan pierwszego wejscia ukladu
	int w2 = znajdzStanBramki(glowa2, glowaW, inTab, wejscia, (*glowa)->w2, 1); //zmienna oznaczajaca stan drugiego wejscia ukladu
	//wykonanie operacji na bramce w zaleznosci od jej typu i powyzszych zmiennych
	if ((*glowa)->typ == neg) {
		if (w1 != X) (*glowa)->stan = zaneguj(w1);
		if (w1 == X) (*glowa)->stan = X;
	}
	if ((*glowa)->typ == and) {
		if (w1 != X && w2 != X) (*glowa)->stan = w1 * w2;
		if (w1 == 1 && w2 == X || w1 == X && w2 == 1) (*glowa)->stan = X;
		if (w1 == 0 && w2 == X || w1 == X && w2 == 0) (*glowa)->stan = 0;
		if (w1 == X && w2 == X) (*glowa)->stan = X;
	}
	if ((*glowa)->typ == nand) {
		if (w1 != X && w2 != X) (*glowa)->stan = zaneguj(w1 * w2);
		if (w1 == 1 && w2 == X || w1 == X && w2 == 1) (*glowa)->stan = X;
		if (w1 == 0 && w2 == X || w1 == X && w2 == 0) (*glowa)->stan = 1;
		if (w1 == X && w2 == X) (*glowa)->stan = X;
	}
	if ((*glowa)->typ == or) {
		if (w1 != X && w2 != X) if (w1 + w2 >= 1) (*glowa)->stan = 1; else (*glowa)->stan = 0;
		if (w1 == 1 && w2 == X || w1 == X && w2 == 1) (*glowa)->stan = 1;
		if (w1 == 0 && w2 == X || w1 == X && w2 == 0) (*glowa)->stan = X;
		if (w1 == X && w2 == X) (*glowa)->stan = X;
	}
	if ((*glowa)->typ == nor) {
		if (w1 != X && w2 != X) if (w1 + w2 >= 1) (*glowa)->stan = 0; else (*glowa)->stan = 1;
		if (w1 == 1 && w2 == X || w1 == X && w2 == 1) (*glowa)->stan = 0;
		if (w1 == 0 && w2 == X || w1 == X && w2 == 0) (*glowa)->stan = X;
		if (w1 == X && w2 == X) (*glowa)->stan = X;
	}
	if ((*glowa)->typ == xor) {
		if (w1 != X && w2 != X) if (w1 == w2) (*glowa)->stan = 0; else (*glowa)->stan = 1;
		if (w1 != X && w2 == X || w1 == X && w2 != X) (*glowa)->stan = X;
		if (w1 == X && w2 == X) (*glowa)->stan = X;
	}
	if ((*glowa)->typ == xnor) {
		if (w1 != X && w2 != X) if (w1 == w2) (*glowa)->stan = 1; else (*glowa)->stan = 0;
		if (w1 != X && w2 == X || w1 == X && w2 != X) (*glowa)->stan = X;
		if (w1 == X && w2 == X) (*glowa)->stan = X;
	}

	wykonajOperacjeNaBramkach(&(*glowa)->nast, glowa2, glowaW, inTab, wejscia);
}

int znajdzNiepoprawnyWezelWejsciowy(int* inTab, int wejscia) {
	for (int i = 0; i < wejscia; i++) {
		for (int j = 0; j < wejscia; j++) {
			if (inTab[i] == inTab[j] && i != j) { return inTab[i]; }
		}
	}
	return 0;
}

int znajdzNiepoprawnyWezelWyjsciowy(int* outTab, int wyjscia) {
	for (int i = 0; i < wyjscia; i++) {
		for (int j = 0; j < wyjscia; j++) {
			if (outTab[i] == outTab[j] && i != j) { return outTab[i]; }
		}
	}
	return 0;
}

int policzWezly(int wejscia, int wyjscia, struct lista* glowa) {
	int licznik = wejscia + wyjscia;
	while (1) {
		if (glowa == NULL) break;
		if (glowa->typ == neg) licznik += 2;  else licznik += 3;
		glowa = glowa->nast;
	}
	return licznik;
}

int sprawdzPoprawnoscWezlow(struct lista* glowa, int* inTab, int* outTab, int wejscia, int wyjscia) {
	int* tab;
	int w = policzWezly(wejscia, wyjscia, glowa);
	tab = malloc(w * sizeof(int)); //inicjalicja tabeli w ktorej trzymane sa wszystkie wezly
	if (!tab) { free(tab); return 0; }
	//wypelnienie tabeli wezlami wejsc, wyjsc oraz bramek
	int p = 0;
	for (int i = 0; i < wejscia; i++) {
		tab[p] = inTab[i];
		p++;
	}

	for (int i = 0; i < wyjscia; i++) {
		tab[p] = outTab[i];
		p++;
	}

	while (1) {
		if (glowa == NULL) break;
		if (glowa->typ == neg) {
			tab[p] = glowa->w1;
			tab[p + 1] = glowa->wy;
			p += 2;
		}
		else {
			tab[p] = glowa->w1;
			tab[p + 1] = glowa->w2;
			tab[p + 2] = glowa->wy;
			p += 3;
		}
		glowa = glowa->nast;
	}

	int h;
	//sortowanie babelkowe tabeli
	for (int i = 0; i < w; i++) {
		for (int j = 1; j < w - i; j++) {
			if (tab[j - 1] > tab[j]) {
				h = tab[j - 1];
				tab[j - 1] = tab[j];
				tab[j] = h;
			}
		}
	}

	h = 1;
	//sprawdzenie czy nie brakuje ktorego z wezlow
	for (int i = 0; i < w; i++) {
		if (tab[i] != h) { free(tab); return h; }
		while (1) {
			if (tab[i] == tab[i + 1]) i++; else break;
		}
		h++;
	}

	free(tab);

	return -1;
}

int policzWezlyWyjsciowe(struct lista* glowa, int wyjscia) {
	int licznik = wyjscia;
	while (1) {
		if (glowa == NULL) break;
		licznik++;
		glowa = glowa->nast;
	}
	return licznik;
}

int znajdzNiepoprawnyWezelWyjsciowyBramek(struct lista* glowa, int wyjscia) {
	int* tab;
	int w1 = policzWezlyWyjsciowe(glowa, wyjscia);
	int w = w1 - wyjscia;
	tab = malloc(w * sizeof(int));
	if (!tab) { free(tab); return 0; }
	int p = 0;

	while (1) {
		if (glowa == NULL) break;
		tab[p] = glowa->wy;
		p++;
		glowa = glowa->nast;
	}

	for (int i = 0; i < w; i++) {
		for (int j = 0; j < w; j++) {
                if (tab[i] == tab[j] && i != j) { p = tab[i]; free(tab); return p; }
		}
	}

	free(tab);

	return -1;
}

int sprawdzPoprawnoscWezlowWy(struct lista* glowa, int* outTab, int wyjscia) {
	struct lista* temp = glowa;
	int p = 0;
	for (int i = 0; i < wyjscia; i++) {
		temp = glowa;
		while (1) {
			if (temp == NULL) break;
			if (temp->wy == outTab[i]) p++;
			temp = temp->nast;
		}
	}
	if (p != wyjscia) return 1;

	return 2;
}

int sprawdzPoprawnoscWezlowWe(struct lista* glowa, int* inTab, int wejscia) {
	struct lista* temp = glowa;
	for (int i = 0; i < wejscia; i++) {
		temp = glowa;
		while (1) {
			if (temp == NULL) break;
			if (temp->wy == inTab[i]) return 1;
			temp = temp->nast;
		}
	}

	return 2;
}

int zapiszDoPliku(char* nazwaPliku, struct lista** glowa, struct wymuszenia* glowaW, int* inTab, int* outTab, int wejscia, int wyjscia, int* wezel) {
	//sprawdzanie czy uklad zostal poprawnie zapisany
	int wybor = znajdzNiepoprawnyWezelWejsciowy(inTab, wejscia);

	if (wybor > 0) { (*wezel) = wybor; return 2; }

	wybor = znajdzNiepoprawnyWezelWyjsciowy(outTab, wyjscia);

	if (wybor > 0) { (*wezel) = wybor; return 3; }

	wybor = sprawdzPoprawnoscWezlow((*glowa), inTab, outTab, wejscia, wyjscia);

	if (wybor == 0) return 1;
	if (wybor > 0) { (*wezel) = wybor; return 4; }

	wybor = znajdzNiepoprawnyWezelWyjsciowyBramek((*glowa), wyjscia);

	if (wybor == 0) return 1;
	if (wybor > 0) { (*wezel) = wybor; return 5; }

	wybor = sprawdzPoprawnoscWezlowWy((*glowa), outTab, wyjscia);

	if (wybor == 1) { return 6; }

	wybor = sprawdzPoprawnoscWezlowWe((*glowa), inTab, wejscia);

	if (wybor == 1) { return 7; }

	FILE* plik;
	plik = fopen(nazwaPliku, "wt");
	if (!plik) return 0;

	int t = 1; //zmienna oznaczajaca takty

	while (1) {
		if (glowaW == NULL) break;
		for (int i = 0; i < glowaW->takty; i++) {
			wyrownajStanyBramek((*glowa));
			wykonajOperacjeNaBramkach(&(*glowa), (*glowa), glowaW, inTab, wejscia);
			fprintf(plik, "IN: ");
			for (int j = 0; j < wejscia; j++) {
				fprintf(plik, "%d:%d ", inTab[j], glowaW->tab[j]);
			}
			fprintf(plik, "T:%d ", t);
			fprintf(plik, "OUT: ");
			for (int j = 0; j < wyjscia; j++) {
				int stan = znajdzStanBramki((*glowa), glowaW, inTab, wejscia, outTab[j], 2);
				if (stan == 0 || stan == 1) fprintf(plik, "%d:%d ", outTab[j], stan);
				if (stan == X) fprintf(plik, "%d:x ", outTab[j]);
			}
			fprintf(plik, "\n");
			t++;
		}
		glowaW = glowaW->nast;
	}

	fclose(plik);
	return 8;
}

void wyczyscPamiec(struct lista** glowa, struct wymuszenia** glowaW, int** inTab, int** outTab) {
	free((*inTab));
	free((*outTab));

	struct lista* nast = NULL;

	while (1) {
		if ((*glowa) == NULL) break;
		nast = (*glowa)->nast;
		free((*glowa));
		(*glowa) = nast;
	}

	struct wymuszenia* nast2 = NULL;

	while (1) {
		if ((*glowaW) == NULL) break;
		nast2 = (*glowaW)->nast;
		free((*glowaW)->tab);
		free((*glowaW));
		(*glowaW) = nast2;
	}
}
