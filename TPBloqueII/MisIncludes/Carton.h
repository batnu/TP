#ifndef _CARTON__H
#define _CARTON__H
// Nombre del TDA Carton.
typedef void * Carton;
// Número de líneas de un cartón.
#define NLINEAS 3
// Devuelve un nuevo cartón.
Carton CartonCrea();
// Destruye el cartón c.
void CartonLibera(Carton c);
// Imprime por pantalla la línea i del cartón c.
// Req: 1<=i<=NLINEAS
void CartonImprimeLinea(Carton c, int i);
// Marca en el cartón c la bola b y devuelve:
// 0, si no se ha producido línea ni bingo
// 1,2,3 (NLINEAS), si se ha producido línea en la línea 1,2,3
// 4 (NLINEAS+1), si se ha producido bingo
int CartonMarca(Carton c, int b); 
#endif
