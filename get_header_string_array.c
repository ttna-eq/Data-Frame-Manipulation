#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "count_row_column.h"

void get_header(char filename[], int column, char* str)
{
    FILE* fp = fopen(filename, "r");

    if(fp == NULL)
    {
        perror("Cannot open flie.");
        exit(1);
    }

    char line[100], header_str[20];

    fgets(line, 100, fp);

    int i, comma_count = 0, buff = 0;

    for(i = 0; i<strlen(line); i++)
    {
        if(line[i] == ',')
            comma_count++;

        else if(comma_count == column)
        {
            header_str[buff] = line[i];
            buff++;
        }
    }

    if(column == count_column(filename) - 1) // in case for the last column string have "\n", so we replace it with NULL
    {
        header_str[buff-1] = NULL;
    }
    else // to identify the stop point of the string
        header_str[buff] = NULL;

    strcpy(str, header_str);

}
