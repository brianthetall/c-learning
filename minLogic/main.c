#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kmap.h"
#include "tokenizer.h"

int main(int argc, char** argv){

  int DEBUG=1;
  int inputs;//how many inputs to this function?

  if (DEBUG){
    for(int i=0;i<argc;i++)
      printf("arg[%d]=%s\n",i,argv[i]);
  }

  inputs = atoi(argv[1]);
  char *minTerms = argv[2];
  char* dontCares = argv[3];

  if (DEBUG){
    printf("Inputs=%d\n",inputs);
    printf("MinTerms:%s\tDon'tCares:%s\n",minTerms,dontCares);


    tokenizer* tok=tokenizer_build();
    int minTermCount=tok->count("hj,89jkk,jk\0",",");
    //    int minTermCount=tok->count(minTerms,",");
    printf("MinTermCount=%d",minTermCount);
    tok->free(tok);
        
  }

  kmap *map = kmap_build(inputs);//was malloc'ed; pass to free when done

  //the char* are AUTOMATIC variables; they are on the function's Stack.
  //As stack variables, they come and go with the execution of the function.
  //That is why the address of the pointer changes, while the pointer value is const.

  printf("Map(s):%s\n",(char*)(map->toString()));
  
  map->kmap_close(map);//destructor inside of kmap
  

  return 0;

}
