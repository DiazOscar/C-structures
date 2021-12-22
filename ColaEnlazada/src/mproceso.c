#include <stdio.h>
#include <stdlib.h>
#include "mproceso.h"

void crear(LProc *lroundrobin){
    *lroundrobin = NULL;
}

void anadirProceso(LProc *lroundrobin, int idproc){
    if(*lroundrobin == NULL){
        *lroundrobin = (LProc) malloc(sizeof(struct nodo));
        if(*lroundrobin == NULL){
            perror("No hay memoria \n");
            exit(-1);
        }
        (*lroundrobin)->id = idproc;
        (*lroundrobin)->next = (*lroundrobin);
    }else{
        LProc ultimo = (LProc) malloc(sizeof(struct nodo));
        if(ultimo == NULL){
            perror("No hay memoria \n");
            exit(-1);
        }
        ultimo->id = idproc;
        ultimo->next = (*lroundrobin)->next;//guardo en next del que inserto el 1º
        (*lroundrobin)->next = ultimo;// actualizo el next del penultimo
        (*lroundrobin) = ultimo;//puntero de la estructura ahora es el ultimo
    }
}

void ejecutarProceso(LProc lroundrobin){
    if(lroundrobin == NULL){
        printf("No hay procesos para ejecutar \n");
    }else{
         LProc aux = lroundrobin->next; //apuntamos al primer nodo de la lista

        //
        do
        {
            printf("id proc: %d \t", aux->id);
            aux = aux->next;
        } while (aux != lroundrobin->next);
        printf("\n");
    }
}

void eliminarProceso(int id, LProc *lista){ //siempre va a existir
    LProc previous, current;
    previous = *lista;
    current = (*lista)->next;

    while(current->id != id){
        previous = current;
        current = current->next;
    }

    if(current == previous){ //solo tengo un nodo
        *lista == NULL;
        free(current);
    }else{
        previous->next = current->next;
        if(*lista==current){ //ultimo de la lista
            *lista = previous;
        }

        free(current);
    }
}

void escribirFichero(char * fName, LProc *lista){
    int numProc = 0;
    FILE *f;

    //contar cuantos procesos tenemos
    LProc current = (*lista)->next; //primer elemento lista
    do
    {
        numProc++;
        current = current->next;
    } while (current != (*lista)->next);// comprobar que el current no es el 1º
    
    if((f=fopen(fName, "wb")) == NULL ){
        perror("No se puede abrir fichero");
    }else{
        fwrite(&numProc, sizeof(int), 1, f);
        current = (*lista)->next;
        if(numProc > 0){
            while (current != (*lista))
            {
                fwrite(&(current->id), sizeof(int), 1, f);
                (*lista)->next =current->next;
                free(current);
                current = (*lista)->next;
            }

            //salgo cuando solo queda 1 elemento
            fwrite(&(current->id), sizeof(int), 1, f);
            free(current);
            *lista =NULL;
        }

        fclose(f);

    }

}