
#include<stdio.h>
#include <time.h>
#include "banco.h"

int main(){

    Lista atendiendo;
    atendiendo = lista_crearLista();
  
    int i,j, k, cliente, tiempo;
    
    Nodo *aux, *m;
    ///////////////
    for (i=1; i<101; i++) {
        printf("Fila de espera:\n");
        if (i % 2 == 0) {
            //Generador de clientes
            cliente = rand() %10 +1;
           for (j=1; j<cliente; j++){
               tiempo = rand() %5 +1;
               m = malloc(sizeof(Nodo));
               *m = lista_crearNodo(j, tiempo);
                lista_agregar(&atendiendo, m);
                printf("Cliente %d\t",m->numerocliente);
        }
        }
        if (i >= 3) {
            aux = atendiendo.cabeza;
            printf("\n");
            for (k=1; k<6; k++){
                tiempo = rand() %5 +1;
                printf("Cajero %d  Cliente %d Espera %d minutos\n",k, aux->numerocliente, aux->tiempo);
                aux->tiempo = aux->tiempo -1;
                if(aux->tiempo == 0){
                    listas_borrarNodo(&atendiendo, aux);
                }
                    aux = aux->siguiente;
                }
        }
        if (i == 1 | i==2) {
        printf("\n");
        for (k=1; k<6; k++){
            printf("Cajero %d\n", k);
        }
        }
        
        printf("Minuto : %d\n", i);
        getchar();
    }
    }
    

