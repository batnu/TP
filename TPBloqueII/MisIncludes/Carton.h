#ifndef _CARTON__H
#define _CARTON__H
// Nombre del TDA Carton.
typedef void * Carton;
// N�mero de l�neas de un cart�n.
#define NLINEAS 3
// Devuelve un nuevo cart�n.
Carton CartonCrea();
// Destruye el cart�n c.
void CartonLibera(Carton c);
// Imprime por pantalla la l�nea i del cart�n c.
// Req: 1<=i<=NLINEAS
void CartonImprimeLinea(Carton c, int i);
// Marca en el cart�n c la bola b y devuelve:
// 0, si no se ha producido l�nea ni bingo
// 1,2,3 (NLINEAS), si se ha producido l�nea en la l�nea 1,2,3
// 4 (NLINEAS+1), si se ha producido bingo
int CartonMarca(Carton c, int b); 
#endif
