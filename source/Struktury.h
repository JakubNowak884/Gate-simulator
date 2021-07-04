#ifndef STRUKTURY_H
#define STRUKTURY_H

#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>

#define X 2

/**
 * \enum bramka
 * \typ bramki logicznej lub oznaczenie w�z��w wej�cia i wyj�cia
 */
typedef enum
{
	in,		/**< w�z�y wej�cia */
	out,	/**< w�z�y wyj�cia */
	and,	/**< bramka and */
	nand,	/**< bramka nand */
	or,		/**< bramka or */
	nor,	/**< bramka nor */
	xor,	/**< bramka xor */
	xnor,	/**< bramka xnor */
	neg,	/**< bramka neg */
} bramka;


/** Element listy jednokierunkowej przechowywuj�cej bramki logiczne. */
struct lista {					//element listy jednokierunkowej przechowywuj�cej bramki
	bramka typ;					//< typ bramki
	int w1;						//< pierwsze wej�cie bramki
	int w2;						//< drugie wej�cie bramki (nieu�ywane w przypadku bramki neg)
	int wy;						//< wyj�cie bramki
	int stanP;					//< stan bramki jeden takt wcze�niej
	int stan;					//< aktualny stan bramki
	struct lista* nast;			///< adres nast�pnego elementu listy
};

/** Element listy jednokierunkowej przechowywuj�cej stany wej��. */
struct wymuszenia {				//element listy jednokierunkowej przechowywuj�cej stany wej��
	int* tab;					//< tabela przechowuj�ca stany poszczeg�lnych wej��
	int takty;					//< ilo�� takt�w dla poszczeg�lnych stan�w wej�� uk�adu
	struct wymuszenia* nast;	///< adres nast�pnego elementu listy
};

#endif
