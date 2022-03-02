#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

#define MAXLINES 10000

char *strings[MAXLINES];
int readlines(char *strings[], int nlines);
void printlines(char *strings[], int nlines);

void copyStr(char *s, char *t);

int main(){
  
  int nlines;
  printf("Enter strings. Enter $ to stop.\n> ");
  
  if ((nlines = readlines(strings, MAXLINES)) < 0){
    printf("error: input too big to use.\n");
    return 1;
  }
  printf("Please choose one of your saved strings.\n");
  List *history = init_history();
  for(int i = 0; i!=nlines; i++){
    add_history(history,strings[i]);
  }
  print_history(history);
  
  getchar();
  char i = getchar();
  char *string = get_history(history,i-'0');
  printf("%s \n",string);
  printf("First letter of first word: %c \n",*word_start(string));
  printf("Last letter of first word: %c \n",*word_terminator(string));
  printf("Number of words: %d \n",count_words(string));
  printf("copy: ");
  for(char *j = copy_str(string,12); *j != '\0'; j++){
    printf("%c", *j);
  }
  printf("\n");
  char **t = tokenize(string);
  print_tokens(t);
  }


#define MAXLEN 1000
int getLine(char *, int);
char *alloc(int);

int readlines(char *strings[], int maxlines){
  int len, nlines;
  char *p, lines[MAXLEN];

  nlines = 0;
  while((len = getLine(lines, MAXLEN)) > 0)
    if (nlines >= maxlines || (p = malloc(len)) == NULL)
      return -1;
    else{
      lines[len-1] = '\0';
      copyStr(p,lines);
      strings[nlines++] = p;
    }
  return nlines;
      }

void copyStr(char *s, char *t){
  while(*s++ = *t++);
}

void printlines(char *strings[], int nlines){
  int i;
  for(i=0; i<nlines; i++)
    printf("%d> %s\n",i, strings[i]);
}

int getLine(char s[], int lim){
  int c, i;

  i = 0;
  while(--lim > 0 && (c=getchar()) != '$' && c != '\n')
    s[i++] = c;
  if (c=='\n'){
    printf("> ");
    s[i++] = c;
  }
  s[i] = '\0';
  return i;
}
