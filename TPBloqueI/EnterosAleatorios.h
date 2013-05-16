#ifndef __ENTEROS_ALEATORIOS_H
#define __ENTEROS_ALEATORIOS_H


/**
   \file EnterosAleatorios.h
   \brief M�dulo con funciones para manejo de enteros aleatorios
          dentro de unos l�mites inferior y superior.
   \author Siro D�az Palaz�n y Pedro S�nchez Le�n
   \version 1.0
   \date 2013
*/

/**
   \brief Lee por teclado dos enteros linf y lsup,
          tales que linf<=lsup.
   \post linf<=lsup
   \param linf El l�mite inferior.
   \param lsup El l�mite superior.
*/
void LimitesLee(int * linf, int * lsup);

/**
   \brief Imprime por pantalla los enteros linf y lsup con formato:
          Limites: [linf,lsup]
   \pre linf<=lsup
   \param linf El l�mite inferior.
   \param lsup El l�mite superior.
*/

void LimitesImprime(int linf, int lsup);

/**
   \brief Genera y devuelve un entero aleatorio entre los l�mites
          linf y lsup.
   \pre linf<=lsup
   \param linf El l�mite inferior.
   \param lsup El l�mite superior.
   \return El entero aleatorio generado.
*/
int EnteroAleatorio(int linf, int lsup);

/**
   \brief Imprime por pantalla un entero e con formatos:
          Entero: e
   \param e El entero.
*/
void EnteroImprime(int e);

#endif
