#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct parameters{
  int frequency;
  int current;

};

struct motor{
  int phases;
  int poles;
  int turns;
  double surfaceAreaCoil;
  double lengthCoil;
  double resistance;
  double u;//magnetic permeability of material
};

int main(int argc,char *argv[]){

  struct motor m;
  
  for(int i=0;i<argc;i++)
    printf("%d=%s\r\n",i,argv[i]);
  
  if(argc==7){
    m.phases = atoi(argv[1]);
  }else{
    printf("Phases: ");
    scanf("%d",&m.phases);
  }
  
  printf("Phases: %d\r\n",m.phases);
  
  return 0;
}
