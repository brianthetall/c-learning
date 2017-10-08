#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "kmap.h"

//the return value either to be logged or STDOUT via printf
char* toString(void){

  char *ret="this is a stub toString()\n";
  printf("toString(): start of string addr=%d, addr_Ptr=%d\n", ret, &ret );
  return ret;
  
}

//free the resources inside this object
void close(void* k){

  char a='a';
  kmap* km = k;
  char** map = km->map;
  
  
  
}

kmap* getKmaps(int inputs){

  printf("0: getKmaps()\n");
  int i=0,col,row;
  kmap *ret;
  char **map;

  //printf("sizeof char**=%d, char*=%d\n", sizeof(char**),sizeof(char*));

  ret = (kmap*)malloc(sizeof(kmap));
  
  if (inputs<=1){
    return NULL;
  }


  else if (inputs==2 || inputs==4){
    
    map = (char**)calloc(inputs,sizeof(char*));//the rows
    //printf("sizeof(map)=%d\tinputs*sizeof(char*)=%d\n",sizeof(map),inputs*sizeof(char*));

    row=inputs;
    col=inputs;
    
    for(i=0;i<inputs;i++){
      printf("&map[%d]=%d\tmap[%d]=%d\n",i,&map[i],i,map[i]);

      
      map[i]=(char*)calloc(inputs,sizeof(char));//the data
      printf("&map[%d]=%d\tmap[%d]=%d\n",i,&map[i],i,map[i]);

      for(int j=0;j<inputs;j++)
	printf("\t&map[%d][%d]=%d\tmap[%d][%d]=%d\n",i,j,&map[i][j],i,j,map[i][j]);
      printf("\n");
    }
    
  }

  /*
  else if(inputs==3){
    map = (char**)calloc(2,sizeof(char*));//the rows
    row=2;
    col=4;
    for(i=0;i<2;i++){
      map[i]=(char*)calloc(4,sizeof(char));//the data
    }
  }
  
  else{
    row=4;
    col=4;
    //this is the challenging part
    int multiplier = (int)pow(2,inputs-4);
    map = (char**)calloc(4 * multiplier,sizeof(char*));//the rows
    for(i=0;i<inputs;i++){
      map[i]=(char*)calloc(4,sizeof(char));//the data; still just 4 wide
    }
    
  }
  */

  printf("&map[0]=%d\n",&map[0]);

  printf("ret->map=%d\n",ret->map);
  
  ret->map=map;
  ret->toString = toString;
  (*ret).col=col;
  (*ret).row=row;
  printf("ret->map=%d\n",ret->map);

  return ret;
 
}
