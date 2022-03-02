#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history(){
  List *list = malloc(sizeof(List));
  list->root = NULL;
  return list;
}

void add_history(List *list, char *str){
  Item *i = malloc(sizeof(Item));
  Item *t = list->root;

  i->str = str;
  i->next = NULL;
  if(t == NULL){
    i->id = 0;
    list->root = i;
  }
  else{
    while(t->next != NULL)
      t = t->next;
    i->id = t->id+1;
    t->next = i;
  }
}

char *get_history(List *list, int id){
  Item *t = list->root;
  for(t; t->id != id && t->next != NULL; t = t->next){
    printf("%d %d \n", t->id, id);
  }
  return t->str;
}

void print_history(List *list){
  int i = 0;
  Item *t = list->root;
  for(t; t != NULL; t = t->next, i++){
    printf("%d> ",i);
    for(char *a = t->str; *a!='\0'; a++)
      printf("%c",*a);
    printf("\n");
  }
}

void free_history(List *list){
  free(list);
}
