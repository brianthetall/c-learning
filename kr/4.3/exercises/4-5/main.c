//add SIN, EXP, POW
//sin(x),exp(x),pow(x,y)

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

extern int getop(char []);
extern void push(double);
extern double pop(void);

extern int sp;
extern double val[];

int main(){

  int type;
  double op2,output;
  char s[MAXOP];

  while((type=getop(s))!=EOF){
    
    switch(type){
    case NUMBER:
      push(atof(s));
      break;

    case '%':
      op2=pop();
      push((int)pop() % (int)op2);
      break;
      
    case '+':
      push(pop()+pop());
      break;

    case '-':
      op2=pop();
      push(pop()-op2);
      break;

    case '*':
      push(pop()*pop());
      break;

    case '/':
      op2=pop();
      if (op2==0.0){
	printf("ERROR divide by zero");
	break;
      }
      push(pop()/op2);
      break;

    case '\n':
      printf("\n\tOutput=%.8g\n",output=pop());
      push(output);//keep us going
      break;

    case 'p':
      printf("print stack:");
      for(int q=0;q<sp;q++)
	printf("%g ",val[q]);
      break;
      
    case 'd':
      printf("duplicate top element to bottom of stack\n");
      if (sp == 0)
	printf("No values on stack");
      else
	push(val[0]);      
      break;

    case 's':
      printf("Swap top two elements\n");
      if (sp<2)
	printf("Not enough elements to swap");
      else{
	op2=val[0];
	val[0]=val[1];
	val[1]=op2;
      }
      break;

    case 'c':
      printf("Clear the stack!\n");
      sp=0;
      break;

    case 'S':
      push( sin(pop()) );
      break;

    case 'E':
      push( exp(pop()) );
      break;

    case 'P':
      op2=pop();
      push( pow(pop(),op2) );
      break;
      
    default:
      printf("unknown command: %s\n",s);
      break;
      
    }
  }
  return 0;
}

