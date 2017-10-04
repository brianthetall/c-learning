#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "kmap.h"

//the return value either to be logged or STDOUT via printf
char* toString(void){

  char *ret="this is a stub toString()";
  return ret;
  
}

kmap* getKmaps(int inputs){

  int i=0;
  kmap *ret;
  char **map;

  if (inputs<=1){
    return NULL;
  }
  
  else if (inputs==2 || inputs==4){
    map = (char**)calloc(inputs,sizeof(char*));//the rows
    for(i=0;i<inputs;i++){
      map[i]=(char*)calloc(inputs,sizeof(char));//the data
    }
  }
  
  else if(inputs==3){
    map = (char**)calloc(2,sizeof(char*));//the rows
    for(i=0;i<inputs;i++){
      map[i]=(char*)calloc(4,sizeof(char));//the data
    }
  }
  
  else{
    //this is the challenging part
    int multiplier = (int)pow(2,inputs-4);
    map = (char**)calloc(4 * multiplier,sizeof(char*));//the rows
    for(i=0;i<inputs;i++){
      map[i]=(char*)calloc(4,sizeof(char));//the data; still just 4 wide
    }
    
  }

  ret->map=map;
  ret->toString = toString;

  return ret;
  
}
