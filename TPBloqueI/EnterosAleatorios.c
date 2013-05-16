#include <stdlib.h>
#include <stdio.h>

/**
   \file EnterosAleatorios.c
   \brief Módulo con funciones para manejo de enteros aleatorios
   \author Siro Díaz Palazón y Pedro Sánchez León
   \version 1.0
   \date 2013
*/

// Lee por teclado dos enteros linf y lsup,
// tales que linf<=lsup.
void LimitesLee(int * linf, int * lsup)
{
    printf("Escribe el limite inferior:  ");
    scanf("%d",linf);
    printf("Escribe el limite superior:  ");
    scanf("%d",lsup);
    while (*linf>*lsup)
    {
          printf("El limite superior no puede ser menor que el limite inferior %d\n",*linf);
          printf("Escribe un nuevo limite superior: ");
          scanf("%d",lsup);
    }
}

// Imprime por pantalla los enteros linf y lsup con formato:
// Limites: [linf,lsup]
void LimitesImprime(int linf, int lsup)
{
     printf("Limites: [%d,%d]\n",linf,lsup);
}

// Genera y devuelve un entero aleatorio entre los límites     
// linf y lsup.
int EnteroAleatorio(int linf, int lsup)
{
    return linf+rand()%(lsup -linf+1);
}

// Imprime por pantalla un entero e con formato:
// Entero: e
void EnteroImprime(int e)
{
     printf("Entero: %d\n",e);
}
