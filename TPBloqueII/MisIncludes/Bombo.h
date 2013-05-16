#ifndef _BOMBO__H
#define _BOMBO__H

// Nombre del TDA Bombo

typedef void * Bombo;

// Devuelve un nuevo bombo con números enteros aleatorios entre 1 y n
// Req: n>1

Bombo BomboCrea(int n);

// Destruye el bombo b

void BomboLibera(Bombo b);

// Extrae y devuelve una bola del bombo b
// Req: El bombo b no es vacío

int BomboExtrae(Bombo b);

// Devuelve 1 (cierto) si el bombo b está vacío y 0 en caso contrario

int BomboVacio(Bombo b); 

#endif
