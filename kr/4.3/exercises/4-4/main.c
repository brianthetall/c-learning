//ADD COMMAND TO PRINT STACK
//DUPLICATE TOP ELEMENT?
//SWAP TOP TWO ELEMENTS
//CLEAR THE STACK
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
      printf("duplicate top element to bottom of stack");
      break;
      
    default:
      printf("unknown command: %s\n",s);
      break;
      
    }
  }
  return 0;
}

