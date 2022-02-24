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
  char *start = word_start(str);
  putchar(*start);
  printf("',end of the start\n\n");

  // This is the *word_terminator(char *word) method
  printf("Method *word_terminator(char *word)\n");
  printf("This is the word terminator,'");
  char *terminator = word_terminator(str);
  putchar(*terminator);
  printf("',end of terminator\n\n");

  // This is the count_words(char *str) method
  printf("Method count_words(char *str)\n");
  printf("The number of words in the string is: ");
  printf("%d\n\n",count_words(str));
  
  // This is the copy string(char *inStr, short len) method
  printf("Method *copy_str(char *inStr, short len)\n");
  printf("Printing the copy of the string...\n");
  char *newString = copy_str(str,sizeof(str));
  printf(newString);
  printf("\nCopy of the string printed successfully!\n\n");

  // This is the **tokenize(char* str) method
  printf("Method **tokenize(char* str)\n");
  printf("Tokenizing the string...\n");
  char **tokens = tokenize(str);
  printf("Tokenize done successfully!\n\n");

  // This is the print_tokens(char **tokens) method
  printf("Method print_tokens(char **tokens)\n");
  printf("Printing tokens...\n");
  print_tokens(tokens);
  printf("Tokens printed!\n\n");
  
  // This is the free_tokens(char **tokens) method
  printf("This is the free_tokens(char **tokens)\n");
  printf("Freeing tokens...\n");
  free_tokens(tokens);
  printf("Tokens have been freed\n");

  printf("\nMethods declared and initialized in history.c\n\n");
  printf("\n");
  
}
