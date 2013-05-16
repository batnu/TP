#ifndef _CARTON__H
#define _CARTON__H

/**
	\file Carton.h
	\brief Módulo con funciones para el funcionamiento
		   de los cartones del bingo.
	\author Pedro Sánchez León
	\version 1.0.0
	\date 2013
*/


/**
	\brief Nombre del TDA Carton.
	\name Carton
	\typedef Carton
*/

typedef void * Carton;

/// Número de líneas de un cartón.

#define NLINEAS 3

/**
	\brief Devuelve un nuevo cartón.
	\return Carton
*/

Carton CartonCrea();

/**
	\brief Destruye el cartón c.
	\param Carton c
	\return el carton creado
*/

void CartonLibera(Carton c);

/**
	\brief Imprime por pantalla la línea i del cartón c.
	\pre 1<=i<=NLINEAS
*/

void CartonImprimeLinea(Carton c, int i);

/**
	\brief Marca en el cartón c la bola b y devuelve:
	       0, si no se ha producido línea ni bingo.
		   1,2,3 (NLINEAS), si se ha producido línea en la línea 1,2,3
	       y 4 (NLINEAS+1), si se ha producido bingo
	\param c contiene el carton
	\param b la bola
	\return entero dentro del dominio [0, 4]
*/

int CartonMarca(Carton c, int b); 

#endif
