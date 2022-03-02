#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

char *getString(){
  char c;
  char *str = (char*)malloc(sizeof(char));
  int i = 0;
  // Loop to assign each charcater to str
  while((c = getchar()) != EOF && c!='\n'){
    *(str + i) = c;
    i++;
  }
  // Look for the first non space
  str = word_start(str);
  printf("\n");
  // Return str
  return str;
}

int main(void){
  // Variables used
  char **tokens;                            // Tokens to tokenize each string
  char *str = (char*)malloc(sizeof(char));  // String enterd by user
  struct s_List *history = init_history();  // List of history
  int inOut = 1;                            // int to know if we continue loop or not
  int id;                                   // id of history
  
  while(inOut){
    printf("\nEnter what you want to do next:(a to enter a string(followed by the string), p to print history, t to get specific id of the history as tokens, g to get a specific id of the history, f to free history, q to quit)\n>");
    char c;
    while((c = getchar()) == '\n');
    switch(c){
    case 'a':
      // Adding string to history
      str = getString();
      add_history(history, str);
      break;
    case 'p':
      // Printing history
      printf("\n");
      print_history(history);
      break;
    case 't':
      // Printing specific id of the history as tokens
      printf("Select id\n>");
      scanf("%d",&id);
      str = get_history(history, id);
      tokens = tokenize(str);
      print_tokens(tokens);
      free_tokens(tokens);
      break;
    case 'g':
      // Printing specific id of history
      printf("Select id\n>");
      scanf("%d",&id);
      str = get_history(history, id);
      printf(str);
      break;
    case 'f':
      // free the history
      printf("Freeing history...\n");
      free_history(history);
      break;
    case 'q':
      printf("Bye bye!\n\n");
      inOut = 0;
      break;
    case '\n':
      break;
    default:
      printf("Invalid character\n");
      break;
    }
  }
}
