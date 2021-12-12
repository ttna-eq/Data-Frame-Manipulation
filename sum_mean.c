#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "count_row_column.h"

double sum_func(char filename[], int column)
{
    FILE* fp = fopen(filename, "r");
    char line[100];
    double sum, val;
    int count_comma, buff;
    char val_str[20];

    while( fgets(line, 100, fp) != NULL )
        {
            count_comma = 0;
            buff = 0;

            for(int i = 0; i < strlen(line); i++)
            {
                if(line[i] == ',')  // count how many comma read
                    count_comma++;
                else if(column == count_comma) // get string for the value from the specific column
                {
                    val_str[buff] = line[i];
                    buff++;
                }

            }

            sscanf(val_str, "%lf", &val); // convert str into double
            sum+=val;

        }

    fclose(fp);

    return sum;
}

double mean_func(char filename[], int column)
{
    return sum_func(filename,column)/ count_row(filename);
}
