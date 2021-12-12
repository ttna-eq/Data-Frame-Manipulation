#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_row(char filename[])
{
    FILE* fp = fopen(filename, "r");
    if(fp == NULL)
    {
        perror("Cannot open the file");
        exit(1);
    }

    char line[100]; // create a string to contain each line

    int row = 0;

    while( fgets(line, 100, fp) != NULL )
        row++;  // plus 1 to row for each line counted

    fclose(fp);

    return row;
}

int count_column(char filename[])
{
    FILE* fp = fopen(filename, "r");
     if(fp == NULL)
    {
        perror("Cannot open the file");
        exit(1);
    }

    char line[100]; // create a string to contain each line

    int column = 0;

    fgets(line, 100, fp);
    for(int i = 0; i < strlen(line); i++)
    {
        if(line[i] == ',')  // for count the number of ',' which separates each column
            column++;
    }
    column++; // add the first column which is not separated by comma

    fclose(fp);

    return column;
}
