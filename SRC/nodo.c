#include "nodo.h"

Nodo *nodo_crear(void *info, size_t size){
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));

    if(!nuevo) return NULL;

    nuevo->info = malloc(size);

    if(!nuevo->info){
        free(nuevo);
        return NULL;
    }
    memcpy(nuevo->info, info, size);
    nuevo->sig = nuevo->ant = NULL;
    
    return nuevo;
}

void nodo_eliminar(Nodo *nodo){
    if(nodo != NULL){
       
        free(nodo->info);
        free(nodo);
    
    }else{
        printf("El nodo no se pude liberar\n");
    }
}

bool nodo_actualizar(Nodo *nodo, void *info, size_t size){
    if(!nodo) return false;

    void *temp = realloc(nodo->info, size);
    if(!temp) return false;

    nodo->info = temp;
    memcpy(nodo->info, info, size);

    return true;
}    