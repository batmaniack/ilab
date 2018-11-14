#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
const int ERROR = -1;
const int ALPH_SIZE = 54;



int CalculateSize (FILE * onegin);
int ReadData (char buf[], int size);
int CountAndChange (char buf[], int size);
int Texting (char buf[], char *text[], int counter, int size);
int PrintText(char **text, int Nlines);
int CustomEncoding (char c);
int CompareStrings (const void *ptr1, const void *ptr2);
void myfree(double **data);
int WriteData (char **text, int Nlines);

#include "funk.c"
