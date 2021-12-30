#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

// definicion de tipos
typedef struct Nodo *LinkedList;

struct Nodo
{
    /* data */
    int id;
    char texto[20];
    LinkedList next;
};

int sizeLista(LinkedList linkedList);

void iniciarLista(LinkedList *linkedList);

int pushNodo(LinkedList *linkedList, int idproc, char texto[]);

int insertAfter(int idPrevio, int idIns, char texto[], LinkedList *linkedList);

void verNodo(LinkedList linkedList, int idproc);

void listarNodos(LinkedList linkedList);

void eliminarNodo(int id, LinkedList *linkedList);

void destruirLista(LinkedList *linkedList);

void modificarNodo(int id,char texto[], LinkedList *linkedList);


#endif
