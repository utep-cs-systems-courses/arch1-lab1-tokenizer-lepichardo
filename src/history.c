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
  tempItem = list->root;
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
  struct s_Item *tempItem;
  // Assigning the temporary variable with the head of the list
  tempItem = (*list).root;
  // Iterating through the list
  while(tempItem != NULL){
    // Checking if the id matches the id of each element and if str in item is null or not
    if(tempItem->id == id && tempItem->str != NULL){
      // Return the corrent element
      return tempItem->str;
    }
    // Keep looking for the element with the id
    tempItem = tempItem->next;
  }
  printf("Invalid id...\n");
  // Return \0 if id not found
  return '\0';
}

void print_history(List *list){
  // Creating space in memory for our temporaty variable
  struct s_Item *tempItem;
  // Assigning the temporary variable with the head
  tempItem = (*list).root;
  // Checking if the head is empty
  if(tempItem == NULL){
    printf("Nothing to print...\n");
    // Return since there is nothign to print
    return;
  }
  // Assigning the head with the first item of the list
  tempItem = tempItem->next;
  // Iterating through the list with the while loop
  while(tempItem != NULL){
    // Printing the current elelment of the list
    printf("History[%d] = %s\n",tempItem->id, tempItem->str);
    // Checking the next element of the list
    tempItem = tempItem->next;
  }
}

void free_history(List *list){
  // Loop to iterate through the list
  while((*list).root->next != NULL){
    // Freeing eCH ELEMENT IN THE LIST
    free((*list).root->next);
    // Accessing the next element in the list
    (*list).root->next = (*list).root->next->next;
  }
  // Freeing the root
  free(list);
}
