#include <stdio.h>

//this has
int workFunction(int a[], int len){

  auto int i=0,total=0;

  printf("workDoer.workFunction\n");
  
  for(;i<len;i++)
    total+=a[i];

  return total;
}
