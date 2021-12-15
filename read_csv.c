#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_csv(char filename[])
{
    FILE* fp = fopen(filename, "r");

    if(fp == NULL)
    {
        perror("");
        exit(1);
    }

    char line[100];

    while(fgets(line, 100, fp))
    {
        char* tk;

        tk = strtok(line,",");
        while(tk != NULL){
            printf("%-10s",tk);
            tk = strtok(NULL, ",");
        }
        printf("\n");
    }

    return 0;
}
