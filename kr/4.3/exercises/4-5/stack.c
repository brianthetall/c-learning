#include <stdio.h>
#include <stdlib.h>

#define MAXVAL 10 //STACK DEPTH

int sp=0;
double val[MAXVAL];

void push(double f){

  //printf("pushing: %g\n",f);
  if(sp<MAXVAL)
    val[sp++]=f;
  else{
    printf("ERROR: Stack full! Can't push %g\n",f);
    exit(1);
  }
}

double pop(void){
  if(sp>0)
    return val[--sp];
  else{
    printf("Empty stack\n");
    return 0.0;
  }
}
