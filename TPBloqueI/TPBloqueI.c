#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <errno.h>
#include <string.h>
#include "EnterosAleatorios.h"
#include "Array.h"

/**
   \file TPBloqueI.c
   \brief Módulo principal
   \author Siro Díaz Palazón y Pedro Sánchez León   
   \version 1.0
   \date 2013
*/

/**
   \brief Esta es la función principal
   
*/
int main()
{
    char nombre[10];
    int edad;
    printf("Hola mundo\n");
    printf("Dime tu nombre: ");
    scanf("%s",nombre);
    printf("Hola %s\n",nombre);
    printf("Dime tu edad: ");
    scanf("%d",&edad);
    while (edad < 0)              //si la edad es menor que 0
    {
        printf("Esta edad no es correcta por ser negativa, introduce una nueva edad: ");
        scanf("%d",&edad);
    }
    printf("Tu edad es %d\n",edad);
     
    srand(time(NULL)); 
    int linf = 0;
    int lsup = 0;
    int ernd = 0;     
    int opcion = 0;
    int f;
    int m;
    Array arnd = ArrayCreaAleatorio(linf,lsup);
    while(opcion!=11)
    {   
        printf("1. Imprimir en pantalla los limites actuales.\n");
        printf("2. Imprimir en pantalla el entero aleatorio actual.\n");
        printf("3. Imprimir en pantalla el array actual.\n");
        printf("4. Imprimir en un fichero el array actual.\n");
        printf("5. Leer desde teclado nuevos limites.\n");
        printf("6. Generar un nuevo entero aleatorio dentro de los limites actuales.\n");
        printf("7. Generar un nuevo array aleatorio dentro de los limites actuales.\n");
        printf("8. Leer desde un fichero un nuevo array.\n");
        printf("9. Crear un nuevo array como subarray del array actual.\n");
        printf("10. Ordenar el array actual.\n");
        printf("11. Salir.\n");
        printf("Introducir opcion (1-11): ");
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1: LimitesImprime(linf, lsup);break;
            case 2: EnteroImprime(ernd);break;
            case 3: ArrayImprime(arnd);break;
            case 4:{ 
                 char nombrefichero[30];  
                 printf("Introduce nombre de fichero: "); 
                 scanf("%s",nombrefichero);
                 FILE * f = fopen(nombrefichero,"w");
                 if (f==NULL) printf("No se puede abrir el archivo %s\n",nombrefichero);
                 else {
                      ArrayImprimeFichero(arnd,f); 
                      fclose(f);
                      ArrayImprime(arnd);
                 }
                 break;
            }
            case 5: LimitesLee(&linf,&lsup); LimitesImprime(linf,lsup);break;
            case 6: ernd = EnteroAleatorio(linf, lsup);EnteroImprime(ernd);break;
            case 7: ArrayLibera(arnd); arnd = ArrayCreaAleatorio(linf,lsup);ArrayImprime(arnd);break;
            case 8: {
                 char nombrefichero[30];  
                 printf("Introduce nombre de fichero: "); 
                 scanf("%s",nombrefichero);
                 FILE * f = fopen(nombrefichero,"r");                 
                 if (f==NULL) printf("No se puede abrir el archivo %s\n",nombrefichero);
                 else {
                     ArrayLibera(arnd);
                     arnd = ArrayCreaFichero(f);  
                     fclose(f);
                     ArrayImprime(arnd);                 
                 }
                 break;
                 }
            case 9: {
                 int i,j;
                 printf("Introduce los limites inferior y superior del subarray: ");
                 scanf("%d",&i);
                 scanf("%d",&j);           
                 if((1 <= i) && (i <= j) && (j <= ArrayTam(arnd))){
                       Array aux = arnd;
                       arnd = ArrayCreaSubarray(arnd,i,j);
                       ArrayLibera(aux);
                       ArrayImprime(arnd);
                 }else{
                       printf("El limite inferior tiene que ser menor o igual que el superior\n");
                 }
                 /*if ((int) leeEnteroError(f,&m)==0) printf("m = %d\n",m);
					else {
							printf("No se puede abrir el archivo %s\n",f);
							printf("Error numero %i\n",errno);
							printf("Descripcion: %s \n", strerror(errno));
						 }*/
                 ArrayImprime(arnd);
                 break;
                 }
            case 10: ArrayOrdena(arnd);ArrayImprime(arnd);break;
            case 11: ArrayLibera(arnd); printf("Salir\n");break;
            default: printf("opcion incorrecta, debe ser del 1 al 11.\n");break;
        }
    }
    system("pause");
    return 0;

}

