//
//  banco.h
//  Banco
//
//  Created by Arturo Tamayo Gonzalez on 10/11/16.
//  Copyright © 2016 Arturo Tamayo Gonzalez. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct MiNodo{
    int numerocliente, tiempo;
    struct MiNodo* siguiente;
    struct MiNodo* anterior;
};
typedef struct MiNodo Nodo;

struct MiLista {
    Nodo* cabeza;
};
typedef struct MiLista Lista;

//Crear Nodo Lista
Nodo lista_crearNodo(int dato, int tiempo){
    Nodo n;
    n.numerocliente = dato;
    n.tiempo = tiempo;
    n.siguiente = malloc(sizeof(Nodo));
    n.siguiente = NULL;
    n.anterior = malloc(sizeof(Nodo));
    n.anterior = NULL;
    return n;
}
//Crear Lista
Lista lista_crearLista(){
    Lista l;
    l.cabeza = malloc(sizeof(Nodo));
    l.cabeza = NULL;
    return l;
}

//Agregar
void lista_agregar(Lista* l, Nodo* n){
    //caso especial cuando se ingresa un primer dato
    if(l->cabeza == NULL)
        l->cabeza = n;
    else{
        Nodo* aux= l->cabeza;
        //Navegar hasta que aux apunte al ultimo nodo de la lista
        while (aux->siguiente != NULL) {
            aux= aux->siguiente;
        }
        //Conectar nuevo nodo con el ultimo nodo de la lista
        aux->siguiente =n;
        n->anterior = aux;
    }
}
//Borrar
void listas_borrarNodo(Lista* l, Nodo* n){
    if(l->cabeza->numerocliente == n->numerocliente){
        l->cabeza = n->siguiente;
        l->cabeza->anterior = NULL;
    }
    else {
        n->anterior->siguiente = n->siguiente;
        //Si n no es el ultimo , ligar el anterior con el siguiente
        if(n->siguiente != NULL)
            n->siguiente->anterior = n->anterior;
    }
}

