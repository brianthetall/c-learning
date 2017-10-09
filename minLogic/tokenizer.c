#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tokenizer.h"

tokenizer* tokenizer_build(void){
  tokenizer* ret=(tokenizer*)malloc(sizeof(tokenizer));
  ret->count=count;
  ret->list=list;
  ret->free=free;
  return ret;
}

void free(void* deleteMe){
  /*
    insert any instance variables that are malloc'ed
   */
  
  free((tokenizer*)deleteMe);//free the host object memory
}

/**
 * list will be populated here, OR should it be tracked by object? then it can be freed later!
 *
 */

int list(char** list,char *string,char* delim){

  int count=1,i=0;
  //char **list;
  char* newPtr;

  char* toke;
  /*get the size of the list*/
  toke=strpbrk(string,delim);
  while(toke!=NULL){
    ++count;
    toke+=strlen(delim);//skip the space
    printf("&toke=%d\ttoke=%s\n",&toke,toke);
    toke=strpbrk(toke,delim);
  }

  printf("COUNT=%d\n",count);

  /*fill out the list*/
  list = (char**)malloc(sizeof(char*) * count);

  newPtr=strpbrk(string,delim);

  while(newPtr!=NULL){
    
    
    printf("&string=%d\tstring=%s\n",string,string);
    printf("&newPtr=%d\tnewPtr=%s\n",newPtr,newPtr);
  
    list[i]=(char*)malloc(sizeof(char)*(newPtr-string));
    memcpy( list[i], string, (long)newPtr-(long)string );
    printf("list[%d]=%s\n\n",i,list[i]);
    i++;

    
    string=newPtr;
    string+=strlen(delim);//skip the space
    newPtr=strpbrk(string,delim);

  }


  list[i]=(char*)malloc(sizeof(char)*(strlen(string)));
  printf("&string=%d\tstring=%s\n",string,string);
  memcpy( list[i], string , strlen(string) );
  printf("list[%d]=%s\n\n",i,list[i]);


  return i++;//return the list size; the list was passed as a pointer

}

int count(char* input,const char* delim){

    char* tok = strtok(input,delim);
    int count =0;
    while(tok!=NULL){
      count++;
      printf("hi %s\n",tok);
      tok=strtok(NULL,delim);
      printf("yj");
    }
    printf("sdf");
    return count;
}

