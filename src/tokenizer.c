#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c){
  return (c==' ' || c=='\n' || c=='\t');
}

int non_space_char(char c){
  return !space_char(c);
}

char *word_start(char *str){
  for(str;space_char(*str);str++);
  return str;
} 

char *word_terminator(char *word){
  word = word_start(word);
  for(word;non_space_char(*word) && *word != '\0';word++);
  return --word;
}

int count_words(char *str){
  int count = 0;
  for(count;*str!='\0';str=word_terminator(str),str++,count++);
  --str;
  if(space_char(*str)) count--;
  return count;
}

char *copy_str(char *inStr, short len){
  char *c = malloc(len);
  char *rem = c;
  for(rem; (*c++ = *inStr++) && len!=1;len--);
  return rem;
}

char **tokenize(char* str){
  char **t = malloc(count_words(str));
  char **rem = t;
  for(rem; *str != '\0';t++){
    str = word_start(str);
    *t = str;
    str = word_terminator(str);
    str++;
  }
  *t = str;
  return rem;
}

void print_tokens(char **tokens){
  char *n = *tokens;
  for(int c = 0; **tokens != '\0';c++,tokens++){
    printf("Token %d: ",c);
    for(n = *tokens; *n != '\0' && non_space_char(*n);n++)
      printf("%c", *n);
    printf("\n");
  }
}

void free_tokens(char **tokens){
  char *n = *tokens;
  while(**tokens != '\0'){
    for(n = *tokens; *n != '\0' && non_space_char(*n);n++)
      free(n);
    tokens++;
  }
}
