#include "list.h"


int main ()
{
  FILE *baza = fopen ("baza.txt", "r");
  int size = CalculateSize (baza);
  fclose (baza);
  char *buf = new char[size];
  ReadData (buf, size);
  int counter = CountAndChange (buf, size);
  char **text = new char* [counter + 1];
  Texting (buf, text, counter, size);
  HashTable hash;
  List lists[SIZE] = {};
  hash.lists = lists;
  for (int i = 0; i < counter; i++)
  {
    int a = HashFunct(&text[i]);
    Registr(&text[i], lists);
  }
  WriteData (lists);
  return 0;
}
