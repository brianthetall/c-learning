/**
 * Induction Motor Modeling
 * To be used for sweeping parameter values and finding optimal
 * design patterns
 * gcc -lm -std=c99 -o inductionMotor inductionMotor.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define RESOLUTION 10

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
  double airgap;
  //add function pointer to motorString()?
  struct parameters *p;
};

char* motorString(struct motor *m){
  char *retval=(char*)malloc(sizeof(char)*256*sizeof(*m));
  if(m==NULL)
    return NULL;

  sprintf(retval,"Phases: %d\r\nPoles: %d\r\nTurns: %d\r\nCoil Surface Area: %lf\r\nCoil Length: %lf\r\nCoil Resistance: %lf\r\nCore Magnetic Permeability: %lf\r\nAirGap: %lf\r\n",(*m).phases,(*m).poles,(*m).turns,(*m).surfaceAreaCoil,(*m).lengthCoil,(*m).resistance,(*m).u,m->airgap);

  if(m->p!=NULL){
    char *parameterString=(char*)malloc(sizeof(char)*64*sizeof((*m).p));
    sprintf(parameterString,"Frequency: %d\r\nPhase Current:%lf\r\n",(*m).p->frequency,m->p->current);
    strcat(retval,parameterString);
    free(parameterString);
  }

  return retval;
}

double statorFlux(struct motor *m){
  if(m==NULL)
    return -1;
  double flux=pow(m->turns,2);
  flux*=m->u;
  flux*=m->surfaceAreaCoil;
  flux*=(m->p->current);
  flux/=m->lengthCoil;
  return flux;
}

/**
 *   Calculate the flux/current
 */
double inductance(struct motor *m){
  double flux=statorFlux(m);
  return flux/(m->p->current);
}

/**
 * Generate Power & Torque curves
 */
double** power(struct motor *m){
  int P=0,T=1;
  double pi=3.14;//look up the math.h way...
  double **curves=(double**)malloc(sizeof(double*)*2);
  curves[P]=(double*)malloc(sizeof(double)*RESOLUTION);//power
  curves[T]=(double*)malloc(sizeof(double)*RESOLUTION);//torque
  //start with 100% slip
  curves[P][0]=m->phases*pow(m->p->current,2)*m->resistance;
  curves[T][0]=curves[P][0]*m->poles/(pi*4*m->p->frequency);

  return curves;
}


int main(int argc,char *argv[]){

  struct motor m;
  m.p=(struct parameters *)malloc(sizeof(struct parameters));
  (*m.p).current = 69.420;
  m.p->frequency=120;
  
  if(argc==9){
    m.phases = atoi(argv[1]);
    m.poles = atoi(argv[2]);
    m.turns = atoi(argv[3]);
    m.surfaceAreaCoil = atof(argv[4]);
    m.lengthCoil = atof(argv[5]);
    m.resistance = atof(argv[6]);
    m.u = atof(argv[7]);
    m.airgap=atof(argv[8]);

    printf("%s\r\n",motorString(&m));
    double **pt=power(&m);
    for(int i=0;i<RESOLUTION;i++)
      printf("power=%lf\ttorque=%lf\r\n",pt[0][i],pt[1][i]);

  }else{
    printf("inductionMotor phases poles turns surfaceArea Length resistance u airgap\r\n");
    /*
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
    printf("AirGap: ");
    scanf("%lf",&m.airgap);
    */
  }

  return 0;
}
