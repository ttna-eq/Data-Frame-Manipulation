#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "count_row_column.h"

double max_func(char filename[], int column)
{
    FILE* fp = fopen(filename, "r");
    char line[100];
    double val, max;
    int count_comma, buff, line_no = 0;
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
            
            if (line_no == 1) // assign first value to max
                max = val;


            else if (line_no > 1) // compare the value between max and val
            {
                if(val > max)
                    max = val;
            }

            line_no++;

        }

    fclose(fp);

    return max;
}

double min_func(char filename[], int column)
{
    FILE* fp = fopen(filename, "r");
    char line[100];
    double val, max;
    int count_comma, buff, line_no = 0;
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
            if (line_no == 1) // assign first value to max
                sscanf(val_str, "%lf", &max); // convert str into double


            else if (line_no > 1) // compare the value between max and val
            {
                sscanf(val_str, "%lf", &val); // convert str into double

                if(val < max)
                    max = val;
            }

            line_no++;

        }

    fclose(fp);

    return max;
}
