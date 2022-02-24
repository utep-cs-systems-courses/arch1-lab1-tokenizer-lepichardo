#include <stdio.h>
#include <stdlib.h>
#include "history.h"

struct litem{
  struct litem *before, *after;
  char *str;
};
struct litem head;




List* init_history(){
  head.before = head.after = &head;
  return head;
}

void add_history(List *list, char *str){}

char *get_history(List *list, int id){}

void print_history(List *list){}

void free_history(List *list){}
