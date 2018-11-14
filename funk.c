int
CalculateSize (FILE * onegin)
{
  fseek (onegin, 0, SEEK_END);
  int size = ftell (onegin);
  fseek (onegin, 0, SEEK_SET);
  return size;
}

int
ReadData (char buf[], int size)
{
  FILE *onegin = fopen ("Onegin.txt", "r");
  if (!onegin)
    {
      printf ("Cannot open Onegin.txt");
      return ERROR;
    };
//  char* buf = (char*) calloc(size+1, sizeof(csshar);
  fread (buf, sizeof (char), size, onegin);
  fclose (onegin);
  return size;
};

int
CountAndChange (char buf[], int size)
{
  int i, counter = 0;
  for (i = 0; i < size; i++)
    if (buf[i] == '\n')
      {
	buf[i] = '\0';
	counter++;
      }
  return counter;
}

int
Texting (char buf[], char *text[], int counter, int size)
{
  int i, m = 1;
  //char** text = (char**) calloc(counter+1, sizeof(char));
  text[0] = &buf[0];

  for (i = 0; i < size; i++)
    if (buf[i] == '\0')
      {
	text[m] = &buf[i + 1];
	m++;
      }
  return m - 1;
}

int
PrintText (char **text, int Nlines)
{
  int i = 0;
  for (i = 0; i < Nlines; i++)
    {
      printf ("%s\n", text[i]);
    }
}

int
CustomEncoding (char c)
{
  char alph[] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" };
  //scanf ("%*[!@#^$%&*()_+{}[];:''"",<.>/?~``\n]",buf);
  for (int i = 0; i <= ALPH_SIZE; ++i)
    if (c == alph[i])
      return i + 1;
}

int
CompareStrings (const void *ptr1, const void *ptr2)
{
  char *str1 = *((char **) ptr1);
  char *str2 = *((char **) ptr2);
  while ((*str1) != '\0' && (*str2) != '\0')
    {
      while (CustomEncoding (*str1) == 0)
	*str1++;
      while (CustomEncoding (*str2) == 0)
	*str2++;
      if (CustomEncoding (*str1) != CustomEncoding (*str2))
	return CustomEncoding (*str1) - CustomEncoding (*str2);
      *str1++;
      *str2++;
    }
  return ((*str1) == '\0') ? -1 : 1;
}

void
MyFree (double **data)
{
  free (*data);
  *data = NULL;
}

int
WriteData (char **text, int Nlines)
{ FILE *sort = fopen ("Sorted.txt", "w");
  if (!sort)			// Проверка открытия файла
    {
      printf ("Cannot open Sorted.txt");
      return ERROR;			//закрытие файла
    }
  int i = 0;
  for (i = 0; i < Nlines; i++)
    {
      fprintf (sort, "%s\n", text[i]);
    }
  fclose (sort);
  return Nlines;
};
