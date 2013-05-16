#include <stdio.h>
#include <stdlib.h>
#include "Array.h"
#include "Carton.h"
#define NCOLUMNAS 9


typedef struct{
        int carton [NLINEAS][NCOLUMNAS];
        int AciertosEnLinea[NLINEAS];
        int AciertosEnCarton;
} CartonRep;

typedef CartonRep * CartonAp;

// Devuelve un nuevo cartón

Carton CartonCrea()
{
    CartonAp c = malloc(sizeof(CartonRep));

    for(int i = 0; i < NLINEAS; i++)
        for(int j = 0; j < NCOLUMNAS; j++)
             c->carton[i][j] = 0;
                  
    for(int i = 0; i < NLINEAS; i++)
        c->AciertosEnLinea[i] = 0;
                  
    c->AciertosEnCarton = 0;
       
    for(int i = 0;i < NLINEAS;i++)
    {
        Array a = ArrayCreaAleatorio(0,NCOLUMNAS-1);
        for(int j = 1; j <= 5; j++)
        {
            int k = ArrayRecupera(a,j);
            c->carton[i][k] = 1;
        }
        ArrayLibera(a);
    }
       
    for(int j = 0;j< NCOLUMNAS; j++)
    {
        int noVacias = 0;
        for(int i = 0; i < NLINEAS; i++)
            if(c->carton[i][j]==1) noVacias++;
        if(noVacias > 0)
        {
            Array b = ArrayCreaAleatorio(1, 10);
            Array d = ArrayCreaSubarray(b, 1, noVacias);
            ArrayLibera(b);
            ArrayOrdena(d);
            int k = 1;
            for(int i = 0; i < NLINEAS; i++)
                if(c->carton[i][j] == 1)
                {
                    int e = ArrayRecupera(d, k);
                    c->carton[i][j]=e+j*10;
                    k++;      
                }
            ArrayLibera(d);              
        }             
    } 
    return c;
}

// Destruye el cartón c

void CartonLibera(Carton c)
{
     free(c);
}

// Imprime por pantalla la línea i del cartón c
// Req: 1<=i<=NLINEAS

void CartonImprimeLinea(Carton c, int i)
{
     CartonAp cp = c;
     for(int j = 0; j < NCOLUMNAS; j++)
         if(cp->carton[i-1][j] == 0)
             printf("__ ");    
         else
             printf("%2d ",cp->carton[i-1][j]);
     printf("\n"); 
}

// Marca en el cartón c la bola b y devuelve:
// 0, si no se ha producido línea ni bingo
// 1,2,3 (NLINEAS), si se ha producido línea en la línea 1,2,3
// 4 (NLINEAS+1), si se ha producido bingo

int CartonMarca(Carton c, int b)
{
    CartonAp cp = c;
    int j = (b-1) / 10;
    int i = 0;
    while(i < NLINEAS && (cp->carton[i][j]<b)) i++;
    if((i < NLINEAS) && (cp->carton[i][j] == b))
    {
        cp->AciertosEnLinea[i]++;
        cp->AciertosEnCarton++;
        if(cp->AciertosEnCarton == 5*NLINEAS) return NLINEAS+1;
        if(cp->AciertosEnLinea[i] == 5) return i + 1;  
    }    
    return 0;
}
