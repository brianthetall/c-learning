#include <stdio.h>
#include <stdlib.h>

extern int workFunction(int a[], int len);

int main(int argc,char* argv[]){

  auto int i,values[argc];
  for(i=0;i<argc;i++){
    values[i]=atoi(argv[i]);
    printf("%s==%d\n",argv[i],values[i]);
  }
  
  auto int total=workFunction(values,argc);
  printf("total=%d\n",total);
  
  return 0;
}
