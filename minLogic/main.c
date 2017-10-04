#include <stdio.h>
#include <stdlib.h>
#include "kmap.h"

int main(int argc, char** argv){

  int i=0;
  int inputs;//how many inputs to this function?

  for(i=0;i<argc;i++){
    printf("arg[%d]=%s\n",i,argv[i]);
  }

  inputs = atoi(argv[1]);

  printf("Inputs=%d\n",inputs);

  kmap *map = getKmaps(inputs);

  char* s=map->toString();
  while( *(++s)!='\0' ){
    printf("%c", *s);
  }
  
  printf("Map(s):%s\n",(char*)map->toString());

  return 0;

}
