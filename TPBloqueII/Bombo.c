#include <stdlib.h>
#include "Array.h"
#include "Bombo.h"

typedef struct{Array v; int n;} BomboRep;
typedef BomboRep * BomboAp;

// Devuelve un nuevo bombo con números enteros aleatorios entre 1 y n
// Req: n>1

Bombo BomboCrea(int n)
{
    BomboAp a = malloc(sizeof(BomboRep));
    a->v = ArrayCreaAleatorio(1, n);
    a->n = n;
    return a;
}
// Destruye el bombo b

void BomboLibera(Bombo b)
{
     BomboAp a = b;
     ArrayLibera(a->v);
     free(a);
}

// Extrae y devuelve una bola del bombo b
// Req: El bombo b no es vacío

int BomboExtrae(Bombo b)
{
    BomboAp a = b;
    a->n--;
    return ArrayRecupera(a->v,a->n+1);     
}

// Devuelve 1 (cierto) si el bombo b está vacío y 0 en caso contrario

int BomboVacio(Bombo b){
    BomboAp a = b;
    return (a->n== 0);
}
