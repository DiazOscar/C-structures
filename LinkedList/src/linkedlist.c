#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

void iniciarLista(LinkedList *linkedList){
    *linkedList = NULL; //inicializo la estructura
}

int sizeLista(LinkedList linkedList){
	int n = 0;
	while(linkedList != NULL){
		n++;
		linkedList = linkedList->next;
	}
	return n;
}

int pushNodo(LinkedList *linkedList, int idproc, char texto[]){
        LinkedList nuevo = (LinkedList) malloc(sizeof(struct Nodo));

        if(nuevo == NULL){
            perror("No hay memoria.");
            return -1;
        }

        nuevo->id = idproc;
        strcpy(nuevo->texto, texto);
        nuevo->next = *linkedList;
        *linkedList = nuevo;

        return 0;
}

int insertAfter(int idPrevio, int idIns, char texto[], LinkedList *linkedList){
	LinkedList nodoInicial = *linkedList;
	while(*linkedList != NULL && idPrevio != (*linkedList)->id){
		*linkedList = (*linkedList)->next;
	}
	if(*linkedList != NULL){
		LinkedList nuevo = (LinkedList) malloc(sizeof(struct Nodo));
		if(nuevo == NULL){
			perror("No hay memoria.");
			return -1;
		}

		nuevo->id = idIns;
		strcpy(nuevo->texto, texto);
		nuevo->next = (*linkedList)->next;
		(*linkedList)->next = nuevo;

	}else{
		printf("No existe el nodo.\n");
	}

	*linkedList = nodoInicial;

	return 0;
}

void verNodo(LinkedList linkedList, int idproc){
    while(linkedList != NULL && idproc != linkedList->id){
        linkedList = linkedList->next;
    }

    if(linkedList != NULL){
        printf("Texto: %s\n", linkedList->texto);
    }else{
        printf("No existe el nodo\n");
    }
}

void listarNodos(LinkedList linkedList){
	if(linkedList == NULL){
		printf("Lista vacia\n");
	}else{
		while(linkedList != NULL){
		        printf("Id proc: %d \tTexto: %s\n", linkedList->id, linkedList->texto);
		        linkedList = linkedList->next;
		}
	}

}

void eliminarNodo(int id, LinkedList *linkedList){
	LinkedList previous, current;
	previous = NULL;
	current = *linkedList;

	while(current != NULL && current->id != id){
		previous = current;
		current = current->next;
	}

	if(current != NULL){
		if(previous == NULL){ //elimino el 1ï¿½
			*linkedList = current->next;
		}else{
			previous->next = current->next;
		}

		free(current);
	}else{
		printf("No existe el nodo\n");
	}

}

void destruirLista(LinkedList *linkedList){
	LinkedList current;
	while(*linkedList != NULL){
		current = *linkedList;
		*linkedList=(*linkedList)->next;
		free(current);
	}
}

void modificarNodo(int id, char texto[], LinkedList *linkedList){
	LinkedList posInicial = *linkedList;
	while(*linkedList != NULL && id != (*linkedList)->id){
	        *linkedList = (*linkedList)->next;
	    }

	if(*linkedList != NULL){
		strcpy((*linkedList)->texto, texto);
	}else{
		printf("No existe el nodo\n");
	}

	*linkedList = posInicial;
}
