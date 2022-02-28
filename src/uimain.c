#include <stdio.h>
#include "history.h"
#include "tokenizer.h"

void getString(){

  char c;
  printf("$ ");
  while((c = getchar()) != EOF && c!='\n'){
    putchar(c);
  }
  printf("\n");
  
}

int main(void){

  char str[] = " hello\tworld,\nhave a good one! ";

  /*

  printf("\nMethods declared and initialized in tokenizer.c\n\n");

  // This is the space_char(char c) method
  printf("Method space_char(char c)\n");
  printf("%d\n\n",space_char('g'));
  
  // This is the non_space_char(char c) method
  printf("Method non_space_char(char c)\n");
  printf("%d\n\n",non_space_char('g'));

  // This is the *word_start(char *str) method
  printf("Method *word_start(char *str)\n");
  printf("This is the start of the word,'");
  */
  char *start = word_start(str);
  /*
  putchar(*start);
  printf("',end of the start\n\n");

  // This is the *word_terminator(char *word) method
  printf("Method *word_terminator(char *word)\n");
  printf("This is the word terminator,'");
  */
  char *terminator = word_terminator(str);
  /*
  putchar(*terminator);
  printf("',end of terminator\n\n");

  // This is the count_words(char *str) method
  printf("Method count_words(char *str)\n");
  printf("The number of words in the string is: ");
  printf("%d\n\n",count_words(str));
  
  // This is the copy string(char *inStr, short len) method
  printf("Method *copy_str(char *inStr, short len)\n");
  printf("Printing the copy of the string...\n");
  */
  char *newString = copy_str(str,sizeof(str));
  /*
  printf(newString);
  printf("\nCopy of the string printed successfully!\n\n");

  // This is the **tokenize(char* str) method
  printf("Method **tokenize(char* str)\n");
  printf("Tokenizing the string...\n");
  */
  char **tokens = tokenize(str);
  /*
  printf("Tokenize done successfully!\n\n");

  // This is the print_tokens(char **tokens) method
  printf("Method print_tokens(char **tokens)\n");
  printf("Printing tokens...\n");
  print_tokens(tokens);
  printf("Tokens printed!\n\n");
  
  // This is the free_tokens(char **tokens) method
  printf("This is the free_tokens(char **tokens)\n");
  printf("Freeing tokens...\n");
  */
  free_tokens(tokens);
  /*
  printf("Tokens have been freed\n");

  */
    
  printf("Methods in tokenize.c work fine\n");
    
  printf("\nMethods declared and initialized in history.c\n\n");

  // This is the init_history() method
  printf("This is the init_history()\n");
  printf("Creating new list...\n");
  struct List *newList = init_history();
  printf("New list created!\n\n");

  // This is the add_history(List *list, char *str) method
  printf("This is the add_history(List *list, char *str)\n");
  printf("Adding new element to the list...\n\n");
  add_history(newList, "hello");
  add_history(newList, "world,");
  add_history(newList, "have");
  add_history(newList, "a");
  add_history(newList, "good");
  add_history(newList, "one!");

  //This is the *get_history(List *list, int id) method
  printf("This is the *get_history(List *list, int id)\n");
  printf("Returning element at id 3...\n");
  char *element = get_history(newList,3);
  printf(element);
  printf("\nDone\n\n");
  // This is the print_history(List *list) method
  printf("This is the print_history(List *list)\n");
  printf("Printing list...\n");
  print_history(newList);
  printf("List printed!\n\n");

  // This is the free_history(List *list) method
  printf("This is the free_history(List *list)\n");
  printf("Freeing history...\n");
  free_history(newList);
  printf("History freed!\n\n");
  print_history(newList);
  printf("\n");
  
}
