#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "delgroup_server.h"
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

int startswith(const char *a, const char *b)
{
   if(strncmp(a, b, strlen(b)) == 0) return 1;
   else
    return 0;
}