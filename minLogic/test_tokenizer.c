#include <string.h>
#include <stdio.h>
#include "tokenizer.h"

int main(void){

  tokenizer* t=tokenizer_build();

  char* testString="this is the official testing string.";
  char* delim=" ";
  char** list;
  int listLen;

  listLen=t->list(list,testString,delim);

  
  printf("asd");

  for(int i=0; i<listLen; i++){
    printf("strlen(list[]=%d\tlist[%d]=%s",strlen(list[i]),i,list[i]);
  }

  if( strcmp(list[0],"this")==0 && strcmp(list[1],"is")==0 && strcmp(list[2],"the")==0 && strcmp(list[3],"official")==0 && strcmp(list[4],"testing")==0 && strcmp(list[5],"string.")==0 ){
    printf("PASS\n");
    t->free(t);
    return 0;
  }

  printf("FAIL\n");
  t->free(t);  
  return -1;
}
