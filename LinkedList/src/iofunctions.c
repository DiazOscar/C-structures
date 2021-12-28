#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void escribirFichero(char filename[], LinkedList linkedList)
{
    FILE *fptr;

    if ((fptr = fopen(filename, "w")) == NULL)
    {
        printf("Error!");
        exit(1);
    }
    else
    {
        if (linkedList == NULL)
        {
            printf("Lista vacia\n");
        }
        else
        {
            while (linkedList != NULL)
            {
                fprintf(fptr, "#%d-%s\n", linkedList->id, linkedList->texto);
                linkedList = linkedList->next;
            }
        }
        fclose(fptr);
    }
}

void leerFichero(char filename[], LinkedList *linkedList)
{
    FILE *fptr;

    if ((fptr = fopen(filename, "r")) == NULL)
    {
        printf("Error!");
        exit(1);
    }
    else
    {
        if (*linkedList == NULL)
        {
            printf("Lista vacia\n");
        }
        else
        {
            char c;
            int ia;
            char texto[20];

            while ((c = getc(fptr)) != EOF)
            {
                if (c == '#' ){
                    char n = getc(fptr);
                    ia = n - '0';
                    printf("%d", ia);
                }else if(c == '-'){
                	int i;
                    for( i = 0;(c = getc(fptr))!= '\n'; i++){
                    	texto[i]=c;
                    }
                    texto[i++] = '\0';
                    printf("%s\n", texto);
                    pushNodo(linkedList, ia, texto);
                }
                    
            }
        }
        fclose(fptr);
    }
}
