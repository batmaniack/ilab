#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>


const long long int SIZE = 923;
const int ERROR = -1;
const int NUM1 = 123;
const int NUM2 = 522;
const int A = 13;



struct Node
{
  char* data;
  Node* next;
  Node* prev;
};

struct List
{
  Node* head;
  int size;
};

struct HashTable
{
  List* lists;
};

int CalculateSize (FILE * onegin);
int ReadData (char buf[], int size);
int CountAndChange (char buf[], int size);
int Texting (char buf[], char *text[], int counter, int size);

Node* CreateNode(char** str);
int HashFunct(char** str);
Node* InsertNod(Node* cur_ptr, char** str);
Node* Search_Node (char** str , Node* head);
Node* Registr( char** text, List* lists );

void DeleteNode(char** text, List* lists);
void DeleteAll (  List* list_ptr);

void WriteData (List* lists);


#include "funklist.cpp"
