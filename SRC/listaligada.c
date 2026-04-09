#include "listaligada.h"

DLista* lista_crear(){
    DLista *l = (DLista *)malloc(sizeof(DLista));
    l->head = l->tail = NULL;

    return l;
}

bool lista_es_vacia(DLista *l){
    return lista->head == NULL;
}


bool lista_insertar_vacia(DLista *l, void *info, size_t size){
    if(l == NULL) return false;
    Nodo *n = nodo_crear(info, size);
    l->head = l->tail = n;

    return true;
}

bool lista_insertar_inicio(DLista *l, void *info, size_t size){
    if(!l) return;

    Nodo *nuevo = nodo_crear(info, size);
    nuevo->sig = l->head;
    l->head->ant = nuevo;
    l->head = nuevo;
}

bool lista_insertar_fin(DLista *l, void *info, size_t size){
    if(!l)return;

    Nodo *nuevo = nodo_crear(info, size);
    nuevo->sig = 
}
bool lista_insertar_x_posicion(DLista *l, void *info, size_t size);