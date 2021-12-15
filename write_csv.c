#include <stdio.h>
#include <stdlib.h>
#include "get_header_string_array.h"

void write_csv(char filename[])
{
    int i, j;
    int row, column;
    char block[20];
    char header[20];

    FILE* in_file = fopen(filename, "w");


    printf("Enter the row: "); // not include the header line which represents the name of each column
    scanf("%d", &row);
    printf("Enter the column: ");
    scanf("%d", &column);

    printf("\nPlease insert the header of the file\n");

    for(i = 0; i < column; i++)
    {
        printf("Column %d: ", i+1);
        scanf("\n%s", &header);
        if(i == column - 1)
            fprintf(in_file, "%s\n", header);
        else
            fprintf(in_file, "%s,", header);
    }
    fclose(in_file);


    FILE* in_file2 = fopen(filename, "a");

    printf("\nInsert the data of \n");

    for(i = 0; i < row ; i++)
    {

        for(j = 0; j < column; j++)
        {
            get_header(filename, j, header);
            printf("Row %d_%s : ", i+1, header);
            scanf("\n%s", &block);
            if(j == column - 1)
                fprintf(in_file, "%s\n", block);
            else
                fprintf(in_file, "%s,", block);
        }

        printf("\n");
    }

    fclose(in_file2);

    printf("%s was created.\n", filename);
}
