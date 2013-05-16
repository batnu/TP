#ifndef _BOMBO__H
#define _BOMBO__H


/**
   \file Bombo.h
   \brief M�dulo con funciones para el funcionamiento del
   	   bombo de un bingo que realiza las acciones del juego.
   \author Pedro S�nchez Le�n y Siro D�az Palaz�n
   \version 1.0.0
   \date 2013
*/


/**
	\name Bombo
	\typedef Bombo
*/

typedef void * Bombo;

/**
   \brief Devuelve un nuevo bombo con n�meros enteros aleatorios entre 1 y n
   \pre n > 1
   \param n cantidad de n�meros a generar
   \return Bombo
*/

Bombo BomboCrea(int n);

/**
	\brief destruye el bombo b
	\param b Bombo
*/

void BomboLibera(Bombo b);

/**
	\brief Extrae y devuelve una bola del bombo b
	\pre El bombo b no es vac�o
	\param b Bombo
	\return entero aleatorio comprendido entre 1 y n
*/
int BomboExtrae(Bombo b);

/**
	\brief Devuelve 1 (cierto) si el bombo b est� vac�o y 0 en caso contrario
	\param b Bombo
	\return 1 o 0
*/

int BomboVacio(Bombo b); 

#endif
