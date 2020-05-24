/* Program in C to mimic the “delgroup” command on Linux. This command will delete a group. 
It handles 2 files “passwd” and “shadow”. Both these files are in some folder 
specified by an environment variable PFILE. 
The program takes all arguments as command line arguments */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Function declaration
int indexOf(FILE *srcfile, const char *word, int *line, int *col);
void deleteLine(FILE *srcfile, FILE *tempFile, const int line);
int main()
{
    FILE *group;    
    FILE *tempFile;
    FILE *gshadow;
    FILE *tempFile1;
    char path[100]="C:/Abhi/C_prj2/group";    //Path of group file
    char path1[100]="C:/Abhi/C_prj2/gshadow"; //Path of gshadow fie
    char word[20]; 
    char str[50];
    int line, col;
    int line1, col1;

    /* Extracting the group name to be deleted from the user input */
    scanf("%[^\n]s", str);
    char *p= strchr(str, ' ');
    int k = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        word[k++] = str[i];
        if (str[i] == ' ') {
            k = 0;
        }
    }
    word[k] = '\0';

    group = fopen(path, "r"); //Open group file in read mode
    tempFile = fopen("delete-line.tmp", "w"); //Open temporary file in write mode
    gshadow = fopen(path1, "r"); //Open gshadow file in read mode
    tempFile1 = fopen("delete-line1.tmp", "w");

    /* Exit program if unable to open file */
    if (group == NULL || gshadow == NULL || tempFile == NULL || tempFile1 == NULL)
    {
        printf("Error opening file.\n");
        exit(0);
    }

    /* Call function to check if a group exists and return it's index if found */
    indexOf(group, word, &line, &col); 
    indexOf(gshadow, word, &line1, &col1); 

    /*
    *Delete a group only if it's present in both group and gshadow files
    *Group name is always present in first column
        hence, delete a group only if it's present in first column
     */
    if (line != -1 && line == line1 && col+1==1 && col1+1==1)
        {
            /* Move file pointer to beginning of file */
            rewind(group);  
            rewind(gshadow); 

            /* Delete group entry from group and gshadow files */ 
            deleteLine(group, tempFile, line+1); 
            deleteLine(gshadow, tempFile1, line1+1); 

            /* Close all open files */
            fclose(group);
            fclose(gshadow);
            fclose(tempFile);
            fclose(tempFile1);

             /* Delete old group and gshadow file and rename tempfile, tempfile1 
             as group and gshadow repectively */
            remove(path);
            remove(path1);
            rename("delete-line.tmp", path);
            rename("delete-line1.tmp", path1);
            printf("Sucessfully deleted group");            
        }
    else
        printf("'%s' Group does not exist.", word); //Throw an error if Group doesn exist
    return 0;
}
/* Function
 * Finds, first index of a word in file. First index is represented
 * using line and column.
 */
int indexOf(FILE *srcfile, const char *word, int *line, int *col)
{
    char str[1000];
    char *pos;
    *line = -1;
    *col  = -1;
    while ((fgets(str, 1000, srcfile)) != NULL)
    {
        *line += 1;
        pos = strstr(str, word);

        if (pos != NULL)
        {
            *col = (pos - str);
            break;
        }
    }
    if (*col == -1)
        *line = -1;
    return *col;
}
/*
 * Function to delete a line from file.
 */
void deleteLine(FILE *srcfile, FILE *tempFile, const int line)
{
    char buffer[1000];
    int count = 1;
    while ((fgets(buffer, 1000, srcfile)) != NULL)
    {
        if (line != count)
            fputs(buffer, tempFile);
        count++;
    }
}