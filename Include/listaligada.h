#ifndef LISTALIGADA_H
#define LISTALIGADA_H
#include "nodo.h"
#include <stdbool.h>
#include <stddef.h>


typedef struct DLista DLista; 

struct DLista{
    Nodo* head;
    Nodo* tail;

};

typedef int (*CompararFunc)(void*, void*);
typedef void (*ImprimirFunc)(void*);

DLista* lista_crear();
bool lista_es_vacia(DLista *l);

bool lista_insertar_vacia(DLista *lista, void *info, size_t size);
bool lista_insertar_inicio(DLista *lista, void *info, size_t size);
bool lista_insertar_fin(DLista *lista, void *info, size_t size);
bool lista_insertar_x_posicion(DLista *lista, void *info, size_t size, int pos);
void lista_eliminar_inicio(DLista *lista);
void lista_eliminar_fin(DLista *lista);
void lista_eliminar_x_posicion(DLista *lista, int pos);
int lista_num_nodos(DLista *lista);
void lista_eliminar(DLista *lista);
void imprimir_lista(DLista *lista, ImprimirFunc imprimir);
void eliminarPorElemento(DLista* lista, void* info, CompararFunc cmp);
void eliminarElementosIguales(DLista *lista, void *info, CompararFunc cmp);

#endif