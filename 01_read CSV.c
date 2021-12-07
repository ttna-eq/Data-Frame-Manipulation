#include <stdio.h>

int main()
{
    // To input the file name in case that we want to read another file
    
    /* 
    const int file_size = 50;
    char file_name[file_size];
    printf("Please enter the location of .csv file: ");
    gets(file_name);
    */
    
    // in this case file_name is "test1.csv"

    char file_name[] = "test1.csv";
    
    FILE* in_file = fopen(file_name,"r");
    if (in_file == NULL)
    {
        perror("Error! The file doesn't exist.");
        exit(1);
    }

    char line[200];

    while(fgets(line, sizeof(line), in_file))
    {
        char *token;

        token = strtok(line, "ม");
        while(token){
            printf("%-s", token);
            token =strtok(NULL, ",");
        }
        printf("\n");
    }
    fclose(in_file);
    return 0;
}
