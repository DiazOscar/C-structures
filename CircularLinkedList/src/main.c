//Oscar Diaz
#include <stdio.h>
#include <stdlib.h>
#include "mproceso.h"

void leerFichero(char *fileName, LProc *plan){
    FILE *f;
    if((f = fopen(fileName, "rb"))==NULL){
        perror("Error al leer");
    }else{
        int numproc;
        fread(&numproc, sizeof(int), 1, f);
        printf("Numero de procesos: %d \n", numproc);
        int proc[numproc];
        int i=0;

        while(fread(&proc[i], sizeof(int), 1, f)){
            anadirProceso(plan, proc[i]);
            i++;
        }        
    }
}

int main()
{
    LProc plan;

    printf("Creamos una lista vacia.\n");
    crear(&plan);
    ejecutarProceso(plan);

    anadirProceso(&plan, 5);
    anadirProceso(&plan, 3);
    anadirProceso(&plan, 4);
    anadirProceso(&plan, 1);

    ejecutarProceso(plan);

    eliminarProceso(4, &plan);

    ejecutarProceso(plan);

    escribirFichero("../files/fichero.txt", &plan);

    LProc plan2;
    crear(&plan2);
    leerFichero("../files/fichero.txt", &plan2);

    ejecutarProceso(plan2);
    escribirFichero("../files/plan2.txt", &plan2);
    return 0;
}
