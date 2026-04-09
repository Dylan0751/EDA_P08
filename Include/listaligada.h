#ifndef LISTALIGADA_H
#define LISTALIGADA_H
#include "nodo.h"

typedef struct DLista DLista; 

struct DLista{
    Nodo* head;
    Nodo* tail;

};

DLista* lista_crear();
bool lista_es_vacia(DLista *l);

bool lista_insertar_vacia(DLista *l, void *info, size_t size);
bool lista_insertar_inicio(DLista *l, void *info, size_t size);
bool lista_insertar_fin(DLista *l, void *info, size_t size);
bool lista_insertar_x_posicion(DLista *l, void *info, size_t size);
void lista_eliminar_inicio(DLista *l);
void lista_eliminar_fin();
void lista_eliminar_x_posicion();

#endif