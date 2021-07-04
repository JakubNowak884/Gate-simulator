#ifndef STRUKTURY_H
#define STRUKTURY_H

#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>

#define X 2

/**
 * \enum bramka
 * \typ bramki logicznej lub oznaczenie wêz³ów wejœcia i wyjœcia
 */
typedef enum
{
	in,		/**< wêz³y wejœcia */
	out,	/**< wêz³y wyjœcia */
	and,	/**< bramka and */
	nand,	/**< bramka nand */
	or,		/**< bramka or */
	nor,	/**< bramka nor */
	xor,	/**< bramka xor */
	xnor,	/**< bramka xnor */
	neg,	/**< bramka neg */
} bramka;


/** Element listy jednokierunkowej przechowywuj¹cej bramki logiczne. */
struct lista {					//element listy jednokierunkowej przechowywuj¹cej bramki
	bramka typ;					//< typ bramki
	int w1;						//< pierwsze wejœcie bramki
	int w2;						//< drugie wejœcie bramki (nieu¿ywane w przypadku bramki neg)
	int wy;						//< wyjœcie bramki
	int stanP;					//< stan bramki jeden takt wczeœniej
	int stan;					//< aktualny stan bramki
	struct lista* nast;			///< adres nastêpnego elementu listy
};

/** Element listy jednokierunkowej przechowywuj¹cej stany wejœæ. */
struct wymuszenia {				//element listy jednokierunkowej przechowywuj¹cej stany wejœæ
	int* tab;					//< tabela przechowuj¹ca stany poszczególnych wejœæ
	int takty;					//< iloœæ taktów dla poszczególnych stanów wejœæ uk³adu
	struct wymuszenia* nast;	///< adres nastêpnego elementu listy
};

#endif
