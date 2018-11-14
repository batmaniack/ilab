#include "funk.h"

int
main ()
{
  FILE *onegin = fopen ("Onegin.txt", "r");
  int size = CalculateSize (onegin);
  fclose (onegin);
  char *buf = (char *) calloc (size + 1, sizeof (char));
  int size1 = ReadData (buf, size);
  if (size == size1)
    {
      int counter = CountAndChange (buf, size);
      char **text = (char **) calloc (counter + 1, sizeof (char *));
      int m = Texting (buf, text, counter, size);
      if (m == counter)
	{
	  qsort (text, counter, sizeof (char *), &CompareStrings);
    WriteData (text, counter);
	  return 0;
	}
      else
	{
	  return ERROR;
	}
    }
  else
    {
      return ERROR;
    }
}
