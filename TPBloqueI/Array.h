#ifndef __ARRAY_H
#define __ARRAY_H

/**
   \file Array.h
   \brief M�dulo con funciones para manejo de array.
   \author Siro D�az Palaz�n y Pedro S�nchez Le�n
   \version 1.0
   \date 2013
*/

#include <stdio.h>

/**
   \name Array
   \typedef Array
*/
typedef void * Array;


/**
   \brief Crea y devuelve un array de tama�o n = lsup-linf+1
          con los n�meros enteros comprendidos entre los l�mites
          linf y lsup, asignados al array de forma aleatoria.
          El array contendr� finalmente una permutaci�n con los
          n�meros enteros comprendidos entre dichos l�mites.
   \post linf<=lsup
   \param linf El l�mite inferior.
   \param lsup El l�mite superior.
*/
Array ArrayCreaAleatorio(int linf, int lsup);

/**
   \brief Destruye el array a.
   \param a El array.
*/
void ArrayLibera(Array a);

/**       
   \brief Imprime por pantalla el array a con formato:
          Array: a_1 a_2 . . . a_n
          Por ejemplo, el array {4,6,3,5} se imprimir�a como:
          Array: 4 6 3 5
   \param a El array.
*/
void ArrayImprime(Array a);

/**
   \brief Crea y devuelve un array cuyos elementos han sido
          leidos desde un fichero de texto con descriptor de fichero f.
          Req: El formato del fichero de lectura es el siguiente:
          n v_1 v_2 . . . v_n
          con n>0.
          Por ejemplo, el array {4,6,3,5} estaria en el fichero como:
          4 4 6 3 5
   \param f El fichero.
*/
Array ArrayCreaFichero(FILE * f);

/**
   \brief Imprime en el fichero de texto con descriptor de fichero f
          los elementos de un array dinamico con el siguiente
          formato:
          n v_1 v_2 . . . v_n
          Por ejemplo, el array {4,6,3,5} se imprimiria como:
          4 4 6 3 5
   \param a El array.
   \param f El fichero.
*/
void ArrayImprimeFichero(Array a, FILE * f);

/**
   \brief Crea y devuelve un array de tama�o n con sus elementos
          inicializados a cero e indexados desde 1 hasta n.
   \post n>0
   \param n Tama�o del array.
*/
Array ArrayCrea(int n);

/**
   \brief Crea y devuelve un subarray del array a comprendido
          entre los �ndices i y j.
   \pre 1<=i<=j<=ArrayTam(a)
   \param a El array.
   \param i Limite inferior
   \param j Limite superior
*/
Array ArrayCreaSubarray(Array a, int i, int j);

/**
   \brief Devuelve el tama�o del array a.
   \param a El array.
*/
int ArrayTam(Array a);

/**
   \brief Asigna el entero e en el �ndice i del array a.
   \pre 1<=i<=ArrayTam(a)
   \param a El array.
   \param i Indice.
   \param e Numero entero.
*/
void ArrayAsigna(Array a, int i, int e);

/**
   \brief Devuelve el entero e que ocupa el �ndice i del array a.
   \pre 1<=i<=ArrayTam(a)
   \param a El array.
   \param i El indice
*/
int ArrayRecupera(Array a, int i);

/**
   \brief Ordena de forma creciente los elementos del array a en O(n^2)
          o inferior, donde n es ArrayTam(a).
   \param a El array.
*/
void ArrayOrdena(Array a);

/**
   \brief Comprueba si hay algun error al leer de un fichero y si no hay error lee los enteros
   \param file El fichero.
   \param n Donde se almacena el entero.
*/
int leeEnteroError(char * file, int * n);

#endif
