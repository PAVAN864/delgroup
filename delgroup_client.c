/* 
    *Program in C to mimic the “delgroup” command on Linux. This command will delete a group. 
    *It handles 2 files “gshadow” and “group”. Both these files are in some folder 
    specified by an environment variable PFILE. 
    *The program takes all arguments as command line arguments 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "delgroup_server.h"
int main()
{
    FILE *group;
    FILE *tempFile;
    FILE *gshadow;
    FILE *tempFile1;
    char path[100] = "C:/Abhi/C_prj2/group";    //Path of group file
    char path1[100] = "C:/Abhi/C_prj2/gshadow"; //Path of gshadow fie
    char word[20];
    char str[50];
    int line, col;
    int line1, col1;
    scanf("%[^\n]s", str);

    /*Verify whether the oeration is valid*/
    if (startswith(str,"delgroup")==0)
    {
        printf("Invalid Operation\n");
        exit(0);
    }

    /* Extracting the group name to be deleted from the user input */

    char *p = strchr(str, ' ');
    int k = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        word[k++] = str[i];
        if (str[i] == ' ')
        {
            k = 0;
        }
    }
    word[k] = '\0';

    group = fopen(path, "r");                 //Open group file in read mode
    tempFile = fopen("delete-line.tmp", "w"); //Open temporary file in write mode
    gshadow = fopen(path1, "r");              //Open gshadow file in read mode
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
    if (line != -1 && line == line1 && col + 1 == 1 && col1 + 1 == 1)
    {
        /* Move file pointer to beginning of file */
        rewind(group);
        rewind(gshadow);

        /* Delete group entry from group and gshadow files */
        deleteLine(group, tempFile, line + 1);
        deleteLine(gshadow, tempFile1, line1 + 1);

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
        printf("Removing group '%s' ...\n Done", word);
    }
    else
        printf("The Group '%s' does not exist.", word); //Throw an error if Group doesn exist
    return 0;
}
