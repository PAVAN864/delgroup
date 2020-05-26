//Function declaration
int indexOf(FILE *srcfile, const char *word, int *line, int *col);
void deleteLine(FILE *srcfile, FILE *tempFile, const int line);
int startswith(const char *a, const char *b);