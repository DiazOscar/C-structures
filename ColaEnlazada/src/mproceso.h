#ifndef MPROCESOS_H_
#define MPROCESOS_H_

// definicion de tipos
typedef struct nodo *LProc;

struct nodo
{
    /* data */
    int id;
    LProc next;
};

void crear(LProc *lroundrobin);

void anadirProceso(LProc *lroundrobin, int idproc);

void ejecutarProceso(LProc lroundrobin);

void eliminarProceso(int id, LProc *lista);

void escribirFichero(char * fName, LProc *lista);

#endif
