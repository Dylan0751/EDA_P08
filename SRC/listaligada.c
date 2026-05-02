#include "listaligada.h"

DLista* lista_crear(){
    DLista *lista = (DLista *)malloc(sizeof(DLista));
    if(!lista) return NULL;
    
    lista->head = lista->tail = NULL;

    return lista;
}

bool lista_es_vacia(DLista *lista){
    return lista->head == NULL;
}


bool lista_insertar_vacia(DLista *lista, void *info, size_t size){
    if(lista == NULL) return false;
    
    Nodo *nuevo = nodo_crear(info, size);
    if(!nuevo) return false;

    lista->head = lista->tail = nuevo;

    return true;
}

bool lista_insertar_inicio(DLista *lista, void *info, size_t size){
    if(!lista) return false;
    
    if(lista_es_vacia(lista)){
        return lista_insertar_vacia(lista, info, size);
    } 

    Nodo *nuevo = nodo_crear(info, size);
    if(!nuevo) return false;

    nuevo->sig = lista->head;
    lista->head->ant = nuevo;
    lista->head = nuevo;

    return true;
}

bool lista_insertar_fin(DLista *lista, void *info, size_t size){
    if(!lista) return false;

    if(lista_es_vacia(lista)){
        return lista_insertar_vacia(lista, info, size);
    }

    Nodo *nuevo = nodo_crear(info, size);
    if(!nuevo) return false;

    nuevo->ant = lista->tail;
    lista->tail->sig = nuevo;
    lista->tail = nuevo;

    return true;
}

int lista_num_nodos(DLista *lista){
    if(!lista) return 0;
    int i = 0;
    for(Nodo *tmp = lista->head; tmp != NULL; tmp = tmp->sig, i++);
    return i;
}

void lista_eliminar_inicio(DLista *lista){
    if(!lista || lista_es_vacia(lista)) return;

    Nodo *tmp = lista->head;

    if(lista->head == lista->tail){
        lista->head = lista->tail = NULL;
    }else{
        lista->head = lista->head->sig;
        lista->head->ant = NULL;
    }
    
    nodo_eliminar(tmp);
}

void lista_eliminar_fin(DLista *lista){
    if(!lista || lista_es_vacia(lista)) return;

    Nodo *tmp = lista->tail;
    
    if(lista->head == lista->tail){
        lista->head = lista->tail = NULL;
    }else{
        lista->tail = lista->tail->ant;
        lista->tail->sig = NULL;
    }

    nodo_eliminar(tmp);

}

bool lista_insertar_x_posicion(DLista *lista, void *info, size_t size, int pos){
    if(!lista || pos < 0) return false;

    if(pos == 0){
        return lista_insertar_inicio(lista, info, size);
    }
    int n = lista_num_nodos(lista);
    if(pos == n){
        return lista_insertar_fin(lista, info, size);
    }

    if(pos > n) return false;

    Nodo *tmp = lista->head;
    for(int i = 0; i < pos-1; i++){
        tmp = tmp->sig;
    }

    Nodo *nuevo = nodo_crear(info, size);
    if(!nuevo) return false;

    nuevo->sig = tmp->sig;
    nuevo->ant = tmp;

    tmp->sig->ant = nuevo;
    tmp->sig = nuevo;

    return true;

}

void lista_eliminar_x_posicion(DLista *lista, int pos){
    if(!lista || lista_es_vacia(lista)) return;

    int n = lista_num_nodos(lista);

    if(pos == 0){
        return lista_eliminar_inicio(lista);
        return;
    }

    if(pos == n-1){
        return lista_eliminar_fin(lista);
        return;
    }

    if(pos >= n) return;

    Nodo *tmp = lista->head;
    for(int i = 0; i < pos; i++){
        tmp = tmp->sig;
    }

    tmp->ant->sig = tmp->sig;
    tmp->sig->ant = tmp->ant;

    nodo_eliminar(tmp);
}

void lista_eliminar(DLista *lista){
    if(!lista || lista_es_vacia(lista)) return;

    Nodo* actual = lista->head;

    while(actual){
        Nodo* temp = actual;
        actual = actual->sig;
        nodo_eliminar(temp);
    }

    free(lista);
}

void imprimir_lista(DLista *lista, ImprimirFunc imprimir){
    if(!lista || lista_es_vacia(lista)) return;

    Nodo* actual = lista->head;

    while(actual){
        imprimir(actual->info);
        actual = actual->sig;
    }
}

void eliminarPorElemento(DLista* lista, void* info, CompararFunc cmp){
    if(!lista || lista_es_vacia(lista)) return;

    Nodo *actual = lista->head;

     while(actual){
        if(cmp(actual->info, info) == 0){

            if(actual == lista->head){
                lista->head = actual->sig;
                if(lista->head){
                    lista->head->ant = NULL;
                }else{
                    lista->tail = NULL; 
                }
            }else if(actual == lista->tail){
                lista->tail = actual->ant;
                lista->tail->sig = NULL;
            }else{
                actual->ant->sig = actual->sig;
                actual->sig->ant = actual->ant;
            }

            nodo_eliminar(actual);
            return;
        }

        actual = actual->sig;
    }
}
void eliminarElementosIguales(DLista *lista, void *info, CompararFunc cmp){
     if(!lista || lista_es_vacia(lista) || !cmp) return;

    Nodo *actual = lista->head;

    while(actual){
        Nodo *siguiente = actual->sig; // 🔑 guardar antes de borrar

        if(cmp(actual->info, info) == 0){

            if(actual == lista->head){
                lista->head = actual->sig;  
                if(lista->head){
                    lista->head->ant = NULL;
                }else{
                    lista->tail = NULL;
                }
            }else if(actual == lista->tail){
                lista->tail = actual->ant;
                lista->tail->sig = NULL;
            }else{
                actual->ant->sig = actual->sig;
                actual->sig->ant = actual->ant;
            }

            nodo_eliminar(actual);
        }

        actual = siguiente; 
    }
}
