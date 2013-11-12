/**
 * Induction Motor Modeling
 * To be used for sweeping parameter values and finding optimal
 * design patterns
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct parameters{
  int frequency;
  double current;
};

struct motor{
  int phases;
  int poles;
  int turns;
  double surfaceAreaCoil;
  double lengthCoil;
  double resistance;
  double u;//magnetic permeability of material
  //add function pointer to motorString()?
  struct parameters *p;
};

char* motorString(struct motor *m){
  char *retval=(char*)malloc(sizeof(char)*256*sizeof(*m));
  if(m==NULL)
    return NULL;

  sprintf(retval,"Phases: %d\r\nPoles: %d\r\nTurns: %d\r\nCoil Surface Area: %lf\r\nCoil Length: %lf\r\nCoil Resistance: %lf\r\nCore Magnetic Permeability: %lf\r\n",(*m).phases,(*m).poles,(*m).turns,(*m).surfaceAreaCoil,(*m).lengthCoil,(*m).resistance,(*m).u);

  if(m->p!=NULL){
    char *parameterString=(char*)malloc(sizeof(char)*64*sizeof((*m).p));
    sprintf(parameterString,"Frequency: %d\r\nPhase Current:%lf\r\n",(*m).p->frequency,m->p->current);
    strcat(retval,parameterString);
    free(parameterString);
  }

  return retval;
}

/**
 *   Calculate the flux/current
 */
double inductance(struct motor *m){}

double powerDeliveredToRotor(struct motor *m, double airGap){}


int main(int argc,char *argv[]){

  struct motor m;
  m.p=(struct parameters *)malloc(sizeof(struct parameters));
  (*m.p).current = 69.420;
  m.p->frequency=120;
  
  if(argc==8){
    m.phases = atoi(argv[1]);
    m.poles = atoi(argv[2]);
    m.turns = atoi(argv[3]);
    m.surfaceAreaCoil = atof(argv[4]);
    m.lengthCoil = atof(argv[5]);
    m.resistance = atof(argv[6]);
    m.u = atof(argv[7]);
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
  
  printf("%s\r\n",motorString(&m));

  return 0;
}
