#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c){
  // Check if is white space or tab
  if (c == ' ' || c == '\t' || c == '\n'){
    // Return 1 if c is white space
    return 1;
  }
  // Return 0 if c is non white space
  return 0;
}

int non_space_char(char c){
  // Check if c is white space
  if (c == ' ' || c == '\t' || c == '\n'){
    // Return 0 is c is white space
    return 0;
  }
  // Return 1 if c is non white space
  return 1;
}

char* word_start(char *str){
  // We check through the string to check the next non space
  while(*str != '\0'){
    // Check if char is non space
    if(non_space_char(*str)){
      // Return the pointer the moment it is pointing to a nonspace char
      return str;
    }
    // Loop through the string with pointers
    str++;
  }
  // Case where we get out of the loop and the string consists of white spaces
  return str;
}

char* word_terminator(char *word){
  // Getting the pointer to be at the start of the word
  char *str = word_start(word);
  // Loop to iterate through the word
  while(*str != '\0'){ 
    // Check if the current char is white space
    if(space_char(*str)){
      // Return the current pointer
      return str;
    }
    // Loop through next pointer
    str++;
  }
  // Return pointer in case that the loop ended and the end is '\0'
  return str;
}

int count_words(char *str){
  // Declare i to keep track of the number of words in the string
  int i = 0;
  // Iterate through the string
  while(*str != '\0'){
    // if (word_start(str) && 
    // Looking for the first char of the word
    str = word_start(str);
    // Checking if word start returned valid start of a word
    if(*str == '\0'){
      // Return current number of words 
      return i;
    }
    // Looking for the last char of the word
    str = word_terminator(str);
    // Adding one to i since 1 start and 1 terminator
    // add up to 1 word in the string
    i++;
    
  }
  // Return i which will be the number of words in the string
  return i;
}

char *copy_str(char *inStr, short len){
  // Calling malloc to create the needed space in memory
  // for the new copy of the string
  char *outStr = (char*)malloc(len + 1);
  // int i to iterate through outStr and assign each pointer
  int i = 0;
  // Iterate thorugh inStr with the while loop
  while(*inStr != '\0'){
    // Assigning each character from inStr to outStr
    *(outStr + i) = *inStr++;
    // Increment i to keep iterating
    i++;
  }
  // Assigning last element in outStr to \0
  *(outStr + len) = '\0';
  // Returning the copy of the string
  return outStr;
}

char **tokenize(char* str){
  // Calling method to know how many words the string has
  int wordsInStr = count_words(str);
  // Creating the needed space for the tokens
  char **tokens = (char**)malloc(sizeof(char*) * (wordsInStr + 1));
  // Loop to iterate through str
  for(int i = 0; i < wordsInStr; i++){
    // Finding start of the word
    char *strt = word_start(str);
    // Finding the end of the word
    char *end = word_terminator(strt);
    // Calculating length of a word in the string
    int len = end - strt;
    // Creating a copy of that word 
    char *newCopy = copy_str(strt,len);
    // Assigning the word to a token
    *(tokens+i) = newCopy;    
    // Start form the end to find a new start for next word
    str = end;
  }
  // Return the tokens
  return tokens;
}

void print_tokens(char **tokens){
  if(*tokens == NULL){
    printf("There are no tokens to print");
    return;
  }
  // int i to iterate through the tokens
  int i = 0;
  // Iterate thtough token to print
  while(*tokens){
    // Print the tokens by order
    printf("Token[%d] = %s\n",i,*tokens);
    // Incrementing i
    i++;
    // Change to print next token
    *tokens++;
  }
}

void free_tokens(char **tokens){
  // int i to iterate through the pointers
  int i = 0;
  // while loop to free each token
  while(*(tokens+i) != NULL){
    // Free each token with the use of i
    free(*(tokens+i));
    // Incrementing i to use next pointer
    i++;
  }
  // Free the pointer that points to the pointers
  free(tokens);
}
