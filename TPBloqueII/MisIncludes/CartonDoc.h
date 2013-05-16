#ifndef _CARTON__H
#define _CARTON__H

/**
	\file Carton.h
	\brief M�dulo con funciones para el funcionamiento
		   de los cartones del bingo.
	\author Pedro S�nchez Le�n
	\version 1.0.0
	\date 2013
*/


/**
	\brief Nombre del TDA Carton.
	\name Carton
	\typedef Carton
*/

typedef void * Carton;

/// N�mero de l�neas de un cart�n.

#define NLINEAS 3

/**
	\brief Devuelve un nuevo cart�n.
	\return Carton
*/

Carton CartonCrea();

/**
	\brief Destruye el cart�n c.
	\param Carton c
	\return el carton creado
*/

void CartonLibera(Carton c);

/**
	\brief Imprime por pantalla la l�nea i del cart�n c.
	\pre 1<=i<=NLINEAS
*/

void CartonImprimeLinea(Carton c, int i);

/**
	\brief Marca en el cart�n c la bola b y devuelve:
	       0, si no se ha producido l�nea ni bingo.
		   1,2,3 (NLINEAS), si se ha producido l�nea en la l�nea 1,2,3
	       y 4 (NLINEAS+1), si se ha producido bingo
	\param c contiene el carton
	\param b la bola
	\return entero dentro del dominio [0, 4]
*/

int CartonMarca(Carton c, int b); 

#endif
