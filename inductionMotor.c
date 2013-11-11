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
  //add function pointer to toString()
};

char* motorString(char *string, struct motor *m){
  //  char *retval=(char*)malloc(sizeof(char;
  if(m==NULL)
    return NULL;

  sprintf(string,"Phases: %d\r\n",(*m).phases);
  //  sprintf(string
  printf("Sizeof(*m)=%d\r\nSizeof(m)=%d\r\n",sizeof(*m),sizeof(m));

  return string;
}

int main(int argc,char *argv[]){

  struct motor m;
  
  if(argc==7){
    m.phases = atoi(argv[1]);
  }else{
    printf("Phases: ");
    scanf("%d",&m.phases);
    printf("Poles: ");
    scanf("%d",&m.poles);
    printf("Turns: ");
    scanf("%d",&m.turns);
    printf("Surface Area of Coil: ");
    scanf("%lf",&m.surfaceAreaCoil);
    printf("Length of Coil: ");
    scanf("%lf",&m.lengthCoil);
    printf("Resistance of Coil: ");
    scanf("%lf",&m.resistance);
    printf("Permeability: ");
    scanf("%lf",&m.u);
  }
  
  printf("Phases: %d\r\n",m.phases);

  char *string=(char*)malloc(256*sizeof(char));
  motorString(string,&m);
  printf("%s\r\n",string);
  
  return 0;
}
