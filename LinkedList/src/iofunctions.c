#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

void escribirFichero(char filename[], LinkedList linkedList){
	FILE *pFile;
	pFile = fopen(filename, "wb");

	if(pFile != NULL) {
		if (linkedList == NULL)
		{
			printf("Lista vacia\n");
		}
		else
		{
			while (linkedList != NULL)
			{
				fwrite(&(linkedList->id), sizeof(int), 1, pFile);
				fwrite(&linkedList->texto, sizeof(char), 20, pFile);



				linkedList = linkedList->next;
			}
		}
		fclose(pFile);
	}else{
		printf("FILE OPEN ERROR\n");
	}
}

void leerFichero(char filename[], LinkedList *linkedList){
	FILE * f;

		if((f = fopen(filename, "rb")) == NULL){
			perror("No se puede abrir el fichero");
		}else{
			int id = 0;
			int ida = 0;
			char texto[20];

			while(fread(&id, sizeof(int), 1, f )>0 && fread(texto, sizeof(char), 20, f)>0){

				if(ida==0){
					pushNodo(linkedList, id, texto);
				}else{
					insertAfter(ida, id, texto, linkedList);
				}

				ida=id;

				printf("Id: %d, Texto : %s \n", id, texto);
			}

			fclose(f);
		}
}
