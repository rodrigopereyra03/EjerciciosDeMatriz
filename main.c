#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define C 5


void cargarMatriz(int m[][C], int t);
void mostrarMatriz(int m[][C],int t);
void calcularPromedioDeMatriz(int m[][C], int t, float prom);
void BuscarMinimoDeLaMatriz(int m[][C],int t);
void buscarMaximoDeLaMatriz(int m[][C], int t);
void sumaPorRenglones(int m[][C], int t);

int main()
{
    srand(time(NULL));
    int tam=5;
    int matriz[tam][C];
    cargarMatriz(matriz,tam);
    mostrarMatriz(matriz,tam);
    calcularPromedioDeMatriz(matriz,tam,C);
    BuscarMinimoDeLaMatriz(matriz,tam);
    buscarMaximoDeLaMatriz(matriz,tam);
    sumaPorRenglones(matriz,tam);


    return 0;
}

void cargarMatriz(int m[][C], int t){
    for(int i=0; i<t; i++){
        for(int j=0; j<C; j++){
            m[i][j]=10+rand()%90;
        }
    }

};
void mostrarMatriz(int m[][C],int t){
    printf("\n");
    for(int i=0; i<t; i++){
        for(int j=0; j<C; j++){
            printf("/ %d /",m[i][j]);
        }
        printf("\n");
    }
};
void calcularPromedioDeMatriz(int m[][C], int t, float prom){
    int suma=0;
    for(int i=0; i<t; i++){
        for(int j=0; j<C; j++){
            suma=suma+m[i][j];
        }
    }
    prom= ((float)suma)/(t*C);
    printf("\nEl promedio de la matriz es: %f",prom);

};
void BuscarMinimoDeLaMatriz(int m[][C],int t){
    int minimo=m[0][0];
    int posMinR=0;
    int posMinC=0;
    for(int i=0; i<t; i++){
        for(int j=0; j<C; j++){
            if(minimo > m[i][j]){
                minimo = m[i][j];
                posMinC=j;
                posMinR=i;
            }
        }
    }
    printf("\n\nEL MINIMO ES: %d y esta en: ( %d , %d )\n",minimo,posMinR, posMinC);

};
void buscarMaximoDeLaMatriz(int m[][C], int t){
    int maximo=m[0][0];
    int posMaxR=0;
    int posMaxC=0;
    for(int i=0; i<t; i++){
        for(int j=0; j<C; j++){
            if(maximo<m[i][j]){
                maximo=m[i][j];
                posMaxR=i;
                posMaxC=j;
            }
        }
    }
    printf("\nEl maximo de la matriz es: %d y esta en ( %d , %d )\n",maximo,posMaxR,posMaxC);

};

void sumaPorRenglones(int m[][C], int t){
    int acumulador;
    for(int i=0; i<t; i++){
            acumulador=0;
        for(int j=0; j<C; j++){
            acumulador=acumulador+m[i][j];
        }
        printf("\nLA SUMA DEL RENGLON: %d es %d\n",i,acumulador);
    }

};
