int CalculateSize (FILE * onegin)
{
  fseek (onegin, 0, SEEK_END);
  int size = ftell (onegin);
  fseek (onegin, 0, SEEK_SET);
  return size;
}

int ReadData (char buf[], int size)
{
  FILE *onegin = fopen ("baza.txt", "r");
  if (!onegin)
    {
      printf ("Cannot open baza.txt");
      return ERROR;
    };
  fread (buf, sizeof (char), size, onegin);
  fclose (onegin);
  return size;
};

int CountAndChange (char buf[], int size)
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

int Texting (char buf[], char *text[], int counter, int size)
{
  int i, m = 1;
  text[0] = &buf[0];
  for (i = 0; i < size; i++)
    if (buf[i] == '\0')
      {
	       text[m] = &buf[i + 1];
	        m++;
      }
  return m - 1;
}



Node* CreateNode(char** str)
{
  Node* newn = new Node;
  int len = strlen(*str)+1;
  newn->data = new char [len];
  newn -> data [len]= '\0';
  strcpy(newn->data,*str);
  newn -> next = NULL;
  newn -> prev = NULL;
  return newn;
}


int HashFunct(char** str)
{
  int len = strlen(*str)+1;
  int sum = 0;
  char letr[len]= {};
  strcpy(letr, *str);
   for ( int i = 0; i < len/3; i++ )
   {
     sum = sum + A*letr[i] ;
     printf("1 %d\n", sum);
     //sum =NUM1*abs( i+sum + letr[i] - NUM1 );

    }
     for ( int i = len/3; i < 2*len/3; i++ )
     {
       sum = sum + A*letr[i] ;
       printf("2 %d\n", sum);
       //sum =NUM1*abs( i+sum + letr[i] - NUM1 );

      }
      for ( int i = 2*len/3; i < len/3; i++ )
      {
        sum = sum + A*letr[i] ;
        printf("3 %d\n", sum);
        //sum =NUM1*abs( i+sum + letr[i] - NUM1 );

       }
  printf("4 %d\n", sum);
  sum =  sum/7;
//  printf("%d\n", sum);
  return sum;
}

Node* InsertNod(Node* cur_ptr, char** str)
{
  Node* newn = new Node;
  int len = strlen(*str)+1;
  newn->data = new char [len];
  newn -> data [len]= '\0';
  strcpy(newn->data, *str);
  newn -> next = cur_ptr;
  cur_ptr->prev = newn;
  return newn;
}


Node* Search_Node (char** str , Node* head)
{
Node* cur =  head;
for (;;)
{
if (strcmp(cur -> data, *str) != 0)
  {
    if (cur -> next != NULL)
    cur = cur -> next;
    else
    {
      printf("NE NASHEL\n");
      return NULL;
    }
  }
  else
    {
      printf("NASHEL %s\n", cur -> data);
      return cur;
    }
}
}

Node* Registr( char** text, List* lists )
{
  int a = HashFunct(text);
  if (lists[a].head  == NULL && lists[a].size == 0)
  {
    lists[a].head = CreateNode(text);
    lists[a].size++;
  } else
    {
      Node* newn =InsertNod(lists[a].head, text);
      lists[a].head= newn  ;
      lists[a].size++;
    }
}

void DeleteNode(char** text, List* lists)
{
  int a = HashFunct(text);
  Node* ptr =Search_Node(text  ,  lists[a].head);
  if ( ptr -> next == NULL && ptr -> prev == NULL)
  {
    printf("такого элемента нет\n");
  }
  if( ptr -> next == NULL && ptr -> prev != NULL)
  {
    (ptr-> prev) -> next = NULL;
    lists[a].size--;
  }
  if( ptr -> next != NULL && ptr -> prev == NULL )
  {
    (ptr-> next)-> prev = NULL;
    lists[a].size--;
  }
  if (ptr -> next != NULL && ptr -> prev != NULL)
  {
    (ptr-> prev) -> next = (ptr -> next);
    (ptr-> next)-> prev = (ptr -> prev);
    lists[a].size--;
  }
  delete []ptr->data ;
  ptr = NULL;
}

void DeleteAll (  List* list_ptr)
{
  for(int a = 0; a < SIZE; a++ )
  {
    if (list_ptr[a].size != 0)
    {
      Node* tmp = list_ptr[a].head;
      while (list_ptr[a].head != NULL)
      {
          list_ptr[a].head = tmp->next;
          delete []tmp->data;
          tmp->next = NULL;
          tmp = NULL;
      }
    }
  }
}

void WriteData (List* lists)
{
  FILE *sort = fopen ("graf.ods", "w");
  if (!sort)
    {
      printf ("Cannot open graf.ods");
    }
  for (int i = 0; i < SIZE; i++)
    {
      fprintf (sort, "%d; ", i);
    }
  fprintf(sort, "\n" );
  for (int i = 0; i < SIZE; i++)
    {
      fprintf (sort, "%d; ", lists[i].size);
    }
  fclose (sort);
}
