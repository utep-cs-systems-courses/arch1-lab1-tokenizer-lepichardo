#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history(){
  // Creating space in the memory for the list
  struct s_List *newList = (List*)malloc(sizeof(List));
  newList->root = (Item*)malloc(sizeof(Item));
  // Returning the start of the list
  return newList;
}

void add_history(List *list, char *str){
  // Using temp variable with new space in the memory
  struct s_Item *tempItem = (Item*)malloc(sizeof(Item));
  // Assigning tempItem to the head of the list
  tempItem = (*list).root;
  // int i to keep track of the id of the Item
  int i = 0;
  // while loop to iterarate through the list
  while(tempItem->next != NULL){
    // Using the next pointer
    tempItem = tempItem->next;
    // Incrementint i to keep the id updated
    i++;
  }
  // Making more space in memory for the next Item
  tempItem->next = (Item*)malloc(sizeof(Item));
  // Assigning the value of str to the next item
  tempItem->next->str = str;
  // Assigning the id to the next item
  tempItem->next->id = i;
  // Update the null pointer
  tempItem->next->next = NULL;
}

char *get_history(List *list, int id){
  // Creating space for the temporary variable
  struct s_Item *tempItem = (Item*)malloc(sizeof(Item));
  // Assigning the temporary variable with the head of the list
  tempItem = (*list).root;
  // Iterating through the list 
  while(tempItem != NULL){
    // Checking if the id matches the id of each element
    if(tempItem->id == id){
      // Return the corrent element
      return tempItem->str;
    }
    // Keep looking for the element with the id
    tempItem = tempItem->next;
  }
  // Return \0 if id not found
  return '\0';
}

void print_history(List *list){
  // Creating space in memory for our temporaty variable
  struct s_Item *tempItem = (Item*)malloc(sizeof(Item));
  // Assigning the temporary variable with the head
  tempItem = (*list).root;
  // Checking if the head is empty
  if(tempItem == NULL){
    printf("Nothing to print...\n");
    // Return since there is nothign to print
    return;
  }
  // Checking if head has an item
  if(tempItem->next == NULL){
    printf("Only the head with no Items...\n");
    // Return since there is nothing to print
    return;
  }
  // Assigning the head with the first item of the list
  tempItem = tempItem->next;
  // Iterating through the list with the while loop
  while(tempItem != NULL){
    // Printing the current elelment of the list
    printf("str: %s,\tid: %d\n",tempItem->str, tempItem->id);
    // Checking the next element of the list
    tempItem = tempItem->next;
  }
}

void free_history(List *list){}
