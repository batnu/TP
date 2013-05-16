#include <stdlib.h>
#include <stdio.h>
#include "Array.h"
#include "EnterosAleatorios.h"

/**
   \file Array.c
   \brief Módulo con funciones para manejo de array.
   \author Siro Díaz Palazón y Pedro Sánchez León
   \version 1.0
   \date 2013
*/

/**
   @struct ArrayRep
   @arg v int *
   @arg n int
*/
typedef struct {
        /**
         \param v
        */
        int * v;
        /**
         \param n
        */
        int n;
} ArrayRep;

/**
   @brief ArrayAp structure
*/
typedef ArrayRep * ArrayAp;

/**
   \brief Crea y devuelve un array de tamaño n = lsup-linf+1
          con los números enteros comprendidos entre los límites
          linf y lsup, asignados al array de forma aleatoria.
          El array contendrá finalmente una permutación con los
          números enteros comprendidos entre dichos límites.
   \pre linf<=lsup
   \param linf limite inferior
   \param lsup limite superior
*/

Array ArrayCreaAleatorio(int linf, int lsup)
{
    ArrayAp a=malloc(sizeof(ArrayRep));
    a->n=lsup-linf+1;
    a->v=malloc(sizeof(int)*(a->n));
    for(int i=0;i<a->n;i++) a->v[i]=linf+i;
    for(int j=0;j<a->n-1;j++) 
    {
        int k = EnteroAleatorio(j,a->n-1);
        int aux=a->v[j];
        a->v[j]=a->v[k];
        a->v[k]=aux;           
    }
    return a;
}

// Destruye el array a.
void ArrayLibera(Array a)
{
    ArrayAp ap=a;
    free (ap->v);
    free(ap);
}
 
          
// Imprime por pantalla el array a con formato:
// Array: a_1 a_2 . . . a_n
// Por ejemplo, el array {4,6,3,5} se imprimiría como:
// Array: 4 6 3 5
void ArrayImprime(Array a)
{
    ArrayAp ap = a;
    printf("Array:"); 
    for (int i=0;i<ap->n;i++) printf(" %d ",ap->v[i]); 
    printf("\n"); 
}
// Crea y devuelve un array cuyos elementos han sido
// leidos desde un fichero de texto con descriptor de fichero f.
// Req: El formato del fichero de lectura es el siguiente:
// n v_1 v_2 . . . v_n
// con n>0.
// Por ejemplo, el array {4,6,3,5} estaria en el fichero como:
// 4 4 6 3 5
Array ArrayCreaFichero(FILE * f)
{
    ArrayAp a=malloc(sizeof(ArrayRep));
    fscanf(f,"%d",&a->n);
    a->v=malloc(sizeof(int)*(a->n));
    for(int i=0;i<a->n;i++) fscanf(f,"%d",&a->v[i]);
    return a;
}

// Imprime en el fichero de texto con descriptor de fichero f
// los elementos de un array dinamico con el siguiente
// formato:
//     n v_1 v_2 . . . v_n
// Por ejemplo, el array {4,6,3,5} se imprimiria como:
//     4 4 6 3 5
void ArrayImprimeFichero(Array a, FILE * f)
{
    ArrayAp ap=a;
    fprintf(f,"%d",ap->n);
    for (int i=0;i<ap->n;i++) fprintf(f," %d",ap->v[i]);     
}
// Crea y devuelve un array de tamaño n con sus elementos
// inicializados a cero e indexados desde 1 hasta n.
// Req: n>0
Array ArrayCrea(int n)
{
    ArrayAp a=malloc(sizeof(ArrayRep));
    a->n=n;
    a->v=malloc(sizeof(int)*a->n);
    for(int i=0;i<a->n;i++) a->v[i]=0;
    return a;  
}
// Crea y devuelve un subarray del array a comprendido
// entre los índices i y j.
// Req: 1<=i<=j<=ArrayTam(a)
Array ArrayCreaSubarray(Array a, int i, int j)
{
    ArrayAp c = a;
    ArrayAp ap = malloc(sizeof(ArrayRep));
    ap->n=j-i+1;
    ap->v=malloc(sizeof(int)*(ap->n));
    for(int k=0;k<ap->n;k++) ap->v[k]=c->v[k+i-1];
    return ap;
}

// Devuelve el tamaño del array a.
int ArrayTam(Array a)
{
    ArrayAp ap=a;
    return ap->n;     
}
// Asigna el entero e en el índice i del array a.
// Req: 1<=i<=ArrayTam(a)
void ArrayAsigna(Array a, int i, int e)
{
    ArrayAp ap=a; 
    ap->v[i-1]=e;
}

// Devuelve el entero e que ocupa el índice i del array a.
// Req: 1<=i<=ArrayTam(a)
int ArrayRecupera(Array a, int i)
{
    ArrayAp ap=a;
    return ap->v[i-1];
}
// Ordena de forma creciente los elementos del array a en O(n^2)
// o inferior, donde n es ArrayTam(a).
void ArrayOrdena(Array a)
{
    ArrayAp ap=a;
    for (int i=0;i<ap->n-1;i++)
        for(int j=i+1;j<ap->n;j++)
            if(ap->v[j]<ap->v[i]) { int aux=ap->v[j]; ap->v[j]=ap->v[i]; ap->v[i]=aux; }
}
// Comprueba si hay error y lee los enteros del fichero
int leeEnteroError(char * file, int * n) {
    FILE * f = fopen(file,"r");
    if(f == NULL) return -1;
    fscanf(f,"%d", n);
    fclose(f);
    return 0;
}
