#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main()
{
    LinkedList lista;
    iniciarLista(&lista);
    pushNodo(&lista, 1, "este es el 1");
    pushNodo(&lista, 2, "este es el 1");
    pushNodo(&lista, 3, "este es el 1");
    pushNodo(&lista, 4, "este es el 1");
    listarNodos(lista);

    modificarNodo(1,"nuevo texto", &lista);
    printf("\n");
    listarNodos(lista);

    eliminarNodo(7, &lista);
    printf("\n");
    listarNodos(lista);

    pushNodo(&lista, 7, "este es el 7");
    printf("\n");
    listarNodos(lista);

    printf("\n");
    modificarNodo(7, "Bla bla", &lista);
    listarNodos(lista);

    insertAfter(1, 8, "texto 8", &lista);
    printf("\n");
	listarNodos(lista);

    printf("\n");
    eliminarNodo(7, &lista);
    listarNodos(lista);

    printf("\n");
	destruirLista(&lista);
	listarNodos(lista);

    return 0;
}
