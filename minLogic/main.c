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

  char* s = map->toString();
  char* backup=s;
  //the char* are AUTOMATIC variables; they are on the function's Stack.
  //As stack variables, they come and go with the execution of the function.
  //That is why the address of the pointer changes, while the pointer value is const.
  printf("start of string addr=%d, addr_Ptr=%d\n", s, &s );

  printf("is newline==10? [%c=%d]\n",'\n','\n');
  for(i=0;i<50;i++){
    char* c = ++s;
    printf("[%c=%d],",*c,*c  );
  }
  s=backup;//restore the pointer; ++s changed it

  printf("\nwhile:\n");
  while( *(++s)!='\0' ){
    printf("%c", *s);
  }
  
  printf("Map(s):%s\n",(char*)(map->toString()));
  //while(1){printf(".");}

  map->close(map);
  free( (kmap*) map);

  //i think that when the main exits, it is freeing the map.
  //this seems to cause a seg-fault.
  //do i need a destructor inside of kmap?

  return 0;

}
