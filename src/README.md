
Project 1: Tokenizer
====================

-----------------------------------
Methods implemented in tokenizer.c
-----------------------------------
->int space_char(char c)
    * It takes in a char c as a paramater and will check if c is a white space or not.
    * If c is not a white space the method will return 0, it will return 1
      otherwise.

->int non_space_char(char c)
    * It takes in a char c as a parameter and will check if c is a non white
      space or not.
    * If c is a white space the method will return 0, it will return 0
      otherwise.
      
->char* word_start(char *str)
    * It takes in a pointer to char str as a parameter.
    * The method will look for the first char in the string str and return
      that start.
    * If no start was found, the method will return a white space.

->char* word_terminator(char *word)
    * This method takes in a ponter to char word as a parameter.
    * It will return the first white space after the last non white space in
      word.

->int count_words(char *str)
    * This method takes in a pointer to a string of words.
    * The method will iterate through the string using the start_word and
      word_terminator methods to count the number of words.
    * The count of words will be kept track with an int i variable.
    * If no start was found after a terminator, then the method will return
      whatever i is.

->char *copy_str(char *inStr, short len)
    * The method will take in a pointer to char inStr and a short len.
    * The method will create space in memory forthe copy of inStr.
    * Using a int i variable we will keep track of the pointer within inStr
      and will be copied to the copy of inStr.
    * The copy of the string will be returned

->char **tokenizer(char* str)
    * This method will take in a pointer to char str.
    * It will call count words to know how many words there will be in the
      pointer to pointers called tokens.
    * Create space in the memory for the pointer to pointers to save them and
      then return them.
    * We iterate through the str looking for the start and end of each word,
      find the lentgh of each word and call copy to store that copy into one of
      the pointers that tokens is pointing to.
    * After iterating through the string, the method will return tokens filled
      up with each word that is within the string.

->void print_tokens(char **tokens)
    * The method will take in a pointer to pointers called tokens.
    * The method will iterate through the pointers and will print each one of
    the tokens within the pointers.

->void free_tokens(char **tokens)
   * The method will take in a pointer to pointers called tokens.
   * It will iterate through the tokens to free each one of them.
   * The pointer pointing to the pointer will be also freed at the end of the loop.


-----------------------------------
Methods implemented in history.c
-----------------------------------
->List* init_history()
   * The method does not take inputs as a parameter.
   * It will create space in the memory for the new list that will be returned.
   * The new list is returned.

->void add_history(List *list, char *str)
   * The method will take a pointer to List list and a pointer to char str.
   * It will iterate through the entire list.
   * A new element will be added at the end of the list.

->char *get_history(List *list, int id)
   * The method will take in a pointer to List list and an int id.
   * A temporary variable is used to iterate through the list
   * It checks the id of each element and will return the current element the
     moment the id matches.
   * It will not return anything otherwise.

->void print_history(List *list)
   * The method will take in a pointer to List list.
   * It will iterate through the list printing each element of the list.

->void free_history(List *list)
   * The method will take in a pointer List list.
   * It iterates through the list to free each element in the list.
