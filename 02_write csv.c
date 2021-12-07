#include <stdio.h>
#include <stdlib.h>

#define SIZE_NAME 20
#define SIZE_NAMELIST 10

int main()
{
    int i;


    FILE* in_file = fopen("test2_write_csv.csv", "w");

    char namelist[SIZE_NAMELIST][SIZE_NAME] = {"John","Henry","Bob","Mark","Manny","Alex","Isac","Mary","Laurent","Patrick"};
    int scorelist[SIZE_NAMELIST] = {10,15,12,13,5,20,19,15,3,4};

    if(in_file == NULL){
        perror("Error! The file doesn't exist.");
        exit(1);
    }

    fprintf(in_file, "Name, Score\n");

    for(int i = 0; i < SIZE_NAMELIST; i++)
        fprintf(in_file, "%s,%d\n", namelist[i], scorelist[i]);


    fclose(in_file);

    return 0;
}
