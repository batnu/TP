#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Bombo.h"
#include "Carton.h"

int main(void)
{
    srand(time(NULL));
    int numCartones = 0;
    do
    {
        printf("Introduce el numero de cartones (mayor de 1): ");
        scanf("%d", &numCartones);
    }while(numCartones <= 1);
    printf("\n");
    
    Carton carton[numCartones];
    for(int i = 0; i < numCartones; i++)
    {
        carton[i] = CartonCrea();
        printf("Carton %d: \n\n",i+1);
        for(int j = 1; j <= NLINEAS; j++)
            CartonImprimeLinea(carton[i], j);
        printf("\n");
    }
    
    int bingo = 0;
    int linea = 0;
    Bombo a = BomboCrea(90);
    printf("Bola: ");
    while(!bingo){
        int bola = BomboExtrae(a);
        printf("%d ", bola);
        for(int k = 0; k < numCartones; k++){
            int result = CartonMarca(carton[k], bola);
            if(!bingo && result == NLINEAS + 1){
                printf("\nBingo en el carton %d: ", k + 1);
                for(int i = 0; i < NLINEAS; i++){
                    
                }
            }
        }
    }
    
    printf("\n");
    BomboLibera(a);
    
    for(int i = 0; i < numCartones; i++)
        CartonLibera(carton[i]);    
    
    system("pause");
    return 0;
}
