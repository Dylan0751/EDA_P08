#include <stdio.h>
#include "listaligada.h"

// Función para comparar enteros
int comparar_int(void *a, void *b){
    int x = *(int*)a;
    int y = *(int*)b;
    return x - y;
}

// Función para imprimir enteros
void imprimir_int(void *a){
    printf("%d ", *(int*)a);
}

int main(){

    DLista *lista = lista_crear();

    int a = 10, b = 20, c = 10, d = 30, e = 10;
    printf("num de nodos sin haber insertado: %d \n",lista_num_nodos(lista));
    // Insertar elementos
    lista_insertar_fin(lista, &a, sizeof(int));
    lista_insertar_fin(lista, &b, sizeof(int));
    lista_insertar_fin(lista, &c, sizeof(int));
    lista_insertar_fin(lista, &d, sizeof(int));
    lista_insertar_fin(lista, &e, sizeof(int));

    printf("num de nodos insertados: %d \n",lista_num_nodos(lista));

    printf("Lista original:\n");
    imprimir_lista(lista, imprimir_int);
    printf("\n");

    // Eliminar un elemento (solo el primero que encuentra)
    eliminarPorElemento(lista, &a, comparar_int);

    printf("Despues de eliminar un 10:\n");
    imprimir_lista(lista, imprimir_int);
    printf("\n");

    // Eliminar todos los elementos iguales
    eliminarElementosIguales(lista, &a, comparar_int);

    printf("Despues de eliminar todos los 10:\n");
    imprimir_lista(lista, imprimir_int);
    printf("\n");

    // Liberar memoria
    lista_eliminar(lista); 

    return 0;
}